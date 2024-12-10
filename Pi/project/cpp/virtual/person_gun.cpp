#include <iostream>
#include <string>
using namespace std;

class IGun { // 인터페이스
public :
    virtual void shoot() = 0; // 순수가상함수
};

class Pistol : public IGun {
public :
    void shoot() override
    {
        cout << "Pistol Shooting\n";
    }
};

class K2 : public IGun {
public :
    void shoot() override{
        cout << "K2 Shooting\n";
    }
};

class ToyGun : public IGun { // mock : 가짜, 테스트 프로그램(클래스)
public :
    void shoot() override{
        cout << "ToyGun Shooting\n";
    }
};

class Person {
private :
    IGun* gun;
    string name;
public :
    Person(string name, IGun* gun)
    {
        if(gun == nullptr)
        {
            throw "gun is nullptr\n";
        }
        this->gun = gun;
        this->name = name;
    }

    void fireWeapon()
    {   
        cout << name << " is firing Weapon\n";
        gun->shoot();
    }
};

int main()
{
    Pistol *pistol = new Pistol();
    K2 *k2 = new K2();
    ToyGun *toygun = new ToyGun();

    Person *child = new Person("child", toygun);
    Person *soldier = new Person("soldier", k2);
    Person *police = new Person("police", pistol);

    child->fireWeapon();
    soldier->fireWeapon();
    police->fireWeapon();

    return 0;
}