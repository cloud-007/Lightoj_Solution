#include<bits/stdc++.h>
using namespace std;
long long int a[1000000];
const int mod=1000003;
void fac()
{
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        a[i]+=a[i-1]*i;
        a[i]=a[i]%mod;
    }
    //for(auto i:a)
    //cout<<i<<' ';
}
long long int bigmod(long long int a,long long int b,long long int m){
    if(b==0)return 1;
    long long int x=bigmod(a,b/2,m)%m;
    x=(x%m * x%m)%m;
    if(b&1)
        x=(a%m)*(x%m);
    return x;
}

int main()
{
    fac();
    int n,casee=1;
    cin>>n;
    while(n--)
    {
        int n,r;
        cin>>n>>r;
        long long int x=(a[r]%mod *a[n-r]%mod)%mod;
        x=bigmod(x,1000001,mod)%mod;
        long long ans=(a[n]%mod *x%mod)%mod;
        printf("Case %d: %d\n",casee++,ans);
    }
}
