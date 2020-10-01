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
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
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
    	ll n;
    	cin>>n;
    	vector<ll> sb[n];
    	ll x,y;
    	f(i,0,n)
    	{
    		cin>>x;
    		sb[i].pb(x);

    		f(j,0,x) 
    		{
    			cin>>y;
    			sb[i].pb(y);
    		}
    	}

    	ll co[n+1]={0};
    	ll ind = -1;
    	f(i,0,n)
    	{
    		bool ok = 0;
    		f(j,1,sb[i][0]+1)
    		{
    			if(co[sb[i][j]]==0)
    			{
    				co[sb[i][j]]=1;
    				ok = 1;
    				break;
    			}
    		}

    		if(ok==0 && ind==-1) ind = i;
    	}

    	if(ind==-1) cout<<"OPTIMAL"<<endl;
    	else
    	{
    		ll va = 1;
    		f(i,1,n+1) 
    		{
    			if(co[i]==0)
    			{
    				va =i;
    				break;
    			}
    		}

    		cout<<"IMPROVE"<<endl;
    		cout<<ind+1<<" "<<va<<endl;
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
