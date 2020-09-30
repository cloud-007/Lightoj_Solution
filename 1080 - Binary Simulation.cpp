#include<bits/stdc++.h>
using namespace std;

const int sz=1e5+50;

struct info{
    int prop,sum;
}tree[sz*3];

void init()
{
    for(int i=0;i<=sz*3;i++)
        tree[i].sum=tree[i].prop=0;
}

void update(int node, int b, int e, int i, int j, int x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main()
{
    int tc,casee=1;
    scanf("%d",&tc);
    while(tc--)
    {
        printf("Case %d:\n",casee++);
        init();
        string s;
        cin>>s;
        int n=s.size();
        int q;
        scanf("%d",&q);
        while(q--)
        {
            char c;
            int l , r;
            while(scanf("%c",&c))
            {
                if(isalpha(c))
                    break;
            }
            if(c=='I')
            {
                scanf("%d%d",&l,&r);
                update(1,1,n,l,r,1);
            }
            else
            {
                scanf("%d",&l);
                int x=query(1,1,n,l,l);
                int y=s[l-1]-'0';
                if(x%2)
                    y^=1;
                printf("%d\n",y);
            }
        }
    }
}
