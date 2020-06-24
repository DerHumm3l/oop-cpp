#include <iostream>

using namespace std;
class Time
{
private:
    int minutes;

public:
    Time();
    Time(int m);
    Time(int m, int h);
    Time(const Time &t);
    virtual ~Time();
    virtual void set(int h, int m);
    virtual void get(int &h, int &m) const;
    virtual void inc();
};

Time::Time() : minutes(0)
{
    cout << "Standard-Konstruktor" << endl;
}

Time::Time(int m) : minutes(m)
{
    cout << "Konstruktor mit Minuten" << endl;
}

Time::Time(int m, int h) : minutes(m + 60 * h)
{
    cout << "Konstruktor mit Stunden und Minuten" << endl;
}

Time::Time(const Time &t) : minutes(t.minutes)
{
    cout << "Kopier-Konstruktor" << endl;
}

Time::~Time()
{
    cout << "Virtual Destruktor" << endl;
}

void Time::inc()
{
    minutes++;
}

void Time::set(int h, int m)
{
    minutes = h * 60 + m;
}

void Time::get(int &h, int &m) const
{
    h = minutes / 60;
    m = minutes % 60;
}

void print(Time t)
{
    int h, m;
    t.get(h, m);
    cout << h << ":" << m << endl;
}

Time input()
{
    Time result;
    int h, m;
    cout << "Uhrzeit eingeben - Stunde: ";
    cin >> h;
    cout << "                   Minute: ";
    cin >> m;
    result.set(h, m);
    return result;
}

int main(int argc, char *argv[])
{
    // Normaler Aufruf Konstruktor mit Stunden und Minuten, so wie oben definiert
    Time t1(10, 10);

    // Aufruf Standard-Konstruktor, so wie oben definiert
    Time t2;

    // Aufruf Standard-Konstruktor für temporäres Objekt "result" in Funktion "input()"
    // Dann Aufruf Kopier-Konstruktor, weil "result" "t2" zugewiesen wird
    // Anschließend doppelter Aufruf für Destruktor,
    // weil "result" und eben angelegte Kopier-Konstruktor-Objekt wieder freigegeben werden
    t2 = input();
    t2.inc();

    // Aufruf Kopier-Konstruktor, weil "t2" in Parameter "t" der Funktion "print()" kopiert wird
    // Anschließend Aufruf des Destruktors für Parameter "t"
    print(t2);

    // Durch "Konstruktor mit Minuten" impliziter Typecast von int -> Time, dadurch auch Aufruf
    // von "Konstruktor mit Minuten"
    // Anschließend Aufruf des Destruktors für Parameter "t"
    print(1234);

    return 0;
}