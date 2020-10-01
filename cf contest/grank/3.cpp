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
    	ll n,l;
    	cin>>n>>l;

    	ll a[n+2]={0};
    	a[0] = 0;
    	a[n+1] = l;

    	f(i,1,n+1) cin>>a[i];

    	n+=2;
    	double t1[n]={0},t2[n]={0};
    	ll sp1[n]={1},sp2[n]={0};
    	sp2[n-1] = 1;
    	ll s = 0;
    	f(i,1,n)
    	{
    		s++;
    		sp1[i] = s+1;
    		t1[i] = double(a[i]-a[i-1])/double(s);
    		
    		t1[i]+=t1[i-1];

    	}

    	s = 0;
    	f(i1,1,n)
    	{
    		ll i = n-i1-1;
    		s++;
    		sp2[i] = s+1;
    		t2[i] = double(-a[i]+a[i+1])/double(s);
    		t2[i] += t2[i+1];
    	}


    	/*for(auto a : t1) cout<<a<<" ";
    		cout<<endl;*/
    	ll ind = 1;

    	f(i,0,n)
    	{
    		if(t1[i]>=t2[i])
    		{
    			ind = i;
    			break;
    		}
    	}

    	cout<<fixed;
    	cout<<setprecision(10);
    	if(t1[ind]==t2[ind])
    	{
    		cout<<t1[ind]<<endl;
    	}
    	else
    	{
    		ind--;

    		double ans = double(a[ind+1]-a[ind] + sp1[ind]*t1[ind] + sp2[ind+1]*t2[ind+1])/double(sp1[ind]+sp2[ind+1]);
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
