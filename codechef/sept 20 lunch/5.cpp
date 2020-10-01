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
    	ll n;
    	cin>>n;
    	ll a1[n];
    	f(i,0,n) cin>>a1[i];
    	
    	
    	ll a[n]={0};
    	f(i,0,n)
    	{
    		f(j,0,i) if(a1[j]>a1[i]) a[i]++;
    		f(j,i+1,n) if(a1[i]>a1[j]) a[i]++;
    	}


    	ll su = 0;

    	f(i,0,n) su+=a[i];

    	//debug(su);
    	if(su%2==1)
    	{
    		cout<<"NO"<<endl;
    		continue;
    	}
    	ll dp[su+1][n+1];

    	f(i,0,su+1)
    	{
    		f(j,0,n+1)
    		{
    			if(i==0) 
    			{
    				dp[i][j] = 1;
    				continue;
    			}
    			if(j==0)
    			{
    				dp[i][j] = 0;
    				continue;
    			}

    			if(i-a[j-1]>=0) dp[i][j] = dp[i][j-1] | dp[i-a[j-1]][j-1];
    			else dp[i][j] = dp[i][j-1];
    		}
    	}

    	if(dp[su/2][n]) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;

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
