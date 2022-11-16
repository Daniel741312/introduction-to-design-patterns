//
// Created by Daniel on 2022/11/12.
//
class Stream {      //流基类
public:
    virtual char Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream(){}
};

class FileStream : public Stream {      //文件流
public:
    virtual char Read(int number) override {
    }

    virtual void Seek(int position) override {
    }

    virtual void Write(char data) override {
    }
};

class NetworkStream : public Stream {       //网络流
public:
    virtual char Read(int number) override {
    }

    virtual void Seek(int position) override {
    }

    virtual void Write(char data) override {
    }
};

class MemoryStream : public Stream {        //内存流
public:
    virtual char Read(int number) override {
    }

    virtual void Seek(int position) override {
    }

    virtual void Write(char data) override {
    }
};

class DecoratorStream : public Stream {
protected:
    Stream* stream;
    DecoratorStream(Stream* stm) : stream(stm) {}
};

class CryptoStream : public DecoratorStream {    //扩展操作，对流进行加密
public:
    CryptoStream(Stream* stm) : DecoratorStream(stm) {}
    virtual char Read(int number) override {        //这里重写的是DecoratorStream的父类Stream中的虚函数
        //额外的加密操作
        stream->Read(number);       //多态的
        //额外的加密操作
    }
    virtual void Seek(int position) override {
        //额外的加密操作
        stream->Seek(position);
        //额外的加密操作
    }
    virtual void Write(char data) override {
        //额外的加密操作
        stream->Write(data);
        //额外的加密操作
    }
};

//缓存流
class BufferedStream : public DecoratorStream{
public:
    BufferedStream(Stream* stm) : DecoratorStream(stm) {}
    virtual char Read(int number) override {
        //额外的缓存操作
        stream->Read(number);
        //额外的缓存操作
    }

    virtual void Seek(int position) override {
        //额外的缓存操作
        stream->Seek(position);
        //额外的缓存操作
    }
    virtual void Write(char data) override {
        //额外的缓存操作
        stream->Write(data);
        //额外的缓存操作
    }
};

int main() {
    FileStream* fs1 = new FileStream();
    CryptoStream* fs2 = new CryptoStream(fs1);      //加密fs1
    fs2->Read(0);

    BufferedStream* fs3 = new BufferedStream(fs1);  //缓存fs1

    BufferedStream* fs4 = new BufferedStream(fs2);  //既加密又缓存

    return 0;
}
