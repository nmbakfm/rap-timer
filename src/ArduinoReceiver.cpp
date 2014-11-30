//
//  ArduinoReceiver.cpp
//  RapTimer
//
//  Created by 南部 晃史 on 2014/11/30.
//
//

#include "ArduinoReceiver.h"

ArduinoReceiver::ArduinoReceiver(){
    data = 0;
}

ArduinoReceiver::ArduinoReceiver(string modem, int rate){
    data = 0;
    serial.setup(modem, rate);
}

void ArduinoReceiver::update(){
    p_data = data;
    if(serial.isInitialized()){
        if(serial.available()){
            data = serial.readByte();
        }
    }
}

void ArduinoReceiver::draw(){
}

bool ArduinoReceiver::isOn(int pin_id){
    return data & (1 << pin_id);
}

bool ArduinoReceiver::isTurnedOn(int pin_id){
    return getStatus(pin_id) == TURN_ON;
}

bool ArduinoReceiver::isTurnedOff(int pin_id){
    return getStatus(pin_id) == TURN_OFF;
}

int ArduinoReceiver::getStatus(int pin_id){
    int current_state = (data & (1 << pin_id))>0 ? 1 << 0 : 0;
    int prev_state = (p_data & (1 << pin_id))>0 ? 1 << 1 : 0;
    switch(current_state + prev_state){
        case 0:
            return STAY_OFF;
        case 1:
            return TURN_ON;
        case 2:
            return TURN_OFF;
        case 3:
            return STAY_ON;
    }
}

