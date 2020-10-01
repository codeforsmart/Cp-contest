#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
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
    	ll n,p,k;
    	cin>>n>>p>>k;
    	ll a[n];
    	f(i,0,n) cin>>a[i];
    	sort(a,a+n);
    	ll dp[n][2];

    	f(i,0,k)
    	{
    		if(a[i]<=p)
    		{
    			dp[i][0]=1;
    			dp[i][1]=a[i];

    			if(i==k-1) dp[i][0] += k-1;
    		}
    		else 
    		{
    			dp[i][0] = 0;
    			dp[i][0] = 0;
    		}
    	}

    	f(i,k,n)
    	{
    		if(a[i]+dp[i-k][1]<=p)
    		{
    			dp[i][0] = dp[i-k][0]+k;
    			dp[i][1] = dp[i-k][1]+a[i];
    		}
    		else if(a[i]<=p)
    		{
    			dp[i][0]=k;
    			dp[i][1]=a[i];
    		}
    		else 
    		{
    			dp[i][0] = 0;
    			dp[i][0] = 0;
    		}
    	}

    	ll ans = 0;
    	f(i,0,n) cout<<dp[i][0]<<" ";
    	cout<<endl;
    	f(i,0,n) ans = max(ans,dp[i][0]);

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
