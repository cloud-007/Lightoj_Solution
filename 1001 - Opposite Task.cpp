#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        int b=0;
        if(a<10)
            cout<<0<<' '<<a<<endl;
        else
        {
            int x=a-(a-10);
            cout<<a-10<<' '<<x<<endl;
        }

    }
    return 0;
}
