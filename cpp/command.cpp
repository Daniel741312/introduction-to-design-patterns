//
// Created by Daniel on 2022/11/11.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Command {
public:
    virtual void execute() = 0;
};

class ConcreteCommand1 : public Command {
    string arg;
public:
    ConcreteCommand1(const string& a) : arg(a) {}
    void execute() override {
        cout << "#1 processing "<< arg << endl;
    }
};

class ConcreteCommand2 : public Command {
    string arg;
public:
    ConcreteCommand2(const string& a) : arg(a) {}
    void execute() override {
        cout << "#2 processing "<< arg << endl;
    }
};

class MarcoCommand : public Command {
    vector<Command*> commands;
public:
    void add(Command* c) {
        commands.push_back(c);
    }
    void execute() override {
        for (auto& c : commands) {
            c->execute();
        }
    }
};

int main() {
    ConcreteCommand1 cmd1("arg ###");
    ConcreteCommand2 cmd2("arg $$$");
    MarcoCommand marco;
    marco.add(&cmd1);
    marco.add(&cmd2);
    marco.execute();

    return 0;
}