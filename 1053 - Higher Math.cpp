#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,casee=1;
    cin>>n;
    while(n--)
    {
        int a[3];
        for(int i=0;i<3;i++)
            cin>>a[i];
        sort(a,a+3);
        if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
            cout<<"Case "<<casee<<": yes"<<endl;
        else
            cout<<"Case "<<casee<<": no"<<endl;
            casee++;
    }

}
