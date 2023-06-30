#include "TowerInfo.h"

#include <phool/PHObject.h>  // for PHObject

#include <algorithm>
#include <cassert>
#include <cmath>

TowerInfo::TowerInfo()
  : _time(0)
  , _amplitude(0)
{

}

TowerInfo::TowerInfo(const TowerInfo &ci)
  : TObject(ci)
  , _time(ci._time)
  , _amplitude(ci._amplitude)
  //, _pedestal(ci._pedestal)
  //, _index(ci._index)
{

}

TowerInfo::~TowerInfo()
{


}
