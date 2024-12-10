#include <string>
#include <iostream>

using namespace std;

class Book{
    string title;
    int price, pages;
public :
    Book(string title ="", int price = 0, int pages = 0){
        this->title = title; this->price = price; this->pages = pages;
    }
    void show(){
        cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
    }
    string getTitle() {return title;}

    // 클래스에 함수 작성
    // Book& operator+=(int op1){
    //     price = price + op1;
    //     return *this;
    // }
    // Book& operator-=(int op1){
    //     price = price - op1;
    //     return *this;
    // }

    // bool operator==(int op1){
    //     if(this->price == op1)
    //         return true;
    //     return false;
    // }
    // bool operator==(string op1){
    //     if(this->title == op1)
    //         return true;
    //     return false;
    // }
    // bool operator==(Book op1){
    //     if(this->pages == op1.pages && this->price == op1.price && this->title == op1.title)
    //         return true;
    //     return false;
    // }
    
    bool operator!()
    {
        if(this->price == 0)
            return true;
        return false;
    }

    
    // 프렌드로 외부 함수 작성
    friend Book& operator+=(Book& op1, int op2);
    friend Book& operator-=(Book& op1, int op2);
    friend bool operator==(Book op1, int op2);
    friend bool operator==(Book op1, string op2);
    friend bool operator==(Book op1, Book op2);
    friend bool operator<(string op1, Book op2);

};

int main()
{
    // *1번 문제*
    // Book a("청춘", 20000, 300), b("미래", 30000, 500);
    // a += 500;
    // b -= 500;
    // a.show();
    // b.show();

    // Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
    // if(a == 30000) cout << "정가 30000원" << endl;
    // if(a == "명품 C++") cout << "명품 C++ 입니다." << endl;
    // if(a == b) cout << "두 책이 같은 책입니다." << endl;

    Book book("벼룩시장", 0, 50);
    if(!book) cout << "공짜다" << endl;

    Book a("청춘", 20000, 300);
    string b;
    cout << "책 이름을 입력하세요>>";
    getline(cin, b);
    if(b < a)
        cout << a.getTitle() << "이 " << b << "보다 뒤에 있구나!" << endl;
}

Book& operator+=(Book& op1, int op2)
{
    op1.price += op2;
    return op1;
}

Book& operator-=(Book& op1, int op2)
{
    op1.price -= op2;
    return op1;
}

bool operator==(Book op1, int op2)
{
    if(op1.price == op2)
        return true;
    return false;
}

bool operator==(Book op1, string op2)
{
    if(op1.title == op2)
        return true;
    return false;
}

bool operator==(Book op1, Book op2)
{
    if(op1.price == op2.price && 
       op1.pages == op2.pages && 
       op1.title == op2.title)
        return true;
    return false;
}

bool operator<(string op1, Book op2)
{
    if(op2.title > op1)
        return true;
    return false;
}
