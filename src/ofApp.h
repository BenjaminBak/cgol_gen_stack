#pragma once

#include "ofMain.h"
#define SIZE 200
#define STEPTIME 0.5
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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		bool reality[SIZE][SIZE];
		int modarith(int a, int b);
		float ulen;
		int sz = SIZE;
		float uptime = 0;
		bool flowing = false;
		
};
