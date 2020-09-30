#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,casee=1;
    cin>>n;
    getchar();
    while(n--)
    {
        string a,b;
        getline(cin,a);
        getline(cin,b);
        for(int i=0;i<a.length();i++)
        {
            if(a[i]>='A' && a[i]<='Z')
                a[i]=tolower(a[i]);
        }
        for(int i=0;i<b.length();i++)
        {
            if(b[i]>='A' && b[i]<='Z')
                b[i]=tolower(b[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        string c,d;
        for(int i=0;i<a.length();i++)
            {
                if(a[i] != ' ')
                    c+=a[i];
            }
        for(int i=0;i<b.length();i++)
            {
                if(b[i] != ' ')
                    d+=b[i];
            }
        if(c==d)
            cout<<"Case "<<casee<<": Yes"<<endl;
        else
            cout<<"Case "<<casee<<": No"<<endl;

        casee++;


    }
}
