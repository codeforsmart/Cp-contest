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
ll n;

ll solve2(ll a1, ll a2,ll a3,ll b1,ll b2,ll b3)
{

	ll ans = 0;
	if(b2>a2+a3) ans+=(b2-a2-a3);
	if(b1>a1+a2) ans+=(b1-a1-a2);
	if(b3>a1+a3) ans+=(b3-a1-a3);

	return ans;
}
pl solve(ll a1, ll a2,ll a3,ll b1,ll b2,ll b3)
{
	ll m1 = min(a1,b2);
	ll m2 = min(a2,b3);
	ll m3 = min(a3,b1);

	a1-=m1;
	b2-=m1;

	a2-=m2;
	b3-=m2;

	a3-=m3;
	b1-=m3;


	ll m11 = min(a1,b1);
	ll m21 = min(a2,b2);
	ll m31 = min(a3,b3);

	a1-=m11;
	b1-=m11;

	a2-=m21;
	b2-=m21;

	a3-=m31;
	b3-=m31;


	return {m1+m2+m3,m1+m2+m3 + m11+m21+m31};

}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 
    //ll n;
    cin>>n;

    ll a1,a2,a3,b1,b2,b3;
    cin>>a1>>a2>>a3>>b1>>b2>>b3;


    cout<<solve2(a1,a2,a3,b1,b2,b3)<<" "<<solve(a1,a2,a3,b1,b2,b3).ff<<endl;
    
    
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
