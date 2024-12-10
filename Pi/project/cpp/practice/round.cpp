#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int N;
    double sum = 0;
    int totalGpa = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string subject;
        int gpa;
        string score;
        double _score;

        cin >> subject >> gpa >> score;
        
        switch (score[0])
        {
        case 'A':
            _score = 4.3;
            switch (score[1])
            {
            case '0':
                _score -= 0.3;
                break;
            case '-':
                _score -= 0.6;
            default:
                break;
            }
            break;

        case 'B':
            _score = 3.3;
            switch (score[1])
            {
            case '0':
                _score -= 0.3;
                break;
            case '-':
                _score -= 0.6;
            default:
                break;
            }
            break;

        case 'C':
            _score = 2.3;
            switch (score[1])
            {
            case '0':
                _score -= 0.3;
                break;
            case '-':
                _score -= 0.6;
            default:
                break;
            }
            break;
        
        case 'D':
            _score = 1.3;
            switch (score[1])
            {
            case '0':
                _score -= 0.3;
                break;
            case '-':
                _score -= 0.6;
            default:
                break;
            }
            break;

        case 'F':
            _score = 0.0;
            break;
        }

        totalGpa += gpa;
        sum += (gpa*_score);
    }
    cout << round((sum / totalGpa)*100)/100;
}
