#include <iostream>
using namespace std;

class Person
{
public:
    Person *nextPerson;

    Person()
    {
        nextPerson = NULL;
    }

    Person(Person *next)
    {
        nextPerson = next;
    }
};

int GetPositionInLine(Person personInLine)
{
    if (personInLine.nextPerson == NULL)
        return 1;
    return GetPositionInLine(*personInLine.nextPerson) + 1;
}

int main()
{
    Person Jake = Person();
    Person Charles = Person(&Jake);
    Person Terry = Person(&Charles);

    cout << GetPositionInLine(Jake) << "\n";
    cout << GetPositionInLine(Terry) << "\n";

    return 0;
}