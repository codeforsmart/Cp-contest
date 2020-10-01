#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back

#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
ll n,x;
ll a[100005]={0};
vector<ll> tr[100001];
ll xo[100005]={0};
ll ans[100005][2]={0};
void dfsxx(ll a1,ll p)
{
    xo[a1]=a[a1];

    f(0,tr[a1].size())
    {
        if(tr[a1][i]==p) continue;
        dfsxx(tr[a1][i],a1);

        if(xo[tr[a1][i]]==0 || xo[tr[a1][i]]==x) continue;

         xo[a1]^=xo[tr[a1][i]];
    }
}

void dfss(ll a1,ll p,ll x2, ll y)
{

    if(xo[a1]==x)
    {
        ans[a1][0]=0;
        ans[a1][1]=1;
    }

    else if(xo[a1]==0)
    {
        ans[a1][0]=1;
        ans[a1][1]=0;
    }
    else 
    {
        ans[a1][0]=x2;
        ans[a1][1]=y;
    }

    f(0,tr[a1].size())
    {
        if(tr[a1][i]==p) continue;
        dfss(tr[a1][i],a1,ans[a1][0],ans[a1][1]);

        ll sa=ans[tr[a1][i]][0],sb=ans[tr[a1][i]][1];
        ll ca=ans[a1][0],cb=ans[a1][1];
        if(xo[tr[a1][i]]==0 || xo[tr[a1][i]]==x) 
        {
            if(x==0) {ans[a1][1]=2*cb*sb;}
            else
                {ans[a1][0]=ca*(sa+sb)+cb*sb;
            ans[a1][1]=cb*(sa+sb)+ca*sb;}


        }
        else if(x==0) ans[a1][1]=sb;
        else
        {
            ans[a1][0]=sa;
            ans[a1][1]=sb;
        }

        ans[a1][0]=(ans[a1][0])%mod;
        ans[a1][1]=(ans[a1][1])%mod;

         
    }
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

         #ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
        #endif
    cin>>n>>x;
    f(1,n+1) cin>>a[i];

    ll x1,y;
    f(0,n-1)
    {
        cin>>x1>>y;
        tr[x1].pb(y);
        tr[y].pb(x1);
    }
    ll ch=0;
    f(1,n+1) ch^=a[i];


    if(ch!=0 && ch!=x)
    {
        cout<<0<<endl;
        return 0;
    }    

    dfsxx(1,0);
    dfss(1,0,-1,-1);

    if(ans<0) cout<<0<<endl;
    else cout<<ans[1][1]%mod<<endl;


    
return 0;
}
