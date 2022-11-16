//
// Created by Daniel on 2022/11/12.
//
#include <iostream>
using namespace std;

class ElementA;
class ElementB;

//访问器基类
class Visitor {
public:
    virtual void visitElementA(ElementA&) = 0;
    virtual void visitElementB(ElementB&) = 0;
    virtual ~Visitor() {}
};

class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual ~Element() {}
};

class ElementA : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visitElementA(*this);
    }
};

class ElementB : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visitElementB(*this);
    }
};

//====上面是稳定部分，下面是变化部分====
//重写一组访问器
class Visitor1 : public Visitor {
public:
    void visitElementA(ElementA& element) override {
        cout << "Visitor1 is processing ElementA" << endl;
    }
    void visitElementB(ElementB& element) override {
        cout << "Visitor1 is processing ElementB" << endl;
    }
};

//重写另外一组访问器
class Visitor2 : public Visitor {
public:
    void visitElementA(ElementA& element) override {
        cout << "Visitor2 is processing ElementA" << endl;
    }
    void visitElementB(ElementB& element) override {
        cout << "Visitor2 is processing ElementB" << endl;
    }
};

int main () {
    Visitor2 visitor;
    ElementB elementB;
    elementB.accept(visitor);

    //double dispatch
    ElementA elementA;
    elementA.accept(visitor);
    return 0;
}
