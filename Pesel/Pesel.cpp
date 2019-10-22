#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include<stdio.h>
#include <iomanip>
using namespace std;


int main()
{
    int iloczyny[10] = {1,3,7,9,1,3,7,9,1,3};
    int L,W,maxL,maxW;
    maxL =0;
    string niepop[150];
    int grudzien,liczbakobiet,n,m;
    n=0;
    m=0;
    int j=0;
    int spraw,suma,sprawk;
    grudzien=0;
    liczbakobiet=0;
    int rok[101];
    int Pesel[11];
   fstream plik;
    string stringrok;
   plik.open("pesel.txt",ios::in);
if(plik.good()==false)
    exit(0);
   string linia;
   while (getline(plik,linia))
   {
        if((linia[2]=='1') && (linia[3]=='2'))
            grudzien++;
        j=atoi(linia.c_str());
        if(((j%10)%2)==0)
            liczbakobiet++;
        stringrok= linia[0];
        string dod;
        dod=linia[1];
        stringrok.insert(1, dod);
        j=atoi(stringrok.c_str());
        rok[n]=j;
        niepop[n]=atoi(linia.c_str());

    for(int i=0; i<10;i++)
    {
    dod =linia[i];
    spraw=atoi(dod.c_str());
    suma=suma+spraw*iloczyny[i];
    }
    suma=suma%10;
    dod=linia[10];
    sprawk=atoi(dod.c_str());
    if((10-sprawk)==suma)
    {
        niepop[m]=linia;
         cout<<niepop[m]<<endl;
        m++;
    }
        n++;
   }
  for(int i = 0; i < 150; i++)
  {
    W = rok[i]; L = 0;
    for(int k = 0; k < 150; k++)
    if(rok[k] == W) L++;
    if(L > maxL)
    {
      maxL = L; maxW = W;
    }
  }
cout<<maxW<< endl;
cout<<grudzien<<endl;
cout<<liczbakobiet<<endl;

}
