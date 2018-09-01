#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // GUI setup
    gui.setup("Parameters");
    gui.add(rad_sph.setup("Sphere radius", 200, 100, 300));
    gui.add(rot_vel.setup("Rotation speed", 100, 1, 360));
    gui.add(vib_amp.setup("Vibration amplitude %", 50, 0, 100));
    gui.add(vib_spe.setup("Vibration speed", 10, 1, 100));
    gui.add(rad_dot.setup("Tip radius %", 5, 1, 10));

    // Visuals setup
    backSphere.set(100, 1);
    vector<ofMeshFace> faces = backSphere.getMesh().getUniqueFaces();
    nFaces = faces.size();
    norms.resize(nFaces);
    phase.resize(nFaces);
    lines.resize(nFaces);

    for (int i = 0; i < nFaces; i++){
        norms[i] = faces[i].getFaceNormal();
        lines[i] = norms[i];
        phase[i] = ofRandom(0, 359);
    }

    ofSetBackgroundColor(ofColor(0));
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < nFaces; i++){
        phase[i] = phase[i] + vib_spe;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    ofEnableDepthTest();
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
    ofRotateDeg(time * rot_vel, 0, 1, 0);
    ofSetColor(255);
    for (int i = 0; i < nFaces; i++){
        ofVec3f base = lines[i] * rad_sph;
        ofVec3f vibr = norms[i] * vib_amp * rad_sph / 100.0 * sin(ofDegToRad(phase[i]));
        ofVec3f endp = base + vibr;
        ofDrawLine(ofVec3f(0, 0, 0), endp);
        ofDrawSphere(endp, rad_dot * rad_sph / 100.0);
    }
    ofPopMatrix();
    ofDisableDepthTest();

    gui.draw();
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
