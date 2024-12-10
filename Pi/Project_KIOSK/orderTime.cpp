#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

string printOrderTime()
{
    string current_time;

    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    ostringstream oss;
    oss << put_time(localtime(&now_time), "%Y-%m-%d %H:%M:%S");
    
    current_time = oss.str();

    return current_time;
}