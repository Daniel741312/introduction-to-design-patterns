//
// Created by Daniel on 2022/11/12.
//
#include <iostream>
using namespace std;

class Library {
public:
    //原来的main逻辑：稳定的template method
    void run() {
        step1();
        if (step2()) {		//虚函数，定制化
            step3();
        }
        for (int i = 0; i < 4; ++i) {
            step4();		//虚函数，定制化
        }
        step5();
    }
    virtual ~Library() {}

protected:
    void step1() {
        cout << "step1 in Library" << endl;
    }
    void step3() {
        cout << "step3 in Library" << endl;
    }
    void step5() {
        cout << "step5 in Library" << endl;
    }
    virtual bool step2() = 0;
    virtual void step4() = 0;
};

class Application : public Library {
protected:
    virtual bool step2() override {
        cout << "step2 in Application" << endl;
        return true;
    }
    virtual void step4() override {
        cout << "step4 in Application" << endl;
    }
};

int main() {
    Library* plib = new Application();
    plib->run();
    delete plib;
}