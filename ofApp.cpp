#include "ofApp.h"

int lineLength, startingPointX, startingPointY;
float rotationAngle, angleOffset, fractalProportion;

int frameNumber;
ofTrueTypeFont font;
string appInfo;

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetFrameRate(25);

	lineLength = 8;
	rotationAngle = 10.0;
	angleOffset = 0;
	fractalProportion = 0.8;
	startingPointX = ofGetWidth()/2;
	startingPointY = ofGetHeight()-300;
}

//--------------------------------------------------------------
void ofApp::update(){

	/*if (frameNumber<10)
	frameNumber++;*/
}

//--------------------------------------------------------------

void ofApp::draw(){

	font.drawString(appInfo, 2, 12);	
	drawTrunk(frameNumber, rotationAngle);
}

//--------------------------------------------------------------
void ofApp::drawTrunk(int depth, float angle) {
	ofTranslate(startingPointX, startingPointY);
	ofSetLineWidth(depth*4);
	ofSetColor(0);
	for (int i=0; i<=ofGetHeight(); ++i)
	{
		ofSetColor(100,100,100);
		ofLine(0,i,0,0);
	}
	drawBranch(depth, angle);
}

//--------------------------------------------------------------
void ofApp::drawBranch(int depth, float angle) {
	float newAngle = angle + angleOffset;

	ofPushMatrix();
	ofRotate(newAngle);
	drawLeaf(depth, newAngle);
	ofPopMatrix();
	ofRotate(-newAngle);
	drawLeaf(depth, newAngle);
}

//--------------------------------------------------------------
void ofApp::drawLeaf(int depth, float angle) {
	int leafLength = lineLength*depth,
		leafSize = 20;

	//appInfo += ofToString(leafLength)+"\n";
	ofTranslate(0,-leafLength);
	ofSetLineWidth(depth);



		ofSetColor(100,100,100);
		ofLine(0,leafLength,0,0);
	
	if(depth == 0) {
		ofEnableAlphaBlending();
		ofSetColor(255,0,255,15);

		if (ofRandom(100) > 0) {
			ofFill();
			ofEllipse(0,0,leafSize,leafSize);
		}
		ofSetColor(100,100,100);
	}
	if(depth>0){
		drawBranch(depth-1, angle);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	cout<<"KEY = "<<key;
	if (key == 357 && frameNumber<11)
	{
		++frameNumber;
	}
	if (key == 359)
	{
		--frameNumber;
	}
	if (key == 358)
	{
		rotationAngle+=10;
	}
	if (key == 356)
	{
		rotationAngle-=10;
	}
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
