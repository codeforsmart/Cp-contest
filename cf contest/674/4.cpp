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

    ll a[n+1]={0};
    f(i,1,n+1) cin>>a[i];

    f(i,1,n+1) a[i]+=a[i-1];

    map<ll,ll> sb;
    sb[0] = 0;

    vector<pl> msm;

    f(i,1,n+1)
    {
    	//cout<<a[i]<<" ";
    	//cout<<sb.count(a[i])<<endl;
    	if(sb.count(a[i])==0)
    	{
    		sb[a[i]] = i;
    		continue;
    	}
    	//debug(i);
    	ll pre = sb[a[i]];
    	sb[a[i]] = i;

    	msm.pb({pre+1,i});
    }
   // cout<<endl;
    sort(msm.begin(),msm.end());

    ll ans = 0;

    ll sz = msm.size();
    ll la = 0;
    //debug(sz);
    f(i,0,sz)
    {
    	if(msm[i].ff<la)
    	{
    		
    		la = min(la,msm[i].ss);
    		continue;
    	}

    	la = msm[i].ss;
    	ans++;
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
