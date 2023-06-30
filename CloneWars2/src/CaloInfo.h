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
