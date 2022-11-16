//
// Created by Daniel on 2022/11/12.
//
#include <string>
using namespace std;
class Image {

};
//依赖于平台实现
class MessagerImp {
public:
    virtual void playSound() = 0;
    virtual void drawShape() = 0;
    virtual void writeText() = 0;
    virtual void connect() = 0;
    virtual ~MessagerImp() {};
};

class Messager {
protected:
    MessagerImp* msg;
public:
    Messager(MessagerImp* m) : msg(m) {}
    virtual void login(string username, string passwd) = 0;
    virtual void sendMessage(string message) = 0;
    virtual void sendPicture(Image image) = 0;

    virtual ~Messager() {};
};

class PCMessagerImp: public MessagerImp {
public:
    virtual void playSound() override {
    }
    virtual void drawShape() override {
    }
    virtual void writeText() override {
    }
    virtual void connect() override {
    }
};

class MobileMessagerImp: public MessagerImp {
public:
    virtual void playSound() override {
    }
    virtual void drawShape() override {
    }
    virtual void writeText() override {
    }
    virtual void connect() override {
    }
};

//精简版PCMessager
//完美版PCMessager

//精简版MobileMessager
class MobileMessagerLite : public Messager {
public:
    MobileMessagerLite(MessagerImp* m) : Messager(m) {}
    virtual void login(string username, string passwd) {
        msg->connect();
    }
    virtual void sendMessage(string message) {
        msg->writeText();
    }
    virtual void sendPicture(Image image) {
        msg->drawShape();
    }
};

//完美版MobileMessager
class MobileMessagerPerfect : public Messager {
public:
    MobileMessagerPerfect(MessagerImp* m) : Messager(m) {}
    virtual void login(string username, string passwd) {
        msg->playSound();
        //****
        msg->connect();
    }
    virtual void sendMessage(string message) {
        msg->playSound();
        //****
        msg->writeText();
    }
    virtual void sendPicture(Image image) {
        msg->playSound();
        //****
        msg->drawShape();
    }
};

int main() {
    MessagerImp* mimp = new MobileMessagerImp();
    Messager* m = new MobileMessagerPerfect(mimp);
    m->login("danile", "hello");
    return 0;
}
