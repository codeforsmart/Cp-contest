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
    	ll n,q;
    	cin>>n>>q;

    	ll a[n];

    	ll ans = 0;

    	f(i,0,n) cin>>a[i];

    	ll po = 1;

        //vector<ll,ll> sb;
    	f(i,0,n)
    	{

    		if(po==1)
    		{
    			if(i==n-1)
    			{
    				ans+=a[i];
                   // sb[i] = 1;
    			}
    			else if(a[i]>a[i+1]) 
				{
					ans+=a[i];
					po = -1;
                  //  sb[i] = 1;
				}
    			
    		}
    		else
    		{
    			if(i!=n-1)
    			{
    				if(a[i]<a[i+1]) 
    					{
    						ans-=a[i];
    						po = 1;
                    //        sb[i] = -1;
    					}
    			}
    			
    		}
    	}

       // if(!sb.count(0)) sb[0] = 0;
       // if(!sb.count(n-1)) sb[n-1] = 0;

        cout<<ans<<endl;
        ll l,r;
        while(q--)
        {
            cin>>l>>r;
            l--;
            r--;

            
            ll l1 = a[r], r2 = a[l];

            ans-=a[0];
            if(l>0) ans-=max(0ll,a[l]-a[l-1]);
            if(l+1<n) ans-=max(0ll,a[l+1]-a[l]);
            
            a[l] = l1;

            ans+=a[0];
            if(l>0) ans+=max(0ll,a[l]-a[l-1]);
            if(l+1<n) ans+=max(0ll,a[l+1]-a[l]);
            
            ans-=a[0];
            if(r>0) ans-=max(0ll,a[r]-a[r-1]);
            if(r+1<n) ans-=max(0ll,a[r+1]-a[r]);

            a[r] = r2;
            ans+=a[0];
            if(r>0) ans+=max(0ll,a[r]-a[r-1]);
            if(r+1<n) ans+=max(0ll,a[r+1]-a[r]);
            cout<<ans<<endl;
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
