//
// Created by Daniel on 2022/11/11.
//
#include <string>
using namespace std;

class Memento {
    string state;       //对象的状态，简化为一个字符串
public:
    Memento(string s) : state(s) {}
    string getState() const {
        return state;
    }
    void setState(const string& s) {
        state = s;
    }
};

class Originator {      //要保存的原始类
    string state;
public:
    Originator() {}
    Memento createMomento() {
        Memento m(state);   //拍摄快照
        return m;
    }
    void setMomento(const Memento& m) {
        state = m.getState();   //从快照中恢复
    }
};

int main () {
    Originator originator;
    //存储到备忘录
    Memento mem = originator.createMomento();
    //**originator状态改变**

    //从备忘录中恢复
    originator.setMomento(mem);
}

