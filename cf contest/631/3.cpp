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
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll exp(ll a,ll b,ll m);

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,m;
    cin>>n>>m;

    ll a[m];

    f(i,0,m) cin>>a[i];

    ll su = 0;
    f(i,0,m) su+=a[i];

    if(su<n)
    {
    	cout<<-1<<endl;
    	return 0;
    }
    
    ll ex = su-n;

    vector< pair<ll,ll> > sb;

    f(i,0,m) sb.pb(mp(-a[i],i));

    //sort(sb.begin(),sb.end());

    ll pr[m]={0};

    ll st = 1;

    pr[sb[0].ss] = 1;
    f(i,1,m)
    {

    	ll i1 = sb[i].ss;
    	ll va = -sb[i].ff;
    	ll pv = -sb[i-1].ff;

    	if(ex<pv-1)
    	{
    		st = st + pv -ex;
    		ex = 0;
    	}
    	else
    	{
    		st = st + 1;
    		ex -= (pv-1);
    	}

    	pr[sb[i].ss] = st;

    	if(st+va-1>n)
    	{
    		cout<<-1<<endl;
    		return 0;
    	}
    }

    f(i,0,m) cout<<pr[i]<<" ";
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
