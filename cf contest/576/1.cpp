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

    ll n,x,y;
    cin>>n>>x>>y;
    ll a[n];
    f(0,n) cin>>a[i];
    ll o =0;
    f(0,n)
    {
    	bool ch = 0;
    	for(ll j = max(o,i-x);j<i;j++)
    	{
    		if(a[j]<=a[i])
    		{
    			ch = 1;
    			break;
    		}
    	}
    	//cout<<ch<<endl;
    	if(ch==0)
    	{
    		for(ll j = i+1;j<=min(n-1,i+y);j++)
	    	{
	    		if(a[j]<=a[i])
	    		{
	    			ch = 1;
	    			break;
	    		}
	    	}
    	}

    	if(ch==0)
    	{
    		cout<<i+1<<endl;
    		return 0;
    	}
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