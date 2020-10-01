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
 
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 
    ll n;
    cin>>n;

    vector<pl> sb;

    ll x,y;

    map<ll,ll> cox,coy;
    f(i,0,n)
    {
    	cin>>x>>y;
    	cox[x]++;
    	cox[y]++;

    	sb.pb(mp(x,y));
    }

    ll msmx = 0,msmy = 0;

    ll rx = 0,ry = 0;

    for(auto v: cox)
    {
    	if(v.ss==1)
    	{
    		rx++;
    		msmx = v.ff;
    	}
    }

    for(auto v: coy)
    {
    	if(v.ss==1)
    	{
    		ry++;
    		msmy = v.ff;
    	}
    }

    bool okk = 0;
    if(rx >=1 || ry>=1)
    {
    	sb.pb(mp(msmx,msmy));
    	cox[msmx]++;
    	coy[msmy]++;
    	n++;
    	okk = 1;
    }

    
    f(i,0,n)
    {
    	if(cox[sb[i].ff]==1 && coy[sb[i].ss]==1)
    	{
    		cout<<-1<<endl;
    		return 0;
    	}
    }


    map<ll, vector<ll> >  sbx,sby;


    f(i,0,n)
    {
    	sbx[sb[i].ff].pb(sb[i].ss);
    	sby[sb[i].ss].pb(sb[i].ff);
    }

    ll ans = 0;

    vector<ll> anss;
    for(auto v: sbx)
    {
    	vector<ll> po = v.ss;

    	ll szz = po.size();

    	sort(po.begin(),po.end());

    	f(i,0,szz-1)
    	{
    		anss.pb(po[i+1]-po[i]);
    	}
    }

    for(auto v: sby)
    {
    	vector<ll> po = v.ss;

    	ll szz = po.size();

    	sort(po.begin(),po.end());

    	f(i,0,szz-1)
    	{
    		anss.pb(po[i+1]-po[i]);
    	}
    }
    
    sort(anss.begin(),anss.end());

    ll szzz = anss.size();
    ans = anss[szzz-1];

    if(okk==0)
    {
    	ans/=2;
    }

    cout<<ans<<endl;
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
