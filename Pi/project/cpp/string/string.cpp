#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    while(1)
    {
        cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)\n";
        getline(cin, input);
    
        if(input == "exit")
            return 0;

        for(auto x = input.rbegin(); x != input.rend(); x++)
            cout << *x;

        cout << '\n';
    }
    
    
}