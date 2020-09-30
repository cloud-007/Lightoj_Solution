#include<iostream>
using namespace std;
int main()
{
    int n,casee=1;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        int sum=0;
            sum+=(abs(a-b)*4);
            sum+=(a*4);
            sum+=10;
            sum+=9;
        cout<<"Case "<<casee<<": "<<sum<<endl;casee++;
    }
}
