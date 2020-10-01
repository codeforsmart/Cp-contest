#include<bits/stdc++.h>
#define ll int
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
ll a[500001]={0};
ll sq = 710;
ll pre[710][710];
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll q;
    cin>>q;
    while(q--)
    {
    	ll type,x,y;
    	cin>>type;
    	if(type==1)
    	{
    		cin>>x>>y;
    		a[x]+=y;
    		f(i,1,sq)
    		{
    			pre[i][x%i]+=y;
    		}
    	}
    	else
    	{
    		cin>>x>>y;
    		if(x<sq)
    		{
    			cout<<pre[x][y]<<endl;
    		}
    		else
    		{
    			ll ans = 0;
    			for(ll j = y;j<=500000;j+=x)
    			{
    				ans+=a[j];
    			}
    			cout<<ans<<endl;
    		}
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