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

    	ll a[n];
    	f(i,0,n) cin>>a[i];

    	vector<ll> ne,po;

    	f(i,0,n)
    	{
    		if(a[i]>=0) po.pb(a[i]);
    		else ne.pb(-a[i]);
    	}

    	sort(ne.begin(),ne.end());
    	sort(po.begin(),po.end());

    	ll pz = po.size();
    	ll nz = ne.size();

    	ll ans = -mod;
    	for(ll i = 0; i <=4;i+=2)
    	{
    		ll j = 5-i;

    		if(i>nz) continue;
    		if(j>pz) continue;

    		ll ans1 = 1;
    		f(i1,0,i) ans1*=ne[nz-i1-1];
    		f(i1,0,j) ans1*=po[pz-i1-1];

    		ans = max(ans,ans1);
    	}

    	if(ans==-mod)
    	{
    		ll ans1 = 1;
    		ll i1 = 0, j1 = 0;

    		ll co = 0;

    		while(co<5)
    		{
    			if(i1==pz)
    			{
    				ans1*=ne[j1];
    				j1++;
    			}
    			else if(j1==nz)
    			{
    				ans1*=po[i1];
    				i1++;
    			}
    			else
    			{
    				ll mi = min(po[i1],ne[j1]);

    				ans1*=mi;
    				if(mi==po[i1])
    				{
    					i1++;
    				}
    				else j1++;
    			}
    			co++;
    		}

    		ans = -ans1;
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
