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
        freopen("/home/savish/Desktop/2019/google/hash code 2020/c_incunabula.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/google/hash code 2020/c_output.txt", "w", stdout);
    #endif

    ll b,l,d;
    cin>>b>>l>>d;

    ll s[b];
    f(i,0,b) cin>>s[i];

    ll n[l],t[l],m[l],su[l]={0};
    vector<pair<ll,ll> > bl[l];
    ll blid;
    f(i,0,l) 
    {
        cin>>n[i]>>t[i]>>m[i];
        f(j,0,n[i]) 
        {
            cin>>blid;
            su[i]+=s[blid];
            bl[i].pb(mp(-s[blid],blid));
        }
        sort(bl[i].begin(),bl[i].end());
    }

    bool vis[b]={0};
    vector< pair< pair<pair<ll,ll>, pair<ll,ll> > ,ll> > sb;
    f(i,0,l) sb.pb(mp(mp(mp(t[i],-su[i]),mp(-m[i],-n[i])),i));
    sort(sb.begin(),sb.end());
    
    
    cout<<l<<endl;
    f(i1,0,l)
    {
        ll i = sb[i1].ss;
        
        vector<ll> pr;
        f(j,0,bl[i].size())
        {
            if(vis[bl[i][j].ss]==1) continue;
            if(-bl[i][j].ff <= 100 ) break;
            vis[bl[i][j].ss]=1;
            pr.pb(bl[i][j].ss);
        }
        if(pr.size()==0)
        {
            pr.pb(bl[i][0].ss);
        }
        ll sz = pr.size();
        cout<<i<<" "<<sz<<endl;
        f(j,0,sz) cout<<pr[j]<<" ";
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
