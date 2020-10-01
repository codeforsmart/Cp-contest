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

    	ll a[n];
    	f(i,0,n) cin>>a[i];

    	ll l[n];
    	f(i,0,n) cin>>l[i];

    	ll b[n];
    	ll c[n];

    	vector<ll> sb;
    	f(i,0,n)
    	{
    		if(l[i]==0)
    		{
    			sb.pb(a[i]);
    		}
    	}

    	sort(sb.begin(),sb.end());

    	ll sz = sb.size();
    	ll ind = 0;

    	ll k1 = 0,k2 = 0;
    	ll pr1 = 0, pr2 = 0;
    	f(i,0,n)
    	{
    		if(l[i]==1)
    		{
    			b[i] = a[i];
    			c[i] = a[i];
    		}
    		else
    		{
    			b[i] = sb[ind];
    			c[i] = sb[sz-ind-1];
    			ind++;
    		}
    		pr1+=b[i];
    		pr2+=c[i];

    		if(pr1<0) k1 = i+1;
    		if(pr2<0) k2 = i+1;
    	}

    	if(k1<=k2)
    	{
    		f(i,0,n) cout<<b[i]<<" ";
    		cout<<endl;
    	}
    	else
    	{
    		f(i,0,n) cout<<c[i]<<" ";
    		cout<<endl;
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
