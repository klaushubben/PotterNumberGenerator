#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(700, 500);
    ofBackground( ofColor::lightSkyBlue );
    nowBook = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofTranslate( 50, 50);
    ofSetColor(0);
    ofDrawBitmapString("PRESS NUMBER 1-7 TO SET CORRECT BOOK & GENERATE 3 WRONG BOOKS", 0, 0);
    
    ofPushMatrix();
    ofTranslate( 0, 20 );
    
    int yPos = 0;
    
    for( int i = 1; i < 8; i ++ ){
        
        ofSetColor( i == nowBook ? ofColor(200) : ofColor( 50 ) );
        ofDrawRectangle( 0, yPos, 300, 30 );
        
        ofSetColor( 255 );
        ofDrawBitmapString( ofToString(i) + " : " + bookFromIndex(i), 20, yPos + 20 );
        
        yPos += 40;
    }
    
    ofSetColor(0);
    ofDrawBitmapString( "Copied to clipboard: " + wrongStr, 0, yPos + 20 );
    
    ofPopMatrix();
}


//-------------------------------------

// https://github.com/elliotwoods/ofxClipboard/blob/master/src/ofxClipboard.cpp

void ofApp::copyToClip( const string & content ){
    //string staticClipboard;
    
    //-----------
  
        ofAppGLFWWindow * window = (ofAppGLFWWindow *)ofGetWindowPtr();
        if (window) {
            glfwSetClipboardString(window->getGLFWWindow(), content.c_str());
        }
        else {
           // ofxClipboard::staticClipboard = content;
        }
   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key >= 49 && key <= 55 ){
        
        nowBook = key - 48;
        
        vector<int> wrong;
        vector<int>::iterator it;
        
        while( static_cast<int>(wrong.size()) < 3 ){
            
            int entry = roundf(ofRandom(8));
            if( entry > 0 && entry < 8 && entry != nowBook ){
                it = find( wrong.begin(), wrong.end(), entry );
                if( it == wrong.end() ) wrong.push_back( entry );
            }
        }
       
        wrongStr = ofToString( wrong );
         // strip out "{ }"
        wrongStr = wrongStr.substr( 1, wrongStr.length()-2);
        cout << wrongStr << endl;
        
        copyToClip(wrongStr);
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
