//
// Created by Daniel on 2022/11/11.
//
#include <iostream>
#include <string>
using namespace std;

enum class RequestType {
    REQ_HANDLER1,
    REQ_HANDLER2,
    REQ_HANDLER3
};

class Request {
    string description;
    RequestType reqType;
public:
    Request(const string& desc, RequestType type) : description(desc), reqType(type) {}
    RequestType getReqType() const {
        return reqType;
    }
    const string& getDescription() const {
        return description;
    }
};

class ChainHandler {
    ChainHandler* nextChain;
    void sendRequestToNextHandler(const Request& req) {
        if (nextChain != nullptr) {
            nextChain->handle(req);
        }
    }

protected:
    virtual bool canHandleRequest(const Request& req) = 0;
    virtual void processRequest(const Request& req) = 0;

public:
    ChainHandler() {
        nextChain = nullptr;
    }
    void setNextChain(ChainHandler* next) {
        nextChain = next;
    }
    void handle(const Request& req) {
        if (canHandleRequest(req)) {
            processRequest(req);
        } else {
            sendRequestToNextHandler(req);
        }
    }
};

class Handler1 : public ChainHandler {
protected:
    bool canHandleRequest(const Request& req) override {
        return req.getReqType() == RequestType::REQ_HANDLER1;       //判断自己能否处理该类型请求
    }
    void processRequest(const Request& req) override {
        cout << "Handler1 is handling request:" << req.getDescription() << endl;
    }
};

class Handler2 : public ChainHandler {
protected:
    bool canHandleRequest(const Request& req) override {
        return req.getReqType() == RequestType::REQ_HANDLER2;
    }
    void processRequest(const Request& req) override {
        cout << "Handler2 is handling request:" << req.getDescription() << endl;
    }
};

class Handler3 : public ChainHandler {
protected:
    bool canHandleRequest(const Request& req) override {
        return req.getReqType() == RequestType::REQ_HANDLER3;
    }
    void processRequest(const Request& req) override {
        cout << "Handler3 is handling request:" << req.getDescription() << endl;
    }
};

int main() {
    Handler1 h1;
    Handler2 h2;
    Handler3 h3;
    h1.setNextChain(&h2);
    h2.setNextChain(&h3);
    /*h1 --> h2 --> h3*/

    Request req("I'm 3, process me", RequestType::REQ_HANDLER3);
    h1.handle(req);
    return 0;
}