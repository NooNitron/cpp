#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ofstream zapis("wyniki.txt");
    int N=0,E=0,Dublony=0,SumM=0,Tortuga=0;
    for(int i=0; i<150 ;i++)
    {
    int zn=0;
    if(i==85)
        cout<<"("<<E<<","<<N<<")"<<endl;
     N+=8;
     E+=11;
     string dlN =to_string(N);

    if (i==3 || i==34 || i==64 || i==95 || i==126)
        zn+=2;

    zn+=dlN.length();
    Dublony+=zn;
    E=E-zn;
    SumM+=zn;
    if(i%7==0)
    {

        Tortuga=Tortuga+floor(Dublony*0.1);
        Dublony=floor(Dublony*0.9);

    }


    }
    zapis.close();
    SumM+=8*150+11*150;
    cout<<SumM<<endl;
    cout<<Tortuga<<endl;

    return 0;
}
