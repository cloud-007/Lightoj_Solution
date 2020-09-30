#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc,sz=100050,casee=1;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        queue< int > p,q;
        vector < int > x[sz];
        bool fl=true;
        int st;
        set < int > s;
        for(int i=0; i<n; i++)
        {
            int u,v;
            cin>>u>>v;
            x[u].push_back(v);
            x[v].push_back(u);
            if(fl)
            {
                st=u;
                fl=false;
            }
            s.insert(u);
            s.insert(v);
        }
        fl=true;
        int fin=0;int vis[sz];
        memset(vis, 0, sizeof vis);
        for(auto i : s)
        {
            int res=0,ans=0;
            if(!vis[i])
            {
                q.push(i);
                vis[i]=1;
                while(!q.empty() || !p.empty())
                {
                    if(fl)
                    {
                        ans+=q.size();
                        while(!q.empty())
                        {
                            for(auto i : x[q.front()])
                            {
                                if(!vis[i])
                                    p.push(i);
                                vis[i]=1;
                            }
                            q.pop();
                        }
                        fl=false;
                    }
                    else
                    {
                        res+=p.size();
                        while(!p.empty())
                        {
                            for(auto i : x[p.front()])
                            {
                                if(!vis[i])
                                    q.push(i);
                                vis[i]=1;
                            }
                            p.pop();
                        }
                        fl=true;
                    }
                }
            }
            fin+=max(res,ans);
        }
        printf("Case %d: %d\n",casee++,fin);
    }
}
