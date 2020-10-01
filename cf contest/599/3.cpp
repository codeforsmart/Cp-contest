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

    if(n==1)
    {
    	cout<<1<<endl;
    	return 0;
    }
    ll ans = n;
    vector<ll> pr;
    for(ll j = 2;j*j<=n;j++)
    {
    	if(ans%j==0)
    	{
    		while(ans%j==0) ans/=j;
    		pr.pb(j);
    	}

    }
    
    if(ans>1) pr.pb(ans);

    ll p = pr[0];
    ll sz = pr.size();
   	
   if(sz==1)
   {
   	cout<<p<<endl;
   }
   else cout<<1<<endl;
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
