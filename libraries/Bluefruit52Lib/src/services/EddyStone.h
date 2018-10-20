/**************************************************************************/
/*!
    @file     EddyStone.h
    @author   hathach

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2017, Adafruit Industries (adafruit.com)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/
#ifndef EDDYSTONE_H_
#define EDDYSTONE_H_

#include "bluefruit_common.h"

#include "BLECharacteristic.h"
#include "BLEService.h"

enum
{
  EDDYSTONE_TYPE_UID = 0x00,
  EDDYSTONE_TYPE_URL = 0x10,
  EDDYSTONE_TYPE_TLM = 0x20,
  EDDYSTONE_TYPE_EID = 0x30,
};

class EddyStoneUrl
{
  private:
    int8_t _rssi;
    const char* _url;

  public:
    EddyStoneUrl(void);
    EddyStoneUrl(int8_t rssiAt0m, const char* url = NULL);

    bool setUrl(const char* url);
    void setRssi(int8_t rssiAt0m);

    bool start(void);
};



/* ================================================================== */
/* Eddystone TLM frame support, lefedor: ffl.public@gmail.com */



class EddyStoneTlm
{
  
  private:
    
    int8_t _rssi;
    
    int8_t _eddy_version;
    int64_t _eddy_payloadSlotA;
    int32_t _eddy_payloadSlotB;
    
    float _temp;
    float _batt;
    
    unsigned long _pockets;
    unsigned long _uptime;

  public:
  
    EddyStoneTlm(void);
    EddyStoneTlm(int8_t rssiAt0m, float temp = 0x8000, float batt = 0x8000, unsigned long pockets = 0, unsigned long uptime = 0);
    EddyStoneTlm(int8_t rssiAt0m, int8_t wversion = 0x00, uint64_t wPayloadA = 0x0000000000000000, uint32_t wPayloadB = 0x00000000);
	
	
    void setTemp(float temp);
    void setBatt(float batt);
    
	void setTlmVersion(int8_t wversion = 0x00);
    void setPayloadA(uint64_t wData = 0x0000000000000000);
    void setPayloadB(uint32_t wData = 0x00000000);
    
    void setPockets(unsigned long pockets);
    void setUptime (unsigned long uptime);
    
    void setRssi(int8_t rssiAt0m);

    bool start(void);
};


#endif /* EDDYSTONE_H_ */
