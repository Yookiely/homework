#include <iostream>
#include  "MyDate.h"
using namespace std;

// => �����е����

int main()
{
    MyDate d0(0);
    //��������0������1970-01-01����������
    cout << d0.toString()  << endl;  // => 1970-01-01
    cout << d0.add(1).toString()  << endl;  // => 1970-01-02
    cout << d0.add(364).toString()  << endl;  // => 1970-12-31
    cout << d0.add(365).toString()  << endl;  // => 1971-01-01
    cout << d0.subtract(1).toString()  << endl;  // => 1969-12-31
    cout << d0.subtract(365).toString()  << endl;  // => 1969-01-01
    cout << d0.subtract(366).toString()  << endl;  // => 1968-12-31
    cout << (d0.subtract(1).equals(d0.add(-1)) ? "equal":"not equal" ) << endl; // => equal
    cout << (d0.subtract(-1).equals(d0.add(1)) ? "equal":"not equal" ) << endl; // => equal
    //��������1��2017-03-01
    MyDate d1(17226*60*60*24LL);
    cout << d1.toString()  << endl;  // => 2017-03-01
    cout << d1.add(7).toString() << endl; // => 2017-03-08
     //��������2��2050-01-01�������Ƿ�֧��2038��֮��
    MyDate d2(2100,1,1);
    cout << d2.subtract(d0) << endl;  // => 47482
    cout << d2.add(365).toString() <<endl; //=>2101-01-01

    return 0;
}
