//
// Created by Daniel on 2022/11/12.
//
struct Context{
    double income;
};

class TaxStrategy;

class StrategyFactory {
public:
    virtual TaxStrategy* newStrategy() = 0;
    virtual ~StrategyFactory() {}
};

//策略基类
class TaxStrategy {
public:
    virtual double Calculate(const Context& context) = 0;
    virtual ~TaxStrategy(){}
};

//各个策略分别实现Calculate方法
class CNTax : public TaxStrategy {
public:
    virtual double Calculate(const Context& context) override {
        //CN****
    }
};

class USTax : public TaxStrategy {
public:
    virtual double Calculate(const Context &context) override {
        //US****
    }
};

class DETax : public TaxStrategy {
public:
    virtual double Calculate(const Context &context) override{
        //DE****
    }
};

class SalesOrder {
private:
    TaxStrategy* strategy;
public:
    SalesOrder(StrategyFactory* strategyFactory) {      //使用Strategy工厂创建strategy对象
        this->strategy = strategyFactory->newStrategy();    //工厂知道构造何种子类对象
    }
    ~SalesOrder() {
        delete this->strategy;
    }
    double CalculateTax() {
        //****
        Context context;
        double val = strategy->Calculate(context);        //多态调用
        return val;
    }
};

int main () {
    return 0;
}
