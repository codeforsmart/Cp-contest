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

    	ll d = 0;
    	vector<ll> pr;
    	
    	ll curr = 2;
    	ll su = 1;
    	ll ind = 1;
    	ll co[100]={0};
    	while(su+curr<=n)
    	{
    		su+=curr;
    		//co[ind] = 1;
    		ind++;
    		curr*=2;
    	}
    	ll x = n -su;
    	if(x==0)
    	{
    		//pt = n;
    		ind--;
    		cout<<ind<<endl;
    		ll tw = 1;
    		f(i,0,ind)
    		{
    			pr.pb(tw);
    			tw*=2;
    		}
    		f(i,0,ind) cout<<pr[i]<<" ";
    		cout<<endl;
    	}
    	else
    	{
    		//ind++;
    		su = su+curr;
    		x = su -n;
    		ll tw = 1;
    		//debug(ind);
    		ll ptw[ind]={0};
    		ptw[0] = 1;
    		f(i,1,ind)
    		{
    			ptw[i] = (ptw[i-1]+1)*2 -1;
    		}
    		/*
    		f(i,0,ind)
    		{
    			cout<<ptw[i]<<" ";
    		}
    		cout<<endl;*/
    		//return 0;
    		f(i,0,ind)
    		{
    			pr.pb(tw);
    			tw*=2;
    		}

    		//cout<<ind<<endl;
    		ll ii = ind-1;
    		ll pri = 0;
    	//	cout<<x<<endl;
	    	while(x>0)
	    	{
	    		//debug(x);
	    		//debug(ii);
	    		//debug(ptw[ii]);
	    		if(x>=ptw[ii] && ii==0)
	    		{
	    			pr[pri]--;
	    			x-=ptw[ii];
	    		}
	    		else
	    		{
	    			ii--;
	    			pri++;
	    		}
	    	}
	    	

	    	ll sz = pr.size();
	    	cout<<sz<<endl;
	    	f(i,0,sz) cout<<pr[i]<<" ";
	    	cout<<endl;
    	}
    	
    	//cout<<pt<<endl;
    	
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
