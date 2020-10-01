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

vector<ll> g[100005];
ll n;
vector<ll> centroid;
vector<ll> sz(100005);

void dfs(int u, int prev) {
        sz[u] = 1;
        bool is_centroid = true;
        for (auto v : g[u]) if (v != prev) {
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > n / 2) is_centroid = false;
        }
        if (n - sz[u] > n / 2) is_centroid = false;
        if (is_centroid) centroid.push_back(u);
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
    	//ll n;
    	cin>>n;
    	ll x,y;

    	f(i,0,n+1) g[i].clear();
    	f(i,0,n-1)
    	{
    		cin>>x>>y;
    		g[x].pb(y);
    		g[y].pb(x);
    	}

    	centroid.clear();
    	dfs(1, -1);
    	ll szz = centroid.size();

    	ll f1 = centroid[0];
    	ll f2 = centroid[0];

    	if(szz>1) f2 = centroid[1];

    	ll ans1 = g[f1][0];
    	ll ind = 1;
    	while(ans1==f2)
    	{
    		ans1 = g[f1][ind];
    		ind++;
    	}
    	cout<<f1<<" "<<ans1<<endl;
    	cout<<f2<<" "<<ans1<<endl;

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
