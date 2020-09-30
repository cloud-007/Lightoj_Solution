#include<iostream>
using namespace std;
int main()
{
    int n,casee=1;
    cin>>n;
    while(n--)
    {
        int x,p,q;
        cin>>x>>p>>q;
        int a[x];
        for(int i=0;i<x;i++)
        {
            cin>>a[i];
        }
        int i=0,count=0,sum=0;
        while(i<x)
        {
            sum+=a[i];
            if(sum>q)
                break;
            count++;
            if(count>=p)
                break;
            i++;
        }
        cout<<"Case "<<casee<<": "<<count<<endl;
        casee++;
    }
}
