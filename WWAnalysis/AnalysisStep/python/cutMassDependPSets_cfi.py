import FWCore.ParameterSet.Config as cms

from WWAnalysis.AnalysisStep.cutPSets_cfi import cloneVPSet

h120 = cms.VPSet()
h130 = cms.VPSet()
h140 = cms.VPSet()
h150 = cms.VPSet()
h160 = cms.VPSet()
h170 = cms.VPSet()
h180 = cms.VPSet()
h190 = cms.VPSet()
h200 = cms.VPSet()
h250 = cms.VPSet()
h300 = cms.VPSet()
h350 = cms.VPSet()
h400 = cms.VPSet()
h450 = cms.VPSet()
h500 = cms.VPSet()
h550 = cms.VPSet()
h600 = cms.VPSet()

h120.append( cms.PSet( label = cms.string("m_{ll} <  40"),      cut = cms.string("mll()    <  40.0 ") , simple = cms.string("mllMax")))
h130.append( cms.PSet( label = cms.string("m_{ll} <  45"),      cut = cms.string("mll()    <  45.0 ") , simple = cms.string("mllMax")))
h140.append( cms.PSet( label = cms.string("m_{ll} <  45"),      cut = cms.string("mll()    <  45.0 ") , simple = cms.string("mllMax")))
h150.append( cms.PSet( label = cms.string("m_{ll} <  50"),      cut = cms.string("mll()    <  50.0 ") , simple = cms.string("mllMax")))
h160.append( cms.PSet( label = cms.string("m_{ll} <  50"),      cut = cms.string("mll()    <  50.0 ") , simple = cms.string("mllMax")))
h170.append( cms.PSet( label = cms.string("m_{ll} <  50"),      cut = cms.string("mll()    <  50.0 ") , simple = cms.string("mllMax")))
h180.append( cms.PSet( label = cms.string("m_{ll} <  60"),      cut = cms.string("mll()    <  60.0 ") , simple = cms.string("mllMax")))
h190.append( cms.PSet( label = cms.string("m_{ll} <  80"),      cut = cms.string("mll()    <  80.0 ") , simple = cms.string("mllMax")))
h200.append( cms.PSet( label = cms.string("m_{ll} <  90"),      cut = cms.string("mll()    <  90.0 ") , simple = cms.string("mllMax")))
h250.append( cms.PSet( label = cms.string("m_{ll} < 150"),      cut = cms.string("mll()    < 150.0 ") , simple = cms.string("mllMax")))
h300.append( cms.PSet( label = cms.string("m_{ll} < 200"),      cut = cms.string("mll()    < 200.0 ") , simple = cms.string("mllMax")))
h350.append( cms.PSet( label = cms.string("m_{ll} < 250"),      cut = cms.string("mll()    < 250.0 ") , simple = cms.string("mllMax")))
h400.append( cms.PSet( label = cms.string("m_{ll} < 300"),      cut = cms.string("mll()    < 300.0 ") , simple = cms.string("mllMax")))
h450.append( cms.PSet( label = cms.string("m_{ll} < 350"),      cut = cms.string("mll()    < 350.0 ") , simple = cms.string("mllMax")))
h500.append( cms.PSet( label = cms.string("m_{ll} < 400"),      cut = cms.string("mll()    < 400.0 ") , simple = cms.string("mllMax")))
h550.append( cms.PSet( label = cms.string("m_{ll} < 450"),      cut = cms.string("mll()    < 450.0 ") , simple = cms.string("mllMax")))
h600.append( cms.PSet( label = cms.string("m_{ll} < 500"),      cut = cms.string("mll()    < 500.0 ") , simple = cms.string("mllMax")))

h120.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  20"), cut = cms.string("ptMax()  > 20.0 ") , simple = cms.string("ptMax")))
h130.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  25"), cut = cms.string("ptMax()  > 25.0 ") , simple = cms.string("ptMax")))
h140.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  25"), cut = cms.string("ptMax()  > 25.0 ") , simple = cms.string("ptMax")))
h150.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  27"), cut = cms.string("ptMax()  > 27.0 ") , simple = cms.string("ptMax")))
h160.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  30"), cut = cms.string("ptMax()  > 30.0 ") , simple = cms.string("ptMax")))
h170.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  34"), cut = cms.string("ptMax()  > 34.0 ") , simple = cms.string("ptMax")))
h180.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  36"), cut = cms.string("ptMax()  > 36.0 ") , simple = cms.string("ptMax")))
h190.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  38"), cut = cms.string("ptMax()  > 38.0 ") , simple = cms.string("ptMax")))
h200.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  40"), cut = cms.string("ptMax()  > 40.0 ") , simple = cms.string("ptMax")))
h250.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  55"), cut = cms.string("ptMax()  > 55.0 ") , simple = cms.string("ptMax")))
h300.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  70"), cut = cms.string("ptMax()  > 70.0 ") , simple = cms.string("ptMax")))
h350.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  80"), cut = cms.string("ptMax()  > 80.0 ") , simple = cms.string("ptMax")))
h400.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  90"), cut = cms.string("ptMax()  > 90.0 ") , simple = cms.string("ptMax")))
h450.append( cms.PSet( label = cms.string("p_{T}^{MAX} > 110"), cut = cms.string("ptMax()  > 110.0") , simple = cms.string("ptMax")))
h500.append( cms.PSet( label = cms.string("p_{T}^{MAX} > 120"), cut = cms.string("ptMax()  > 120.0") , simple = cms.string("ptMax")))
h550.append( cms.PSet( label = cms.string("p_{T}^{MAX} > 130"), cut = cms.string("ptMax()  > 130.0") , simple = cms.string("ptMax")))
h600.append( cms.PSet( label = cms.string("p_{T}^{MAX} > 140"), cut = cms.string("ptMax()  > 140.0") , simple = cms.string("ptMax")))

h120.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 10"), cut = cms.string("ptMin()  > 10.0 ") , simple = cms.string("ptMin")))
h130.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 10"), cut = cms.string("ptMin()  > 10.0 ") , simple = cms.string("ptMin")))
h140.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 15"), cut = cms.string("ptMin()  > 15.0 ") , simple = cms.string("ptMin")))
h150.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h160.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h170.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h180.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h190.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h200.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h250.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h300.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h350.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h400.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h450.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h500.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h550.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
h600.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))

h120.append( cms.PSet( label = cms.string("#Delta#phi < 115"),  cut = cms.string("dPhillInDegrees() < 115.0") , simple = cms.string("deltaPhi")))
h130.append( cms.PSet( label = cms.string("#Delta#phi < 90"),   cut = cms.string("dPhillInDegrees() <  90.0") , simple = cms.string("deltaPhi")))
h140.append( cms.PSet( label = cms.string("#Delta#phi < 90"),   cut = cms.string("dPhillInDegrees() <  90.0") , simple = cms.string("deltaPhi")))
h150.append( cms.PSet( label = cms.string("#Delta#phi < 90"),   cut = cms.string("dPhillInDegrees() <  90.0") , simple = cms.string("deltaPhi")))
h160.append( cms.PSet( label = cms.string("#Delta#phi < 60"),   cut = cms.string("dPhillInDegrees() <  60.0") , simple = cms.string("deltaPhi")))
h170.append( cms.PSet( label = cms.string("#Delta#phi < 60"),   cut = cms.string("dPhillInDegrees() <  60.0") , simple = cms.string("deltaPhi")))
h180.append( cms.PSet( label = cms.string("#Delta#phi < 70"),   cut = cms.string("dPhillInDegrees() <  70.0") , simple = cms.string("deltaPhi")))
h190.append( cms.PSet( label = cms.string("#Delta#phi < 90"),   cut = cms.string("dPhillInDegrees() <  90.0") , simple = cms.string("deltaPhi")))
h200.append( cms.PSet( label = cms.string("#Delta#phi < 100"),  cut = cms.string("dPhillInDegrees() < 100.0") , simple = cms.string("deltaPhi")))
h250.append( cms.PSet( label = cms.string("#Delta#phi < 140"),  cut = cms.string("dPhillInDegrees() < 140.0") , simple = cms.string("deltaPhi")))
h300.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))
h350.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))
h400.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))
h450.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))
h500.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))
h550.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))
h600.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))

hMT120 = cloneVPSet(h120)
hMT130 = cloneVPSet(h130)
hMT140 = cloneVPSet(h140)
hMT150 = cloneVPSet(h150)
hMT160 = cloneVPSet(h160)
hMT170 = cloneVPSet(h170)
hMT180 = cloneVPSet(h180)
hMT190 = cloneVPSet(h190)
hMT200 = cloneVPSet(h200)
hMT250 = cloneVPSet(h250)
hMT300 = cloneVPSet(h300)
hMT350 = cloneVPSet(h350)
hMT400 = cloneVPSet(h400)
hMT450 = cloneVPSet(h450)
hMT500 = cloneVPSet(h500)
hMT550 = cloneVPSet(h550)
hMT600 = cloneVPSet(h600)

hMT120.append( cms.PSet( label = cms.string("70 < m_{T} < 120"), cut = cms.string("mTHiggs('PFMET') > 70 && mTHiggs('PFMET') < 120") , simple = cms.string("mT")))
hMT130.append( cms.PSet( label = cms.string("75 < m_{T} < 125"), cut = cms.string("mTHiggs('PFMET') > 75 && mTHiggs('PFMET') < 125") , simple = cms.string("mT")))
hMT140.append( cms.PSet( label = cms.string("80 < m_{T} < 130"), cut = cms.string("mTHiggs('PFMET') > 80 && mTHiggs('PFMET') < 130") , simple = cms.string("mT")))
hMT150.append( cms.PSet( label = cms.string("80 < m_{T} < 150"), cut = cms.string("mTHiggs('PFMET') > 80 && mTHiggs('PFMET') < 150") , simple = cms.string("mT")))
hMT160.append( cms.PSet( label = cms.string("90 < m_{T} < 160"), cut = cms.string("mTHiggs('PFMET') > 90 && mTHiggs('PFMET') < 160") , simple = cms.string("mT")))
hMT170.append( cms.PSet( label = cms.string("20 < m_{T} < 170"), cut = cms.string("mTHiggs('PFMET') > 20 && mTHiggs('PFMET') < 170") , simple = cms.string("mT")))
hMT180.append( cms.PSet( label = cms.string("20 < m_{T} < 180"), cut = cms.string("mTHiggs('PFMET') > 20 && mTHiggs('PFMET') < 180") , simple = cms.string("mT")))
hMT190.append( cms.PSet( label = cms.string("20 < m_{T} < 190"), cut = cms.string("mTHiggs('PFMET') > 20 && mTHiggs('PFMET') < 190") , simple = cms.string("mT")))
hMT200.append( cms.PSet( label = cms.string("20 < m_{T} < 200"), cut = cms.string("mTHiggs('PFMET') > 20 && mTHiggs('PFMET') < 200") , simple = cms.string("mT")))
hMT250.append( cms.PSet( label = cms.string("20 < m_{T} < 250"), cut = cms.string("mTHiggs('PFMET') > 20 && mTHiggs('PFMET') < 250") , simple = cms.string("mT")))
hMT300.append( cms.PSet( label = cms.string("20 < m_{T} < 300"), cut = cms.string("mTHiggs('PFMET') > 20 && mTHiggs('PFMET') < 300") , simple = cms.string("mT")))
hMT350.append( cms.PSet( label = cms.string("20 < m_{T} < 350"), cut = cms.string("mTHiggs('PFMET') > 20 && mTHiggs('PFMET') < 350") , simple = cms.string("mT")))
hMT400.append( cms.PSet( label = cms.string("20 < m_{T} < 400"), cut = cms.string("mTHiggs('PFMET') > 20 && mTHiggs('PFMET') < 400") , simple = cms.string("mT")))
hMT450.append( cms.PSet( label = cms.string("20 < m_{T} < 450"), cut = cms.string("mTHiggs('PFMET') > 20 && mTHiggs('PFMET') < 450") , simple = cms.string("mT")))
hMT500.append( cms.PSet( label = cms.string("20 < m_{T} < 500"), cut = cms.string("mTHiggs('PFMET') > 20 && mTHiggs('PFMET') < 500") , simple = cms.string("mT")))
hMT550.append( cms.PSet( label = cms.string("20 < m_{T} < 550"), cut = cms.string("mTHiggs('PFMET') > 20 && mTHiggs('PFMET') < 550") , simple = cms.string("mT")))
hMT600.append( cms.PSet( label = cms.string("20 < m_{T} < 600"), cut = cms.string("mTHiggs('PFMET') > 20 && mTHiggs('PFMET') < 600") , simple = cms.string("mT")))

hGammaMR120 = cloneVPSet(h120)
hGammaMR130 = cloneVPSet(h130)
hGammaMR140 = cloneVPSet(h140)
hGammaMR150 = cloneVPSet(h150)
hGammaMR160 = cloneVPSet(h160)
hGammaMR170 = cloneVPSet(h170)
hGammaMR180 = cloneVPSet(h180)
hGammaMR190 = cloneVPSet(h190)
hGammaMR200 = cloneVPSet(h200)
hGammaMR250 = cloneVPSet(h250)
hGammaMR300 = cloneVPSet(h300)
hGammaMR350 = cloneVPSet(h350)
hGammaMR400 = cloneVPSet(h400)
hGammaMR450 = cloneVPSet(h450)
hGammaMR500 = cloneVPSet(h500)
hGammaMR550 = cloneVPSet(h550)
hGammaMR600 = cloneVPSet(h600)

# hGammaMR120.append( cms.PSet( label = cms.string("0.5  < 2*#gamma*m_{R}^{*}/m_{H} < 1.1 "), cut = cms.string("2*gammaMRStar()/120 > 0.5  && 2*gammaMRStar()/120 < 1.1 ") , simple = cms.string("gammaMR")))
# hGammaMR130.append( cms.PSet( label = cms.string("0.5  < 2*#gamma*m_{R}^{*}/m_{H} < 1.1 "), cut = cms.string("2*gammaMRStar()/130 > 0.5  && 2*gammaMRStar()/130 < 1.1 ") , simple = cms.string("gammaMR")))
# hGammaMR140.append( cms.PSet( label = cms.string("0.5  < 2*#gamma*m_{R}^{*}/m_{H} < 1.1 "), cut = cms.string("2*gammaMRStar()/140 > 0.5  && 2*gammaMRStar()/140 < 1.1 ") , simple = cms.string("gammaMR")))
# hGammaMR150.append( cms.PSet( label = cms.string("0.75 < 2*#gamma*m_{R}^{*}/m_{H} < 1.15"), cut = cms.string("2*gammaMRStar()/150 > 0.75 && 2*gammaMRStar()/150 < 1.15") , simple = cms.string("gammaMR")))
# hGammaMR160.append( cms.PSet( label = cms.string("0.75 < 2*#gamma*m_{R}^{*}/m_{H} < 1.2 "), cut = cms.string("2*gammaMRStar()/160 > 0.75 && 2*gammaMRStar()/160 < 1.2 ") , simple = cms.string("gammaMR")))
# hGammaMR170.append( cms.PSet( label = cms.string("0.75 < 2*#gamma*m_{R}^{*}/m_{H} < 1.3 "), cut = cms.string("2*gammaMRStar()/170 > 0.75 && 2*gammaMRStar()/170 < 1.3 ") , simple = cms.string("gammaMR")))
# hGammaMR180.append( cms.PSet( label = cms.string("0.8  < 2*#gamma*m_{R}^{*}/m_{H} < 1.4 "), cut = cms.string("2*gammaMRStar()/180 > 0.8  && 2*gammaMRStar()/180 < 1.4 ") , simple = cms.string("gammaMR")))
# hGammaMR190.append( cms.PSet( label = cms.string("0.8  < 2*#gamma*m_{R}^{*}/m_{H} < 1.4 "), cut = cms.string("2*gammaMRStar()/190 > 0.8  && 2*gammaMRStar()/190 < 1.4 ") , simple = cms.string("gammaMR")))
# hGammaMR200.append( cms.PSet( label = cms.string("0.8  < 2*#gamma*m_{R}^{*}/m_{H} < 1.4 "), cut = cms.string("2*gammaMRStar()/200 > 0.8  && 2*gammaMRStar()/200 < 1.4 ") , simple = cms.string("gammaMR")))
# hGammaMR250.append( cms.PSet( label = cms.string("0.9  < 2*#gamma*m_{R}^{*}/m_{H} < 1.4 "), cut = cms.string("2*gammaMRStar()/250 > 0.9  && 2*gammaMRStar()/250 < 1.4 ") , simple = cms.string("gammaMR")))
# hGammaMR300.append( cms.PSet( label = cms.string("0.9  < 2*#gamma*m_{R}^{*}/m_{H} < 1.5 "), cut = cms.string("2*gammaMRStar()/300 > 0.9  && 2*gammaMRStar()/300 < 1.5 ") , simple = cms.string("gammaMR")))
# hGammaMR350.append( cms.PSet( label = cms.string("0.9  < 2*#gamma*m_{R}^{*}/m_{H} < 1.5 "), cut = cms.string("2*gammaMRStar()/350 > 0.9  && 2*gammaMRStar()/350 < 1.5 ") , simple = cms.string("gammaMR")))
# hGammaMR400.append( cms.PSet( label = cms.string("0.9  < 2*#gamma*m_{R}^{*}/m_{H} < 1.5 "), cut = cms.string("2*gammaMRStar()/400 > 0.9  && 2*gammaMRStar()/400 < 1.5 ") , simple = cms.string("gammaMR")))
# hGammaMR450.append( cms.PSet( label = cms.string("0.9  < 2*#gamma*m_{R}^{*}/m_{H} < 1.5 "), cut = cms.string("2*gammaMRStar()/450 > 0.9  && 2*gammaMRStar()/450 < 1.5 ") , simple = cms.string("gammaMR")))
# hGammaMR500.append( cms.PSet( label = cms.string("0.8  < 2*#gamma*m_{R}^{*}/m_{H} < 1.5 "), cut = cms.string("2*gammaMRStar()/500 > 0.8  && 2*gammaMRStar()/500 < 1.5 ") , simple = cms.string("gammaMR")))
# hGammaMR550.append( cms.PSet( label = cms.string("0.8  < 2*#gamma*m_{R}^{*}/m_{H} < 1.5 "), cut = cms.string("2*gammaMRStar()/550 > 0.8  && 2*gammaMRStar()/550 < 1.5 ") , simple = cms.string("gammaMR")))
# hGammaMR600.append( cms.PSet( label = cms.string("0.8  < 2*#gamma*m_{R}^{*}/m_{H} < 1.5 "), cut = cms.string("2*gammaMRStar()/600 > 0.8  && 2*gammaMRStar()/600 < 1.5 ") , simple = cms.string("gammaMR")))

hGammaMR120.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/120 > 0.5  && 2*gammaMRStar()/120 < 1.1 ") , simple = cms.string("gammaMR")))
hGammaMR130.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/130 > 0.5  && 2*gammaMRStar()/130 < 1.1 ") , simple = cms.string("gammaMR")))
hGammaMR140.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/140 > 0.5  && 2*gammaMRStar()/140 < 1.1 ") , simple = cms.string("gammaMR")))
hGammaMR150.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/150 > 0.75 && 2*gammaMRStar()/150 < 1.15") , simple = cms.string("gammaMR")))
hGammaMR160.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/160 > 0.75 && 2*gammaMRStar()/160 < 1.2 ") , simple = cms.string("gammaMR")))
hGammaMR170.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/170 > 0.75 && 2*gammaMRStar()/170 < 1.3 ") , simple = cms.string("gammaMR")))
hGammaMR180.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/180 > 0.8  && 2*gammaMRStar()/180 < 1.4 ") , simple = cms.string("gammaMR")))
hGammaMR190.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/190 > 0.8  && 2*gammaMRStar()/190 < 1.4 ") , simple = cms.string("gammaMR")))
hGammaMR200.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/200 > 0.8  && 2*gammaMRStar()/200 < 1.4 ") , simple = cms.string("gammaMR")))
hGammaMR250.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/250 > 0.9  && 2*gammaMRStar()/250 < 1.4 ") , simple = cms.string("gammaMR")))
hGammaMR300.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/300 > 0.9  && 2*gammaMRStar()/300 < 1.5 ") , simple = cms.string("gammaMR")))
hGammaMR350.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/350 > 0.9  && 2*gammaMRStar()/350 < 1.5 ") , simple = cms.string("gammaMR")))
hGammaMR400.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/400 > 0.9  && 2*gammaMRStar()/400 < 1.5 ") , simple = cms.string("gammaMR")))
hGammaMR450.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/450 > 0.9  && 2*gammaMRStar()/450 < 1.5 ") , simple = cms.string("gammaMR")))
hGammaMR500.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/500 > 0.8  && 2*gammaMRStar()/500 < 1.5 ") , simple = cms.string("gammaMR")))
hGammaMR550.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/550 > 0.8  && 2*gammaMRStar()/550 < 1.5 ") , simple = cms.string("gammaMR")))
hGammaMR600.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/600 > 0.8  && 2*gammaMRStar()/600 < 1.5 ") , simple = cms.string("gammaMR")))

hOneJet120 = cms.VPSet()
hOneJet130 = cms.VPSet()
hOneJet140 = cms.VPSet()
hOneJet150 = cms.VPSet()
hOneJet160 = cms.VPSet()
hOneJet170 = cms.VPSet()
hOneJet180 = cms.VPSet()
hOneJet190 = cms.VPSet()
hOneJet200 = cms.VPSet()
hOneJet250 = cms.VPSet()
hOneJet300 = cms.VPSet()
hOneJet350 = cms.VPSet()
hOneJet400 = cms.VPSet()
hOneJet450 = cms.VPSet()
hOneJet500 = cms.VPSet()
hOneJet550 = cms.VPSet()
hOneJet600 = cms.VPSet()

hOneJet120.append( cms.PSet( label = cms.string("m_{ll} <  40"),      cut = cms.string("mll()    <  40.0 ") , simple = cms.string("mllMax")))
hOneJet130.append( cms.PSet( label = cms.string("m_{ll} <  45"),      cut = cms.string("mll()    <  45.0 ") , simple = cms.string("mllMax")))
hOneJet140.append( cms.PSet( label = cms.string("m_{ll} <  45"),      cut = cms.string("mll()    <  45.0 ") , simple = cms.string("mllMax")))
hOneJet150.append( cms.PSet( label = cms.string("m_{ll} <  50"),      cut = cms.string("mll()    <  50.0 ") , simple = cms.string("mllMax")))
hOneJet160.append( cms.PSet( label = cms.string("m_{ll} <  50"),      cut = cms.string("mll()    <  50.0 ") , simple = cms.string("mllMax")))
hOneJet170.append( cms.PSet( label = cms.string("m_{ll} <  50"),      cut = cms.string("mll()    <  50.0 ") , simple = cms.string("mllMax")))
hOneJet180.append( cms.PSet( label = cms.string("m_{ll} <  60"),      cut = cms.string("mll()    <  60.0 ") , simple = cms.string("mllMax")))
hOneJet190.append( cms.PSet( label = cms.string("m_{ll} <  80"),      cut = cms.string("mll()    <  80.0 ") , simple = cms.string("mllMax")))
hOneJet200.append( cms.PSet( label = cms.string("m_{ll} <  90"),      cut = cms.string("mll()    <  90.0 ") , simple = cms.string("mllMax")))
hOneJet250.append( cms.PSet( label = cms.string("m_{ll} < 150"),      cut = cms.string("mll()    < 150.0 ") , simple = cms.string("mllMax")))
hOneJet300.append( cms.PSet( label = cms.string("m_{ll} < 200"),      cut = cms.string("mll()    < 200.0 ") , simple = cms.string("mllMax")))
hOneJet350.append( cms.PSet( label = cms.string("m_{ll} < 250"),      cut = cms.string("mll()    < 250.0 ") , simple = cms.string("mllMax")))
hOneJet400.append( cms.PSet( label = cms.string("m_{ll} < 300"),      cut = cms.string("mll()    < 300.0 ") , simple = cms.string("mllMax")))
hOneJet450.append( cms.PSet( label = cms.string("m_{ll} < 350"),      cut = cms.string("mll()    < 350.0 ") , simple = cms.string("mllMax")))
hOneJet500.append( cms.PSet( label = cms.string("m_{ll} < 400"),      cut = cms.string("mll()    < 400.0 ") , simple = cms.string("mllMax")))
hOneJet550.append( cms.PSet( label = cms.string("m_{ll} < 450"),      cut = cms.string("mll()    < 450.0 ") , simple = cms.string("mllMax")))
hOneJet600.append( cms.PSet( label = cms.string("m_{ll} < 500"),      cut = cms.string("mll()    < 500.0 ") , simple = cms.string("mllMax")))

hOneJet120.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  20"), cut = cms.string("ptMax()  > 20.0 ") , simple = cms.string("ptMax")))
hOneJet130.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  25"), cut = cms.string("ptMax()  > 25.0 ") , simple = cms.string("ptMax")))
hOneJet140.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  25"), cut = cms.string("ptMax()  > 25.0 ") , simple = cms.string("ptMax")))
hOneJet150.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  27"), cut = cms.string("ptMax()  > 27.0 ") , simple = cms.string("ptMax")))
hOneJet160.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  30"), cut = cms.string("ptMax()  > 30.0 ") , simple = cms.string("ptMax")))
hOneJet170.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  34"), cut = cms.string("ptMax()  > 34.0 ") , simple = cms.string("ptMax")))
hOneJet180.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  36"), cut = cms.string("ptMax()  > 36.0 ") , simple = cms.string("ptMax")))
hOneJet190.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  38"), cut = cms.string("ptMax()  > 38.0 ") , simple = cms.string("ptMax")))
hOneJet200.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  40"), cut = cms.string("ptMax()  > 40.0 ") , simple = cms.string("ptMax")))
hOneJet250.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  55"), cut = cms.string("ptMax()  > 55.0 ") , simple = cms.string("ptMax")))
hOneJet300.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  70"), cut = cms.string("ptMax()  > 70.0 ") , simple = cms.string("ptMax")))
hOneJet350.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  80"), cut = cms.string("ptMax()  > 80.0 ") , simple = cms.string("ptMax")))
hOneJet400.append( cms.PSet( label = cms.string("p_{T}^{MAX} >  90"), cut = cms.string("ptMax()  > 90.0 ") , simple = cms.string("ptMax")))
hOneJet450.append( cms.PSet( label = cms.string("p_{T}^{MAX} > 110"), cut = cms.string("ptMax()  > 110.0") , simple = cms.string("ptMax")))
hOneJet500.append( cms.PSet( label = cms.string("p_{T}^{MAX} > 120"), cut = cms.string("ptMax()  > 120.0") , simple = cms.string("ptMax")))
hOneJet550.append( cms.PSet( label = cms.string("p_{T}^{MAX} > 130"), cut = cms.string("ptMax()  > 130.0") , simple = cms.string("ptMax")))
hOneJet600.append( cms.PSet( label = cms.string("p_{T}^{MAX} > 140"), cut = cms.string("ptMax()  > 140.0") , simple = cms.string("ptMax")))

hOneJet120.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 10"), cut = cms.string("ptMin()  > 10.0 ") , simple = cms.string("ptMin")))
hOneJet130.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 10"), cut = cms.string("ptMin()  > 10.0 ") , simple = cms.string("ptMin")))
hOneJet140.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 15"), cut = cms.string("ptMin()  > 15.0 ") , simple = cms.string("ptMin")))
hOneJet150.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet160.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet170.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet180.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet190.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet200.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet250.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet300.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet350.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet400.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet450.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet500.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet550.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))
hOneJet600.append( cms.PSet( label = cms.string("p_{T}^{MIN} > 25"), cut = cms.string("ptMin()  > 25.0 ") , simple = cms.string("ptMin")))

hOneJet120.append( cms.PSet( label = cms.string("#Delta#phi < 115"),  cut = cms.string("dPhillInDegrees() < 115.0") , simple = cms.string("deltaPhi")))
hOneJet130.append( cms.PSet( label = cms.string("#Delta#phi < 90"),   cut = cms.string("dPhillInDegrees() <  90.0") , simple = cms.string("deltaPhi")))
hOneJet140.append( cms.PSet( label = cms.string("#Delta#phi < 90"),   cut = cms.string("dPhillInDegrees() <  90.0") , simple = cms.string("deltaPhi")))
hOneJet150.append( cms.PSet( label = cms.string("#Delta#phi < 90"),   cut = cms.string("dPhillInDegrees() <  90.0") , simple = cms.string("deltaPhi")))
hOneJet160.append( cms.PSet( label = cms.string("#Delta#phi < 60"),   cut = cms.string("dPhillInDegrees() <  60.0") , simple = cms.string("deltaPhi")))
hOneJet170.append( cms.PSet( label = cms.string("#Delta#phi < 60"),   cut = cms.string("dPhillInDegrees() <  60.0") , simple = cms.string("deltaPhi")))
hOneJet180.append( cms.PSet( label = cms.string("#Delta#phi < 70"),   cut = cms.string("dPhillInDegrees() <  70.0") , simple = cms.string("deltaPhi")))
hOneJet190.append( cms.PSet( label = cms.string("#Delta#phi < 90"),   cut = cms.string("dPhillInDegrees() <  90.0") , simple = cms.string("deltaPhi")))
hOneJet200.append( cms.PSet( label = cms.string("#Delta#phi < 100"),  cut = cms.string("dPhillInDegrees() < 100.0") , simple = cms.string("deltaPhi")))
hOneJet250.append( cms.PSet( label = cms.string("#Delta#phi < 140"),  cut = cms.string("dPhillInDegrees() < 140.0") , simple = cms.string("deltaPhi")))
hOneJet300.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))
hOneJet350.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))
hOneJet400.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))
hOneJet450.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))
hOneJet500.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))
hOneJet550.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))
hOneJet600.append( cms.PSet( label = cms.string("#Delta#phi < 175"),  cut = cms.string("dPhillInDegrees() < 175.0") , simple = cms.string("deltaPhi")))

hOneJet120.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/120 > 0.5  && 2*gammaMRStar()/120 < 1.1 ") , simple = cms.string("gammaMR")))
hOneJet130.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/130 > 0.5  && 2*gammaMRStar()/130 < 1.1 ") , simple = cms.string("gammaMR")))
hOneJet140.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/140 > 0.5  && 2*gammaMRStar()/140 < 1.1 ") , simple = cms.string("gammaMR")))
hOneJet150.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/150 > 0.75 && 2*gammaMRStar()/150 < 1.15") , simple = cms.string("gammaMR")))
hOneJet160.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/160 > 0.75 && 2*gammaMRStar()/160 < 1.2 ") , simple = cms.string("gammaMR")))
hOneJet170.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/170 > 0.75 && 2*gammaMRStar()/170 < 1.3 ") , simple = cms.string("gammaMR")))
hOneJet180.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/180 > 0.8  && 2*gammaMRStar()/180 < 1.4 ") , simple = cms.string("gammaMR")))
hOneJet190.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/190 > 0.8  && 2*gammaMRStar()/190 < 1.4 ") , simple = cms.string("gammaMR")))
hOneJet200.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/200 > 0.8  && 2*gammaMRStar()/200 < 1.4 ") , simple = cms.string("gammaMR")))
hOneJet250.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/250 > 0.9  && 2*gammaMRStar()/250 < 1.4 ") , simple = cms.string("gammaMR")))
hOneJet300.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/300 > 0.9  && 2*gammaMRStar()/300 < 1.5 ") , simple = cms.string("gammaMR")))
hOneJet350.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/350 > 0.9  && 2*gammaMRStar()/350 < 1.5 ") , simple = cms.string("gammaMR")))
hOneJet400.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/400 > 0.9  && 2*gammaMRStar()/400 < 1.5 ") , simple = cms.string("gammaMR")))
hOneJet450.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/450 > 0.9  && 2*gammaMRStar()/450 < 1.5 ") , simple = cms.string("gammaMR")))
hOneJet500.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/500 > 0.8  && 2*gammaMRStar()/500 < 1.5 ") , simple = cms.string("gammaMR")))
hOneJet550.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/550 > 0.8  && 2*gammaMRStar()/550 < 1.5 ") , simple = cms.string("gammaMR")))
hOneJet600.append( cms.PSet( label = cms.string("2*#gamma*m_{R}^{*}/m_{H}"), cut = cms.string("2*gammaMRStar()/600 > 0.8  && 2*gammaMRStar()/600 < 1.5 ") , simple = cms.string("gammaMR")))
