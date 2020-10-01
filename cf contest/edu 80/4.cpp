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

    //ll pri = 33;
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    f(i,0,n) f(j,0,m) cin>>a[i][j];
   
    ll p2 = 1 << m;

    ll ans1,ans2;
    ll st = 0, en = 1e9;

    while(st<=en)
    {
        ll mi = (st+en+1)/2;
        ll sb[p2]={0};
        f(i,0,n)
        {
            ll nu = 0;
            f(j,0,m)
            {
                if(a[i][j]>=mi) nu |= 1<<j;
            }
            sb[nu]=i+1;
        }
        bool ok = 0;
        f(i,0,p2)
        {
            if(sb[i]==0) continue;
            f(j,i,p2)
            {
                if(sb[j]==0) continue;
                ll x = i | j;
                if(x!=p2-1) continue;

                ok  = 1;
                ans1 = sb[i];
                ans2 = sb[j];
            }
        }

        if(ok==0)
        {
            en = mi-1;
        }
        else st = mi + 1;;
    }

    cout<<ans1<<" "<<ans2<<endl;
    
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
