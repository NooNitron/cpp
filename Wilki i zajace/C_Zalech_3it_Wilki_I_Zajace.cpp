#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

int main()
{
ofstream zapis("wyniki_wilki.txt");

    double a = 0.02, b = 0.0005, c = 0.05;
    double Z = 100.0, W = 30.0;
for (int n=1; n<=60; n++)
{
      double nZ = Z + a*Z - b*Z*W;
      double nW = W + b*Z*W - c*W;
        Z = nZ;
        W = nW;
}
zapis<<"Liczba zajency po 5 latach: "<<round(Z*100)/100<<endl;
zapis<<"Liczba wilkow po 5 latach: "<<round(W*100)/100<<endl<<endl;


int k=1, odpZ=0, odpW=0;
Z = 100.0, W = 30.0;
while (odpZ==0 || odpW==0)
{
    double nZ = Z + a*Z - b*Z*W;
    double nW = W + b*Z*W - c*W;
    if ( nZ < Z && odpZ == 0 ) odpZ = k;
    if ( nW < W && odpW == 0 ) odpW = k;
    Z = nZ;
    W = nW;
    k++;
}
zapis<<"Iloœæ miesiêcy po ilu liczba zajecy zacznie malec: "<<odpZ<<endl;
zapis<<"Iloœæ miesiêcy po ilu liczba wilkow zacznie malec: "<<odpW<<endl<<endl;

Z = 100.0, W = 30.0;
double minZ, maxZ, minW, maxW;
minZ = maxZ = Z; minW = maxW = W;
for (int n=1; n<=40*12; n++)
{
double nZ = Z + a*Z - b*Z*W;
double nW = W + b*Z*W - c*W;
Z = nZ;
W = nW;
minZ = min( minZ, Z ); maxZ = max( maxZ, Z );
minW = min( minW, W ); maxW = max( maxW, W );
}
cout<<endl;


zapis<<"MIN zajecy: "<<round(minZ*100)/100<<"| MAX zajecy: "<<round(maxZ*100)/100<<endl;
zapis<<"MIN wilkow: "<<round(minW*100)/100<<"| MAX wilkow: "<<round(maxW*100)/100<<endl;

zapis.close();

    return 0;
}
