#include <iostream>
using namespace std;

template <typename T>
T biggest(T arr[], int size)
{
    if(size <= 0)
        return 0;

    T max = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}

int main()
{
    int x[] = {1, 10, 100, 5, 4};
    cout << "max value : " << biggest(x, 5) << endl;

    double y[] = {1.2, 3.5, 4.4, 12.5, 31.5, 11.1};
    cout << "max value : " << biggest(y, 6) << endl;

    string s[] = {"aaa", "aab", "aac", "aad", "aae"};
    cout << "max value : " << biggest(s, 5) << endl;

    return 0;
}