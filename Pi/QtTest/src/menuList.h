#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct _menulist
{
    string menu_info;
    string image_path;
} MenuList;

vector<MenuList> getMenuList();