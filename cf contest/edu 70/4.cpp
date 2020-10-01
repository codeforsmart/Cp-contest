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
    ll t;
    cin>>t;
    while(t--)
    {
    ll n;
    cin>>n;
    ll ans = 1;
    ll x = 3;
    while(ans + (x*(x-1))/2 <= n)
    {
    	ans += (x*(x-1))/2;
    	x++;
    }
    x--;
    ll di = n-ans;
    string s2="";
    for(ll j=x;j>=2;j--)
    {
    	ll re = (2*di)/(j*(j-1));
    	di-=re*(j*(j-1))/2;
    	f(0,re) s2+="7";
    	s2+="73";
    } 
    s2+="31";
    reverse(s2.begin(),s2.end());
    cout<<s2<<endl;
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