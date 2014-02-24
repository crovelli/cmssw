// -- CLASS DESCRIPTION [PLOT] --
// This creates an sPlot.  See BAD 509 for more information on sPlots.  An sPlot gives us
// the distribution of some variable, x in our data sample for a given species,
// for instance the distribution of signal mES.  The result is similar to a likelihood
// projection plot, but no cuts are made, so every event contributes to the distribution.
//
// To use this class, you first must perform your fit twice:  The first time perform your nominal fit.
// For the second fit, fix your parameters at the minimum, float only your yields, and remove any PDFs correlated
// with the variable of interest.  (In particular, if you want to make a signal mES sPlot, fix everything but yields,
// and perform the fit without the mES PDFs.)  Be sure to save the RooFitResult.   Now you can use RooSPlot.

#include <iostream>
#include <vector>
#include <map>

#include "MLFit/MLSPlot.hh"
#include <RooAbsPdf.h>
#include <RooDataSet.h>
#include <RooRealVar.h>
#include <RooSimultaneous.h>
#include "TTree.h"

#include <TMatrixD.h>

ClassImp(MLSPlot) ;


MLSPlot::MLSPlot() :
  TH1F()
{
  // Default constructor
}

MLSPlot::MLSPlot(const MLSPlot &other) :
  TH1F(other)
{
}

MLSPlot::MLSPlot(const char* name, const char* title, Int_t nbins, Double_t xmin, Double_t xmax) :
  TH1F(name, title, nbins, xmin, xmax)
{
  // Constructor
}


RooDataSet* MLSPlot::addSWeightToData(const RooSimultaneous* pdf,
				      const RooArgList &yieldsTmp,
				      RooDataSet &data, const RooArgSet &projDeps) 
{  
  Int_t nspec = yieldsTmp.getSize();
  RooArgList yields = *(RooArgList*)yieldsTmp.snapshot(kFALSE);

  // The list of variables to normalize over when calculating PDF values.
  RooArgSet vars(*data.get());
  vars.remove(projDeps, kTRUE, kTRUE);

  std::cout << "Now printing the original data : " << std::endl;
  data.tree()->Print();

  // Attach data set
  const_cast<RooSimultaneous*>(pdf)->attachDataSet(data);
    
  // this is a big tricky. we need to extract all the simultaneous pdfs from the full pdf
  //   std::map<int,std::vector<RooAbsPdf*> > speciespdfs ;
  //   std::vector<TString> speciesnames ;
  //   speciesnames.push_back("CPFit_sig") ;
  //   speciesnames.push_back("CPFit_bkg") ;
  //   const RooAbsCategory& indexcat = pdf->indexCat() ;
  //   TIterator* typeiter = indexcat.typeIterator() ;  
  //   RooCatType* cattype;
  //   while( (cattype=static_cast<RooCatType*>(typeiter->Next())) ) {
  //     int icat = cattype->getVal() ;
  //     RooAbsPdf* thispdf = pdf->getPdf(cattype->GetName()) ;
  //     std::vector<RooAbsPdf*> pdfvec ;
  //     for(int k=0; k<nspec; ++k) {
  //       RooAbsCollection* comps = thispdf->getComponents()->selectByName(TString("*") + speciesnames[k] + "*") ;
  //       if(comps->getSize()!=1) {
  // 	std::cout << "something wrong: " << comps->getSize() << std::endl ;
  // 	comps->Print("V") ;
  // 	return ;
  //       }
  //       RooAbsPdf* specpdf = static_cast<RooAbsPdf*>(comps->first()) ;
  //       std::cout << specpdf->GetName() << std::endl ;
  //       pdfvec.push_back(specpdf) ;
  //     }
  //     speciespdfs[icat] = pdfvec ;
  //     std::cout << cattype->GetName() << " " << cattype->getVal() << " " << speciespdfs[icat].size() << std::endl ;
  //   }
  //   delete typeiter ;

  // first calculate the pdf values for all species and all events
  std::vector<RooRealVar*> yieldvars ;
  RooArgSet* parameters = pdf->getParameters(&data) ;
  //parameters->Print("V") ;

  std::vector<double> yieldvalues ;
  for (Int_t k = 0; k < nspec; ++k) {
    RooRealVar* thisyield = dynamic_cast<RooRealVar*>(yields.at(k)) ;
    RooRealVar* yieldinpdf = dynamic_cast<RooRealVar*>(parameters->find(thisyield->GetName() )) ;
    std::cout << "yield in pdf: " << yieldinpdf << " " << thisyield->getVal() << std::endl ;
    yieldvars.push_back(yieldinpdf) ;
    yieldvalues.push_back(thisyield->getVal()) ;
  }

  int numevents = data.numEntries() ;
 
  std::vector<std::vector<double> > pdfvalues(numevents,std::vector<double>(nspec,0)) ; 
  
  // set all yield to zero
  for(int m=0; m<nspec; ++m) yieldvars[m]->setVal(0) ;
  
  for (Int_t ievt = 0; ievt <numevents; ievt++) {
    if (ievt % 100 == 0) {
      std::cout << ".";
      std::cout.flush();
    }
    RooArgSet row(*data.get(ievt));
    for(int k = 0; k < nspec; ++k) {
      // set this yield to 1
      yieldvars[k]->setVal( 1 ) ;
      // evaluate the pdf
      double f_k = pdf->getVal(&vars) ;
      pdfvalues[ievt][k] = f_k ;
      if( !(f_k>1 || f_k<1) ) std::cout << "Strange pdf value: " << ievt << " " << k << " " << f_k << std::endl ;
      yieldvars[k]->setVal( 0 ) ;
    }
  }

  // check that the likelihood normalization is fine
  std::vector<double> norm(nspec,0) ;
  for (Int_t ievt = 0; ievt <numevents ; ievt++) {
    double dnorm(0) ;
    for(int k=0; k<nspec; ++k) dnorm += yieldvalues[k] * pdfvalues[ievt][k] ;
    for(int j=0; j<nspec; ++j) norm[j] += pdfvalues[ievt][j]/dnorm ;
  }
  
  std::cout << "likelihood norms: "  ;
  for(int k=0; k<nspec; ++k) std::cout << norm[k] << " " ;
  std::cout << std::endl ;

  // Make a TMatrixD to hold the covariance matrix.
  TMatrixD covInv(nspec, nspec);
  for (Int_t i = 0; i < nspec; i++) for (Int_t j = 0; j < nspec; j++) covInv(i,j) = 0;

  std::cout << "Calculating covariance matrix";
  for (Int_t ievt = 0; ievt < numevents; ++ievt) {

    // Calculate contribution to the inverse of the covariance
    // matrix. See BAD 509 V2 eqn. 15

    // Sum for the denominator
    Double_t dsum(0);
    for(int k = 0; k < nspec; ++k) 
      dsum += pdfvalues[ievt][k] * yieldvalues[k] ;

    for(int n=0; n<nspec; ++n)
      for(int j=0; j<nspec; ++j) 
	covInv(n,j) +=  pdfvalues[ievt][n]*pdfvalues[ievt][j]/(dsum*dsum);
  }
  // Covariance inverse should now be computed!
  covInv.Print();
  
  // Invert to get the covariance matrix
  if (covInv.Determinant() <=0) {
    std::cout << "MLSPlot Error: covariance matrix is singular; I can't invert it!" << std::endl;
    covInv.Print();
    return 0 ;
  }

  TMatrixD covMatrix(TMatrixD::kInverted,covInv);
  covMatrix.Print() ;

  //check cov normalization
  for(int k=0; k<nspec; ++k) {
    double covnorm(0) ;
    for(int m=0; m<nspec; ++m) covnorm += covInv[k][m]*yieldvalues[m] ;
    double sumrow(0) ;
    for(int m = 0; m < nspec; ++m) sumrow += covMatrix[k][m] ;
    std::cout << yieldvalues[k] << " " << sumrow << " " << covnorm << std::endl ;
  }

  // calculate for each event the sWeight (BAD 509 V2 eq. 21)
  std::cout << "Calculating sWeight" << std::endl;
  std::vector<RooRealVar*> sweightvec ;
  std::vector<RooRealVar*> pdfvec ;  
  RooArgSet sweightset ;

  char wname[256] ;
  for(int k=0; k<nspec; ++k) {
    sprintf(wname,"%s_sw", yieldvars[k]->GetName()) ;
    RooRealVar* var = new RooRealVar(wname,wname,0) ;
    sweightvec.push_back( var) ;
    sweightset.add(*var) ;
    sprintf(wname,"L_%s", yieldvars[k]->GetName()) ;
    var = new RooRealVar(wname,wname,0) ;
    pdfvec.push_back( var) ;
    sweightset.add(*var) ;
  }

  std::cout << "Merging the sWeights variables to the data variables:" << std::endl;
  std::cout << "weight variables follow..." << std::endl;
  sweightset.Print();
  std::cout << "data variables follow..." << std::endl;
  data.get()->Print();
  sweightset.add(*data.get()) ;
  std::cout << "merged variables. Now filling the dataset." << std::endl;
  RooDataSet* sWeightData = new RooDataSet("dataset", "dataset with sWeights", sweightset);
  
  for(int ievt = 0; ievt < numevents; ++ievt) {

    if(ievt%1000==0) std::cout << "processing evt " << ievt << "..." << std::endl;
    
    data.get(ievt) ;

    // sum for denominator
    Double_t dsum(0);
    for(int k = 0; k < nspec; ++k) dsum += pdfvalues[ievt][k] * yieldvalues[k] ;
    
    // covariance weighted pdf for each specief
    double sweightsum(0) ;
    for(int n=0; n<nspec; ++n) {
      double nsum(0) ;
      for(int j=0; j<nspec; ++j) nsum += covMatrix(n,j) * pdfvalues[ievt][j] ;      
      sweightvec[n]->setVal(nsum/dsum) ;
      pdfvec[n]->setVal( pdfvalues[ievt][n] ) ;
      sweightsum+=  nsum/dsum ;
      if( !(fabs(nsum/dsum)>=0 ) ) {
	std::cout << "error: " << nsum/dsum << std::endl ;
	return 0 ;
      }

      //std::cout << nsum/dsum << " " ;
    }
    sWeightData->add(sweightset) ;
  }

  return sWeightData;
  
}

void MLSPlot::fillSPlot(const RooDataSet &data, TString varname, TString weightname) 
{
  if (data.get()->find(varname) == NULL) {
    std::cout << "Can't find variable " << varname << " in data set!" << std::endl;
    return;
  }
  
  if (data.get()->find(weightname) == NULL){
    std::cout << "Can't find weight " << weightname << " in data set!" << std::endl;
    return;
  }
  
  
  for (Int_t ievt = 0; ievt < data.numEntries(); ievt++) {
    RooArgList row(*data.get(ievt));
    Double_t xval = ((RooAbsReal*)row.find(varname))->getVal();
    
    Double_t p = ((RooAbsReal*)row.find(weightname))->getVal();
    
    Fill(xval,p);
  }
  
  
}



void MLSPlot::fillSPlot(const RooAbsReal &x, RooAbsReal &nstar, RooDataSet data, const RooFitResult &fitRes, const RooArgList &pdfListTmp, const RooArgList &yieldsTmp, RooAbsPdf &totalPdf, Bool_t doErrors, const RooArgSet &projDeps) 
{
  Bool_t verbose = kTRUE;
  if (verbose) {
    std::cout << "yieldsTmp:" << std::endl;
    yieldsTmp.Print("V");
    std::cout << "pdfListTmp:" << std::endl;
    pdfListTmp.Print();
  }
  
  // Size of bins...
  Double_t xmin = GetXaxis()->GetXmin();
  Double_t xmax = GetXaxis()->GetXmax();
  Double_t nbins = GetNbinsX();
  Double_t binSize = (xmax - xmin)/nbins;

  if (verbose) {
    std::cout << "Bins: " << xmin << " to " << xmax << " with " << nbins << " bins." << std::endl;
    std::cout << "binSize = " << binSize << std::endl;
  }
  
  // Number of species in this fit.
  Int_t nspec = yieldsTmp.getSize();

  // The list of parameters (with their final fit values)
  RooArgList finalPars = fitRes.floatParsFinal();

  // Number of parameters in the fit result.
  Int_t npars = finalPars.getSize();

  RooArgList pdfList = *(RooArgList*)pdfListTmp.snapshot();
  RooArgList yields = *(RooArgList*)yieldsTmp.snapshot(kFALSE);
  //RooAbsPdf totalPdf = *(RooAbsPdf*)totalPdfTmp.Clone();
  
  if (verbose) {
    std::cout << "Yields I will use in calculation:" << std::endl;
    yields.Print("V");
    std::cout << "pdfList:" << std::endl;
    pdfList.Print();
  }

  // The list of variables to normalize over when calculating PDF values.
  RooArgSet vars(*data.get());
  vars.remove(projDeps, kTRUE, kTRUE);

  // Make a TMatrixD to hold the covariance matrix.
  TMatrixD covMatrix(npars, npars);
  
  // Loop over all the parameters to make the covariance matrix.
  for (Int_t i = 0; i < npars; i++) {
    for (Int_t j = 0; j < npars; j++) {
      const RooRealVar *rowVar= (const RooRealVar*)finalPars.at(i);
      const RooRealVar *colVar= (const RooRealVar*)finalPars.at(j);
      assert(0 != rowVar && 0 != colVar);
      covMatrix(i,j) = rowVar->getError()*colVar->getError()*fitRes.correlation(rowVar->GetName(),colVar->GetName());  
    }
  }
  
  // Get the inverse of the covariance matrix
  // First check if it's singular
  if (covMatrix.Determinant() == 0) {
    std::cout << "MLSPlot Error: covariance matrix is singular;  I can't invert it!" << std::endl;
    covMatrix.Print();
    return;
  }
  TMatrixD covInv(TMatrixD::kInverted,covMatrix);

  if (verbose) {
    std::cout << "Covariance matrix:" << std::endl;
    covMatrix.Print();
    std::cout << "Inverse of covariance matrix:" << std::endl;
    covInv.Print();
  }
  
  // Make a matrix to hold V(i,j) inverse.
  TMatrixD vinv(nspec, nspec);

  // And fill it with the correct numbers...
  Int_t istar(0);
  Int_t vi = 0;
  for (Int_t ci = 0; ci < npars; ci++) {
    // If this parameter isn't a yield, move to the next row
    if (yields.find(finalPars.at(ci)->GetName()) == 0) continue;

    // If this parameter is the one of interest (nstar), then remember its index.
    TString name = ((RooRealVar*)finalPars.at(ci))->GetName();
    if (!name.CompareTo(nstar.GetName())) {
      istar = vi;
    }

    Int_t vj = 0;
    for (Int_t cj = 0; cj < npars; cj++) {

      // If this parameter isn't a yield, move to the next column
      if (!yields.contains(*finalPars.at(cj))) continue;

      // This element's row and column correspond to yield parameters.  Put it in V inverse.
      vinv(vi, vj) = covInv(ci, cj);
      vj++;
    }
    vi++;
  }

  // Now invert V(i, j) inverse to get V(i, j)
  if (vinv.Determinant() == 0) {
    std::cout << "MLSPlot Error: Yield covariance matrix V inverse is singular and can't be inverted!" << std::endl;
    vinv.Print();
    return;
  }
  
  TMatrixD v(TMatrixD::kInverted,vinv);

  if (verbose) {
    std::cout << "V inverse:" << std::endl;
    vinv.Print();
    std::cout << "V:" << std::endl;
    v.Print();
    
    Double_t sum = 0;
    for (Int_t j = 0; j < nspec; j++) {
      sum += v(j,istar);
    }
    std::cout << "Sum of star column in V: " << sum << std::endl;
    
  }


  
  Double_t sum = 0;
  //  Double_t sumtmp = 0;
  
  // This forces the error in a bin to be calculated as the sqrt of the sum of the squares of
  // weights, as they should be.
  if (doErrors) Sumw2();

  totalPdf.attachDataSet(data);
  for (Int_t ievt = 0; ievt < data.numEntries(); ievt++) {
    
    if (ievt % 100 == 0) std::cout << "Event: " << ievt << std::endl;
    // Read this event and find the value of x for this event.
    const RooArgSet *row = data.get(ievt);
    Double_t xval = ((RooAbsReal*)row->find(x.GetName()))->getVal();
    
    // Loop over the species and calculate P.
    Double_t numerator = 0;
    Double_t denominator = 0;    
    for (Int_t i = 0; i < nspec ; i++){

      RooAbsPdf *pdf = (RooAbsPdf*)pdfList.at(i);
      pdf->attachDataSet(data);
      Double_t pdfval = pdf->getVal(&vars);
      numerator += v(istar, i)*pdfval;
      
      //Double_t ni = ((RooAbsReal*)yields.at(i))->getVal();
      //denominator += ni*pdfval;
    }
    denominator = totalPdf.getVal(&vars);

    Double_t p = 1/nstar.getVal()*(numerator/denominator);
    if (xval > xmin && xval < xmax) sum += p*nstar.getVal();
    
    Fill(xval, p*nstar.getVal());

  }// end event loop

  SetEntries(sum*Double_t(binSize));
  if (verbose) std::cout << "Entries should be: " << sum*Double_t(binSize) << " (" << sum << " events)" << std::endl;
  
}

void MLSPlot::fillSPlot(const RooAbsReal &x, RooAbsReal &nstar, RooDataSet data, const RooFitResult &fitRes, const RooArgList &pdfListTmp, const RooArgList &yieldsTmp, Bool_t doErrors, const RooArgSet &projDeps) 
{
  Bool_t verbose = kTRUE;
  if (verbose) {
    std::cout << "nstar: " << std::endl;
    nstar.Print();
    std::cout << "yieldsTmp:" << std::endl;
    yieldsTmp.Print("V");
    std::cout << "pdfListTmp:" << std::endl;
    pdfListTmp.Print();
  }
  
  // Size of bins...
  Double_t xmin = GetXaxis()->GetXmin();
  Double_t xmax = GetXaxis()->GetXmax();
  Double_t nbins = GetNbinsX();
  Double_t binSize = (xmax - xmin)/nbins;

  if (verbose) {
    std::cout << "Bins: " << xmin << " to " << xmax << " with " << nbins << " bins." << std::endl;
    std::cout << "binSize = " << binSize << std::endl;
  }
  
  // Number of species in this fit.
  Int_t nspec = yieldsTmp.getSize();

  // The list of parameters (with their final fit values)
  RooArgList finalPars = fitRes.floatParsFinal();

  // Number of parameters in the fit result.
  Int_t npars = finalPars.getSize();

  RooArgList pdfList = *(RooArgList*)pdfListTmp.snapshot();
  RooArgList yields = *(RooArgList*)yieldsTmp.snapshot(kFALSE);

  if (verbose) {
    std::cout << "Yields I will use in calculation:" << std::endl;
    yields.Print("V");
    std::cout << "pdfList:" << std::endl;
    pdfList.Print();
  }

  // The list of variables to normalize over when calculating PDF values.
  RooArgSet vars(*data.get());
  vars.remove(projDeps, kTRUE, kTRUE);

  // Make a TMatrixD to hold the covariance matrix.
  TMatrixD covMatrix(npars, npars);
  
  // Loop over all the parameters to make the covariance matrix.
  for (Int_t i = 0; i < npars; i++) {
    for (Int_t j = 0; j < npars; j++) {
      const RooRealVar *rowVar= (const RooRealVar*)finalPars.at(i);
      const RooRealVar *colVar= (const RooRealVar*)finalPars.at(j);
      assert(0 != rowVar && 0 != colVar);
      covMatrix(i,j) = rowVar->getError()*colVar->getError()*fitRes.correlation(rowVar->GetName(),colVar->GetName());  
    }
  }
  
  // Get the inverse of the covariance matrix
  // First check if it's singular
  if (covMatrix.Determinant() == 0) {
    std::cout << "MLSPlot Error: covariance matrix is singular;  I can't invert it!" << std::endl;
    covMatrix.Print();
    return;
  }
  TMatrixD covInv(TMatrixD::kInverted,covMatrix);

  if (verbose) {
    std::cout << "Covariance matrix:" << std::endl;
    covMatrix.Print();
    std::cout << "Inverse of covariance matrix:" << std::endl;
    covInv.Print();
  }
  
  // Make a matrix to hold V(i,j) inverse.
  TMatrixD vinv(nspec, nspec);

  // And fill it with the correct numbers...
  Int_t istar(0);
  Int_t vi = 0;
  for (Int_t ci = 0; ci < npars; ci++) {
    // If this parameter isn't a yield, move to the next row
    if (yields.find(finalPars.at(ci)->GetName()) == 0) continue;

    // If this parameter is the one of interest (nstar), then remember its index.
    TString name = ((RooRealVar*)finalPars.at(ci))->GetName();
    if (!name.CompareTo(nstar.GetName())) {
      istar = vi;
    }

    Int_t vj = 0;
    for (Int_t cj = 0; cj < npars; cj++) {

      // If this parameter isn't a yield, move to the next column
      if (!yields.contains(*finalPars.at(cj))) continue;

      // This element's row and column correspond to yield parameters.  Put it in V inverse.
      vinv(vi, vj) = covInv(ci, cj);
      vj++;
    }
    vi++;
  }

  // Now invert V(i, j) inverse to get V(i, j)
  if (vinv.Determinant() == 0) {
    std::cout << "MLSPlot Error: Yield covariance matrix V inverse is singular and can't be inverted!" << std::endl;
    vinv.Print();
    return;
  }
  
  TMatrixD v(TMatrixD::kInverted,vinv);

  if (verbose) {
    std::cout << "V inverse:" << std::endl;
    vinv.Print();
    std::cout << "V:" << std::endl;
    v.Print();
    
    Double_t sum = 0;
    for (Int_t j = 0; j < nspec; j++) {
      sum += v(j,istar);
    }
    std::cout << "Sum of star column in V: " << sum << std::endl;
    
  }


  
  Double_t sum = 0;
  Double_t sumtmp = 0;
  
  // This forces the error in a bin to be calculated as the sqrt of the sum of the squares of
  // weights, as they should be.
  if (doErrors) Sumw2();

  for (Int_t i = 0; i < nspec; i++) {
    RooAbsPdf *pdf = (RooAbsPdf*)pdfList.at(i);
    pdf->attachDataSet(data);
  }

  for (Int_t ievt = 0; ievt < data.numEntries(); ievt++) {
    
    if (ievt % 100 == 0) std::cout << ".";
    // Read this event and find the value of x for this event.
    const RooArgSet *row = data.get(ievt);
    Double_t xval = ((RooAbsReal*)row->find(x.GetName()))->getVal();
    
    // Loop over the species and calculate P.
    Double_t numerator = 0;
    Double_t denominator = 0;    
    for (Int_t i = 0; i < nspec ; i++){

      RooAbsPdf *pdf = (RooAbsPdf*)pdfList.at(i);
      //pdf->attachDataSet(data);
      Double_t pdfval = pdf->getVal(&vars);
      numerator += v(istar, i)*pdfval;
      
      Double_t ni = ((RooAbsReal*)yields.at(i))->getVal();
      denominator += ni*pdfval;
    }
    
    Double_t p = 1/nstar.getVal()*(numerator/denominator);
    sumtmp += ((RooAbsPdf*)pdfList.at(istar))->getVal(&vars)/denominator;

    //if (xval > xmin && xval < xmax)
      sum += p*nstar.getVal();
    
    Fill(xval, p*nstar.getVal());

  }// end event loop

  SetEntries(sum*Double_t(binSize));
  
  std::cout << std::endl;
  if (verbose) std::cout << "Entries should be: " << sum*Double_t(binSize) << " (" << sum << " events)" << std::endl;
  if (verbose) std::cout << "Sum of likelihood ratios for nstar: " << sumtmp << std::endl;
  
}


void MLSPlot::fillSPlot(const RooAbsReal &x, RooAbsReal &nstar, RooDataSet data, const RooFitResult &fitRes, RooAbsPdf &totalPdf, RooArgList &yields, Bool_t doErrors, const RooArgSet &projDeps) 
{
  Bool_t verbose = kTRUE;
  if (verbose) {
    //std::cout << "yieldsTmp:" << std::endl;
    //yieldsTmp.Print("V");
    //std::cout << "pdfListTmp:" << std::endl;
    //pdfListTmp.Print();
  }
  
  // Size of bins...
  Double_t xmin = GetXaxis()->GetXmin();
  Double_t xmax = GetXaxis()->GetXmax();
  Double_t nbins = GetNbinsX();
  Double_t binSize = (xmax - xmin)/nbins;

  if (verbose) {
    std::cout << "Bins: " << xmin << " to " << xmax << " with " << nbins << " bins." << std::endl;
    std::cout << "binSize = " << binSize << std::endl;
  }
  
  // Number of species in this fit.
  Int_t nspec = yields.getSize();

  // The list of parameters (with their final fit values)
  RooArgList finalPars = fitRes.floatParsFinal();

  // Number of parameters in the fit result.
  Int_t npars = finalPars.getSize();

  //RooArgList pdfList = *(RooArgList*)pdfListTmp.snapshot();
  //RooArgList yields = *(RooArgList*)yieldsTmp.snapshot(kFALSE);
  //RooAbsPdf totalPdf = *(RooAbsPdf*)totalPdfTmp.Clone();
  
  if (verbose) {
    std::cout << "Yields I will use in calculation:" << std::endl;
    yields.Print("V");
    //std::cout << "pdfList:" << std::endl;
    //pdfList.Print();
  }

  // The list of variables to normalize over when calculating PDF values.
  RooArgSet vars(*data.get());
  vars.remove(projDeps, kTRUE, kTRUE);

  // Make a TMatrixD to hold the covariance matrix.
  TMatrixD covMatrix(npars, npars);
  
  // Loop over all the parameters to make the covariance matrix.
  for (Int_t i = 0; i < npars; i++) {
    for (Int_t j = 0; j < npars; j++) {
      const RooRealVar *rowVar= (const RooRealVar*)finalPars.at(i);
      const RooRealVar *colVar= (const RooRealVar*)finalPars.at(j);
      assert(0 != rowVar && 0 != colVar);
      covMatrix(i,j) = rowVar->getError()*colVar->getError()*fitRes.correlation(rowVar->GetName(),colVar->GetName());  
    }
  }
  
  // Get the inverse of the covariance matrix
  // First check if it's singular
  if (covMatrix.Determinant() == 0) {
    std::cout << "MLSPlot Error: covariance matrix is singular;  I can't invert it!" << std::endl;
    covMatrix.Print();
    return;
  }
  TMatrixD covInv(TMatrixD::kInverted,covMatrix);

  if (verbose) {
    std::cout << "Covariance matrix:" << std::endl;
    covMatrix.Print();
    std::cout << "Inverse of covariance matrix:" << std::endl;
    covInv.Print();
  }
  
  // Make a matrix to hold V(i,j) inverse.
  TMatrixD vinv(nspec, nspec);

  // And fill it with the correct numbers...
  Int_t istar(0);
  Int_t vi = 0;
  for (Int_t ci = 0; ci < npars; ci++) {
    // If this parameter isn't a yield, move to the next row
    if (yields.find(finalPars.at(ci)->GetName()) == 0) continue;

    // If this parameter is the one of interest (nstar), then remember its index.
    TString name = ((RooRealVar*)finalPars.at(ci))->GetName();
    if (!name.CompareTo(nstar.GetName())) {
      istar = vi;
    }

    Int_t vj = 0;
    for (Int_t cj = 0; cj < npars; cj++) {

      // If this parameter isn't a yield, move to the next column
      if (!yields.contains(*finalPars.at(cj))) continue;

      // This element's row and column correspond to yield parameters.  Put it in V inverse.
      vinv(vi, vj) = covInv(ci, cj);
      vj++;
    }
    vi++;
  }

  // Now invert V(i, j) inverse to get V(i, j)
  if (vinv.Determinant() == 0) {
    std::cout << "MLSPlot Error: Yield covariance matrix V inverse is singular and can't be inverted!" << std::endl;
    vinv.Print();
    return;
  }
  
  TMatrixD v(TMatrixD::kInverted,vinv);

  if (verbose) {
    std::cout << "V inverse:" << std::endl;
    vinv.Print();
    std::cout << "V:" << std::endl;
    v.Print();
    
    Double_t sum = 0;
    for (Int_t j = 0; j < nspec; j++) {
      sum += v(j,istar);
    }
    std::cout << "Sum of star column in V: " << sum << std::endl;
    
  }


  
  Double_t sum = 0;
  //Double_t sumtmp = 0;
  
  // This forces the error in a bin to be calculated as the sqrt of the sum of the squares of
  // weights, as they should be.
  if (doErrors) Sumw2();

  totalPdf.attachDataSet(data);
  for (Int_t ievt = 0; ievt < data.numEntries(); ievt++) {
    
    if (ievt % 100 == 0) std::cout << "Event: " << ievt << std::endl;
    // Read this event and find the value of x for this event.
    const RooArgSet *row = data.get(ievt);
    Double_t xval = ((RooAbsReal*)row->find(x.GetName()))->getVal();
    
    // Loop over the species and calculate P.
    Double_t numerator = 0;
    Double_t denominator = 0;    
    for (Int_t i = 0; i < nspec ; i++){

      //RooAbsPdf *pdf = (RooAbsPdf*)pdfList.at(i);
      //pdf->attachDataSet(data);
      //Double_t pdfval = pdf->getVal(&vars);
      Double_t pdfval = getComponentValue(totalPdf, yields, i, vars);
      numerator += v(istar, i)*pdfval;
      
      //Double_t ni = ((RooAbsReal*)yields.at(i))->getVal();
      //denominator += ni*pdfval;
    }
    denominator = totalPdf.getVal(&vars);

    Double_t p = 1/nstar.getVal()*(numerator/denominator);
    if (xval > xmin && xval < xmax) sum += p*nstar.getVal();
    
    Fill(xval, p*nstar.getVal());

  }// end event loop

  SetEntries(sum*Double_t(binSize));
  if (verbose) std::cout << "Entries should be: " << sum*Double_t(binSize) << " (" << sum << " events)" << std::endl;
  
}


Double_t MLSPlot::getComponentValue(RooAbsPdf &pdf, RooArgList &yieldsTmp, Int_t igood, RooArgSet &normSet) 
{
  int i=0;
  Int_t nspec = yieldsTmp.getSize();
  Double_t yields[nspec];
  //  std::cout << "Before: " << pdf.getVal(&normSet) << std::endl;
  for (i=0; i < nspec; i++) {
    yields[i] = ((RooRealVar*)yieldsTmp.at(i))->getVal();
    ((RooRealVar*)yieldsTmp.at(i))->setVal(0);
  }
  
  ((RooRealVar*)yieldsTmp.at(igood))->setVal(1);
  
  Double_t result = pdf.getVal(&normSet);
  //  std::cout << "During: " << result << std::endl;

  for (i=0; i < nspec; i++) {
    ((RooRealVar*)yieldsTmp.at(i))->setVal(yields[i]);
  }
  //  std::cout << "After: " << pdf.getVal(&normSet) << std::endl;
  return result;
  
}





