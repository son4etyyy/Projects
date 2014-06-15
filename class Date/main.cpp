#include <iostream>
#include <string>
#include "Date.cpp"
using namespace std;

void example_by_param(Date d)
{
    cout << "An object is passed by value to a function." << endl;
}

void example_by_ref(Date& d)
{
    cout << "An object is passed by reference to a function." << endl;
}

int main()
{
    cout << "initialization:" << endl;
    Date s;
    Date t = s;
    cout << endl;

    cout << "assignment :" << endl;
    Date d;
    Date v;
    cout << endl;

    cin >> d;
    v = d;
    cout << endl;

    cout << "Operator ++" << endl;
    cout << "postfix" << endl;
    cout << "The day after " << d << " is: " << endl;
    d++;
    cout << d << endl;
    cout << "prefix" << endl;
    cout << "The next is: " << ++d << endl;
    cout << endl;

    cout << "Operator --" << endl;
    cout << "postfix" << endl;
    cout << "Before " << d << " is: " << endl;
    d--;
    cout << d << endl;
    cout << "prefix" << endl;
    cout << "Before " << d << " is: " << endl;
    cout << --d << endl;
    cout << endl;

    example_by_param(v);
    cout << endl;
    example_by_ref(v);
    cout << endl;

    return 0;
}
