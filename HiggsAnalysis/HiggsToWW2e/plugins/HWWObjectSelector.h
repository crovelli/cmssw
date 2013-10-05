#ifndef RecoAlgos_HWWObjectSelector_h
#define RecoAlgos_HWWObjectSelector_h
/** \class HWWObjectSelector
 *
 * selects a subset of a collection. 
 * 
 * \author Luca Lista, INFN
 *
 * \version $Revision: 1.13 $
 *
 * $Id: HWWObjectSelector.h,v 1.13 2007/01/31 14:51:37 llista Exp $
 *
 */

#include "FWCore/Framework/interface/EDFilter.h"
#include "FWCore/Framework/interface/EventPrincipal.h" 
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Common/interface/CloneTrait.h"
#include "FWCore/ParameterSet/interface/InputTag.h"
#include "DataFormats/Common/interface/RefVector.h"
#include "DataFormats/Common/interface/RefProd.h"
#include "PhysicsTools/UtilAlgos/interface/ParameterAdapter.h"
#include "PhysicsTools/UtilAlgos/interface/NonNullNumberSelector.h"
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>

namespace helper {

  template<typename C, 
	   typename P = typename edm::clonehelper::CloneTrait<C>::type>
  struct SimpleCollectionStoreManager {
    typedef C collection;
    SimpleCollectionStoreManager() : selected_( new C ) { 
    }
    template<typename I>
    void cloneAndStore( const I & begin, const I & end, edm::Event & ) {
      for( I i = begin; i != end; ++ i )
        selected_->push_back( P::clone( * * i ) );
    }
    edm::OrphanHandle<C> put( edm::Event & evt ) {
      return evt.put( selected_ );
    }
    size_t size() const { return selected_->size(); }
  private:
    std::auto_ptr<C> selected_;
  };

  template<typename C>
    struct HWWObjectSelectorBase : public edm::EDFilter {
      HWWObjectSelectorBase( const edm::ParameterSet & ) {
	produces<C>();
      }
   };

  template<typename C>
  struct CollectionStoreManager {
    typedef SimpleCollectionStoreManager<C> type;
    typedef HWWObjectSelectorBase<C> base;
  };
}

namespace reco {
  namespace helpers {
    template<typename C>
    struct NullPostProcessor {
      NullPostProcessor( const edm::ParameterSet & ) { }
      void init( edm::EDFilter & ) { }
      void process( edm::OrphanHandle<C>, edm::Event & ) { }
    };
  }
}

template<typename S, 
	 typename N = NonNullNumberSelector,
	 typename P = reco::helpers::NullPostProcessor<typename S::collection>,  
	 typename M = typename helper::CollectionStoreManager<typename S::collection>::type, 
	 typename B = typename helper::CollectionStoreManager<typename S::collection>::base>
class HWWObjectSelector : public B {
public:
  /// constructor 
  explicit HWWObjectSelector( const edm::ParameterSet & cfg ) :
  B( cfg ),
  src_( cfg.template getParameter<edm::InputTag>( "src" ) ),
  filter_( false ),
  selector_( cfg ),
  sizeSelector_( reco::modules::make<N>( cfg ) ),
  postProcessor_( cfg ) {
    const std::string filter( "filter" );
    std::vector<std::string> bools = cfg.template getParameterNamesForType<bool>();
    bool found = std::find( bools.begin(), bools.end(), filter ) != bools.end();
    if ( found ) filter_ = cfg.template getParameter<bool>( filter );

    postProcessor_.init( * this );
  }
  /// destructor
  virtual ~HWWObjectSelector() { }
  
private:
  /// process one event
  bool filter( edm::Event& evt, const edm::EventSetup& evtSetup ) {
    edm::Handle<typename S::collection> source;
    evt.getByLabel( src_, source );
    M manager;
    selector_.select( source, evt, evtSetup );
    manager.cloneAndStore( selector_.begin(), selector_.end(), evt );
    bool result = ( ! filter_ || sizeSelector_( manager.size() ) );
    edm::OrphanHandle<typename M::collection> filtered = manager.put( evt );
    postProcessor_.process( filtered, evt );
    return result;
  }
  /// source collection label
  edm::InputTag src_;
  /// filter event
  bool filter_;
  /// Object collection selector
  S selector_;
  /// selected object collection size selector
  N sizeSelector_;
  /// post processor
  P postProcessor_;
};

#endif
