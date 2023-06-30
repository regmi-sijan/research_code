// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME ClonesContainer_Dict
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
#include "../ClonesContainer.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_ClonesContainer(void *p = nullptr);
   static void *newArray_ClonesContainer(Long_t size, void *p);
   static void delete_ClonesContainer(void *p);
   static void deleteArray_ClonesContainer(void *p);
   static void destruct_ClonesContainer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ClonesContainer*)
   {
      ::ClonesContainer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::ClonesContainer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("ClonesContainer", ::ClonesContainer::Class_Version(), "", 14,
                  typeid(::ClonesContainer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::ClonesContainer::Dictionary, isa_proxy, 4,
                  sizeof(::ClonesContainer) );
      instance.SetNew(&new_ClonesContainer);
      instance.SetNewArray(&newArray_ClonesContainer);
      instance.SetDelete(&delete_ClonesContainer);
      instance.SetDeleteArray(&deleteArray_ClonesContainer);
      instance.SetDestructor(&destruct_ClonesContainer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ClonesContainer*)
   {
      return GenerateInitInstanceLocal((::ClonesContainer*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ClonesContainer*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr ClonesContainer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ClonesContainer::Class_Name()
{
   return "ClonesContainer";
}

//______________________________________________________________________________
const char *ClonesContainer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ClonesContainer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ClonesContainer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::ClonesContainer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ClonesContainer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ClonesContainer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ClonesContainer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::ClonesContainer*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void ClonesContainer::Streamer(TBuffer &R__b)
{
   // Stream an object of class ClonesContainer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(ClonesContainer::Class(),this);
   } else {
      R__b.WriteClassBuffer(ClonesContainer::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_ClonesContainer(void *p) {
      return  p ? new(p) ::ClonesContainer : new ::ClonesContainer;
   }
   static void *newArray_ClonesContainer(Long_t nElements, void *p) {
      return p ? new(p) ::ClonesContainer[nElements] : new ::ClonesContainer[nElements];
   }
   // Wrapper around operator delete
   static void delete_ClonesContainer(void *p) {
      delete ((::ClonesContainer*)p);
   }
   static void deleteArray_ClonesContainer(void *p) {
      delete [] ((::ClonesContainer*)p);
   }
   static void destruct_ClonesContainer(void *p) {
      typedef ::ClonesContainer current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ClonesContainer

namespace {
  void TriggerDictionaryInitialization_ClonesContainer_Dict_Impl() {
    static const char* headers[] = {
"0",
nullptr
    };
    static const char* includePaths[] = {
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "ClonesContainer_Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class ClonesContainer;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "ClonesContainer_Dict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#ifndef CLONESCONTAINER_H
#define CLONESCONTAINER_H

#include <cstddef>  // for size_t
#include <iostream>
#include <set>

#include <phool/PHObject.h>
#include <TClonesArray.h>
#include "CaloInfo.h"

class ClonesContainer : public PHObject
{
 public:
  ClonesContainer();
  ~ClonesContainer() override;

  void Reset() override;
  void add(CaloInfo *ci, int pos);
  CaloInfo* at(int pos);
  int size() { return _clones->GetEntries(); }

 private:
  std::string _clonesClass;
  TClonesArray *_clones;


  ClassDefOverride(ClonesContainer, 1);
};

#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"ClonesContainer", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ClonesContainer_Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ClonesContainer_Dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ClonesContainer_Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ClonesContainer_Dict() {
  TriggerDictionaryInitialization_ClonesContainer_Dict_Impl();
}
