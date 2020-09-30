#include<iostream>
#include<deque>
using namespace std;
int main()
{
    int x,a,casee=1;
    cin>>x;
    while(x--)
    {
        int n,a,z;
        cin>>n>>a;
        cout<<"Case "<<casee<<":"<<endl;casee++;
        z=0;
        deque<int>v;
        while(a--)
        {
            string s;
            cin>>s;
            if(s=="pushLeft")
            {
                int c;
                cin>>c;
                if(z==n)
                    cout<<"The queue is full"<<endl;
                else
                {
                    z++;
                    v.push_front(c);
                    cout<<"Pushed in left: "<<c<<endl;
                }
            }
            else if(s=="pushRight")
            {
                int c;
                cin>>c;
                if(z==n)
                    cout<<"The queue is full"<<endl;
                else
                {
                    z++;
                    v.push_back(c);
                    cout<<"Pushed in right: "<<c<<endl;
                }
            }
            else if(s=="popLeft")
            {
                if(z==0)
                    cout<<"The queue is empty"<<endl;
                else
                {
                    z--;
                    cout<<"Popped from left: "<<v.front()<<endl;
                    v.pop_front();
                }
            }
            else if(s=="popRight")
            {
                if(z==0)
                    cout<<"The queue is empty"<<endl;
                else
                {
                    z--;
                     cout<<"Popped from right: "<<v.back()<<endl;
                    v.pop_back();

                }
            }
        }
        v.clear();
    }
}
