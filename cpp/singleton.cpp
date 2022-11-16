//
// Created by Daniel on 2022/11/4.
//
#include <thread>
#include <mutex>
using namespace std;

class Singleton {
private:
    Singleton(){   //私有化默认构造函数和拷贝构造函数
    }
    Singleton(const Singleton& s);
    //...

public:
    static Singleton* getInstance() {
        if (m_instance == nullptr) {
            mutex lock;
            if (m_instance == nullptr) {
                m_instance = new Singleton();
            }
        }
        return m_instance;
    }
    static Singleton* m_instance;       //全局的唯一实例
};
Singleton* Singleton::m_instance = nullptr;

/*示意代码：非线程安全版本
Singleton* Singleton::getInstance() {
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}
*/

/*线程安全版本，但锁的代价过高
Singleton* Singleton::getInstance() {
    mutex lock;
    if (m_instance == nullptr) {
        m_instance = new Singleton();
    }
    return m_instance;
}
*/

//双检查锁，但由于指令执行reorder导致不安全

//要用C++实现一个正确可用的单例模式可太难了
int main () {
    Singleton* s1 = Singleton::getInstance();
    return 0;
}