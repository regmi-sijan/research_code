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
