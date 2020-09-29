#include<iostream>
#include<fstream>
using namespace std;
class password{
    public:
    int pass;

};


int main()
{
    password obj;
    fstream stream;
    stream.open("password.dat",ios::in|ios::binary);
    
    
    while(stream.write(reinterpret_cast<char *> (&obj),sizeof(password)))
    {
        cout<<obj.pass;
    }

    stream.close();
}