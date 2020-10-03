#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
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

    	ll n,d;
        cin>>n>>d;
        ll a[n];
        ll ma = 0;
        f(i,0,n) cin>>a[i];
        f(i,0,n) ma= max(ma,a[i]);
        //sort(a,a+n);

        map<ll,ll> sb;

        f(i,0,n) sb[a[i]]++;

        if(d==2)
        {
            ll ans = 1;
            for(auto v = sb.begin();v!=sb.end();v++)
            {
                if(v->ss>=2) ans = 0;
            }
            cout<<ans<<endl;
        }
        else
        {

            ll on = 1;
            ll ans = 2;
            for(auto v = sb.begin();v!=sb.end();v++)
            {
                if(v->ss>=3){ ans = 0; break;}

                if(v->ss>=2)
                {
                    if(v->ff!=ma)
                    {
                        ans = min(ans,on);
                    }
                }
                else if(v->ss==1)
                {
                    if(sb.count(2*v->ff))
                    {
                        ans= min(ans,on);
                    }
                }
            }
            cout<<ans<<endl;
        }

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
