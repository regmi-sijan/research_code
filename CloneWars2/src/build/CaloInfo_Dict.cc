// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME CaloInfo_Dict
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
#include "../CaloInfo.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CaloInfo(void *p = nullptr);
   static void *newArray_CaloInfo(Long_t size, void *p);
   static void delete_CaloInfo(void *p);
   static void deleteArray_CaloInfo(void *p);
   static void destruct_CaloInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CaloInfo*)
   {
      ::CaloInfo *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CaloInfo >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CaloInfo", ::CaloInfo::Class_Version(), "", 14,
                  typeid(::CaloInfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CaloInfo::Dictionary, isa_proxy, 4,
                  sizeof(::CaloInfo) );
      instance.SetNew(&new_CaloInfo);
      instance.SetNewArray(&newArray_CaloInfo);
      instance.SetDelete(&delete_CaloInfo);
      instance.SetDeleteArray(&deleteArray_CaloInfo);
      instance.SetDestructor(&destruct_CaloInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CaloInfo*)
   {
      return GenerateInitInstanceLocal((::CaloInfo*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CaloInfo*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr CaloInfo::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *CaloInfo::Class_Name()
{
   return "CaloInfo";
}

//______________________________________________________________________________
const char *CaloInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CaloInfo*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int CaloInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CaloInfo*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CaloInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CaloInfo*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CaloInfo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CaloInfo*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void CaloInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class CaloInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CaloInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(CaloInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_CaloInfo(void *p) {
      return  p ? new(p) ::CaloInfo : new ::CaloInfo;
   }
   static void *newArray_CaloInfo(Long_t nElements, void *p) {
      return p ? new(p) ::CaloInfo[nElements] : new ::CaloInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_CaloInfo(void *p) {
      delete ((::CaloInfo*)p);
   }
   static void deleteArray_CaloInfo(void *p) {
      delete [] ((::CaloInfo*)p);
   }
   static void destruct_CaloInfo(void *p) {
      typedef ::CaloInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CaloInfo

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = nullptr);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 423,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));

      ::ROOT::AddClassAlternate("vector<int>","std::vector<int, std::allocator<int> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<int>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)nullptr)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace {
  void TriggerDictionaryInitialization_CaloInfo_Dict_Impl() {
    static const char* headers[] = {
"0",
nullptr
    };
    static const char* includePaths[] = {
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "CaloInfo_Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class CaloInfo;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "CaloInfo_Dict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#ifndef CALOINFO_H
#define CALOINFO_H

#include <cstddef>  // for size_t
#include <iostream>
#include <set>
#include <TObject.h>

#include <phool/PHObject.h>
#include <TClonesArray.h>

class CaloInfo : public TObject
{
 public:
  CaloInfo();
  CaloInfo(const CaloInfo &ci);
  ~CaloInfo() override;

  void setTime(short t) { _time = t; }
  short getTime() { return _time; }
  void setAmplitude(float amp) { _amplitude = amp; }
  float getAmplitude() { return _amplitude; }
  void setVWaveform(int t, int p) { _vwaveform[p] = t; }
  int getVWaveform(int p) { return _vwaveform[p]; }


protected:
  short _time;
  float _amplitude;
  std::vector<int> _vwaveform = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


  ClassDefOverride(CaloInfo, 1);
};

#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CaloInfo", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("CaloInfo_Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_CaloInfo_Dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_CaloInfo_Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_CaloInfo_Dict() {
  TriggerDictionaryInitialization_CaloInfo_Dict_Impl();
}
