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

    string s;
    cin>>s;

    ll n = s.length();

    ll fib[n+5]={0};
    fib[0]=1;
    fib[1]=1;
    fib[2] = 2;

    f(i,3,n+1) fib[i] = (fib[i-1] + fib[i-2])%mod;
    f(i,0,n)
    {
    	if(s[i]=='m' || s[i]=='w')
    	{
    		cout<<0<<endl;
    		return 0;
    	}
    }
    
    ll co = 0;
    ll ans = 1;
    char sb = 'a';
    f(i,0,n)
    {
    	if(sb!=s[i])
    	{
    		ans = ans*fib[co];
    		ans = ans%mod;

    		co = 1;
    		sb = s[i];
    	}
    	else if(s[i]=='u' || s[i]=='n') co++;
    }

    ans = ans*fib[co];
    ans = ans%mod;
    
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
