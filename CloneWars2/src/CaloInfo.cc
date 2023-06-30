#include "CaloInfo.h"

#include <phool/PHObject.h>  // for PHObject

#include <algorithm>
#include <cassert>
#include <cmath>

CaloInfo::CaloInfo()
{

}

CaloInfo::CaloInfo(const CaloInfo &ci)
  : TObject(ci)
  , _time(ci._time)
  , _amplitude(ci._amplitude)
  , _vwaveform(ci._vwaveform)
{

}

CaloInfo::~CaloInfo()
{


}
