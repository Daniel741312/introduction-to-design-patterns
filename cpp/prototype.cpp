//
// Created by Daniel on 2022/11/12.
//

//Splitter基类
class ISplitter {
public:
    virtual void split() = 0;
    virtual ISplitter* clone() = 0;     //将不同的子类拷贝进来使用
    virtual ~ISplitter() {};
};

//具体类
class BinarySplitter : public ISplitter{
public:
    virtual void split() override {
    }
    virtual ISplitter* clone() override {
        return new BinarySplitter(*this);   //拷贝构造自身
    }
};

class TxtSplitter : public ISplitter{
public:
    virtual void split() override {
    }
    virtual ISplitter* clone() override {
        return new TxtSplitter(*this);
    }
};

class PictureSpliter : public ISplitter{
public:
    virtual void split() override {
    }
    virtual ISplitter* clone() override {
        return new PictureSpliter(*this);
    }
};

class MainForm {
    ISplitter* prototype;
public:
    MainForm(ISplitter* p) : prototype(p) {}    //传入的子工厂类型决定了产生的子类
    void Button1_click() {
        ISplitter* splitter = prototype->clone();    //多态clone
        splitter->split();
    }
};

int main () {
    ISplitter* binarySplitter = new BinarySplitter();
    MainForm* mainForm = new MainForm(binarySplitter);
    mainForm->Button1_click();
    return 0;
}