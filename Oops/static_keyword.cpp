#include <iostream>
using namespace std;

class parent{
    public:

    // can't do this
    // static string name = "my name";
    static string name;
    static string otherName;
    string childName;

    parent(string name, string cName){
        this->name = name;
        this->childName = cName;
    }

    // can not access unstatic
    // static void sayHello(){
    //     cout << "Hello, my name is " + name << " and childName is " <<childName << endl;
    // }

    static void sayHello(){
        cout << "Hello, my name is " + name << endl;
    }
};

string parent::otherName = "other name";

// this line is necessary to run
string parent::name = "my name";

int main(){
    parent par("lokesh", "satish");
    par.sayHello();
    parent::sayHello();
}