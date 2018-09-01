#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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


        /*
         * Sphere radius
         * Length variation
         * Rotation speed
         * Vibration
         * Vibration speed
         * Dot radius
         */

        // GUI
        ofxIntSlider rad_sph;
        ofxIntSlider rot_vel;
        ofxIntSlider vib_amp;
        ofxIntSlider vib_spe;
        ofxIntSlider rad_dot;
        ofxPanel gui;
        void onResetSeed();

        // Visuals
        ofIcoSpherePrimitive backSphere;
        vector<ofVec3f> norms;
        vector<ofVec3f> lines;
        vector<int> phase;
        int nFaces;

};
