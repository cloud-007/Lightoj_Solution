#include<bits/stdc++.h>
using namespace std;
typedef pair < int, int > pi;
typedef long long ll;
typedef pair< ll,ll > pll;
#define Solve_ABC ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pb push_back
#define bug() puts("Debug here")
#define f(n) for(int i=0;i<n;i++)
#define tc() int t;cin>>t;while(t--)

int row,col,casee=1;
int vis[1000],dis[1000];
vector < int > x[1000];
int bfs(int b, int e)
{
    queue< int > q;
    q.push(b);
    vis[b]=1;
    dis[b]=0;
    while(!q.empty())
    {
        int u=q.front();
        for(auto i : x[u])
        {
            if(!vis[i])
            {
                q.push(i);
                dis[i]=dis[u]+1;
                vis[i]=1;
            }
            if(i==e)
                return dis[i];
        }
        q.pop();
    }
    return 0;
}


int main()
{
    Solve_ABC;
    tc()
    {
        cin>>row>>col;
        char a;
        int mp[row+5][col+5];
        int c=1,des;
        vector < int > st;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cin>>a;
                if(a=='a' || a=='b' || a=='c')
                {
                    st.pb(c);
                }
                if(a=='h')
                    des=c;
                if(a!='#' && a!='m')
                    mp[i][j]=c++;
                else if(a=='#' || a=='m')
                    mp[i][j]=0;
            }
        }
        for(int i=1; i<=1000; i++)
            x[i].clear();
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(mp[i][j])
                {
                    if(i!=0)
                    {
                        if(mp[i-1][j])
                        {
                            x[mp[i-1][j]].pb(mp[i][j]);
                        }
                    }
                    if(j!=0)
                    {
                        if(mp[i][j-1])
                        {
                            x[mp[i][j-1]].pb(mp[i][j]);
                        }
                    }
                    if(i!=row-1)
                    {
                        if(mp[i+1][j])
                        {
                            x[mp[i+1][j]].pb(mp[i][j]);
                        }
                    }
                    if(j!=col-1)
                    {
                        if(mp[i][j+1])
                        {
                            x[mp[i][j+1]].pb(mp[i][j]);
                        }
                    }
                }
            }
        }
        int mx=0;
        for(auto i : st)
        {
            memset(vis,0,sizeof vis);
            memset(dis,0,sizeof dis);
            int res=bfs(i,des);
            mx=max(mx,res);
        }
        printf("Case %d: %d\n",casee++,mx);
    }
    return 0;
}
