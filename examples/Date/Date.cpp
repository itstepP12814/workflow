#include <cstring>
#include "Date.h"

Date::Date(unsigned int day, unsigned int month, unsigned int year)
    : daysInMonth{31,28,31,30,31,30,31,31,30,31,30,31},  y(year), m(month), d(day) {
    daysFromYearStart[0]=0;
    // наогул, гэты цыкл трэба зрабіць толькі аднойчы, але гэта можно рэалізаваць толькі з дапамогай статычных метадаў, якія мы яшчэ не праходзілі.
    for(int i=1;i<12;i++) {
        daysFromYearStart[i] = daysFromYearStart[i-1] + daysInMonth[i-1];
    }
};

Date::Date(const char * str) : Date(1,1,1) {
    int res = sscanf(str,"%d.%d.%d",&d,&m,&y);
    if ( (res == 0) || (d<1) || (d>31) ) {
        reportError("Invalid day number\n");
    }
    if ( (res == 1) || (m<1) || (m>12) ) {
        reportError("Invalid month number\n");
    }
    if ( (res == 2) || (y<1) || (y>9999) ) {
        reportError("Invalid year number\n");
    }
}

int Date::getDayNumber() const {
    int days = (y-1)*365; // колькасць дзён у гадах з 0001 да у-1 з улікам толькі невісакосных
    days += (y-1)/4; // улічваем Юліанскія вісакосныя
    days -= (y-1)/100; // і Грэгар'янскія
    days += (y-1)/400;
    if (m>2) {
        days += isLeap(y); // калі цякучы год вісакосны, а люты ўжо мінуў, дадаем яшчэ дзень
    }
    days += daysFromYearStart[m-1];
    days += d-1;
    return days;
}

Date& Date::setDayNumber(int days) {
    // спачатку год
    y = days*400/146097 + 1; // /365.2524

    // зараз у "у" прыблiзны нумар года
    // адымаем ад days дакладную колькасць дзён у мінулых гадах
    days -= (y-1)*365+(y-1)/4 - (y-1)/100 + (y-1)/400;

    // калі days атрымался больш чым магчыма у адпаведным годзе
    if (days>=365+isLeap(y)) {  // памылка акруглення - нумар года меньш чым трэба
        days -= 365+isLeap(y);
        y++;
    }

    // калі days больш за колькасць дзён у адпаведным месяцы (з улікам магчымасці 29 лютага) - адымаем гэту колькасць і павялічваем нумар месяца
    m=0;
    while (days >= (daysInMonth[m] +isLeap(y) *(m==1))  ) {
        days -= (daysInMonth[m] +isLeap(y) *(m==1));
        m++;
    }
    m++;

    // засталася колькасць дзён ад першага дня месяца
    d=days+1;

    return *this;
}
