#include <string>
#include <vector>

using namespace std;

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
    // virtual void print();
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
    // virtual void print();
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

class Trackpoint : public Position
{
private:
    int time;

public:
    Trackpoint();
    Trackpoint(double alt, double lon, double lat, int t);
    Trackpoint(const Trackpoint &trackpoint);
    virtual ~Trackpoint();
    int getTime();
    void setTime(int t);
    // virtual void print();
};

Trackpoint::Trackpoint() {}

Trackpoint::Trackpoint(double alt, double lon, double lat, int t) : Position(alt, lon, lat), time(t) {}

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

class Track
{
private:
    vector<Trackpoint> trackpoints;

public:
    Track();
    // Track(vector<Trackpoint> points);
    // Track(const Track &t);
    virtual ~Track();
    // vector<Trackpoint> getTrackpoints();
    // void setTrackpoints(vector<Trackpoint>)
    // virtual void print();
    // virtual void append();
    // virtual double averageAltitude();
    // virtual void read();
    // virtual void write();
};

Track::Track() {}

Track::~Track() {}

// To-Do
// - Add Getter,Setter,Copy-Constructor and constructor for Track-Class
// - Add Implementation for print methods
// - Add Implementation for other Track-methods
// - Add main loop
// - Clean

int main(int argc, char *argv[])
{
    Waypoint w1(100, 20, 30, "Hallo");
    Waypoint w2(200, -20, 1.5, "Im new");
    Waypoint w3(w2);

    return 0;
}
