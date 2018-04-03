#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofSetColor(39, 139);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(180);

	float radius = 350;
	float small_radius = 50;

	for (int deg = 0; deg <= 360; deg += 1) {

		ofPoint p1 = make_point(radius, small_radius, deg, deg * 8 + ofGetFrameNum());
		ofPoint p2 = make_point(radius, small_radius, deg + 180, deg * 8 + ofGetFrameNum());

		ofDrawLine(p1, p2);
		ofDrawSphere(p1, 2);
		//ofDrawSphere(p2, 2);
	}

	this->cam.end();
}

//--------------------------------------------------------------
ofPoint ofApp::make_point(float radius, float small_radius, float deg, float small_deg) {

	float x_1 = radius * cos(deg * DEG_TO_RAD);
	float y_1 = radius * sin(deg * DEG_TO_RAD);

	float x_2 = small_radius * cos(small_deg * DEG_TO_RAD) * cos(deg * DEG_TO_RAD);
	float y_2 = small_radius * cos(small_deg * DEG_TO_RAD) * sin(deg * DEG_TO_RAD);

	float x = x_1 + x_2;
	float y = y_1 + y_2;
	float z = small_radius * sin(small_deg * DEG_TO_RAD);

	return ofPoint(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}