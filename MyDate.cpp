#include "MyDate.h"
#include <sstream>
#define EPOCH_YEAR 1970
#define SECOND_OF_DAY 86400
#define PING 365
#define RUN 366
using namespace std;
MyDate::MyDate(long long i){
    days=days+i/SECOND_OF_DAY;//按天储存
}

MyDate::MyDate(int x,int y,int z){
    year=x;
    month=y;
    day=z;
    int numberOfRun =0;
    int numberOfPing = 0;
    int countYear=x-EPOCH_YEAR;
    if(x>1972){
         numberOfRun = (countYear-3)/4+1;
         numberOfPing = countYear - numberOfRun;
    }else{
         numberOfRun = 0;
         numberOfPing = 1;
    }

    days = days+numberOfRun*RUN + numberOfPing*PING;//计算平闰年总天数
    days = days+monthNumber(year,month);
    days = days+z-1;//按天储存
}
MyDate MyDate::add(int i) const{
    return MyDate((days + i)*86400LL);//转换成秒创建新的对象。
}
MyDate MyDate::subtract(int i) const{
    return MyDate((days - i)*86400LL);//转换成秒创建新的对象。
}
int MyDate::subtract(const MyDate& date ) const{
    return (this->days - date.days);//返回天数
}
bool MyDate::equals(const MyDate& date) const{
    if(this->days==date.days)
    {
        return true;
    }else{
        return false;
    }//对天数进行一个判断,下同
}
bool MyDate::lessThan(const MyDate& date) const{
    if(this->days<date.days)
    {
        return true;
    }else{
        return false;
    }
}
bool MyDate::lessThanOrEquals(const MyDate& date) const{
    if(this->days<=date.days)
    {
        return true;
    }else{
        return false;
    }
}
bool MyDate::greaterThan(const MyDate& date) const{
    if(this->days>date.days)
    {
        return true;
    }else{
        return false;
    }
}
bool MyDate::greaterThanOrEquals(const MyDate& date) const{
    if(this->days>=date.days)
    {
        return true;
    }else{
        return false;
    }
}
string MyDate::toString() const
{
    if(year!=1970){
        return myToString(1970,days,1,1);
    }else{
        if(days>0){
            return myToString(year,days,month,day);
        }else{
            int   MyDays = days + 25567;//25567为1900-01-01到1970-01-01天数
            int  MyYear=1900;//当days<0时,转换成正数套入编写的私有函数。
            return myToString(MyYear,MyDays,month,day);
        }
    }
}
int MyDate::monthNumber(int year,int month) const{//私有函数计算由月份转换而来的天数
    int a[13];
    a[0]=0;a[1]=31;a[2]=59;a[3]=90;a[4]=120;a[5]=151;a[6]=181;a[7]=212;a[8]=243;a[9]=273;a[10]=304;a[11]=334;a[12]=365;
    if(((year%100==0&&year%400==0)||(year%100!=0&&year%4==0))&&month>2){
        return a[month-1]+1;
    }else{
        return a[month-1];
    }
}
string MyDate::myToString(int year, int days,int month,int day) const{//为了实现toString写的骚函数。。。。
    int a[13];
    a[0]=0;a[1]=31;a[2]=59;a[3]=90;a[4]=120;a[5]=151;a[6]=181;a[7]=212;a[8]=243;a[9]=273;a[10]=304;a[11]=334;a[12]=365;
    int i =1;
    int myMonth = 1;
    while(i){
        if(((year)%100==0&&(year)%400==0)||((year)%100!=0&&(year)%4==0)){
            if(days>=(a[12]+1)){
                days=days-a[12]-1;
                year++;

            }
            else{i=0;}
        }else{
            if(days>=a[12]){
                days=days-a[12];
                year++;
            }
            else{i=0;}
        }
    }
    for(int i=12;i>1;i--){
        if(year%100==0&&year%400==0){a[i]++;}
        if(year%100!=0&&year%4==0){a[i]++;}
    }
    for(int i=0;i<13;i++){
        if(days<a[i]){
                myMonth=i;
                days=days-a[i-1];
                break;
        }
    }
    day=days+1;
    std::stringstream c;
        c<<year;
        c<<"-";
        if(myMonth<10){
            c<<"0";
        }
        c<<myMonth;
        c<<"-";
        if(day<10){
            c<<"0";
        }
        c<<day;
        string d = c.str();
        return d;
}

