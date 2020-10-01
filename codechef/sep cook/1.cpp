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
    	ll n,m,k;
    	cin>>n>>m>>k;

    	ll ans = 1;
    	f(i,0,k)
    	{
    		ans = ans*(n-i);
    		ans = ans%mod;
    		ans = ans*exp(i+1,mod-2,mod);
    		ans = ans%mod;
    	}
    	//cout<<ans<<"ss"<<endl;
    	ll ans2 = 0;
    	for(ll i = n-k;i>=0;i--)
    	{
    		ll pr = exp(m-1,i,mod);
    	//	cout<<"pr "<<pr<<endl;
    		ans2 += ans*pr;
    		ans2 = ans2%mod;

    		ans = ans*(i);
    		ans = ans%mod;

    		ans = ans*exp(n-i+1,mod-2,mod);
    		ans = ans%mod;

    		//cout<<ans2<<" "<<i<<" "<<ans<<endl;
    	}

    	cout<<ans2<<endl;

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