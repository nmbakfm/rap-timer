#pragma once

#include "ofMain.h"
#include "ArduinoReceiver.h"


#define USB_MODEM "/dev/tty.usbmodem411"
#define RATE 9600
#define LANE_NUM 3

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ArduinoReceiver * ard;
    
    int pMillis[LANE_NUM];
    int millis[LANE_NUM];
    int rap[LANE_NUM];
};
