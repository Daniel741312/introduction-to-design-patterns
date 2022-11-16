//
// Created by Daniel on 2022/11/11.
//
#include <iostream>
using namespace std;

template<typename T> class MyCollection;

template<typename T>
class Iterator {
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual T& current() = 0;
};


template<typename T>
class CollectionIterator : public Iterator<T> {
    MyCollection<T> mc;
public:
    CollectionIterator(const MyCollection<T>& c) : mc(c) {}
    void first() override {
    }
    void next() override {
    }
    bool isDone() const override {
        return true;
    }
    T& current() override {
        T t;
        return t;
    }
};

template<typename T>
class MyCollection {
public:
    Iterator<T>* getIterator() {
        //....
        return new CollectionIterator<T>(*this);
    }
};

int main() {
    MyCollection<int> mc;
    Iterator<int>* iter = mc.getIterator();
    for (iter->first(); !iter->isDone(); iter->next()) {
        cout << iter->current() << endl;
    }
    return 0;
}
