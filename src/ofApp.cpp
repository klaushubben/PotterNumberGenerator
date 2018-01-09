#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground( 200, 150, 140);
    nowBook = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    ofTranslate( 50, 50 );
    
    int yPos = 0;
    
    for( int i = 1; i < 8; i ++ ){
        
        ofSetColor( i == nowBook ? ofColor(200) : ofColor( 50 ) );
        ofDrawRectangle( 0, yPos, 300, 30 );
        
        ofSetColor( 255 );
        ofDrawBitmapString( ofToString(i) + " : " + bookFromIndex(i), 20, yPos + 20 );
        
        yPos += 40;
    }
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key >= 49 && key <= 55 ){
        
        nowBook = key - 48;
        string out;
        vector<int> wrong;
        vector<int>::iterator it;
        
        while( static_cast<int>(wrong.size()) < 3 ){
            
            int entry = roundf(ofRandom(8));
            if( entry > 0 && entry < 8 && entry != nowBook ){
                it = find( wrong.begin(), wrong.end(), entry );
                if( it == wrong.end() ) wrong.push_back( entry );
            }
        }
        
        out = ofToString( wrong );
        cout << out << endl;
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
