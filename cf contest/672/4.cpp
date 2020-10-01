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
 
    ll n,k;
    cin>>n>>k;
    ll l,r;
   // map<ll,ll> sb;
    vector<pl> msm;
    f(i,0,n)
    {
    	cin>>l>>r;
    	msm.pb({l,r});
    }

   
    ll sz = msm.size();

    sort(msm.begin(),msm.end());
    ll ans = 0;

    ll c[n+1]={0};
    c[k-1] = 1;
    f(i,k,n+1)
    {
    	c[i] = c[i-1];
    	c[i]*=i;
    	c[i] = c[i]%mod;
    	c[i] *= exp(i-k+1,mod-2,mod);
    	c[i] = c[i]%mod;
    	//debug(c[i]);
    }

    multiset<ll> sb;
    f(i,0,sz)
    {
    	while(sb.size() && *sb.begin()<msm[i].ff) sb.erase(sb.begin());
    	ll n = sb.size();
    	if(n>=k-1)
    	{
    		ll n1 = c[n]%mod;
    		ans+=n1%mod;
    		ans = ans%mod;
    	}
    	sb.insert(msm[i].ss);
    //	debug(n);
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
