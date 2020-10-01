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
 map<pair<ll,ll> , bool> ch;
 map< pair<ll,ll > , bool> hog;
 ll n,m,k;
 bool pk = 0;
 ll adk(ll x, ll y)
 {
 	if(x>n || y>m || x<=0 || y<=0) return 1;

 	if(ch.count(mp(x,y))) return 1;
 	return 0;
 }
 ll pt(ll x, ll y)
 {
 	if(adk(x,y)) return 4;
 	ll ans = adk(x+1,y) + adk(x,y+1)+ adk(x,y-1) + adk(x-1,y);
 	return ans;
 }
bool msm(ll x, ll y)
{
	if(adk(x,y) || hog.count(mp(x,y))) return 0;

	ll ans = adk(x+1,y) + adk(x,y+1)+ adk(x,y-1) + adk(x-1,y);
	if(ans==4 && k!=(n*m-1))
	{
		pk = 1;
		return 1;
	}
	if(ans>=3) 
		{
			hog[mp(x,y)]=1;
			return 1;
		}

	if(ans==2)
	{
		bool ok = 0;
		if(pt(x+1,y)<=1) ok =  1;
		if(pt(x,y+1)<=1) ok =  1;
		if(pt(x-1,y)<=1) ok =  1;
		if(pt(x,y-1)<=1) ok = 1;
		if(ok)
		{
			//cout<<x<<" "<<y<<endl;
			//cout<<pt(x+1,y)<<" "<<pt(x,y+1)<<" "<<pt(x-1,y)<<" "<<pt(x,y-1)<<endl;
			hog[mp(x,y)]=1;
			return 1;
		}
	}
	return 0;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

   
    cin>>n>>m>>k;
   
    vector< pair<ll,ll> > sb;
    ll x,y;
    f(i,0,k)
    {
    	cin>>x>>y;
    	sb.pb(mp(x,y));
    	ch[mp(x,y)]=1;
    }
    ll ans = 0;
    f(i,0,k)
    {
    	x = sb[i].ff,y=sb[i].ss;
    	ans+= (msm(x,y+1) || msm(x,y-1) || msm(x+1,y) || msm(x-1,y));
    	if(ans>=2 || pk) break;
    }
   // cout<<ans<<endl;
    ch[mp(1,1)]=1;
    if(msm(1,2) && msm(2,1)) ans++;
    if(ans>=2 || pk)
    {
    	cout<<"No"<<endl;
    }
    else
    {
    	cout<<"Yes"<<endl;
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
