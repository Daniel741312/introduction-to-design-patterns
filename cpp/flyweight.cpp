//
// Created by Daniel on 2022/11/12.
//
#include <string>
#include <map>
#include <iostream>
using namespace std;

//字体对象
class Font {
private:
    string key;
public:
    Font(const string& k) {
        cout << "key = " << k << " constructed" << endl;
        key = k;
    }
    string getKey() {
        return key;
    }
};

//采用“池”的思想，将创建好的对象缓存下来
class FontFactory{
private:
    map<string, Font*> fontPool;
public:
    Font* getFont(const string& key) {
        map<string, Font*>::iterator it = fontPool.find(key);
        if (it != fontPool.end()) {
            return it->second;
        } else {
            Font* font = new Font(key);
            fontPool[key] = font;
            return font;
        }
    }
    void clear() {
        //***
    }
};

int main () {
    Font* pfont = nullptr;
    FontFactory* fontFactory = new FontFactory();

    pfont = fontFactory->getFont("song");
    cout << pfont->getKey() << endl;
    pfont = fontFactory->getFont("kai");
    cout << pfont->getKey() << endl;

    pfont = fontFactory->getFont("song");
    cout << pfont->getKey() << endl;
    return 0;
}