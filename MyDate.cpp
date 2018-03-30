#include "MyDate.h"
#include <sstream>
#include <cmath>
#define SECOND_OF_DAY 86400
using namespace std;

bool isLeapYear(int year){
    if(year>1752&&year%100==0){
        if(year%400==0){
            return true;
        }else{
            return false;
        }
    }else if(year%4==0){
        return true;
    }else{
        return false;
    }
}

int getMonthDay(int month,bool isLeapYear){
    switch(month){
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        return 31;
    case 4:case 6:case 9:case 11:
        return 30;
    case 2:
        if(isLeapYear)return 29;
        else return 28;
    }

}

bool validate(int year ,int month ,int day){
    if(year==1752&&month==9&&day>2&&day<14){
        return false;
    }else if(year>=-9998&&year<=9999&&month>=1&&month<=12&&day>=1&&day<=getMonthDay(month,isLeapYear(year))){
        return true;
    }else{
        return false;
    }
}



int getYearDay(int year){
    if(isLeapYear(year)) return 366;
    else return 365;
}

int getDays(int year,int month,int day){
    long days = 0;
    if(year>1970){
        for(int y=1970;y<year;++y){
            days=days+getYearDay(y);
        }
    }else{
        for(int y=1969;y>=year;--y){
            days=days-getYearDay(y);
        }
    }
    for(int m = 1;m<month;++m){
        days=days+getMonthDay(m,isLeapYear(year));
    }
    days =days+day-1;
    if(year==1752){
        if(month==9){
            if(day<14){
                days+=11;
            }
        }else if(month<9){
            days+=11;
        }
    }else if(year<1752){
        days+=11;
    }
    return days;
}

void getDate(int& year,int& month,int&day,long days){
    int daysOfYear;
    if(days>=0){
        year=1970;
        daysOfYear=getYearDay(year);
        while(days>=daysOfYear){
            year++;
            days-=daysOfYear;
            daysOfYear=getYearDay(year);
        }
        }else{
            if(days<getDays(1752,9,14)){
                days-=11;
            }
            year=1970;
            while(days<0){
                year--;
                daysOfYear=getYearDay(year);
                days+=daysOfYear;

            }
        }
        month = 1;
        days++;
        for(int m=1;m<=12;++m){
            int daysOfMonth = getMonthDay(m,isLeapYear(year));
            if(days>daysOfMonth){
                days-=daysOfMonth;
                month++;
            }else{
                break;
            }
        }
        day=days;
    }

MyDate::MyDate(long long i){
    days = i/SECOND_OF_DAY;
    if(days<-4371596||days>2932896){
        days=0;
    }
} //seconds since UNIX epoch

MyDate::MyDate(int x,int y,int z){
    if(validate(x,y,z)){
        days = getDays(x,y,z);
    }else{
        days = 0;
    }
}

MyDate MyDate::add(int i) const{
    return MyDate((i+days)*86400LL);//转换成秒创建新的对象。
}

MyDate MyDate::subtract(int i) const{
    return MyDate((days-i)*86400LL);//转换成秒创建新的对象。
}

int MyDate::subtract(const MyDate& date ) const{
    return (this->days - date.days);//返回天数
}

bool MyDate::equals(const MyDate& date) const{
    return this->days==date.days;//对天数进行一个判断,下同
}

bool MyDate::lessThan(const MyDate& date) const{
    return this->days<date.days;
}

bool MyDate::lessThanOrEquals(const MyDate& date) const{
    return this->days<=date.days;
}

bool MyDate::greaterThan(const MyDate& date) const{
    return this->days>date.days;
}

bool MyDate::greaterThanOrEquals(const MyDate& date) const{
    return this->days>=date.days;
}

bool MyDate::operator<(const MyDate& dt) const{
    return MyDate::lessThan(dt);
}
bool MyDate::operator<=(const MyDate& dt) const{
    return MyDate::lessThanOrEquals(dt);
}
bool MyDate::operator>(const MyDate& dt) const{
    return MyDate::greaterThan(dt);
}
bool MyDate::operator==(const MyDate& dt) const{
    return MyDate::equals(dt);
}
MyDate MyDate::operator+(int days) const{
    return MyDate::add(days);
}
MyDate MyDate::operator-(int days) const{
    return MyDate::subtract(days);
}
int MyDate::operator-(const MyDate& dt) const{
    return MyDate::subtract(dt);
}
std::string MyDate::toString() const{
    int year ,month,day=0;
    getDate(year,month,day,this->days);
    std::stringstream c;
    if(year<0){
        c<<"-";
        year=abs(year);
    }
    if(year>=-999&&year<=999){
        c<<"0";
        if(year>=-99&&year<=99){
            c<<"0";
            if(year>=-9&&year<=9){
                c<<"0";
            }
        }
    }
        c<<year;
        c<<"-";
        if(month<10){
            c<<"0";
        }
        c<<month;
        c<<"-";
        if(day<10){
            c<<"0";
        }
        c<<day;
        string d = c.str();
        return d;
}

std::ostream& operator<<(std::ostream& os,const MyDate& dt){
    os<<dt.toString();
    return os;
}

int MyDate::getWeekday() const{
    int weekday = (days-3)%7;
    if(weekday>0){
        return weekday;
    }else if(weekday==0){
        return 7;
    }else{
        return weekday+7;
    }
}



