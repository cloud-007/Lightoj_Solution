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
int vis[1000];
vector < int > x[1000];
int res=0;
void dfs(int u)
{
    if(vis[u])
        return;
    vis[u]=1;
    res++;
    for(auto i : x[u])
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }

}


int main()
{
    Solve_ABC;
    tc()
    {
        cin>>col>>row;
        int st;
        char a;
        int mp[row+5][col+5];
        int c=1;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                cin>>a;
                if(a=='@')
                    st=c;
                if(a!='#')
                    mp[i][j]=c++;
                else
                    mp[i][j]=0;
            }
        }
        for(int i=1;i<=1000;i++)
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
        res=0;
        memset(vis,0,sizeof vis);
        dfs(st);
        printf("Case %d: %d\n",casee++,res);
    }
    return 0;
}
