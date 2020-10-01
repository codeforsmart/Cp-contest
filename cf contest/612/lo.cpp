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
	if(lev>=30) return pan;
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
       // cout<<"ss"<<endl;
    ll t;
    cin>>t;
        ll n = 0;
        p2[29]=1;
    for(ll i = 28;i>=0;i--)
    {
    	p2[i]=p2[i+1]*2;
    }
    while(t--)
    {


   	f(i,0,30)
   	{
   		f(j,0,n+1) sb[j][i] = 0;
   	}
    cin>>n;

    ll a[n];
    f(i,0,n) cin>>a[i];
    sort(a,a+n);
    for(ll j = 0;j<n;j++)
    {
    	ll x = a[j];
	    for(ll i = 29;i>=0;i--)
	    {
	    	if(x%2==0) sb[j][i] = 0;
	    	else sb[j][i] = 1;
	    	x/=2;
	    }
    }
       for(ll j = 0;j<n;j++)
    {
    	f(i,0,30) cout<<sb[j][i]<<" ";
    	cout<<endl;
    }
    cout<<solve(0,n-1,0,0)<<endl;
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
