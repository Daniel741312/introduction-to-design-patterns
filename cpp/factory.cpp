//
// Created by Daniel on 2022/11/12.
//

//Splitter基类
class ISplitter {
public:
    virtual void split() = 0;
    virtual ~ISplitter() {};
};
//工厂基类
class SplitterFactory {
public:
    virtual ISplitter* createSplitter() = 0;
    virtual ~SplitterFactory() {}
};

//具体类
class BinarySplitter : public ISplitter{
public:
    virtual void split() override {
    }
};

class TxtSplitter : public ISplitter{
public:
    virtual void split() override {
    }
};

class PictureSpliter : public ISplitter{
public:
    virtual void split() override {
    }
};

//具体工厂
class BinarySplitterFactory : public SplitterFactory{
public:
    virtual ISplitter* createSplitter() override {
        return new BinarySplitter();
    }
};

class TxtSplitterFactory : public SplitterFactory{
public:
    virtual ISplitter* createSplitter() override {
        return new TxtSplitter();
    }
};

class PictureSpliterFactory : public SplitterFactory {
public:
    virtual ISplitter* createSplitter() override {
        return new PictureSpliter();
    }
};

class MainForm {
    SplitterFactory* factory;
public:
    MainForm(SplitterFactory* f) : factory(f) {}    //传入的子工厂类型决定了产生的子类
    void Button1_click() {
        //new依赖于具体的构造函数，违背的依赖倒置原则：只依赖于抽象而非依赖于具体
        //ISplitter* splitter1 = new BinarySplitter();
        ISplitter* splitter = factory->createSplitter();    //多态new
        splitter->split();
        delete splitter;
    }
    ~MainForm(){
        delete factory;
    }
};

int main () {
    SplitterFactory* binarySplitterFactory = new BinarySplitterFactory();
    MainForm* mainForm = new MainForm(binarySplitterFactory);
    mainForm->Button1_click();
}