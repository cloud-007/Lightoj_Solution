#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,casee=1;
    cin>>n;
    while(n--)
    {
        printf("Case %d:\n",casee++);
        vector <string >v;
        v.push_back("http://www.lightoj.com/");
        int flag=0,cur=0;
        while(true)
        {
            string s;
            cin>>s;
            if(s=="QUIT")
                break;
            else if(s=="BACK")
            {
                cur--;
                if(cur<0)
                {
                    cout<<"Ignored"<<endl;
                    cur++;
                }
                else
                {
                    cout<<v[cur]<<endl;
                }
            }
            else if(s=="FORWARD")
            {
                cur++;
                if(cur<=flag)
                    cout<<v[cur]<<endl;
                else
                {
                    cout<<"Ignored"<<endl;
                    cur--;
                }
            }
            else if(s=="VISIT")
            {
                flag++;
                cur++;
                string a;
                    cin>>a;
                cout<<a<<endl;
                if(cur==flag)
                {
                    v.push_back(a);
                }
                else if(cur<flag)
                {
                    while(flag!=cur)
                    {
                        //cout<<cur<<' '<<flag<<endl;
                        flag--;
                        v.pop_back();
                    }
                    cur=flag;
                    v.push_back(a);
                }

            }
        }
    }
}
