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
    string name;

public:
    Video(string name)
    {
        this->name = name;
        likes = dislikes = 0;
    }

    void info()
    {
        cout << "\nName:" << name << "\n";
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

int main()
{
    Video v1("Cat Video");
    v1.info();
    v1.like();
    v1.like();
    v1.like();
    v1.dislike();
    v1.dislike();
    v1.info();

    return 0;
}