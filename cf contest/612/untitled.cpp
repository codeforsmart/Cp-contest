#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
bool sb[100001][30];
ll p2[31]={0};
ll solve(ll l, ll r, ll lev, ll pan)
{
	if(lev>=30 || l==r) return pan;
	if(sb[l][lev]==sb[r][lev]) return solve(l,r,lev+1,pan);

	ll ind = l;

	while(sb[ind][lev]!=1)
	{
		ind++;
	}

	return min(solve(l,ind-1,lev+1,pan+p2[lev]),solve(ind,r,lev+1,pan+p2[lev]));
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


 	ll n;
    cin>>n;

    ll a[n];
    f(i,0,n) cin>>a[i];
    
    ll ma = a[0];

    f(i,0,n) ma = max(ma,a[i]);
    ll ans = 2*ma;
    f(i,0,50)
    {
    	ll mi = 0;
    	f(k,0,n)
    	{
    		ll nu = a[k]^i;
    		mi = max(mi,nu);
    	}
    	
    
    	ans = min(ans,mi);
    		cout<<i<<" "<<mi<<" "<<ans<<endl;
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
