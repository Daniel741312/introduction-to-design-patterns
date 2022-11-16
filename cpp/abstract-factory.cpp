//
// Created by Daniel on 2022/11/12.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class EmployeeDO {
};

//数据库访问有关的基类
class IDBConnection {
public:
    virtual void connectionString(string str) = 0;
};

class IDBCommand {
public:
    virtual void commandText(string str) = 0;
    virtual void setConnection(IDBConnection*) = 0;
};

class IDBDataReader {
public:
    virtual bool read() = 0;
};

//数据库访问基类工厂
class IDBFactory {
public:    //将相互关联的子操作放在一起，避免产生交叉混叠
    virtual IDBConnection* createDBConnection() = 0;
    virtual IDBCommand* createDBCommand() = 0;
    virtual IDBDataReader* createDBDataReader() = 0;
};

//SQL Server数据库访问类
class SqlConnection : public IDBConnection {
public:
    virtual void connectionString(string str) override{
        cout << "Sql connection, " << str << endl;
    }
};

class SqlCommand : public IDBCommand{
public:
    virtual void commandText(string str) override {
        cout << "Sql commandText" << str << endl;
    }
    virtual void setConnection(IDBConnection*) {
    }
};

class SqlDataReader : public IDBDataReader {
public:
    virtual bool read() override {
        cout << "Sql reading" << endl;
        return true;
    }
};

class SqlDBFactory : public IDBFactory {
public:
    //将相互关联的子操作放在一起，避免产生交叉混叠
    virtual IDBConnection* createDBConnection() override {
        return new SqlConnection();
    }
    virtual IDBCommand* createDBCommand() {
        return new SqlCommand();
    }
    virtual IDBDataReader* createDBDataReader() {
        return new SqlDataReader();
    }
};

//Oracle数据库访问类
class OracleConnection : public IDBConnection {
public:
    virtual void connectionString(string str) override{
    }
};
class OracleCommand : public IDBCommand{
public:
    virtual void commandText(string str) override {
    }
    virtual void setConnection(IDBConnection*) override {
    }
};
class OracleDataReader : public IDBDataReader {
public:
    virtual bool read() override {
        return true;
    }
};

class OracleDBFactory : public IDBFactory {
public:
    //将相互关联（依赖）的子操作放在一起，避免产生交叉混叠
    virtual IDBConnection* createDBConnection() {
        return new OracleConnection();
    }
    virtual IDBCommand* createDBCommand() {
        return new OracleCommand();
    }
    virtual IDBDataReader* createDBDataReader() {
        return new OracleDataReader();
    }
};

class EmployeeDAO {
    IDBFactory* dbFactory;
public:
    EmployeeDAO(IDBFactory* dbf) : dbFactory(dbf) {};
    vector<EmployeeDO> getEmployees() {
        IDBConnection* connection = dbFactory->createDBConnection();
        connection->connectionString("...");

        IDBCommand* command = dbFactory->createDBCommand();
        command->commandText("...");
        command->setConnection(connection);

        IDBDataReader* reader = dbFactory->createDBDataReader();
        while (reader->read()) {
            //****
        }
    }
};

int main () {
    IDBFactory* dbf = new SqlDBFactory();
    EmployeeDAO* e = new EmployeeDAO(dbf);
    e->getEmployees();
    return 0;
}