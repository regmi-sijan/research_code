// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME TowerInfoContainer_Dict
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
#include "../TowerInfoContainer.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_TowerInfoContainer(void *p = nullptr);
   static void *newArray_TowerInfoContainer(Long_t size, void *p);
   static void delete_TowerInfoContainer(void *p);
   static void deleteArray_TowerInfoContainer(void *p);
   static void destruct_TowerInfoContainer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TowerInfoContainer*)
   {
      ::TowerInfoContainer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TowerInfoContainer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TowerInfoContainer", ::TowerInfoContainer::Class_Version(), "", 17,
                  typeid(::TowerInfoContainer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TowerInfoContainer::Dictionary, isa_proxy, 4,
                  sizeof(::TowerInfoContainer) );
      instance.SetNew(&new_TowerInfoContainer);
      instance.SetNewArray(&newArray_TowerInfoContainer);
      instance.SetDelete(&delete_TowerInfoContainer);
      instance.SetDeleteArray(&deleteArray_TowerInfoContainer);
      instance.SetDestructor(&destruct_TowerInfoContainer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TowerInfoContainer*)
   {
      return GenerateInitInstanceLocal((::TowerInfoContainer*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TowerInfoContainer*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TowerInfoContainer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TowerInfoContainer::Class_Name()
{
   return "TowerInfoContainer";
}

//______________________________________________________________________________
const char *TowerInfoContainer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TowerInfoContainer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TowerInfoContainer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TowerInfoContainer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TowerInfoContainer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TowerInfoContainer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TowerInfoContainer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TowerInfoContainer*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TowerInfoContainer::Streamer(TBuffer &R__b)
{
   // Stream an object of class TowerInfoContainer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TowerInfoContainer::Class(),this);
   } else {
      R__b.WriteClassBuffer(TowerInfoContainer::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TowerInfoContainer(void *p) {
      return  p ? new(p) ::TowerInfoContainer : new ::TowerInfoContainer;
   }
   static void *newArray_TowerInfoContainer(Long_t nElements, void *p) {
      return p ? new(p) ::TowerInfoContainer[nElements] : new ::TowerInfoContainer[nElements];
   }
   // Wrapper around operator delete
   static void delete_TowerInfoContainer(void *p) {
      delete ((::TowerInfoContainer*)p);
   }
   static void deleteArray_TowerInfoContainer(void *p) {
      delete [] ((::TowerInfoContainer*)p);
   }
   static void destruct_TowerInfoContainer(void *p) {
      typedef ::TowerInfoContainer current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TowerInfoContainer

namespace {
  void TriggerDictionaryInitialization_TowerInfoContainer_Dict_Impl() {
    static const char* headers[] = {
"0",
nullptr
    };
    static const char* includePaths[] = {
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TowerInfoContainer_Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class TowerInfoContainer;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TowerInfoContainer_Dict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#ifndef TOWERINFOCONTAINER_H
#define TOWERINFOCONTAINER_H

#include "TowerInfo.h"
//#include "ClonesContainer.h"

#include <cstddef>  // for size_t
#include <iostream>
#include <set>

#include <phool/PHObject.h>
#include <TClonesArray.h>


class TowerInfoContainer : public PHObject
{
 public:
  TowerInfoContainer();
  ~TowerInfoContainer() override;

  void Reset() override;
  void add(TowerInfo *ci, int pos);
  TowerInfo* at(int pos);
  int size() { return _clones->GetEntries(); }

  private:
   TClonesArray *_clones;

  ClassDefOverride(TowerInfoContainer, 1);
};

#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TowerInfoContainer", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TowerInfoContainer_Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TowerInfoContainer_Dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TowerInfoContainer_Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TowerInfoContainer_Dict() {
  TriggerDictionaryInitialization_TowerInfoContainer_Dict_Impl();
}
