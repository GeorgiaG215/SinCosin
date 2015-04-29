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
    // Zach's note - this movees the points left across the screen
    for (int i =0; i < sinLine.getVertices().size(); i++){
        sinLine[i].x -= 8;}
    
    //this for loop creates a variable i of the type int, sets i's initial value at 0.
    
    //i's last value is less than sinLine.getVertices().size()
    
    //sinLine is a vector (?) of the class ofPolyline
    
    //within ofPolyline, there are functions of getVertices and size. Size is the number of points in the ofPolyline. getVertices is the vector of vertices the line contains (?) this makes no sense to me - I pulled this from the of documentation
    
    //i++ so i increases by 1
    
    //sinLine[i].x -=3 this is the part that is updating with the frame rate, and x is being subtracted by whatever is after -=, which makes it appear to run across the screen to the left (x is getting smaller)
    
    //so it seems that i had to be associated with sinLine to allow for the code creating the animation to be an option. I thought variables had to be declared specifically in the setup or draw, or header though. When and where can you create a variable or not?

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0); //sets background color to black
    
    totalSinVal =   sin(  (sinFreqA * TWO_PI) * ofGetElapsedTimef()) +
    sin(  (sinFreqB * TWO_PI) * ofGetElapsedTimef()) +
    sin(  (sinFreqC * TWO_PI) * ofGetElapsedTimef());
    
    totalSinVal /= 3.0;     // Zach - keep it between -1 and 1 (we are adding three sin waves together, so it's good to try to normalize them, ie keep it still between -1 and 1)
    
    
    //GG totalSinVal is a what...? A combo of all of these things...?
    // sin( (sinFreqA - sin of the float we made
    //* TWO_PI which I guess is a constant?
    //* ofGetElapsedTimef() - so this is whatever the elapsed time is, and it is always increasing
    //+ sin( (sinFreqB... sin of the float we made again
    //so there's a lot of trigonometry going on here
    //I don't know where the -1 and 1 are coming in
    
    //then, totalSinVal /= 3.0, or totalSinVal is the same as totalSinVal/3
    //I'm lost on this
    
    sinLine.addVertex( ofGetWidth()-300, ofGetHeight()/2 + totalSinVal * 300);
    //within the ofPolyline that is sinLine, addVertex (which means add a point - why isn't it addPoint then?)
    //ofGetWidth - get the width of the app window and subtract 300, ofGetHeight()/2, get height of window and divide by 2 (start in the middle)
    //totalSinVal - multiply by 300, though we just divided it by 3. This seems like it would amplify it.
    
    // Zach - this keeps the line from growing infinitely...  once we have 300 points, delete the oldest one....
    if (sinLine.size() > 300){
        sinLine.getVertices().erase(sinLine.getVertices().begin());
        //if (sinLine.size() > 300 - if the number of points of the ofPolyline sinLine gets to 300,
        //sinLine.getVertices - so get this vector
        //.erase - clearly this means erase, but is this a function? how do I know this is a possibility in this code?
        //sinLine.getVertices().begin()) - so this would erase the points at the beginning of the sinLine
        //where was this declared? again how do I know this is possibly within ofPolyline? I see begin in the documentation, but erase isn't there
        
    }
    //ofSetLineWidth(5);
    sinLine.draw();
    
    //draw the sinLine

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
