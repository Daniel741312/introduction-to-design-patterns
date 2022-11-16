//
// Created by Daniel on 2022/11/13.
//
//目标接口
class ITarget {
public:
    virtual void process() = 0;
};

//旧接口
class IAdaptee {
public:
    virtual void foo(int data) = 0;
    virtual int bar() = 0;
};

//旧接口的一个实现
class OldAdaptee : public IAdaptee {
public:
    virtual void foo(int data) override {
    }
    virtual int bar() override {
        return 0;
    }
};

//IAdaptee --Adapter--> Itarget
class Adapter : public ITarget {
public:
    Adapter(IAdaptee* pa) : padaptee(pa) {}
    virtual void process() override {
        //一些适配工作
        int data = padaptee->bar();
        padaptee->foo(data);
        //一些适配工作
    }

protected:
    IAdaptee* padaptee;
};

int main () {
    IAdaptee* pold = new OldAdaptee();      //旧接口的一个实现
    ITarget* ptarget = new Adapter(pold);   //对旧接口做适配工作
    ptarget->process();
    return 0;
}