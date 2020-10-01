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
ll isp(ll a)
{
	ll sz = sqrt(a);

	f(i,2,sz+1)
	{
		if(a%i==0) return 0;
	}
	return 1;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 
    ll n;
    cin>>n;

    ll a[n];
    f(i,0,n) cin>>a[i];

    if(n==1)
    {
    	cout<<1<<" "<<1<<endl;
    	cout<<-a[0]<<endl;
    	cout<<1<<" "<<1<<endl;
    	cout<<0<<endl;
    	cout<<1<<" "<<1<<endl;
    	cout<<0<<endl;
    	return 0;
    }

    if(n==2)
    {
    	cout<<1<<" "<<1<<endl;
    	cout<<-a[0]<<endl;
    	cout<<2<<" "<<2<<endl;
    	cout<<-a[1]<<endl;
    	cout<<1<<" "<<1<<endl;
    	cout<<0<<endl;
    	return 0;
    }

    if(n==3)
    {
    	cout<<1<<" "<<1<<endl;
    	cout<<-a[0]<<endl;
    	cout<<2<<" "<<2<<endl;
    	cout<<-a[1]<<endl;
    	cout<<3<<" "<<3<<endl;
    	cout<<-a[2]<<endl;
    	return 0;
    }

    ll nu = n-1;

    while(isp(nu)==0)
    {
    	nu--;
    }
    map<ll,ll> sb;
    
    f(i,0,n)
    {
    	sb[(i*nu)%n]=i;
    }

    cout<<1<<" "<<nu<<endl;

    f(i,0,nu)
    {
    	ll mo = (a[i]%n + n)%n;
    	ll re = (n - mo)%n;
    	cout<<nu*sb[re]<<" ";

    	a[i]+=nu*sb[re];
    }
    cout<<endl;

    cout<<n-nu+1<<" "<<n<<endl;

    f(i,n-nu,n)
    {
    	ll mo = (a[i]%n + n)%n;
    	ll re = (n - mo)%n;
    	cout<<nu*sb[re]<<" ";
    	a[i]+=nu*sb[re];
    }
    cout<<endl;


    cout<<1<<" "<<n<<endl;

    f(i,0,n)
    {
    	cout<<-a[i]<<" ";
    }
    cout<<endl;
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
