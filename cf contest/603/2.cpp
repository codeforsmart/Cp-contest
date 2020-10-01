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
    	ll n;
    	cin>>n;

    	map<ll,ll> sb;
    	ll a[n];
    	f(i,0,n)
    	{
    		cin>>a[i];
    		sb[a[i]]+=1;
    	}
    	ll ans = 0;
    	f(i,0,n)
    	{
    		if(sb[a[i]]>1)
    		{
    			sb[a[i]]--;

    			ll va = a[i]/10;

    			va*=10;

    			f(j,0,10)
    			{
    				if(sb[va+j]==0)
    				{
    					sb[va+j]=1;
    					a[i]=va+j;
    					ans++;
    					break;
    				}
    			}
    		}
    	}
    	cout<<ans<<endl;
    	f(i,0,n) 
    	{
    		if(a[i]/1000==0) cout<<0;
    		if(a[i]/100==0) cout<<0;
    		if(a[i]/10==0) cout<<0;
     		cout<<a[i]<<endl;
    	}
    	//cout<<endl;

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
