#include "TowerInfoGeo.h"

#include "TowerInfoContainer.h"
#include "TowerInfo.h"

#include <phool/PHObject.h>  // for PHObject

#include <algorithm>
#include <cassert>
#include <cmath>

TowerInfoGeo::TowerInfoGeo(DETECTOR detec)
  : _detector(detec)
{

  switch (_detector) {
    case DETECTOR::EMCAL:

  }

}

TowerInfoGeo::~TowerInfoGeo()
{

}

int TowerInfoGeo::getTowerPhiBin(int towerIndex)
{

}

int TowerInfoGeo::getTowerEtaBin(int towerIndex)
{

}


/*
void TowerInfoContainer::Reset()
{

}
*/
