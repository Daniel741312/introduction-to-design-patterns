//
// Created by Daniel on 2022/11/12.
//
#include <string>
#include <list>
using namespace std;

class Form {
};
class ProgressBar{
public:
    void setValue(float value);
};
class TextBox {
public:
    string getText();
};

class IProgress {       //抽象的通知机制
public:
    virtual void DoProgress(float value) = 0;
    virtual ~IProgress() {};
};

class FileSplitter {
public:
    string m_filepath;
    int m_filenum;
    list<IProgress*> m_iprogress;     //抽象的通知机制，多个观察者
    FileSplitter(const string& path, int num) : m_filepath(path), m_filenum(num){}

    void add_iprogress(IProgress* p) {      //增加观察者
        m_iprogress.push_back(p);
    }

    void remove_iprogress(IProgress* p) {       //移除观察者
        m_iprogress.remove(p);
    }

    void split() {
        //读入大文件
        //分批次向小文件中写入
        for (int i = 0; i < m_filenum; ++i) {
            //****
            for (auto it = m_iprogress.begin(); it != m_iprogress.end(); ++it) {
                (*it)->DoProgress((i + 1.0) / m_filenum);     //通知所有观察者
            }
        }
    }
};

class MainForm : public Form , public IProgress{        //多继承
    TextBox* txtFilePath;
    TextBox* txtFileNumber;
    ProgressBar* progessBar;
public:
    void Button1_click() {
        string filePath = txtFilePath->getText();
        int num = atoi(txtFileNumber->getText().c_str());

        FileSplitter splitter(filePath, num);
        splitter.add_iprogress(this);		//this加入观察者，订阅通知
        splitter.split();

        splitter.remove_iprogress(this);	//将this从观察者中移除
    }
    virtual void DoProgress(float value) {
        progessBar->setValue(value);        //这个处理方式取决于窗口自己，多态化的
    }
};

int main () {
    return 0;
}
