#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef pair<ll,ll> pl;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
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
    	ll n,x;
    	cin>>n>>x;

    	ll a[n];
    	f(i,0,n) cin>>a[i];

    	ll su = 0;

    	bool sb = 0;
    	f(i,0,n)
    	{
    		su+= (x-a[i]);

    		if(a[i]==x) sb =1;
    	}

    	bool sa = 1;


    	f(i,0,n)
    	{
    		if(a[i]!=x)
    		{
    			sa = 0;
    			break;
    		}
    	}


    	if(su==0)
    	{
    		if(sa==1) cout<<0<<endl;
    		else cout<<1<<endl;
    	}
    	else 
    		{
    			if(sb==1)
    			{
    				cout<<1<<endl;
    			}
    			else cout<<2<<endl;
    			
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
