#ifndef MYDATE_H
#define MYDATE_H
#include <iostream>
using namespace std;

class MyDate
{
public:
	MyDate(long long); //seconds since UNIX epoch
	MyDate(int,int,int);  //year,month,day
	MyDate add(int) const;
	MyDate subtract(int) const;
	int subtract(const MyDate&) const;
	bool equals(const MyDate&) const;
	bool lessThan(const MyDate&) const;
	bool lessThanOrEquals(const MyDate&) const;
	bool greaterThan(const MyDate&) const;
	bool greaterThanOrEquals(const MyDate&) const;
	string toString() const;
private:
    int year = 1970;
    int month = 1;
    int day = 1;
    int days = 0;
    int theDateCount(int ,int ,int) const;
    int monthNumber(int,int) const;
    string myToString(int , int,int ,int ) const;
};

#endif // MYDATE_H
