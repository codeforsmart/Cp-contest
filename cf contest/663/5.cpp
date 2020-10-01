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

ll pr[1000005];
bool vis[1000005];
ll de[1000005];
vector<ll> tr[1000005];

void dfs(ll a, ll par)
{
	if(vis[a]==1) return;

	vis[a] = 1;
	if(par!=-1) de[a] = de[par] + 1;

	pr[a] = par;

	for(auto v: tr[a])
	{
		dfs(v,a);
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
    	ll n,m;
    	cin>>n>>m;

    	f(i,1,n+1)
    	{
    		tr[i].clear();
    		de[i] = 0;
    		vis[i] = 0;
    		pr[i] = 0;
    	}
    	ll x,y;
    	f(i,0,m)
    	{
    		cin>>x>>y;
    		tr[x].pb(y);
    		tr[y].pb(x);
    	}

    	dfs(1,-1);

    	ll ce = n - n/2;
    	bool ok = 0;
    	f(i,1,n+1)
    	{
    		if(de[i]+1>=ce)
    		{
    			ll ind = i;
    			cout<<"PATH"<<endl;
    			cout<<de[i]+1<<endl;
    			while(ind!=-1)
    			{
    				cout<<ind<<" ";
    				ind = pr[ind];
    			}
    			cout<<endl;
    			ok = 1;
    			break;
    		}
    	}

    	if(ok) continue;

    	vector<ll> sb[n];

    	f(i,1,n+1) sb[de[i]].pb(i);

    	vector<pl> ans;

    	f(i,1,n+1)
    	{
    		ll sz = sb[i].size();
    		for(ll j = 0; j+1<sz;j+=2)
    		{
    			ans.pb(mp(sb[i][j],sb[i][j+1]));
    		}
    	}

    	cout<<"PAIRING"<<endl;
    	cout<<ans.size()<<endl;

    	for(auto v: ans)
    	{
    		cout<<v.ff<<" "<<v.ss<<endl;
    	}
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
