//
// Created by Daniel on 2022/11/11.
//
#include <list>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

//节点基类：内部节点或叶子节点
class Component {
public:
    virtual void process() = 0;
    virtual ~Component(){}
};

//树内部节点
class Composite : public Component {
    string name;
    list<Component*> elements;      //孩子节点
public:
    Composite(const string& s) : name(s) {}
    void add(Component* elem) {
        elements.push_back(elem);
    }
    void remove(Component* elem) {
        elements.remove(elem);
    }
    void process() override {
        //process currnet node
        cout << "my name is " << name << endl;

        //process leaf nodes, recursively
        for(auto& e : elements) {
            e->process();
        }
    }
};

//叶子节点
class Leaf : public Component {
    string name;
public:
    Leaf(string s) : name(s) {}
    void process() override {
        cout << "my name is " << name << endl;
    }
};

void invoke(Component& c) {
    //****
    c.process();
    //***
}

int main() {
    Composite root("root");
    Composite n1("treeNode1");
    Composite n2("treeNode2");
    Composite n3("treeNode3");
    Composite n4("treeNode4");
    Leaf l1("leaf1");
    Leaf l2("leaf2");

    root.add(&n1);
    n1.add(&n2);
    n2.add(&l1);

    root.add(&n3);
    n3.add(&n4);
    n4.add(&l2);
    /*
     *     root
     *     / \
     *    n1  n3
     *    /    \
     *    n2    n4
     *    /      \
     *    l1      l2
     *
     * */

    invoke(root);
    return 0;
}