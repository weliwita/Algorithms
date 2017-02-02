
#include<iostream>
using namespace std;

struct fraction{
    int nom;
    int denom;
};


int main()
{

    fraction s;
    s.nom = 9;
    s.denom = 10;

    int i =((fraction*)&(s.denom))->nom;
    int j = ((fraction*)&(s.denom))->denom;
    
    cout << i << endl << j <<  endl;
    return 0;
}