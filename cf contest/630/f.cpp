#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 998244353
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll exp(ll a,ll b,ll m);

vector<ll> tr[400000];

ll dp[400000]={0},dp1[400000]={0},dp2[400000]={0};

void dfs(ll a, ll p)
{
	dp[a] = 1;
	dp1[a] = 1;
	dp2[a] = 1;
	for(auto v:tr[a])
	{
		if(v==p) continue;
		dfs(v,a);
		dp1[a]*=((2*dp1[v]+2*dp2[v]-dp[v])%mod);
		dp2[a]*=((2*dp1[v]+dp2[v]-dp[v])%mod);
		dp[a]*=((dp1[v]+dp2[v]-dp[v])%mod);

		dp1[a] = dp1[a]%mod;
		dp2[a] = dp2[a]%mod;
		dp[a] = dp[a]%mod;
	}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;
    ll x,y;
    f(i,0,n-1)
    {
    	cin>>x>>y;
    	tr[x].pb(y);
    	tr[y].pb(x);
    }
    
    dfs(1,0);
    
    ll ans = dp1[1] + dp2[1] - dp[1] - 1 + 2 * mod;
    ans = ans%mod;

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
