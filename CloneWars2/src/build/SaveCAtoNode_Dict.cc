// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME SaveCAtoNode_Dict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "../SaveCAtoNode.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *SaveCAtoNode_Dictionary();
   static void SaveCAtoNode_TClassManip(TClass*);
   static void *new_SaveCAtoNode(void *p = nullptr);
   static void *newArray_SaveCAtoNode(Long_t size, void *p);
   static void delete_SaveCAtoNode(void *p);
   static void deleteArray_SaveCAtoNode(void *p);
   static void destruct_SaveCAtoNode(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SaveCAtoNode*)
   {
      ::SaveCAtoNode *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SaveCAtoNode));
      static ::ROOT::TGenericClassInfo 
         instance("SaveCAtoNode", "", 59,
                  typeid(::SaveCAtoNode), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SaveCAtoNode_Dictionary, isa_proxy, 3,
                  sizeof(::SaveCAtoNode) );
      instance.SetNew(&new_SaveCAtoNode);
      instance.SetNewArray(&newArray_SaveCAtoNode);
      instance.SetDelete(&delete_SaveCAtoNode);
      instance.SetDeleteArray(&deleteArray_SaveCAtoNode);
      instance.SetDestructor(&destruct_SaveCAtoNode);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SaveCAtoNode*)
   {
      return GenerateInitInstanceLocal((::SaveCAtoNode*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SaveCAtoNode*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SaveCAtoNode_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SaveCAtoNode*)nullptr)->GetClass();
      SaveCAtoNode_TClassManip(theClass);
   return theClass;
   }

   static void SaveCAtoNode_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_SaveCAtoNode(void *p) {
      return  p ? new(p) ::SaveCAtoNode : new ::SaveCAtoNode;
   }
   static void *newArray_SaveCAtoNode(Long_t nElements, void *p) {
      return p ? new(p) ::SaveCAtoNode[nElements] : new ::SaveCAtoNode[nElements];
   }
   // Wrapper around operator delete
   static void delete_SaveCAtoNode(void *p) {
      delete ((::SaveCAtoNode*)p);
   }
   static void deleteArray_SaveCAtoNode(void *p) {
      delete [] ((::SaveCAtoNode*)p);
   }
   static void destruct_SaveCAtoNode(void *p) {
      typedef ::SaveCAtoNode current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SaveCAtoNode

namespace {
  void TriggerDictionaryInitialization_SaveCAtoNode_Dict_Impl() {
    static const char* headers[] = {
"0",
nullptr
    };
    static const char* includePaths[] = {
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "SaveCAtoNode_Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class SaveCAtoNode;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "SaveCAtoNode_Dict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#ifndef SAVECATONODE_H__
#define SAVECATONODE_H__


#define HomogeneousField

#include "ClonesContainer.h"
#include "CaloInfo.h"


#include <fun4all/SubsysReco.h>

#include <fastjet/ClusterSequence.hh>
#include <fastjet/FunctionOfPseudoJet.hh>
#include <fastjet/JetDefinition.hh>
#include <fastjet/PseudoJet.hh>

#include <calobase/RawCluster.h>
#include <calobase/RawClusterContainer.h>
#include <calobase/RawClusterUtility.h>
#include <calobase/RawTower.h>
#include <calobase/RawTowerContainer.h>
#include <calobase/RawTowerGeom.h>
#include <calobase/RawTowerGeomContainer.h>
#include <calotrigger/CaloTriggerInfo.h>

#include <g4jets/Jetv1.h>
#include <g4jets/JetMapv1.h>

#include <vector>

#include <TClonesArray.h>
#include <TParticle.h>


/// Class declarations for use in the analysis module
class Fun4AllHistoManager;
class PHCompositeNode;
class TFile;
class TTree;
class TH1;
class TH1I;
class PHCompositeNode;
class RawClusterContainer;
class RawCluster;
class SvtxTrackMap;
class GlobalVertex;
class PHHepMCGenEventMap;
class JetRecoEval;
class SvtxTrackEval;
class PHG4TruthInfoContainer;
class PHHepMCGenEvent;
class SvtxTrack;
class PHG4Particle;

/// Definition of this analysis module class
class SaveCAtoNode : public SubsysReco
{
 public:

  /// Constructor
  SaveCAtoNode(const std::string &name = "SaveCAtoNode",
              const std::string &fname = "SaveCAtoNode.root", const bool read = false);

  // Destructor
  virtual ~SaveCAtoNode();

  /// SubsysReco initialize processing method
  int Init(PHCompositeNode *);

  /// SubsysReco event processing method
  int process_event(PHCompositeNode *);

  /// SubsysReco end processing method
  int End(PHCompositeNode *);

  int createNode(PHCompositeNode* topNode);



 private:
  /// String to contain the outfile name containing the trees
  std::string m_outfilename;
  std::string m_jetcontainer_name;

  /// Fun4All Histogram Manager tool
  Fun4AllHistoManager *m_hm;
  TH1 *m_htracks_pt;



  /// TFile to hold the following TTrees and histograms
  TFile *m_outfile;
  ClonesContainer *m_CaloInfoContainer; //! Calo info
  bool m_read = false;


  /**
   * Make variables for the relevant trees
   */


};

#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"SaveCAtoNode", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SaveCAtoNode_Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SaveCAtoNode_Dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SaveCAtoNode_Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SaveCAtoNode_Dict() {
  TriggerDictionaryInitialization_SaveCAtoNode_Dict_Impl();
}
