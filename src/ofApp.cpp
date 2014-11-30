#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(100);
    ofBackground(0);
    for(int i=0; i<LANE_NUM; ++i){
        pMillis[i] = 0;
        millis[i] = 0;
        rap[i] = 0;
    }
    ard = new ArduinoReceiver(USB_MODEM, RATE);
}

//--------------------------------------------------------------
void ofApp::update(){
    ard->update();
    for(int i=0; i<LANE_NUM; ++i){
        if(ard->isTurnedOn(i)){
            rap[i] = ofGetElapsedTimeMillis() - pMillis[i];
            pMillis[i] = ofGetElapsedTimeMillis();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ard->draw();
    
    stringstream ss;
    for(int i=0; i<LANE_NUM; ++i){
        ss << "LANE" << i << ":" << rap[i]*0.001 << endl;
    }
    
    ofDrawBitmapString(ss.str(), 50, 50);
    
    stringstream time;
    time << ofGetElapsedTimeMillis()*0.001 << "(sec)";
    ofDrawBitmapString(time.str(), 50, 300);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
