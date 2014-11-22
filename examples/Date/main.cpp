#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    Date a,b(1,1,5),c("5.8.1998"),d("11.23.1897"),e("11.11.junk"), millenium("1.1.2001"), now("21.11.2014"), then("26.12.1985"), last("31.12.9999");
    cout << a.getDayNumber() << " should be 0\n";
    cout << b.getDayNumber() << " should be 1461\n";
    cout << millenium.getDayNumber() << " should be 730485\n";
    int days = now.getDayNumber();
    cout << "translating 21.11.2014 to days -> " << days << "\n";
    e.setDayNumber(days);
    cout << e.getDay() <<'.' <<e.getMonth()<< '.' <<e.getYear() <<  " should be 21.11.2014\n" ;
    cout << "I'm "<<(now-then)<<" days old now!" << endl;

    // "Супертэставанне" - правяраем адпаведнасць пераўтварээняў ва ўсіх разумных выпадках
    for (int i=0;i<last.getDayNumber();i++) {
        e.setDayNumber(i);
        int ii = e.getDayNumber();
        if (i!= ii) {
            cout << "failed on day " << i << " got " << ii<<  " on " << e.getDay() <<'.' <<e.getMonth()<< '.' <<e.getYear()  << "\n";
        }
    }

    e.setDayNumber(1461); // 1.1.5
    e-=2;
    cout  << e.getDay() <<'.' <<e.getMonth()<< '.' <<e.getYear()  << " should be 30.12.4\n";


    return 0;
}
