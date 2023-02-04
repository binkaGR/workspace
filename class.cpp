#include <iostream>
#include <string>
#include <string.h>

using namespace std;

 class Ivan
{
private:
    string name;
 public:
    Ivan(string Name);
    virtual string  Get_Name()
    {
        return name;
    }
    ~Ivan();
};

class BBB: public Ivan
{
 Ivan(name);
 public:
 string name;
 int a;
 BBB();
 virtual string Get_Name()
{
return "sdsds";
}
~BBB();
};

Ivan::Ivan(string Name)
{
    name=Name;
}
//string Get_Name(){
//    return "sdsds";
//}
Ivan::~Ivan()
{
 name.clear();
}

BBB::BBB()
{
    name="sinasa"
}


int main()
{
BBB *bbb = new BBB();
Ivan *ivan = new Ivan("Ivab");
cout<<ivan->Get_Name()<<endl;

//delete ivan;
cout<<bbb->Get_Name()<<endl;
ivan->~Ivan();
}
