#pragma once

#include "ofMain.h"

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
     
    
    int nowBook;
    string wrongStr;
    void copyToClip( const string & content );
    
    string bookFromIndex(int index){
        string book = "nope";
        switch( index ){
            case 1:
                book = "The Sorcerer's Stone";
                break;
            case 2:
                book = "The Chamber of Secrets";
                break;
            case 3:
                book = "The Prisoner of Azkaban";
                break;
            case 4:
                book = "The Goblet of Fire";
                break;
            case 5:
                book = "The Order of the Phoenix";
                break;
            case 6:
                book = "The Half-Blood Prince";
                break;
            case 7:
                book = "The Deathly Hallows";
                break;
        }
        return book;
    }
		
};
