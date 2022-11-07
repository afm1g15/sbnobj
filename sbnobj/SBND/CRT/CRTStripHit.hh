/**
 * \class CRTStripHit
 *
 * \brief Product to store 2D CRT "strip hit"
 *
 * \author Henry Lay
 *
 */

#ifndef SBND_CRTSTRIPHIT_HH
#define SBND_CRTSTRIPHIT_HH

#include <stdint.h>
#include "TVector3.h"

namespace sbnd::crt {

  class CRTStripHit{
    
    uint32_t channel;      // Channel ID for 1st SiPM
    uint32_t ts0;          // T0 counter [ns]
    uint32_t ts1;          // T1 counter [ns]
    uint32_t s;            // Unixtime of event [s]
    double   pos;          // Lateral position within strip [cm]
    double   err;          // Error on lateral position [cm]
    uint16_t adc1;         // ADC 1st SiPM
    uint16_t adc2;         // ADC 2nd SiPM
    TVector3 xyz;          // Global position [cm]
    TVector3 exyz;         // Global position error [cm]

  public:

    CRTStripHit();
    
    CRTStripHit(uint32_t _channel, uint32_t _ts0, uint32_t _ts1, uint32_t _s, double _pos,
		double _err, uint16_t _adc1, uint16_t _adc2, TVector3 _xyz, TVector3 _exyz);

    virtual ~CRTStripHit();

    uint32_t Channel();
    uint32_t Ts0();
    uint32_t Ts1();
    uint32_t UnixS();
    double   Pos();
    double   Error();
    uint16_t ADC1();
    uint16_t ADC2();
    TVector3 XYZ();
    TVector3 XYZ_Error();
  };
}

#endif