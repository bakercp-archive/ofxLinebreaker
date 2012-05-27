#pragma once

#include "ofMain.h"
#include "ofUnicode.h"
#include "ofUTF8.h"
#include "ofTextConverter.h"
#include "ofLinebreaker.h"

class testApp : public ofBaseApp{
	public:
		void setup();

    ofLinebreaker linebreaker;
    
    void dumpBreaks(const ofUniCharBreaks& breaks);
};
