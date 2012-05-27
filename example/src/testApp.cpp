#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    // some panagrams for testing.
    string en = "The quick brown fox jumps over the lazy dog.";
    string de = "Victor jagt zwölf Boxkämpfer quer über den großen Sylter Deich";
    string es = "El veloz murciélago hindú comía feliz cardillo y kiwi. La cigüeña tocaba el saxofón detrás del palenque de paja.";
    string fr = "Buvez de ce whisky que le patron juge fameux.";
    string ru = "Эх, чужак! Общий съём цен шляп (юфть) – вдрызг!";
    string zh = "視野無限廣，窗外有藍天";  // the concept of a chinese panagram is, well ...
    
    // break some lines in various languages
    
    cout << "--- en ---" << endl;
    dumpBreaks(linebreaker.breakLines(en,"en"));
    cout << "--- de ---" << endl;
    dumpBreaks(linebreaker.breakLines(de,"de"));
    cout << "--- es ---" << endl;
    dumpBreaks(linebreaker.breakLines(es,"es"));
    cout << "--- fr ---" << endl;
    dumpBreaks(linebreaker.breakLines(fr,"fr"));
    cout << "--- ru ---" << endl;
    dumpBreaks(linebreaker.breakLines(ru,"ru"));
    cout << "--- zh ---" << endl;
    dumpBreaks(linebreaker.breakLines(zh,"zh"));

    
    
}

//--------------------------------------------------------------
void testApp::dumpBreaks(const ofUniCharBreaks& breaks) {
    
    for(int i = 0; i < breaks.size(); i++) {
        if(breaks[i].breakStatus == LINEBREAK_MUSTBREAK) {
            cout << ofTextConverter::toUTF8(breaks[i].c) << "\t-> " << "LINEBREAK_MUSTBREAK" << endl;
        } else if(breaks[i].breakStatus == LINEBREAK_ALLOWBREAK) {
            cout << ofTextConverter::toUTF8(breaks[i].c) << "\t-> " << "LINEBREAK_ALLOWBREAK" << endl;
        } else if(breaks[i].breakStatus == LINEBREAK_NOBREAK) {
            cout << ofTextConverter::toUTF8(breaks[i].c) << "\t-> " << "LINEBREAK_NOBREAK" << endl;
        } else if(breaks[i].breakStatus == LINEBREAK_INSIDEACHAR) {
            cout << ofTextConverter::toUTF8(breaks[i].c) << "\t-> " << "LINEBREAK_INSIDEACHAR" << endl;
        }
    }
}
