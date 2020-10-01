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

    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    vector<ll> pr[k];
    ll szz[k]={0};
    ll in = 0;

    bool ok = 1;

    while(ok && in<k)
    {
    	ll co = 0;
    	f(j,0,n)
    	{
    		if(s[j]=='R' && s[j+1]=='L')
    		{
    			co++;
    			pr[in].pb(j);
    		}
    	}

    	if(co==0)
    	{
    		ok = 0;
    		break;
    	}

    	f(j,0,co)
    	{
    		s[pr[in][j]] = 'L';
    		s[pr[in][j]+1] = 'R';
    	}
    	szz[in] = co;
    	in++;
    	//cout<<in<<" "<<co<<" "<<ok<<endl;
    	//cout<<s<<endl;
    }
    //cout<<in<<" "<<ok<<endl;
    //cout<<s<<endl;

    ll co2 = 0;
    	f(j,0,n)
    	{
    		if(s[j]=='R' && s[j+1]=='L')
    		{
    			co2++;
    		}
    	}
    	if(co2==0) ok = 0;

    if(ok)
    {
    	cout<<-1<<endl;
    	return 0;
    }
    ll su = 0;
    f(i,0,in) su+=szz[i];

    //debug(su);
    if(su<k)
    {
    	cout<<-1<<endl;
    	return 0;
    }

    ll ex = k-in;

    f(i,0,in)
    {
    	ll mii = min(ex,szz[i]-1);
    	ex-=mii;
    	f(j,0,mii) cout<<1<<" "<<pr[i][j]+1<<endl;

    	cout<<szz[i]-mii<<" ";

    	f(j,mii,szz[i]) cout<<pr[i][j]+1<<" ";
    	cout<<endl;
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
