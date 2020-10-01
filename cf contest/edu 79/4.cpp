#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 998244353
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
ll gi[1000005]={0};
ll gi2[1000005]={0};
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;

    ll ks =1;
    ll k;
    ll x;
    ll km = 1;
    f(i,0,n)
    {
    	cin>>k;
    	ll kin = exp(k,mod-2,mod);
    	ks*=kin;
    	ks = ks%mod;

    	km*=k;

    	km = km%mod;
    	f(j,0,k)
    	{
    		cin>>x;
    		gi[x]+=kin;
    		gi2[x]++;

    		gi[x] = gi[x]%mod;
    	}
    }
    
    ll ns = n*n;

    ns = ns%mod;

    ns = exp(ns,mod-2,mod);

    ll to = (ns*ks)%mod;

    ll up = 0;

    f(i,0,1000004)
    {
    	up += (gi[i]*gi2[i])%mod;

    	up = up%mod;
    }
    up = (up*km)%mod;

    ll ans = (to*up)%mod;

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
