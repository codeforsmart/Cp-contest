#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
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
 	/*
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 	*/

    ll n;
    cin>>n;

    cout.flush();
	vector<char> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
	    if (is_prime[i] && (long long)i * i <= n) {
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	    }
	}

	vector<ll> pr;

	f(i,2,n+1)
	{
		if(is_prime[i]==true) pr.pb(i);
	}

	ll sz = pr.size();
debug(sz);
	vector<ll> sb;
	ll x;

	ll pre = 1;
	for(ll i = sz-1;i>=0;i--)
	{
		if(pr[i]*pre>n) continue;
		cout<<"B "<<pr[i]<<endl;
		cout<<flush;
		cin>>x;
		cout<<"A "<<pr[i]<<endl;
		cout<<flush;
		cin>>x;

		if(x>=1)
		{
			sb.pb(pr[i]);
			pre*=pr[i];
		}

	}
    

    ll ans = 1;

    sz = sb.size();
    f(i,0,sz)
    {
    	x = 1;
    	ll va = sb[i];
    	ans*=va;
    	va*=sb[i];
    	ll co= 1;
    	while((va/sb[i]*pre)<=n)
    	{
    		cout<<"A "<<va<<endl;
			cout<<flush;
			cin>>x;
			if(x==0) break;
			ans*=sb[i];
			va*=sb[i];
			co*=sb[i];
    	}

    	pre*=co;
    	//ans/=sb[i];
    }

    cout<<"C "<<ans<<endl;
    cout<<flush;
    
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
