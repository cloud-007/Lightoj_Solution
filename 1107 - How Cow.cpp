#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,casee=1;
    cin>>n;
    while(n--)
    {
        int a,b,c,d;
        printf("Case %d:\n",casee++);
        cin>>a>>b>>c>>d;
        int x;
        cin>>x;
        while(x--)
        {
            int y,z;
            bool flag=false;
            cin>>y>>z;
            if(y>=a && y <=c && z>=b && z<=d)
                flag=true;
            if(flag)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
}
