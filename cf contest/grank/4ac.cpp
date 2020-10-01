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
 
    ll n,m;
    cin>>n>>m;
	ll x,y;
    
    vector<pl> sb;
    
    f(i,0,n)
    {
    	cin>>x>>y;
    	sb.pb({x,y});
    }

    vector<pl> msm;
    
    f(i,0,m)
    {
    	cin>>x>>y;
    	msm.pb({x,y});
    }

   
    /*
    set<ll> ys;
    for(auto v: sb)
    {
    	ll ma = 0;
    	for(auto a:msm)
    	{
    		if(a.ff>=v.ff && a.ss>=v.ss)
    		{
    			//ma = max(ma,a.ss-v.ss+1);
    			ys.insert(a.ss-v.ss+1);
    		}
    	}
    	//ys.insert(ma);
    }
    ys.insert(0);


    //msm.pb({-1,mod});
    //msm.pb({mod,-1});
    */
    sort(msm.begin(),msm.end());
    vector<pl> q;

    f(i,0,m)
    {
    	while (!q.empty() && (q.back().ff <= msm[i].ff && q.back().ss<=msm[i].ss)) 
    		{
    			//debug(q.back().ff);
    			q.pop_back();
    		}
		q.push_back(msm[i]);
    }

    map<ll,ll> bap;
    for(auto v: q)
    {
    	//debug(v.ff);
    	bap[v.ss] = v.ff;
    }
    bap[mod] = -mod;

    
    ll ans = mod;
    
    vector<pl> ok;
    for(auto a:sb)
	{
		ll xk = bap.lower_bound(a.ss+v)->ss;
		if(xk>=a.ff)mi = max(mi,xk-a.ff+1);
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
