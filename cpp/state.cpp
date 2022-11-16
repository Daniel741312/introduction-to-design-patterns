//
// Created by Daniel on 2022/11/10.
//

//网络状态抽象基类
class NetworkState {
public:
    NetworkState* pNext;
    virtual void operation1() = 0;  //状态对象的行为
    virtual void operation2() = 0;
    virtual void operation3() = 0;
    virtual ~NetworkState() {}
};

//关闭状态
class CloseState : public NetworkState {
    static NetworkState* m_instance;
public:
    static NetworkState* getInstance() {        //单例
        //lock
        if (m_instance == nullptr) {
            m_instance = new CloseState();
        }
        return m_instance;
    }
    void operation1() override {
        //****
        //状态转移
    }
    void operation2() override {
        //****
        //状态转移
    }
    void operation3() override {
        //****
        //状态转移
    }
};
NetworkState* CloseState::m_instance = nullptr;

//连接状态
class ConnectState : public NetworkState {
    static NetworkState* m_instance;
public:
    static NetworkState* getInstance() {
        if (m_instance == nullptr) {
            m_instance = new ConnectState();
        }
        return m_instance;
    }
    void operation1() override {
        //****
        //状态转移
    }
    void operation2() override {
        //****
        //状态转移
    }
    void operation3() override {
        //****
        //状态转移
    }
};
NetworkState* ConnectState::m_instance = nullptr;

//打开状态
class OpenState : public NetworkState {
    static NetworkState* m_instance;
public:
    static NetworkState* getInstance() {    //单例
        //lock
        if (m_instance == nullptr) {
            m_instance = new OpenState();
        }
        return m_instance;
    }
    void operation1() override {
        //****
        pNext = CloseState::getInstance();      //转入下一个状态：关闭
    }
    void operation2() override {
        //****
        pNext = ConnectState::getInstance();    //转入下一个状态：连接
    }
    void operation3() override {
        //****
        pNext = OpenState::getInstance();       //转入下一个状态：打开
    }
};
NetworkState* OpenState::m_instance = nullptr;

class NetworkProcessor {
    NetworkState* pState;
public:
    NetworkProcessor(NetworkState* pState) {
        this->pState = pState;
    }
    void operation1() {
        //****
        pState->operation1();
        pState = pState->pNext;
        //****
    }
    void operation2() {
        //****
        pState->operation2();
        pState = pState->pNext;
        //****
    }
    void operation3() {
        //****
        pState->operation3();
        pState = pState->pNext;
        //****
    }
};

int main () {
    NetworkState* networkState = new OpenState();
    NetworkProcessor* networkProcessor = new NetworkProcessor(networkState);
    networkProcessor->operation1();
    return 0;
}
