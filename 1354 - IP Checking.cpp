#include<bits/stdc++.h>
using namespace std;

int btod(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}
int main()
{
    int n,casee=1;
    cin>>n;
    while(n--)
    {
        int a,b,c,d;
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        int w,x,y,z;
        scanf("%d.%d.%d.%d",&w,&x,&y,&z);
        if(a==btod(w) && b==btod(x) && c==btod(y) && d==btod(z))
            cout<<"Case "<<casee<<": Yes"<<endl;
        else
            cout<<"Case "<<casee<<": No"<<endl;

        casee++;
    }
    return 0;
}
