#include "ClonesContainer.h"

#include <phool/PHObject.h>  // for PHObject
#include <TClonesArray.h>
#include <CaloInfo.h>

#include <algorithm>
#include <cassert>
#include <cmath>

ClonesContainer::ClonesContainer()
{
  _clones = new TClonesArray("CaloInfo", 50);
  _clones->SetOwner();
  _clones->SetName("CaloInfoContainer");
}

ClonesContainer::~ClonesContainer()
{
  if (_clones)
  {
    delete _clones;
    _clones = 0;
  }

}

void ClonesContainer::Reset()
{
  _clones->Clear();
}

void ClonesContainer::add(CaloInfo *ci, int pos)
{
  new ((*_clones)[pos]) CaloInfo(*ci);
}

CaloInfo* ClonesContainer::at(int pos)
{
  return (CaloInfo*)_clones->At(pos);
}
