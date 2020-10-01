#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
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

vector<ll> tr[300001];
vector< ll> sb;

ll dfs(ll a, ll p, ll de)
{
	ll su = 0;

	for(auto v: tr[a])
	{
		if(v==p) continue;

		su+=dfs(v,a,de+1);
	}
	sb.pb(de-su);
	return su+1;
}

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,k;
    cin>>n>>k;
    ll x,y;
    f(i,0,n-1)
    {
    	cin>>x>>y;
    	tr[x].pb(y);
    	tr[y].pb(x);
    }
    
    dfs(1,0,0);

    sort(sb.begin(),sb.end());

    ll sz = sb.size();
    ll ans = 0;
    for(ll i = 0;i<k;i++)
    {
    	ans+=sb[sz-i-1];
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
