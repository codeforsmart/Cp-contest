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
vector<ll> va,co;
ll n;
ll sz;

bool solve(ll a1,ll b1,ll ind, ll av, ll bv, ll ko)
{
	//cout<<a1<<" "<<b1<<" "<<ind<<" "<<av<<" "<<bv<<endl;
	if(ind==0)
	{
		a1-=co[ind];
		av = va[ind];
		return solve(a1,b1,ind+1,av,bv,0);
	}

	if(a1<0 || b1<0) return 0;

	if(ind==sz+1)
	{
		if(a1==0 && b1 ==0) return 1;
		return 0;
	}
	bool ok1 = 0, ok2 = 0;
	if(va[ind]>bv || ko==0) ok1 = solve(a1-co[ind],b1,ind+1,max(va[ind],av),bv,0);
	if((ko==1 || va[ind]>av) && !ok1) ok2 = solve(a1,b1-co[ind],ind+1,av,max(va[ind],bv),1);

	return ok1 || ok2;
}
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
    	
    	cin>>n;
    	va.clear();
    	co.clear();

    	ll a[2*n];
    	f(i,0,2*n) cin>>a[i];

    	va.pb(a[0]);
    	co.pb(1);

    	sz = 0;

    	f(i,1,2*n)
    	{
    		if(a[i]<a[i-1]) co[sz]++;
    		else
    		{
    			sz++;
    			co.pb(1);
    			va.pb(a[i]);
    		}
    	}

    	//f(i,0,sz+1)
    	//{
    	//	cout<<va[i]<<" "<<co[i]<<endl;
    	//}
    	bool ok = solve(n,n,0,-1,-1,0);

    	if(ok==1) cout<<"YES"<<endl;
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
