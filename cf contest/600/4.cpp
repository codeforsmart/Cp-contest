#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
vector<ll> tr[200002];
bool vis[200002]={0};
ll mi,ma;
void dfs(ll a)
{
	if(vis[a]==1) return;
	vis[a] = 1;
	mi = min(mi,a);
	ma = max(ma,a);
	f(i,0,tr[a].size())
	{
		dfs(tr[a][i]);
	}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,m;
    cin>>n>>m;

    f(i,0,m)
    {
    	ll x,y;
    	cin>>x>>y;
    	tr[x].pb(y);
    	tr[y].pb(x);
    }
    
    vector< pair<ll,ll> > sb;

    f(i,1,n+1)
    {
    	if(vis[i]==1) continue;

    	mi = i;
    	ma = i;

    	dfs(i);
    	sb.pb(mp(mi,ma));
    }

    sort(sb.begin(),sb.end());

    ll sz = sb.size();
    ll ans = 0;
    ll co =-1;
    f(i,0,sz)
    {
    	if(sb[i].ff<=co)
    	{
    		ans++;
    	}
    	co = max(co,sb[i].ss);
    }
    cout<<ans<<endl;
return 0;
}

ll exp(ll a,ll b,ll m)
{
	if(b==0)
	{
		return 1;
	}
	ll temp =exp(a,b/2,m);
	temp=(temp*temp)%m;
	if(b&1)
	{
		return (temp*(a%m))%m;
	}
	return temp;
}
