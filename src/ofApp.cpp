#include "ofApp.h"
#include <random>
#include <math.h>
#include <iostream>
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(900,900);
	
	for(int i = 0; i<sz; i++){
		for(int j = 0; j<sz; j++){
			//ofApp::reality[i][j] = (bool)(rand()%2);
			if (j == sz/2 || i == sz/2) ofApp::reality[i][j] = true;
			else ofApp::reality[i][j] = false;
		}
	}
}
//--------------------------------------------------------------
int ofApp::modarith(int a, int b){
	int c = a + b;
	if (c>=0) {
		return c % sz;
	}
	else {
		return (c+sz)%sz;
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	if(ofApp::flowing && ofApp::uptime < ofGetElapsedTimef()){
		uptime = ofGetElapsedTimef() + STEPTIME;
		bool newreal[SIZE][SIZE];
		for(int i = 0; i < sz; i++){
			for(int j = 0; j < sz; j++){
				int n = 0;
				for(int k = -1; k < 2; k++){
					for(int l = -1; l < 2; l++){
						if(ofApp::reality[ofApp::modarith(i,k)][ofApp::modarith(j,l)]&&(l!=0||k!=0)){
							n++;
						}
					}
				}
				if(ofApp::reality[i][j]&&(n<2||n>3)){
					newreal[i][j] = false;
				}
				else if(ofApp::reality[i][j]){
					newreal[i][j] = true;
				}
				else if(n==3){
					newreal[i][j] = true;
				}
				else{
					newreal[i][j] = false;
				}
				
			}
		}
			
		for(int i = 0; i < sz; i++){
			for(int j = 0; j < sz; j++){
				ofApp::reality[i][j] = newreal[i][j];
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofApp::ulen = ofGetWidth()/sz;
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	for(int i = 0;i<sz;i++){
		for(int j = 0;j<sz;j++){
			if(ofApp::reality[i][j]){ofSetColor(255);}
			else{ofSetColor(0);}
			ofBeginShape();
			ofVertex(ofVec2f(i*ulen,j*ulen));
			ofVertex(ofVec2f((i+1)*ulen,j*ulen));
			ofVertex(ofVec2f((i+1)*ulen,(j+1)*ulen));
			ofVertex(ofVec2f(i*ulen,(j+1)*ulen));
			ofEndShape();
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key=='r'){
		for(int i = 0; i<sz; i++){
			for(int j = 0; j<sz; j++){
				ofApp::reality[i][j] = (bool)(rand()%2);
			}
		}
	}
	if(key=='b'){
		for(int i = 0; i<sz; i++){
			for(int j = 0; j<sz; j++){
				ofApp::reality[i][j] = false;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(key==' '){
		ofApp::flowing = !ofApp::flowing;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	int i = floor((float)sz*((float)x/(float)ofGetWidth()));
	int j = floor((float)sz*((float)y/(float)ofGetHeight()));

		
	if(button == 0){
		ofApp::reality[i][j] = true;
		}
	else if (button == 2){
		ofApp::reality[i][j] = false;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	int i = floor((float)sz*((float)x/(float)ofGetWidth()));
	int j = floor((float)sz*((float)y/(float)ofGetHeight()));

		
	if(button == 0){
		ofApp::reality[i][j] = true;
		}
	else if (button == 2){
		ofApp::reality[i][j] = false;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
