#include<bits/stdc++.h>
using namespace std;
#define pi 2*acos(0.0)
int main()
{
    int n,casee=1;
    cin>>n;
    while(n--)
    {
        double a;
        cin>>a;
        double b=a*2;
        double ans=pi*a*a;
        double abs1=b*b;
        printf("Case %d: %.2f\n",casee,(abs1-ans)+pow(10,-9));
        casee++;
    }
}
