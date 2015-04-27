#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    sinFreqA = 0.33; // once per three seconds.
    sinFreqB = 0.2; // once every five seconds
    sinFreqC = 1.0; // once per second...
    ofSetFrameRate(30);

}

//--------------------------------------------------------------
void ofApp::update(){
    // this movees the points left across the screen
    for (int i =0; i < sinLine.getVertices().size(); i++){
        sinLine[i].x -= 3;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    totalSinVal =   sin(  (sinFreqA * TWO_PI) * ofGetElapsedTimef()) +
    sin(  (sinFreqB * TWO_PI) * ofGetElapsedTimef()) +
    sin(  (sinFreqC * TWO_PI) * ofGetElapsedTimef());
    totalSinVal /= 3.0;     // keep it between -1 and 1 (we are adding three sin waves together, so it's good to try to normalize them, ie keep it still between -1 and 1)
    
    sinLine.addVertex( ofGetWidth()-300, ofGetHeight()/2 + totalSinVal * 300);
    // this keeps the line from growing infinitely...  once we have 300 points, delete the oldest one....
    if (sinLine.size() > 300){
        sinLine.getVertices().erase(sinLine.getVertices().begin());
    }
    sinLine.draw();

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
