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
 ll a1[400000];
 vector<ll> tr[400000];
ll k=0;
 ll dfs(ll a)
 {
 	//cout<<"Dsf "<<a<<endl;
 	ll mi=mod;
 	ll mi2=0;
 	f(0,tr[a].size())
 	{
 		ll ko = dfs(tr[a][i]) ; 
 		mi=min(mi,ko);
 		mi2+=ko;
 	}

 	if(mi==mod) 
 		{
 			mi=0;
 		}

 	if(tr[a].size()==0)
 	{
 		k++;
 		return 0;
 	} 
 	if(a1[a]==0) return mi2+tr[a].size()-1;

 	return mi;
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
   
    f(1,n+1) cin>>a1[i];
    	ll x;
    f(0,n-1)
    {
    	cin>>x;
    	tr[x].pb(i+2);
    }

    ll ans = dfs(1);
   // cout<<ans<<" "<<k<<endl;
    cout<< k -ans<<endl;
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