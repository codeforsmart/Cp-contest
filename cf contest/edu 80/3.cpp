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
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
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

    ll dp[m+1][n+1];
    dp[0][0] = 0;
    f(i,1,n+1) dp[0][i] = 1;
    f(i,1,m+1)
    {	dp[i][0] = 0;
    	f(j,1,n+1)
    	{
    		dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
    	}
    }
    
    ll ans = 0;
   // cout<<dp[m][10]<<endl;
    f(i,1,n+1)
    {
    	f(i1,i,n+1)
    	{
    		ans += (dp[m-1][i] * dp[m-1][n-i1+1])%mod;
    		ans = ans%mod;
    	}
    	
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
