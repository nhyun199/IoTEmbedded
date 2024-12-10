class Person
{
    int id;
    char *name;

public :
    Person(int id, const char *name);
    Person(const Person& copy);
    ~Person();
    void changeName(const char *name);
    void show();
};

