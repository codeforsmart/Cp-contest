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


    	ll su = 0;
    	f(i,0,n) su +=a[i];


    	if(su%n!=0)
    	{
    		cout<<-1<<endl;
    		continue;
    	}

    	ll bap = su/n;

    	

    	vector<ll> pr;
    	
    	f(i,1,n)
    	{
    		ll i1 = i+1;

    		ll re = (i1-(a[i]%i1))%i1;

    		pr.pb(1);
    		pr.pb(i+1);
    		pr.pb(re);

    		a[i]+=re;

    		pr.pb(i+1);
    		pr.pb(1);
    		pr.pb(a[i]/i1);

    	}


    	f(i,1,n)
    	{
    		pr.pb(1);
    		pr.pb(i+1);
    		pr.pb(bap);
    	}
    
    
    	ll sz = pr.size();

    	cout<<sz/3<<endl;

    	for(ll i = 0; i<sz;i+=3)
    	{
    		cout<<pr[i]<<" "<<pr[i+1]<<" "<<pr[i+2]<<endl;
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
