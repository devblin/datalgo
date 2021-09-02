#include <iostream>
#include <list>
using namespace std;

class Youtube
{
public:
    //attributes (by default private, made public using 'public' keyword)
    string name, owner;
    int subscriberCount;
    list<string> videoTitles;

    //constructor (invoked when class instance created)
    Youtube(string name = "", string owner = "")
    {
        this->name = name;
        this->owner = owner;
        subscriberCount = 0;
    }

    //class method
    void info()
    {
        cout << "\nName:" << name << "\n";
        cout << "Owner:" << owner << "\n";
        cout << "Subscribers:" << subscriberCount << "\n";
        cout << "Videos: ";
        for (auto a : videoTitles)
            cout << a << ", ";
        cout << "\n";
    }
};

int main()
{
    Youtube a;
    Youtube b("BB", "Beep");

    a.name = "DD";
    a.owner = "Deep";
    a.subscriberCount = 1000;
    a.videoTitles = {"A video", "B video", "C video"};

    a.info();
    b.info();

    return 0;
}