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
		ll a,b,c;
		cin>>a>>b>>c;
		ll h1,h2;
		cin>>h1>>h2;
		ll p = 0;
		if(h1>=h2)
		{
			ll mi = min(a/2,b);
			p+=mi*h1;
			a-=mi*2;
			ll m2 = min(a/2,c);
			p+=m2*h2;
		}
		else
		{
			ll mi = min(a/2,c);
			p+=mi*h2;
			a-=mi*2;
			ll m2 = min(a/2,b);
			p+=m2*h1;
		}
		cout<<p<<endl;
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