#ifndef TOWERINFOCONTAINER_H
#define TOWERINFOCONTAINER_H

#include "TowerInfoGeo.h"
//#include "ClonesContainer.h"

#include <cstddef>  // for size_t
#include <iostream>
#include <set>

#include <phool/PHObject.h>


class TowerInfoGeo : public PHObject
{
 public:
  TowerInfoGeo(DETECTOR detec);
  ~TowerInfoGeo() override;

  enum DETECTOR
  {
    EMCAL = 0;
    OHCAL = 1;
    IHCAL = 2;
    EPD = 3;
  }

  //void Reset() override;


  private:
   DETECTOR _detector;

  ClassDefOverride(TowerInfoGeo, 1);
};

#endif
