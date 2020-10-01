#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;

    ll co =0;

    char a[n];
    f(0,n) cin>>a[i];

   	ll dp[n][n];
   	dp[0][0] = 1;
   	f(1,n) dp[0][i]=0;
    f(1,n)
    {
    	if(a[i-1]=='s')
    	{
    		dp[i][n-1] = dp[i-1][n-1];
    		for(ll j = n-2;j>=0;j--)
    		{
    			dp[i][j] = dp[i-1][j] + dp[i][j+1];
    			dp[i][j] = dp[i][j]%mod;
    		}
    	}
    	else if(a[i-1]=='f')
    	{
    		dp[i][0]=0;
    		for(ll j=1 ; j<n;j++)
    		{
    			dp[i][j] = dp[i-1][j-1];
    		}
    	}
    }
    
    ll ans = 0;
    f(0,n)
    {
    	ans+=dp[n-1][i];
    	ans = ans%mod;
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