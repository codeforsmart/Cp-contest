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
ll w,h,l,u,r,d;
long double sbb(ll x, ll y)
{
    ll n = (x+y-2);
    long double ans = 1.0;
    ll r =min(x-1,y-1);
    
    ll upp = 0 , dow = 1, m2 = x+y-2;

    while(upp < r || dow<=r || m2>0)
    {

        if(ans>1000000000 && m2>0)
        {
            m2--;
            ans/=2;
            continue;
        }
        if(ans>10000000000 && dow<=r)
        {
            ans/=double(dow);
            dow++;
            continue;
        }

        if(upp + 1<= r)
        {
            ans*=double(n-upp);
            upp++;
        }
        else if(dow<=r)
        {
            ans/=double(dow);
            dow++;
        }
        else
        {
            ans/=2;
            m2--;
        }
        //cout<<ans<<" "<<upp<<" "<<dow<<endl;

    }
    return ans;
}

long double msm(ll x, ll y)
{
     long double va = 0;
        long double d2 = 1;
        f(i,0,y-1) d2/=y;
        long double cur = d2;

        ll n = y-1;
        ll r = 0;
        va+=cur;
        f(i,1,x+1)
        {
            n++;
            r++;
            cur = cur*double(n/2)/double(r);
            va+=cur;
        }

        return va;
}
long double solve(ll x, ll y)
{
    long double va = 0;

    if(x-1<=0 || y+1>h) va =0;
    else
    {
        x--;
        y++;

        va = msm(x,y);
    }

    return va;
}
long double solve2(ll x, ll y)
{
    swap(x,y);
     long double va = 0;

    if(x-1<=0 || y+1>w) va =0;
    else
    {
        x--;
        y++;

        va = msm(x,y);
    }

    return va;
}
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
    	
        cin>>w>>h>>l>>u>>r>>d;

       // long double dow = sbb(l,d) + sbb(r,u) - sbb(l,u);
        long double up = solve(l,d) + solve2(r,u);

        //dow = dow + up;
        cout<<fixed;
        cout<<setprecision(10)<<up<<endl;
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
