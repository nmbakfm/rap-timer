//
//  ArduinoReceiver.h
//  RapTimer
//
//  Created by 南部 晃史 on 2014/11/30.
//
//

#ifndef __RapTimer__ArduinoReceiver__
#define __RapTimer__ArduinoReceiver__

#include "ofMain.h"

enum PinStatus{
    STAY_ON, STAY_OFF, TURN_ON, TURN_OFF
};

class ArduinoReceiver {
private:
    ofSerial serial;
    unsigned long data;
    unsigned long p_data;
    
    int getStatus(int pin_id);
    
public:
    ArduinoReceiver();
    ArduinoReceiver(string modem, int rate);
    void update();
    void draw();
    
    bool isOn(int pin);
    bool isTurnedOff(int pin);
    bool isTurnedOn(int pin);
};

#endif /* defined(__RapTimer__ArduinoReceiver__) */
