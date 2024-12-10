#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Book{
private :
    char *title;
    int price;
public :
    Book(const char *title, int price)
    {
        int len = strlen(title);
        this->title = new char[len+1];
        strcpy(this->title, title);
        this->price = price;
        cout << "c-string 생성자\n";
    }

    Book(const Book& book)
    {
        this->price = book.price;
        int len = strlen(book.title);
        this->title = new char[len+1];
        strcpy(this->title, book.title);
        cout << "c-string 복사생성자\n";
    }

    ~Book()
    {
        if(title)
        {
            delete [] title;
            cout << "c-string 메모리 해제 - 소멸자 호출\n";
        }
        cout << "c-string 소멸자 호출\n";
    }

    void set(char *title, int price)
    {
        if (strlen(title) > strlen(this->title)) {
            delete[] this->title; 
            this->title = new char[strlen(title) + 1];  
        }
        strcpy(this->title, title);  
        this->price = price;
    }

    void show()
    {
        cout << title << ' ' << price << "원\n";
    }
};

class Book_string{
private :
    string title;
    int price;
public :
    Book_string(const string title, int price)
    {
        this->title = title;
        this->price = price;
        cout << "string 생성자\n";
    }
    ~Book_string()
    {
        cout << "string 소멸자 호출\n";
    }
    void set(string title, int price)
    {
        this->title = title;
        this->price = price;
    }
    void show()
    {
        cout << title << ' ' << price << "원\n";
    }
};

int main()
{   
    cout << "----using c-string type----\n";
    Book cpp("명품C++", 10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();

    cout << "----using string type----\n";
    Book_string cpp_string("명품C++", 10000);
    Book_string java_string = cpp_string;
    java_string.set("명품자바", 12000);
    cpp_string.show();
    java_string.show();
}


