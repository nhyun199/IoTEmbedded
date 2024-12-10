#include <vector>
#include <iostream>
#include <string>
#include "menu.h"

vector<Menu> getMenuList() {
    int i = 1;
    return {
        {i, "핫 아메리카노", 1300},
        {++i, "아이스 아메리카노", 1500},
        {++i, "카푸치노", 3500},
        {++i, "핫초코", 3000},
        {++i, "카라멜마끼아또", 3500},
        {++i, "디카페인 아메리카노(Hot Only)", 2000},
        {++i, "레몬 에이드", 4000},
        {++i, "자몽 에이드", 4000}
    };
}
