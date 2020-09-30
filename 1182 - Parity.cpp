#include<iostream>
#include<vector>
using namespace std;

bool dtob(long long int n)
{
    int i,count=0;
    vector<int>a;
    for(i=0; n>0; i++)
    {
        a.push_back(n%2);
        n= n/2;
    }
    for(i=0 ; i<a.size() ; i++)
    {
        if(a[i]==1)
            count++;

    }
    if(count%2==0)
        return true;
    else
        return false;
}

int main()
{
    int n,casee=1;
    cin>>n;
    while(n--)
    {
        long long int a;
        cin>>a;
        if(dtob(a))
            cout<<"Case "<<casee<<": even"<<endl;
        else
            cout<<"Case "<<casee<<": odd"<<endl;
        casee++;
    }
}
