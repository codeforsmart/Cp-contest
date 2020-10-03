#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000000
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
    	string s;
        cin>>s;
        ll n = s.length();
        vector<ll> sb;
        sb.pb(1);

        ll ns = 0 , we = 0;
        f(i,0,n)
        {
            ll la = sb.back();
            if(s[i]=='(')
            {
                ll mu = s[i-1]-'0';
                ll nu = (la*mu)%mod;
                sb.pb(nu);
            }
            else if(s[i]==')')
            {
                sb.pop_back();
            }
            else if(s[i]=='N') { ns-=la; ns+=mod; ns = ns%mod;}
            else if(s[i]=='S') { ns+=la; ns = ns%mod;}
            else if(s[i]=='W') {we -=la;we+=mod; we = we%mod;}
            else if(s[i]=='E') {we+=la; we = we%mod;}
        }

        ns = ns%mod;
        we = we%mod;

        ns+=mod;
        we+=mod;

        ns = ns%mod;
        we = we%mod;

        cout<<we+1<<" "<<ns+1<<endl;
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
