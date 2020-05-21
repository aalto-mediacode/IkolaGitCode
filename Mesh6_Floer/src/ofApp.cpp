#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    easyCam.setDistance(-500);
    ofBackground(0);
    mySound.load("Ikola_-_All_Set.mp3");
    mySound.play();
    image.load("IMG_1846.JPG");
    pic.load("1846_copy.jpg");
    image.resize(200, 200);
    pic.resize(1250,1250);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    mesh.enableColors();
    gui.setup();
    gui.add(uiAmount.set("mesh", 0,0,100));
    
    // We are going to be using indices this time
    mesh.enableIndices();

    // ...
    // Omitting the code for creating vertices for clarity
    // but don't erase it from your file!

    // Let's add some lines!
    float connectionDistance = 10; // ****TEST
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

    
    
    float intensityThreshold = 20.0; // LOW with texture pics
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
    /*
    // (5) grab the fft, and put in into a "smoothed" array,
      //        by taking maximums, as peaks and then smoothing downward
      float * val = ofSoundGetSpectrum(nBandsToGet);        // request 128 values for fft
      for (int i = 0;i < nBandsToGet; i++){
          
          // let the smoothed value sink to zero:
          fftSmoothed[i] *= 0.96f;
          
          // take the max, either the smoothed or the incoming:
          if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
          */
        int count = 0;
        for (int x = 0; x < size; x++){
        for (int y = 0; y < size; y++){
            glm::vec3 position = mesh.getVertex(count);
            position.z = ofMap(ofNoise(count, ofGetElapsedTimef()), 0, 1, 0, uiAmount); //(fftSmoothed[i]) * uiAmount)
            mesh.setVertex(count, position);
            count++;
            
    }
    }
    }
// }

//--------------------------------------------------------------
void ofApp::draw(){


    // ofColor centerColor = ofColor(85, 78, 68, 10);
     //  ofColor edgeColor(0, 0, 0);
     //  ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

       easyCam.begin();
    
    pic.draw(-625, -625);
    //for(int i=0; i<5; i++);
           ofPushMatrix();
               ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
               mesh.draw();
           ofPopMatrix();
  
    
    ofPushMatrix();
                  ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
                  mesh.draw();
              ofPopMatrix();
 
    ofPushMatrix();
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 100);
        mesh.draw();
    ofPopMatrix();
    
  
    ofPushMatrix();
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 200);
        mesh.draw();
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 300);
        mesh.draw();
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 400);
        mesh.draw();
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 500);
        mesh.draw();
    ofPopMatrix();
  
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
