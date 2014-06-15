#include "Date.h"
#include <iostream>
using namespace std;

//Constructor
Date::Date()
{
    cout << "(Constructor invoked!)" << endl;
    arr = new int[SIZE];
}

//Copy constructor
Date::Date(const Date& d)
{
    cout << "(Copy constructor invoked!)" << endl;
    if (this != & d)// prevent self-copying
    {
        arr = new int[SIZE];
        for(int i = 0; i < SIZE; i++)
        {
            arr[i] = d.arr[i];
        }
    }
}

//Destructor
Date::~Date()
{
    cout << "(Destructor invoked!)" << endl;
    if(arr)
    {
        delete[] arr;
        arr = 0;
    }
}

//predefine assignment operator
Date& Date::operator =(const Date& d)
{
    cout << "(Assignment operator invoked!)" << endl;
    if(this != &d) // prevent self-copying
    {
        if(arr)
        {
            delete[] arr;
            arr = 0;
        }
        arr = new int[SIZE];
        for(int i = 0; i < SIZE; i++)
        {
            arr[i] = d.arr[i];
        }
    }
    return *this;
}

//set the day
void Date::set_day(int& value)
{
    arr[0] = value;
}

//set the month
void Date::set_month(int& value)
{
    arr[1] = value;
}

//set the year
void Date::set_year(int& value)
{
    arr[2] = value;
}

//get the day
int Date::get_day() const
{
    return arr[0];
}

//get the month
int Date::get_month() const
{
    return arr[1];
}

//get the year
int Date::get_year() const
{
    return arr[2];
}

//Prefix increment by 1 day
Date Date::operator++()
{
    if(arr[0] >= 28)
    {
        if(arr[1] == 2)//arr[0] == 28||29
        {
            arr[0] = 1;
            arr[1] = 3;
        }
        else if(arr[0] == 30 && (arr[1] == 4 || arr[1] == 6 || arr[1] == 9 || arr[1] == 11))
        {
            arr[0] = 1;
            arr[1]++;
        }
        else if( arr[0] == 31 && (arr[1] == 1 || arr[1] == 3 || arr[1] == 5 || arr[1] == 7 || arr[1] == 8 || arr[1] == 10))
        {
            arr[0] = 1;
            arr[1]++;
        }
        else if(arr[0] == 31 && arr[1] == 12)
        {
            arr[0] = 1;
            arr[1] = 1;
            arr[2]++;
        }
        else
        {
            arr[0]++;
        }
    }
    else
    {
        arr[0]++;
    }
    return *this;
}

//Postfix increment by 1 day
Date Date::operator++(int dummy)
{
    Date temp = *this;
    if(arr[0] >= 28)
    {
        if(arr[1] == 2)//arr[0] == 28||29
        {
            arr[0] = 1;
            arr[1] = 3;
        }
        else if(arr[0] == 30 && (arr[1] == 4 || arr[1] == 6 || arr[1] == 9 || arr[1] == 11))
        {
            arr[0] = 1;
            arr[1]++;
        }
        else if( arr[0] == 31 && (arr[1] == 1 || arr[1] == 3 || arr[1] == 5 || arr[1] == 7 || arr[1] == 8 || arr[1] == 10))
        {
            arr[0] = 1;
            arr[1]++;
        }
        else if(arr[0] == 31 && arr[1] == 12)
        {
            arr[0] = 1;
            arr[1] = 1;
            arr[2]++;
        }
        else
        {
            arr[0]++;
        }
    }
    else
    {
        arr[0]++;
    }
    return temp;
}

//Prefix decrement by 1 day
Date Date::operator--()
{
    //the first month
    if (arr[0] == 1 && arr[1] == 1)
    {
        arr[0] = 31;
        arr[1] = 12;
        arr[2]--;
    }
    else if(arr[0] == 1)
    {
        //previous month has 28 days
        if(arr[1] == 3)
        {
            arr[0] = 28;
        }

        //previous month has 30 days
        if(arr[1] == 5 || arr[1] == 7 || arr[1] == 10 || arr[1] == 12)
        {
            arr[0] = 30;
        }

        //previous month has 31 days
        if(arr[1] == 2 || arr[1] == 4 || arr[1] == 6 || arr[1] == 8 || arr[1] == 9 || arr[1] == 11)
        {
            arr[0] = 31;
        }

        arr[1]--;
    }
    else
    {
        arr[0]--;
    }
    return *this;
}

//Postfix decrement by 1 day
Date Date::operator--(int dummy)
{
    Date temp = *this;
    //the first month
    if (arr[0] == 1 && arr[1] == 1)
    {
        arr[0] = 31;
        arr[1] = 12;
        arr[2]--;
    }
    else if(arr[0] == 1)
    {
        //previous month has 28 days
        if(arr[1] == 3)
        {
            arr[0] = 28;
        }

        //previous month has 30 days
        if(arr[1] == 5 || arr[1] == 7 || arr[1] == 10 || arr[1] == 12)
        {
            arr[0] = 30;
        }

        //previous month has 31 days
        if(arr[1] == 2 || arr[1] == 4 || arr[1] == 6 || arr[1] == 8 || arr[1] == 9 || arr[1] == 11)
        {
            arr[0] = 31;
        }

        arr[1]--;
    }
    else
    {
        arr[0]--;
    }
    return temp;
}

//Print a Date object
ostream& operator<<(ostream& out, const Date& day)
{
    if (day.get_day() < 10) out << "0";
    out << day.get_day() << ".";
    if (day.get_month() < 10) out << "0";
    out << day.get_month() << ".";
    if (day.get_year() < 10) out << "0";
    out << day.get_year();
    return out;
}

//Read a Date object
istream& operator>>(istream& in, Date& d)
{
    int day;
    int month;
    int year;
    char ch;

    cout << "Write a date:";
    in >> day >> ch >> month >> ch >> year;
    d.set_day(day);
    d.set_month(month);
    d.set_year(year);

    return in;
}
