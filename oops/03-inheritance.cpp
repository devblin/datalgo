#include <iostream>
using namespace std;

class Video
{
private:
    /*
    Attributes should be inaccessible outside class as per encapsulation concept,
    instead provide getter and setter methods to the user for manipulating private attributes
*/
    int likes, dislikes;
    string type;

protected:
    string name;

public:
    Video(string name, string type = "")
    {
        this->name = name;
        this->type = type;
        likes = dislikes = 0;
    }
    void info()
    {
        cout << "\nType:" << type << "\n";
        cout << "Name:" << name << "\n";
        cout << "Likes:" << likes << ", "
             << "Dislikes:" << dislikes << "\n";
    }
    void like()
    {
        likes++;
    }
    void dislike()
    {
        dislikes++;
    }
};
/*
This derived class inherits only public methods
*/
class CatVideo : public Video
{
private:
    string catVar = "Attribute not accessible by base class (only Cat)\n";

public:
    CatVideo(string name, string type = "Cat") : Video(name, type)
    {
    }

    void cat()
    {
        /*
        Protected attributes are accessible by dervied class
        */
        cout << name << ":method not accessible by base class\n";
    }
};

int main()
{
    Video v("Video");
    CatVideo c("Cat Video1");
    CatVideo cc("Cat Video2");

    c.info();
    cc.info();
    v.info();
    c.cat();
    cc.cat();

    return 0;
}