#include "TowerInfoContainer.h"

#include "TowerInfo.h"
//#include "ClonesContainer.h"

#include <Event/Event.h>
#include <Event/EventTypes.h>
#include <Event/msg_profile.h>

#include <phool/PHObject.h>  // for PHObject
#include <TClonesArray.h>

#include <algorithm>
#include <cassert>
#include <cmath>

TowerInfoContainer::TowerInfoContainer()
{
  _clones = new TClonesArray("TowerInfo", 50);
  _clones->SetOwner();
  _clones->SetName("TowerInfoContainer");

}

TowerInfoContainer::~TowerInfoContainer()
{
  if (_clones)
  {
    delete _clones;
    _clones = 0;
  }
}

void TowerInfoContainer::Reset()
{
  _clones->Clear();
}

void TowerInfoContainer::add(TowerInfo *ci, int pos)
{
  new ((*_clones)[pos]) TowerInfo(*ci);
}

TowerInfo* TowerInfoContainer::at(int pos)
{
  return (TowerInfo*)_clones->At(pos);
}
