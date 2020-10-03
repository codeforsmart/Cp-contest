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

    ll t;
    cin>>t;
    ll t1 = 0;
    while(t--)
    {
    	t1++;
    	cout<<"Case #"<<t1<<": ";
    	ll n,k;
    	cin>>n>>k;
    	ll a[n];
    	f(i,0,n) cin>>a[i];

    	vector<ll> di;

        f(i,0,n-1) di.pb(a[i+1]-a[i]);

        sort(di.begin(),di.end());
        reverse(di.begin(),di.end());
        ll st = 1, en = di[0]+1;

        ll mi;
        ll dn = n-1;
        while(st<en)
        {

            mi = (st+en)/2;
            ll ans = 0;
            f(i,0,dn)
            {
                if(di[i]<=mi) break;

                ll pl = di[i]/mi  - (di[i]%mi==0);
                ans+=pl;
            }
            cout<<st<<" "<<en<<" ss "<<ans<<endl;
            if(ans>k) st =mi+1;
            else en = mi;
        }
        cout<<st<<endl;
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
