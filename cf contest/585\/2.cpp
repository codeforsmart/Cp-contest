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

    ll n;
    cin>>n;
    ll a[n];
    f(i,0,n) cin>>a[i];

    ll dp[n][2];
    dp[0][0] = (a[0]>0); // positive
    dp[0][1] = 1-dp[0][0];
    
    f(i,1,n)
    {
 
    	if(a[i]>0)
    	{
    		dp[i][0] = dp[i-1][0]+1;
    		dp[i][1] = dp[i-1][1];
    	}
    	else
    	{
    		dp[i][0] = dp[i-1][1];
    		dp[i][1] = dp[i-1][0] + 1;
    	}
    }
    ll ne =  0, po = 0;

    f(i,0,n) 
    {
    	ne+=dp[i][1];
    	po+=dp[i][0];
    }
    cout<<ne<<" "<<po<<endl;
    
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
