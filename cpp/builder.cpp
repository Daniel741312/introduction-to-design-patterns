//
// Created by Daniel on 2022/11/2.
//

class House {
public:
    //some pure virtual functions
    virtual ~House() {}
};

class HouseBuilder {
    House* pHouse;
public:
    House* getResult() {
        return pHouse;
    }
    virtual ~HouseBuilder(){}
    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual bool BuildPart3() = 0;
    virtual void BuildPart4() = 0;
    virtual void BuildPart5() = 0;
};

class StoneHouseBuilder : public HouseBuilder {
protected:
    virtual void BuildPart1() override {}
    virtual void BuildPart2() override {}
    virtual bool BuildPart3() override {}
    virtual void BuildPart4() override {}
    virtual void BuildPart5() override {}
};

class HouseDirector {
    HouseBuilder* pHouseBuilder;
public:
    //根据不同的HouseBuilder子类创建出不同的House
    HouseDirector(HouseBuilder* phb) : pHouseBuilder(phb) {}
    House* Construct() {
        pHouseBuilder->BuildPart1();
        for (int i = 0; i < 4; ++i) {
            pHouseBuilder->BuildPart2();
        }
        bool flag = pHouseBuilder->BuildPart3();
        if (flag) {
            pHouseBuilder->BuildPart4();
        }
        pHouseBuilder->BuildPart5();
        return pHouseBuilder->getResult();
    }
};

class StoneHouse : public House {

};

int main () {
    HouseBuilder* phb = new StoneHouseBuilder();
    HouseDirector* phd = new HouseDirector(phb);
    House* stoneHouse = phd->Construct();
}
