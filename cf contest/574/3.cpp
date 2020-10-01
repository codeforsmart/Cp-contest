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
    ll a[n];
    ll b[n];
    f(0,n) cin>>a[i];
    f(0,n) cin>>b[i];

    ll dp[n][2];
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    f(1,n)
    {
    	dp[i][0] = max(dp[i-1][0],a[i]+dp[i-1][1]);
    	dp[i][1] = max(dp[i-1][1],b[i]+dp[i-1][0]);
    }

    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
    
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