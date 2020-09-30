#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,casee=1;
    cin>>n;
    while(n--)
    {
        int x,flag=0,sum=0;
        cin>>x;
        while(x--)
        {
            int z;
            string a;
            cin>>a;
            if(a=="donate")
            {
                cin>>z;
                sum+=z;
            }
            else if(a=="report" && flag==0)
            {
                cout<<"Case "<<casee<<":"<<endl<<sum<<endl;
                flag++;
                casee++;
            }
            else if(a=="report" && flag==1)
                cout<<sum<<endl;
        }
    }
}
