#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Circle {
    string name;
    int radius;
public :
    Circle(int radius, string name) {this->radius = radius, this->name = name;}
    double getArea() {return 3.14*radius*radius;}
    string getName() {return name;}
};

int main()
{
    vector<Circle> circleList;
    vector<Circle>::iterator it;
    cout << "원을 삽입하고 삭제하는 프로그램입니다.\n";

    while(1)
    {
        int command;
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> command;

        if(command == 1)
        {
            int radius;
            string name;
            cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
            cin >> radius >> name;
            Circle newCircle(radius, name);
            circleList.push_back(newCircle);
        }
        else if(command == 2)
        {
            string name;
            cout << "삭제하고자 하는 원의 이름은 >> ";
            cin >> name;
            for(int i = 0; i < circleList.size(); i++)
            {
                if(circleList[i].getName() == name)
                    
            }
        }
    }


    return 0;
}