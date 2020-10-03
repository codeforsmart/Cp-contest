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
 /*
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif
 */
    ll t;
    cin>>t;

    ll t1 = 0;
    while(t--)
    {
    	t1++;

    	cout<<"Case #"<<t1<<": ";

    	ll n,x;
    	cin>>n>>x;

    	vector<pl> sb;

        ll a,b;
    	f(i,0,n) 
        {
            cin>>a>>b;
            sb.pb({a,b});
        }

        sort(sb.begin(),sb.end());

        ll st = sb[0].ff;
        ll ans = 0;

        f(i,0,n)
        {
            if(sb[i].ss<=st) continue;


            ll msm = max(st,sb[i].ff);

            ll req = sb[i].ss - msm;
            ll n1 = req/x + (req%x!=0);

            ans+=n1;

            st = msm+n1*x;
        }

        cout<<ans<<endl;
    	
    	
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
