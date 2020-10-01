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
   vector<ll> sb;
    ll x;

    f(0,n)
    {
    	cin>>x;
    	sb.pb(x);
    }

   sort(sb.begin(),sb.end());

   vector<ll> v;

   v.pb(sb[0]);
   f(1,n)
   {
   	if(v.back()!=sb[i]) v.pb(sb[i]);
   }

   ll q;
   ll y,l,r;
   cin>>q;
   ll le=v.size();

   vector<ll> di;
   vector< pair<ll,ll> > d2;
   f(1,le) di.pb(v[i]-v[0]);
 f(1,le) d2.pb(mp(di[i-1],i-1));
 ll si=le-1;
 sort(d2,begin,d2.end());
    while(q--)
    {
    	cin>>y>>x;
    	
    	ll d=x-y+1;

    	vector<ll> ind;
    	for(ll j=si-1;j>=0;j--)
    	{
    		if(d2[j].ff>d)
    		{
    			ind.pb(d2[j].ss);
    		}
    	}
    	sort(ind.begin(),ind.end());
    	ll p=0;
    	ans+=(v[ind[0]])
    	f(1,ind.size())
    	{

    	}
    	cout<<ans<<" ";
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