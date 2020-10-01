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
    	ll dp[n][2][2];

    	dp[0][0][1] = mod;
    	dp[0][0][0] = mod;

    	dp[0][1][1] = mod;
    	dp[0][1][0] = a[0];
    	
    	f(i,1,n)
    	{
    		dp[i][0][1] = dp[i-1][0][0];
    		dp[i][0][0] = min(dp[i-1][1][0],dp[i-1][1][1]);
    		dp[i][1][1] = dp[i-1][1][0];
    		dp[i][1][0] = min(dp[i-1][0][0],dp[i-1][0][1]);
    		if(a[i]==1)
    		{	
		    	dp[i][1][0]++;
		    	dp[i][1][1]++;
    		}
    	}

    	ll ans = mod;
    	f(i,0,2)
    	{
    		f(j,0,2)
    		{
    			ans = min(ans,dp[n-1][i][j]);
    		}
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
