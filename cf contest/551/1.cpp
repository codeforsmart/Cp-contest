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

    ll n, t;
    cin>>n>>t;

    ll s,d;
    ll ans=mod;
    ll ind=0;

    f(1,n+1)
    {
    	cin>>s>>d;

    	ll va=0;

    	if(s>=t) va=s;
    	else
    	{
    		ll di = t-s;
    		ll mi = (t-s)/d;

    		if((t-s)%d!=0) mi++;

    		va =mi*d + s;
    		//cout<<"va = "<<va<<endl;
    	}

    	if(ans>=va)
    	{
    		ans=va;
    		ind=i;
    	}
    }

    cout<<ind<<endl;
    
    
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