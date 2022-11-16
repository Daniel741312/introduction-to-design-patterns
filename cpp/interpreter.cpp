//
// Created by Daniel on 2022/11/12.
//
#include <string>
#include <iostream>
#include <map>
#include <stack>
using namespace std;

class Expression{
public:
    virtual int interpreter(map<char, int> var) = 0;
    virtual ~Expression(){};
};

//变量表达式
class VarExperssion : public Expression {
    char key;
public:
    VarExperssion(char key) {
        this->key = key;
    }
    int interpreter(map<char, int> var) override {
        return var[key];
    }
};

//符号表达式
class SymbolExpression : public Expression {
protected:
    Expression* left;
    Expression* right;
public:
    SymbolExpression(Expression* left, Expression* right) : left(left), right(right) {}
};

class AddExpression : public SymbolExpression {
public:
    AddExpression(Expression* l, Expression* r) : SymbolExpression(l, r) {}
    int interpreter(map<char, int> var) override {
        return left->interpreter(var) + right->interpreter(var);
    }
};

class SubExpression : public SymbolExpression {
public:
    SubExpression(Expression* l, Expression* r) : SymbolExpression(l, r) {}
    int interpreter(map<char, int> var) override {
        return left->interpreter(var) - right->interpreter(var);
    }
};

Expression* analyse(string exp) {
    stack<Expression*> expstk;
    Expression* left = nullptr;
    Expression* right = nullptr;
    for (int i = 0; i < exp.size(); ++i) {
        switch (exp[i]) {
            case '+':
                left = expstk.top();
                right = new VarExperssion(exp[++i]);
                expstk.push(new AddExpression(left, right));
                break;
            case '-':
                left = expstk.top();
                right = new VarExperssion(exp[++i]);
                expstk.push(new SubExpression(left, right));
                break;
            default:
                expstk.push(new VarExperssion(exp[i]));
        }
    }
    return expstk.top();
}

void release(Expression* expression) {
    //...
}
int main () {
    string expStr = "a+b-c+d";
    map<char, int> var;
    var['a'] = 5;
    var['b'] = 2;
    var['c'] = 1;
    var['d'] = 6;

    Expression* expression = analyse(expStr);

    int result = expression->interpreter(var);  //interpret from root recursively
    cout << result << endl;

    release(expression);
    return 0;
}


