#include <iostream>
#include <string>
using namespace std;

string ReverseString(string toReverse)
{
    if (toReverse.empty())
        return "";

    return ReverseString(toReverse.substr(1)) + toReverse[0];
}

int main()
{
    string temp = "Hello!";
    cout << ReverseString(temp);
    return 0;
}
