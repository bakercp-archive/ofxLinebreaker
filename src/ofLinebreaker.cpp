//
//  ofLinebreaker.cpp
//  ofxLinebreaker
//
//  Created by Christopher Baker on 5/24/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//


#include "ofLinebreaker.h"


//------------------------------------------------------------------
ofLinebreaker::ofLinebreaker() {
    language = "en";
}

//------------------------------------------------------------------
ofLinebreaker::~ofLinebreaker() {}


//------------------------------------------------------------------
void ofLinebreaker::setLanguage(const string& lang) {
    language = lang;
}
//------------------------------------------------------------------
string ofLinebreaker::getLanguage() {
    return language;
}

//------------------------------------------------------------------
ofUniCharBreaks ofLinebreaker::breakLines(const ofUTF8String& utf8String) {
    return ofLinebreaker::breakLines(utf8String,language);
}

//------------------------------------------------------------------
ofUniCharBreaks ofLinebreaker::breakLines(const ofUTF8String& utf8String, const string& lang) {
    
    //string language = ofTextLangaugeToString(lang);

    size_t count = utf8String.length();
    
    const ofUTF8Char* buffer = reinterpret_cast<const ofUTF8Char*>(utf8String.c_str());
    char breakData[count];
    
    // set breakpoints
    set_linebreaks_utf8(buffer,count,lang.c_str(),breakData);
    
    ofUniCharBreaks breaks; // the array of chars and their breaks
    
    // TODO: replace this with ofUnicode iteration via ofUTF8
    // multibyte character iteration
    Poco::UTF8Encoding utf8;
    Poco::TextIterator iter(utf8String, utf8);
    Poco::TextIterator end(utf8String);
    
    
    for(int i = 0; i < count; i++) {
        if(breakData[i] != LINEBREAK_INSIDEACHAR) {
            if(iter != end) {
                breaks.push_back(ofUniCharBreak(*(iter++),breakData[i]));
            } else {
                ofLog(OF_LOG_ERROR,"Error calculating line breaks.");
            }
        }
    }
    
    
    return breaks;
}
