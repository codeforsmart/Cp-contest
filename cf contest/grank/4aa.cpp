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

    ll n1 = 1000005;
    ll dp[n1]={0};
    memset(dp,-1,sizeof(dp));

    //ll co[1e6+1]={0};
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
    f(i,0,n)
    {
        pl v =sb[i];
    	ll ma = 0;
    	for(auto a:q)
    	{
    		if(a.ff>=v.ff && a.ss>=v.ss)
    		{
    			dp[a.ss-v.ss+1] = max(dp[a.ss-v.ss+1],a.ff-v.ff+1);
    		}
    	}
    	//ys.insert(ma);
    }
    ll ans = mod;

    f(i,0,n1)
    {
        if(dp[i]==-1) continue;
        debug(dp[i]);
        debug(i);
        ans = min(ans,dp[i]+i);
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
