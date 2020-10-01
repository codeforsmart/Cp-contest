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
    	ll n,m;
    	cin>>n>>m;
    	ll a[m];
    	f(i,0,m)
    	{
    		cin>>a[i];
    	}
    	ll ans = 0;
    	ll su = 0;
    	

    	ll di = n;

    	ll co[75]={0};

    	ll re[72]={0};

    	f(i,0,72)
    	{
    		if(n%2==1) re[i]=1;
    		else re[i]=0;
    		n/=2;
    	}
    	f(i,0,m)
    	{
    		ll ak = log2(a[i]);
    		co[ak]++;
    	}

    
    	f(i,0,72)
    	{
    		if(re[i]==1)
    		{
    			if(co[i]>0) co[i]--;
    			else
    			{
    				ll j2 = 73;
    				f(j,i+1,72)
    				{
    					if(co[j])
    					{
    						j2 = j;
    						break;
    					}
    				}
    				if(j2==73)
    				{
    					ans = -1;
    					break;
    				}
    				else
    				{
    					ans+=(j2-i);
    					f(j,i+1,j2)
    					{
    						co[j]++;
    					}
    					co[j2]--;
    				}
    			}
    		}
    		
    		co[i+1]+=co[i]/2;
    	}


    	
    		cout<<ans<<endl;
    	
    	
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
