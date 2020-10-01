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
ll n;
vector<ll> sb;
vector<ll> tr[500005];
ll dfs(ll a,ll p)
{
	ll ans = 1;
	for(auto v: tr[a])
	{
		if(v==p) continue;

		ll v1 = dfs(v,a);
		sb.pb((n-v1)*v1);
		ans+=v1;
	}
	return ans;
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
    	
    	cin>>n;

    	f(i,0,n+1) tr[i].clear();
    	sb.clear();
    	ll x,y;
    	f(i,0,n-1)
    	{
    		cin>>x>>y;
    		tr[x].pb(y);
    		tr[y].pb(x);
    	}

    	dfs(1,0);
    	sort(sb.begin(),sb.end());
    	ll sz = sb.size();
    	ll m;
    	cin>>m;
    	
    	ll pr[m];
    	f(i,0,m) cin>>pr[i];
    	sort(pr,pr+m);
    	
    	ll ind = min(m-1,sz-1);
    	ll ans = 0;

    	

    	
    	
		for(ll j = m-2;j>=ind;j--)
		{
			pr[j]*=pr[j+1];
			pr[j] = pr[j]%mod;
		}
    	
    	
    	for(ll i = sz-1;i>=0;i--)
    	{
    		if(ind>=0)
    			{
    				ans += (sb[i]%mod * pr[ind]%mod)%mod;
    				ans = ans%mod;
    				ind--;
    			}
    			else
    			{
    				ans += sb[i]%mod;
    				ans = ans%mod;
    			}
    	}

    	//ans += (sb[sz-1]%mod * fi%mod)%mod;
    	//ans = ans%mod;
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
