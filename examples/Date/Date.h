#ifndef DATE_H
#define DATE_H

#include <cstdio>

// вызначае, ці будзе год вісакосны ў Грыгар'янскім календары
inline int isLeap(const int year) {
    if (year % 100 == 0) { // кожны 100 - не вісакосны
        return (year % 400 == 0); // але кожны 400 - вісакосны
    } else {
        return (year % 4 == 0); // у астатніх выпадках - кожны 4 - вісакосны
    }
}

class Date
{
    public:
        const int daysInMonth[12];
        int daysFromYearStart[12]; // колькасць дзён з пачатку года да пачатку месяца
        Date() : Date(1,1,1) {}; // па змоўчанню - 1 студзеня 1 года
        Date(unsigned int day, unsigned int month, unsigned int year) ;
        // задаць дату праз радок "DD.MM.YYYY"
        Date(const char * str);
        unsigned int getDay() {return d;};
        unsigned int getMonth() {return m;};
        unsigned int getYear() {return y;};
        int getDayNumber() const;  // вяртае нумар дня з пачатку 1 тысячагодзя
        int operator-(const Date &what) const {return getDayNumber() - what.getDayNumber();}; // вяртае розніцу паміж датамі ў днях
        Date& setDayNumber(int days); // задае дату праз нумар дня з пачатку 1 тысячагодзя
        Date& operator+=(int days) { return setDayNumber(getDayNumber()+days); }; // дадае days дзён да даты
        Date operator+(int days) const { Date tmp(*this); return tmp+=days;}; // дадае days дзён да даты
        Date& operator-=(int days) { return setDayNumber(getDayNumber()-days); }; // адымае days дзён ад даты
        Date operator-(int days) const { Date tmp(*this); return tmp-=days;}; // адымае days дзён ад даты
    protected:
        unsigned int y;
        unsigned int m;
        unsigned int d;
    private:
        void reportError(const char* error) { puts(error); y=1; d=1; m=1; }
};

#endif // DATE_H
