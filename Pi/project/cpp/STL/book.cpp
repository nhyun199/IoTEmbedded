#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private : 
    int year;
    string title;
    string author;

public :
    Book(int year, string title, string author) {this->year = year, this->title = title, this->author = author;}
    
    void setYear(int year) {this->year = year;}
    void setTitle(string title) {this->title = title;}
    void setAuthor(string author) {this->author = author;}

    int getYear() {return this->year;}
    string getAuthor() {return this->author;}
    string getTitle() {return this->title;}
};

int main()
{
    vector<Book> booklist;
    int listSize = 0;
    
    cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다.\n";
    while (1)
    {
        int year;
        string title;
        string author;

        cout << "년도>>"; cin >> year; cin.ignore();  
        if(year == -1)
            break;

        cout << "책이름>>"; 
        getline(cin, title);

        cout << "저자>>"; 
        getline(cin, author);

        Book newbook(year, title, author);
        booklist.push_back(newbook);
        listSize++;
    }

    cin.ignore();
    
    string author;
    int year;

    if(booklist.size() == 0)
        return 0;

    cout << "총 입고된 책은 " << booklist.size() << "권입니다.\n";
    cout << "검색하고자 하는 저자 이름을 입력하세요>>";
    cin.ignore(); getline(cin, author);
    
    for(int i = 0; i < listSize; i++)
    {
        if(booklist[i].getAuthor() == author)
            cout << booklist[i].getYear() << "년도, " << booklist[i].getTitle() << ", " << booklist[i].getAuthor() << '\n'; 
    }

    cout << "검색하고자 하는 년도를 입력하세요>>";
    cin >>  year;
    for(int i = 0; i < listSize; i++)
    {
        if(booklist[i].getYear() == year)
            cout << booklist[i].getYear() << "년도, " << booklist[i].getTitle() << ", " << booklist[i].getAuthor() << '\n'; 
    }

}