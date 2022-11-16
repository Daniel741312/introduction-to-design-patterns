//
// Created by Daniel on 2022/11/12.
//

class ISubject {
public:
    virtual void process() = 0;
};

//Proxy的设计一般很复杂
class SubjectProxy: public ISubject {
public:
    virtual void process() override {
        //对RealSubject的一种间接访问
    }
};

class ClientApp {
    ISubject* subject;
public:
    ClientApp() {
        //subject = new RealSubject();  //可能无法按照这种方式完成构建
        subject = new SubjectProxy();
    }
    void doTask() {
        subject->process();
    }
};

int main () {
    ClientApp* clientApp = new ClientApp();
    clientApp->doTask();
    return 0;
}