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

    ll t;
    cin>>t;
    while(t--)
    {
    	ll a,b;
    	cin>>a>>b;

    	
    	ll a1 = min(a,b);
    	ll b1 = max(a,b);

    	ll sq = 0;

    	while( (sq*(sq+1))/2 < (b1-a1)) sq++;
    	
    	ll ans = sq;

    	ll d1 = (a1+(sq*(sq+1))/2-b1);
    	if(d1%2==0)
    	{
    		cout<<ans<<endl;
    		
    	}
    	else if(sq%2==0)
    	{
    		cout<<ans+1<<endl;
    	}
    	else cout<<ans+2<<endl;
    	
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
