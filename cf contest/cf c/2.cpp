#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);

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
    f(0,n) cin>>a[i];
    ll ans[n]={0};
    ll co =0;
    vector< pair<ll,ll> > sb;
    f(0,n) 
    {
    	if(a[i]>=0)
    	{
    			sb.pb(mp(-a[i]-1,i));
    	}
    	else sb.pb(mp(a[i],i));
    
    }

    sort(sb.begin(),sb.end());
  	ll sz = 0;
    if(n%2==1)
    {	
    	sb[sz].ff = -sb[sz].ff-1;
    }
    
    f(0,sb.size())
    {
    	ans[sb[i].ss] = sb[i].ff;
    }
   

    f(0,n) cout<<ans[i]<<" ";
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