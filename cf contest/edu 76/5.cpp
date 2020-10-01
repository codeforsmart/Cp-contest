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

    ll k1,k2,k3;
    cin>>k1>>k2>>k3;
    ll n = k1+k2+k3;
    ll a[n+2];
    ll x;
    f(i,0,n)
    {
    	cin>>x;
    	if(i<k1) a[x]=1;
    	else if(i<k1+k2) a[x]= 2;
    	else a[x] = 3;
    }
    
    ll dp[n+1]={0};

    ll a1 = k1, a2 = 0, a3 = k3;

    dp[0] = k1;

    f(i,1,n+1)
    {
    	if(a[i]==1) a1--;
    	else if(a[i]==2) a2++;
    	dp[i] = min(dp[i-1],a1 + a2);
    }
    ll ans = k3 + dp[n];
    //cout<<ans<<endl;
    a2 = 0;
    for(ll i = n;i>=1;i--)
    {
    	if(a[i]==3) a3--;
    	else if(a[i]==2) a2++;
    	ans = min(ans,dp[i-1]+a3+a2);
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
