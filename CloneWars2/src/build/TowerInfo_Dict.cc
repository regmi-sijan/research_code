// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME TowerInfo_Dict
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
#include "../TowerInfo.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_TowerInfo(void *p = nullptr);
   static void *newArray_TowerInfo(Long_t size, void *p);
   static void delete_TowerInfo(void *p);
   static void deleteArray_TowerInfo(void *p);
   static void destruct_TowerInfo(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TowerInfo*)
   {
      ::TowerInfo *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TowerInfo >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TowerInfo", ::TowerInfo::Class_Version(), "", 13,
                  typeid(::TowerInfo), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TowerInfo::Dictionary, isa_proxy, 4,
                  sizeof(::TowerInfo) );
      instance.SetNew(&new_TowerInfo);
      instance.SetNewArray(&newArray_TowerInfo);
      instance.SetDelete(&delete_TowerInfo);
      instance.SetDeleteArray(&deleteArray_TowerInfo);
      instance.SetDestructor(&destruct_TowerInfo);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TowerInfo*)
   {
      return GenerateInitInstanceLocal((::TowerInfo*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TowerInfo*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TowerInfo::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TowerInfo::Class_Name()
{
   return "TowerInfo";
}

//______________________________________________________________________________
const char *TowerInfo::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TowerInfo*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TowerInfo::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TowerInfo*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TowerInfo::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TowerInfo*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TowerInfo::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TowerInfo*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TowerInfo::Streamer(TBuffer &R__b)
{
   // Stream an object of class TowerInfo.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TowerInfo::Class(),this);
   } else {
      R__b.WriteClassBuffer(TowerInfo::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TowerInfo(void *p) {
      return  p ? new(p) ::TowerInfo : new ::TowerInfo;
   }
   static void *newArray_TowerInfo(Long_t nElements, void *p) {
      return p ? new(p) ::TowerInfo[nElements] : new ::TowerInfo[nElements];
   }
   // Wrapper around operator delete
   static void delete_TowerInfo(void *p) {
      delete ((::TowerInfo*)p);
   }
   static void deleteArray_TowerInfo(void *p) {
      delete [] ((::TowerInfo*)p);
   }
   static void destruct_TowerInfo(void *p) {
      typedef ::TowerInfo current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TowerInfo

namespace {
  void TriggerDictionaryInitialization_TowerInfo_Dict_Impl() {
    static const char* headers[] = {
"0",
nullptr
    };
    static const char* includePaths[] = {
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "TowerInfo_Dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class TowerInfo;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "TowerInfo_Dict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#ifndef TOWERINFO_H
#define TOWERINFO_H

#include <cstddef>  // for size_t
#include <iostream>
#include <set>
#include <TObject.h>

#include <phool/PHObject.h>

class TowerInfo : public TObject
{
 public:
  TowerInfo();
  TowerInfo(const TowerInfo &ci);
  ~TowerInfo() override;

  void setTime(short t) { _time = t; }
  short getTime() { return _time; }
  void setAmplitude(float amp) { _amplitude = amp; }
  float getAmplitude() { return _amplitude; }

  //void setPedestal(float ped) { _pedestal = ped; }
  //float getPedestal() { return _pedestal; }
  //void setIndex(unsigned short int id) { _index = id; }
  //unsigned short int getIndex() { return _index; }



/*
  void setVTime(short t, int p) { _vtime[p] = t; }
  short getVTime(int p) { return _vtime[p]; }
  void setVAmplitude(float amp, int p) { _vamplitude[p] = amp; }
  float getVAmplitude(int p) { return _vamplitude[p]; }
*/


protected:

  short _time;
  float _amplitude;
  //float _pedestal;
  //unsigned int _index;


  //short _vtime[2] = {0, 0};
  //float _vamplitude[2] = {0., 0.};


  ClassDefOverride(TowerInfo, 1);
};

#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TowerInfo", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("TowerInfo_Dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_TowerInfo_Dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_TowerInfo_Dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_TowerInfo_Dict() {
  TriggerDictionaryInitialization_TowerInfo_Dict_Impl();
}
