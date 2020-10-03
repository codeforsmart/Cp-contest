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
    ll t1 = 0;
    while(t--)
    {
    	t1++;
    	cout<<"Case #"<<t1<<": ";

    	ll n;
    	cin>>n;
    	ll a[n];
    	f(i,0,n) cin>>a[i];
    	ll ma = 0;

    	int max_so_far = -1, max_ending_here = 0; 
  
	    for (int i = 0; i < n; i++) 
	    { 
	        max_ending_here = max_ending_here + a[i]; 
	        if (max_so_far < max_ending_here) 
	            max_so_far = max_ending_here; 
	  
	        if (max_ending_here < 0) 
	            max_ending_here = 0; 
	    }
	    ma = max_so_far;
	    if(ma<0) ma = 0;
	    ll sq = sqrt(ma);
	    //debug(sq);
	    f(i,1,n) a[i]+=a[i-1];

	    ll ans = 0;
	    
	    map<ll,ll> sb;

	    sb[0] = 1;

	    f(i,0,n)
	    {
	    	f(j,0,sq+1)
	    	{
	    		if(sb[-j*j+a[i]]) ans+=sb[-j*j+a[i]];
	    		//cout<<j*j-a[i]<<endl;
	    	}
	    	sb[a[i]]++;
	    	//cout<<"aaa "<<a[i]<<endl;
	    	//debug(ans);
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
