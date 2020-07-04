#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

void split(const string &s, vector<string> &container, char delimiter = ' ')
{
    size_t current, previous = 0;
    current = s.find(delimiter);
    while (current != std::string::npos)
    {
        container.push_back(s.substr(previous, current - previous));
        previous = current + 1;
        current = s.find(delimiter, previous);
    }
    container.push_back(s.substr(previous, current - previous));
}

time_t convertTime(int time1980)
{
    const int DIFFERENCE = 315878400;

    time_t date(time1980 + DIFFERENCE);

    return date;
}

class Position
{
protected:
    double altitude;
    double longitude;
    double latitude;

public:
    Position();
    Position(double alt, double lon, double lat);
    Position(const Position &pos);
    virtual ~Position();
    double getAltitude();
    void setAltitude(int alt);
    double getLongitude();
    void setLongitude(int lon);
    double getLatitude();
    void setLatitude(int lat);
    virtual void print();
};

Position::Position() {}

Position::Position(double alt, double lon, double lat) : altitude(alt), longitude(lon), latitude(lat) {}

Position::Position(const Position &pos)
{
    altitude = pos.altitude;
    longitude = pos.longitude;
    latitude = pos.latitude;
}

Position::~Position() {}

double Position::getAltitude()
{
    return altitude;
}

void Position::setAltitude(int alt)
{
    altitude = alt;
}

double Position::getLongitude()
{
    return longitude;
}

void Position::setLongitude(int lon)
{
    longitude = lon;
}

double Position::getLatitude()
{
    return latitude;
}

void Position::setLatitude(int lat)
{
    latitude = lat;
}

void Position::print()
{
    cout << "Höhe: " << altitude << " Laengengrad: " << longitude << " Breitengrad: " << latitude << endl;
}

class Waypoint : public Position
{
private:
    string name;

public:
    Waypoint();
    Waypoint(double alt, double lon, double lat, string s);
    Waypoint(const Waypoint &waypoint);
    virtual ~Waypoint();
    string getName();
    void setName(string s);
    virtual void print();
};

Waypoint::Waypoint() {}

Waypoint::Waypoint(double alt, double lon, double lat, string s) : Position(alt, lon, lat), name(s) {}

Waypoint::Waypoint(const Waypoint &waypoint) : Position(waypoint), name(waypoint.name) {}

Waypoint::~Waypoint() {}

string Waypoint::getName()
{
    return name;
}

void Waypoint::setName(string s)
{
    name = s;
}

void Waypoint::print()
{
    cout << "Höhe: " << altitude << " Laengengrad: " << longitude << " Breitengrad: " << latitude << " Name: " << name << endl;
}

class Trackpoint : public Position
{
private:
    int time;

public:
    Trackpoint();
    Trackpoint(double alt, double lon, double lat, int t);
    Trackpoint(const string &line);
    Trackpoint(const Trackpoint &trackpoint);
    virtual ~Trackpoint();
    int getTime();
    void setTime(int t);
    virtual void print();
};

Trackpoint::Trackpoint() {}

Trackpoint::Trackpoint(double alt, double lon, double lat, int t) : Position(alt, lon, lat), time(t) {}

Trackpoint::Trackpoint(const string &line)
{
    vector<string> properties;

    split(line, properties);

    altitude = stod(properties[2]);
    longitude = stod(properties[1]);
    latitude = stod(properties[0]);
    time = stoi(properties[3]);
}

Trackpoint::Trackpoint(const Trackpoint &trackpoint) : Position(trackpoint), time(trackpoint.time) {}

Trackpoint::~Trackpoint() {}

int Trackpoint::getTime()
{
    return time;
}

void Trackpoint::setTime(int t)
{
    time = t;
}

void Trackpoint::print()
{
    time_t date = convertTime(time);

    cout << "Höhe: " << altitude << " Laengengrad: " << longitude << " Breitengrad: " << latitude << " Zeitpunkt: " << put_time(gmtime(&date), "%c %Z") << endl;
}

class Track
{
private:
    vector<Trackpoint> trackpoints;

public:
    Track();
    Track(vector<Trackpoint> points);
    Track(const string &fileName);
    Track(const Track &t);
    virtual ~Track();
    vector<Trackpoint> getTrackpoints();
    void setTrackpoints(vector<Trackpoint>);
    virtual void print();
    virtual void append(Trackpoint point);
    virtual double getAverageAltitude();
    virtual void read(const string fileName);
    virtual void write(const string fileName);
};

Track::Track() {}

Track::Track(vector<Trackpoint> points) : trackpoints(points) {}

Track::Track(const string &fileName)
{
    read(fileName);
}

Track::Track(const Track &t) : trackpoints(t.trackpoints) {}

Track::~Track() {}

vector<Trackpoint> Track::getTrackpoints()
{
    return trackpoints;
}

void Track::setTrackpoints(vector<Trackpoint> points)
{
    trackpoints = points;
}

void Track::print()
{
    for (auto &&trackpoint : trackpoints)
    {
        trackpoint.print();
    }
}

void Track::append(Trackpoint point)
{
    trackpoints.push_back(point);
}

double Track::getAverageAltitude()
{
    double altitudeSum = 0;

    for (auto &&trackpoint : trackpoints)
    {
        altitudeSum += trackpoint.getAltitude();
    }

    return altitudeSum / trackpoints.size();
}

void Track::read(const string fileName)
{
    vector<Trackpoint> fileTrackpoints;
    string line;
    ifstream file;

    file.open(fileName);

    while (getline(file, line))
    {
        Trackpoint trackpoint(line);
        fileTrackpoints.push_back(trackpoint);
    }

    trackpoints = fileTrackpoints;
}

void Track::write(const string fileName)
{
    ofstream file;

    file.open(fileName);

    for (auto &&trackpoint : trackpoints)
    {
        file << trackpoint.getLongitude() << " " << trackpoint.getLatitude() << " " << trackpoint.getAltitude() << " " << trackpoint.getTime() << endl;
    }

    file.close()
}

// To-Do
// x Add Getter,Setter,Copy-Constructor and constructor for Track-Class
// x Add Implementation for print methods
// x Add Implementation for other Track-methods
// x Get track property time to work
// - Add main loop
// - Change to latitude, longitude, altitude constructors
// - Clean

int main(int argc, char *argv[])
{
    Waypoint wp1(100, 20, 30, "Hallo");
    Waypoint wp2(200, -20, 1.5, "Im new");
    Waypoint wp3(wp2);

    Trackpoint tp1(30, 30, 300, 400);
    Trackpoint tp2(20, 20, 200, 300);

    Track t1("exercise-7\\bin\\track.txt");

    t1.append(tp1);
    t1.append(tp2);

    time_t testDate = convertTime(t1.getTrackpoints()[0].getTime());
    time_t testDate2 = convertTime(0);

    cout << put_time(gmtime(&testDate), "%c %Z") << endl;
    cout << put_time(gmtime(&testDate2), "%c %Z") << endl;
    cout << put_time(gmtime(&testDate2), "%c %Z") << endl;

    t1.write("track_updated.txt");

    return 0;
}
