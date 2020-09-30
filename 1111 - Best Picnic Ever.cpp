#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int sz=2000;
vector < int > x[sz];
int vis[sz],pos[sz];

void dfs(int u)
{
    if(vis[u])return;
    vis[u]=1;
    for(auto i : x[u])
    {
        if(!vis[i])
            dfs(i);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc,casee=1;
    cin>>tc;
    while(tc--)
    {
        int k , n , m;
        cin >> k >> n >> m;
        vector < int > v(k);
        for( auto & i : v)
            cin>>i;
        for(int i=1;i<=n;i++)
            x[i].clear();
        memset(pos , 0 , sizeof pos);
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            x[u].pb(v);
        }
        int j=1;
        for(auto i : v)
        {
            memset(vis , 0 , sizeof vis);
            dfs(i);
            if(j)
            {
                for(int i=1;i<=n;i++)
                    pos[i]=vis[i];
                j=0;
            }
            else
            {
                for(int i=1;i<=n;i++)
                {
                    if(pos[i]==1 && pos[i]==vis[i])
                        pos[i]=1;
                    else
                        pos[i]=0;
                }
            }
        }
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(pos[i])
                c++;
        }
        cout<<"Case "<<casee++<<": "<<c<<endl;
    }
}
