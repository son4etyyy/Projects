#ifndef Date_h
#define Date_H
#include <iostream>
using namespace std;

class Date
{
public:
    Date();// standard constructor
    Date(const Date& d);// copy constructor
    ~Date();// destructor
    Date& operator =(const Date& d); // assignment operator

    void set_day(int& value);
    void set_month(int& value);
    void set_year(int& value);
    int get_day() const;
    int get_month() const;
    int get_year() const;

    Date operator++(); //prefix
    Date operator++(int dummy); //postfix
    Date operator--(); //prefix
    Date operator--(int dummy); //postfix
    friend ostream& operator<<(ostream& out, const Date& stc);
    friend istream& operator>>(istream& in, Date& stc);

private:
    static const int SIZE = 3;
    int* arr;
};

#endif // Date_h
