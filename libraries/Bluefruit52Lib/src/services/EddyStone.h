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


/* Eddystone TLM frame support, lefedor: ffl.public@gmail.com */

class EddyStoneTlm
{
  
  private:
    int8_t _rssi;
    float _temp;
    float _batt;

  public:
  
    EddyStoneTlm(void);
    EddyStoneTlm(int8_t rssiAt0m, float temp = -128, float batt = 0.0);

    bool setTemp(float temp);
    bool setBatt(float batt);
    void setRssi(int8_t rssiAt0m);

    bool start(void);
};


#endif /* EDDYSTONE_H_ */
