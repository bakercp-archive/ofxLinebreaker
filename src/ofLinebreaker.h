//
//  ofLinebreaker.h
//  ofxLinebreaker
//
//  Created by Christopher Baker on 5/24/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofUnicode.h"
#include "ofUTF8.h"

#include "linebreak.h"
#include "linebreakdef.h"

class ofUniCharBreak {
public:
    ofUniCharBreak(ofUniChar _c, char _breakStatus) {
        c           = _c;
        breakStatus = _breakStatus;
    }
    
    ofUniChar  c;
    char       breakStatus;
};

typedef vector<ofUniCharBreak> ofUniCharBreaks;

class ofLinebreaker {
public:
    ofLinebreaker();
    virtual ~ofLinebreaker();
    
    void setLanguage(const string& lang);
    string getLanguage();
    
    ofUniCharBreaks breakLines(const ofUTF8String& string);

    static ofUniCharBreaks breakLines(const ofUTF8String& utf8String, const string& lang);

protected:
    
private:
    
    string language;
    
};
