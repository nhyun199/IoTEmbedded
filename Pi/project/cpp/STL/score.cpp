#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> scoreList;
    cout << "***** 점수관리 프로그램 HIGT SCORE를 시작합니다 *****\n";
    while(1)
    {
        int command;
        string name; int score;
        
        cout << "입력1, 조회:2, 종료:3 >> ";
        cin >> command;

        if(command == 1)
        {
            cout << "이름과 점수>> ";
            cin >> name >> score;
            scoreList.insert(make_pair(name, score));
        }
        else if(command == 2)
        {
            if(scoreList.size() == 0)
            {
                cout << "입력된 정보가 없습니다. 이름과 점수를 입력해주세요.\n";
                continue;
            }

            string nameToScore;
            cout << "이름>> ";
            cin >> nameToScore;
            
            if(scoreList.find(nameToScore) == scoreList.end())
                cout << nameToScore << "가 항목에 없습니다.\n";
            else
                cout << nameToScore << "의 점수는 " << scoreList[nameToScore] << '\n';
        }
        else if(command== 3)
        {
            cout << "프로그램을 종료합니다...";
            return 0;
        }
    }
    
    return 0;
}