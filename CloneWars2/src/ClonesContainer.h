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
