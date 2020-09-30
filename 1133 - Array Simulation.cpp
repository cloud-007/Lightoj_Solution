#include<iostream>
#include<algorithm>
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
using namespace std;
int main()
{
    long long int n,casee=1;
    cin>>n;
    while(n--)
    {
        int x,b;
        cin>>x>>b;
        long long int a[x];
        for(int i=0; i<x; i++)
            cin>>a[i];
        int len=my_sizeof(a)/my_sizeof(a[0]);
        //cout<<len<<endl;
        for(int i=0; i<b; i++)
        {
            char c;
            cin>>c;
            if(c=='S')
            {
                int d;
                cin>>d;
                for(int i=0; i<len; i++)
                    a[i]+=d;
            }
            else if(c=='M')
            {
                int d;
                cin>>d;
                for(int i=0; i<len; i++)
                    a[i]*=d;
            }
            else if(c=='D')
            {
                int d;
                cin>>d;
                for(int i=0; i<len; i++)
                    a[i]/=d;
            }
            else if(c=='R')
            {
                int start=0,end=len-1;
                //cout<<start<<' '<<end;
                while (start < end)
                {
                    int temp = a[start];
                    a[start] = a[end];
                    a[end] = temp;
                    start++;
                    end--;
                }
            }
            else if(c=='P')
            {
                int t,y;
                cin>>t>>y;
                swap(a[t],a[y]);
            }
        }
        cout<<"Case "<<casee<<":"<<endl;casee++;
        for(int i=0; i<len; i++)
        {
            if(i!=len-1)
                cout<<a[i]<<' ';
            else
                cout<<a[i];
        }
        cout<<endl;

    }

}
