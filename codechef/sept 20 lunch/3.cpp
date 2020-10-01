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
#define ub upper_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef pair<ll,ll> pl;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
ll exp(ll a,ll b,ll m);


vector<ll> tr[10005];
ll vis[10005];

ll ans = 0;
void dfs(ll a)
{
	if(vis[a]==1)
	{
		ans++;
		return;
	}

	vis[a] = 1;
	for(auto v: tr[a])
	{
		dfs(v);
	}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 
    ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;

    	ll x,y;

    	f(i,0,n+1)
    	{
    		tr[i].clear();
    		vis[i] = 0;
    	}

    	ll ba[n+1]={0};
    	f(i,0,n-1)
    	{
    		cin>>x>>y;
    		tr[x].pb(y);
    		ba[y]++;
    	}

    	ans = 0;

    	f(i,1,n+1)
    	{
    		if(ba[i]==0 && vis[i]==0) dfs(i);
    	}

    	cout<<ans<<endl;
    }

    
    
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
