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

vector<ll> tr[100005];
//ll vis[100005];
/*
void dfs3(ll a, ll b, ll p)
{
	vis[a]++;
	if(a==b) return;

	for(auto v: tr[a])
	{
		if(v==p) continue;
		dfs3(v,b,a);
	}
}

ll dfs(ll a, ll b, ll p)
{
	ll mi = 0;
	for(auto v: tr[a])
	{
		if(v==p || vis[v]>=2) continue;
		ll va = dfs(v,b,a);
		mi =max(mi,va);
	}
	return 1+mi;
}

*/

ll ma = 0, ind = 0;
void dfs(ll a,ll p, ll co)
{
	if(co>ma)
	{
		ma = co;
		ind = a;
	}
	//cout<<a<<" "<<p<<" "<<co<<endl;
	for(auto v: tr[a])
	{
		if(v==p) continue;

		dfs(v,a,co+1);
	}
}

ll de = 0;

void dfs2(ll a, ll b, ll p, ll co)
{
	if(a==b)
	{
		de = co;
		return;
	}

	if(de) return;

	for(auto v: tr[a])
	{
		if(v==p) continue;
		dfs2(v,b,a,co+1);
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
    	ll n,a,b,da,db;
    	cin>>n>>a>>b>>da>>db;
    	f(i,0,n+1) 
    	{
    		tr[i].clear();
    		//vis[i] = 0;
    	}
    	ll x,y;
    	f(i,0,n-1)
    	{
    		cin>>x>>y;
    		tr[x].pb(y);
    		tr[y].pb(x);
    	}

    	if(db<2*da+1)
    	{
    		cout<<"Alice"<<endl;
    		continue;
    	}

    	//dfs3(a,b,0);
    	//dfs3(b,a,0);

    	de = 0;
    	dfs2(a,b,0,0);

    	if(de<=da)
    	{
    		cout<<"Alice"<<endl;
    		continue;
    	}


    	ma = 0, ind = 0;

    	/*ll le1 = dfs(a,b,0)-1,le2 = dfs(b,a,0)-1;
    	if(le1<0) le1 = 0;
    	if(le2<0) le2 = 0;
    	//cout<<le1<<" "<<le2<<endl<<" "<<de<<endl;
    	ll su = le1+le2+de+1;*/
    	//cout<<su<<endl;


    	dfs(a,0,0);
    	//cout<<ind<<" "<<ma<<endl;
    	dfs(ind,0,0);

    	ll su = ma+1;
    	//cout<<su<<endl;
    	if(su>=2*da+2)
    	{
    		cout<<"Bob"<<endl;
    	}
    	else cout<<"Alice"<<endl;

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
