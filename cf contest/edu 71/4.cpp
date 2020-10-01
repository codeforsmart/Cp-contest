#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 998244353 
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
ll pm[300001];
 ll n;
ll solve(vector<pair<ll,ll> > sb)
{
	sort(sb.begin(),sb.end());
	ll co = 1;
	ll b = sb[0].ff;
	ll ans = 1;
	f(i,1,n)
	{
		if(sb[i].ff == b) co++;
		else
		{
			ans*=pm[co];
			ans = ans%mod;
			co =1;
			b = sb[i].ff;
		}
	}
	ans*=pm[co];
	ans = ans%mod;
	return ans;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

   
    cin>>n;
    pm[0]=1;
    f(i,1,n+1)
    {
    	pm[i] = (pm[i-1]*i)%mod;
    }
    vector<pair<ll,ll> > sb1,sb2;
    map < pair<ll,ll> , ll> msm; 
    ll x,y;
    f(i,0,n)
    {
    	cin>>x>>y;
    	sb1.pb(mp(x,y));
    	sb2.pb(mp(y,x));
    	msm[mp(x,y)]++;
    }

    ll ans = (solve(sb1) + solve(sb2) )%mod;

    ll ans1 = 1;
    ll f1 =0 ,f2 = 0;
    for(auto it = msm.begin(); it!=msm.end();it++)
    {
    	pair<ll,ll> hl = it->ff;
    	if(hl.ff<f1 || hl.ss<f2)
    	{
    		ans1=0;
    		break;
    	}
    	f1=hl.ff;
    	f2 = hl.ss;
    	ans1 *= pm[it->ss];
    	ans1 = ans1 %mod;
    }
    
    cout<<(pm[n]-(ans-ans1)+mod)%mod<<endl;
    
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