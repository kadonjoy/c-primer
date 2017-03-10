#include <iostream>

/**
 * 这个demo是为了说明拷贝构造函数和赋值构造函数何时被调用
 */

using namespace std;
class Person {
public:
    Person(const string& name);
    Person(const Person& person);
    ~Person();
    Person& operator=(const Person& person);
private:
    char * name;
};

Person::Person(const string& username) {
    name = new char[10];
    strncpy(name, username.data(), 10);
    cout << "construct Person: " << name << endl;
}

Person::Person(const Person& person) {
    cout << "copy construct Person: " << person.name << endl;
    name = new char[10];
    memcpy(name, person.name, 10);
}

Person& Person::operator=(const Person& person) {
    cout << "operator= id called: " << name << "    :" << person.name << endl;
    if (this == &person)
        return *this;
    if (name != NULL) {
        delete name;
        name = NULL;
    }
    name = new char[10];
    memcpy(name, person.name, 10);
    return *this;
}

Person::~Person() {
    cout << "deconstructor Person: " << name << endl;
    delete name;
    name = NULL;
}

int main(int argc, char** argv) {
    Person james("james");
    //这里将会调用copy构造函数
    //Person tom = james;
    //下面调用赋值构造函数
    Person tom("tom");
    tom = james;

    return 1;
}