#include <string>
#include <vector>
using namespace std;

typedef struct _Menu
{
    int id;
    string name;
    int price;
} Menu;

vector<Menu> getMenuList();