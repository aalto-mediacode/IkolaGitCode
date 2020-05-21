#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    easyCam.setDistance(-700);
    ofBackground(0);
    mySound.load("ikola-leafdrops.mp3");
    mySound.play();
    image.load("sky.png");
    pic.load("landscape.jpg");
    image.resize(500, 500);
    bool vertical = false;
    bool horizontal = true;
    image.mirror(vertical,horizontal);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    mesh.enableColors();
    gui.setup();
    gui.add(uiAmount.set("rain", 0,0,100));
   
    
    // We are going to be using indices this time
    mesh.enableIndices();

    // ...
    // Omitting the code for creating vertices for clarity
    // but don't erase it from your file!

    // Let's add some lines!
    float connectionDistance = 5; // ****TEST
    int numVerts = mesh.getNumVertices();
    for (int a=0; a<numVerts; ++a) {
        ofVec3f verta = mesh.getVertex(a);
        for (int b=a+1; b<numVerts; ++b) {
            glm::vec3 vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if (distance <= connectionDistance) {
                // In OF_PRIMITIVE_LINES, every pair of vertices or indices will be
                // connected to form a line
                mesh.addIndex(a);
                mesh.addIndex(b);
            }
        }
    }

    float intensityThreshold = 15.0; // LOW with texture pics
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
                // We shrunk our image by a factor of 4, so we need to multiply our pixel
                // locations by 4 in order to have our mesh cover the openFrameworks window
                glm::vec3 pos(x*4, y*4, 0.0);
                mesh.addVertex(pos);
                mesh.addColor(c);
            
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
        int count = 0;
        for (int x = 0; x < size; x++){
        for (int y = 0; y < size; y++){
            glm::vec3 position = mesh.getVertex(count);
            position.z = ofMap(ofNoise(count, ofGetElapsedTimef()), 0, 1, 0, uiAmount);
            mesh.setVertex(count, position);
            count++;
            
    }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){


    // ofColor centerColor = ofColor(85, 78, 68, 10);
     //  ofColor edgeColor(0, 0, 0);
     //  ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

       easyCam.begin();
    //for(int i=0; i<5; i++);
    
    pic.draw(-ofGetWidth()/2, -ofGetHeight()/2);
    ofTranslate(1000, 1000);
  
    
    ofPushMatrix();
    ofRotateDeg(180);
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
        mesh.draw();
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateDeg(180);
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, -100);
        mesh.draw();
    ofPopMatrix();
 /*
    ofPushMatrix();
    ofRotateDeg(180);
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 300);
        mesh.draw();
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateDeg(180);
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 400);
        mesh.draw();
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateDeg(180);
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 500);
        mesh.draw();
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateDeg(180);
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 600);
        mesh.draw();
    ofPopMatrix();
    
    ofPushMatrix();
    ofRotateDeg(180);
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 700);
        mesh.draw();
    ofPopMatrix();
  */
     easyCam.end();
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
