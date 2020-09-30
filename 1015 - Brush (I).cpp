#include<iostream>
using namespace std;


int main()
{
    int n,casee=1;
    cin>>n;
    int ans[n],j=0;
    while(n--)
    {
        int x;
        cin>>x;
        int sum=0,a[x];
        for(int i=0; i<x; i++)
        {
            cin>>a[i];
            if(a[i]<0)
                sum+=0;
            else
                sum+=a[i];
        }
        ans[j]=sum;j++;
    }
    for(int i=0;i<j;i++)
    {
        cout<<"Case "<<casee<<": "<<ans[i]<<endl;
        casee++;
    }
}
