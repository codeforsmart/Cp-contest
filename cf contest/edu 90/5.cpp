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

ll dig(ll n)
{
	ll ans = 0;
	while(n>0)
	{
		ans+=n%10;
		n/=10;
	}
	return ans;
}
ll sb(ll n, ll k)
{
	ll ans = 0;
	f(i,0,k)
	{
		ans+= dig(n+i);
	}
	return ans;
}

ll st_to_nu(string a)
{
	ll l = a.length();
	ll ans = 0;
	ll te = 1;

	for(ll i = l-1;i>=0;i--)
	{
		ans+= (a[i]-'0')*te;
		te*=10;
	}

	return ans;
}
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
    while(t--)
    {
    	ll n,k;
    	cin>>n>>k;

    	ll ans = -1;
    	f(n1,0,n+1)
    	{
    		ll n2 = n-n1;
    		f(j,0,k+1)
    		{
    			ll si = (j*(j+1))/2;
    			if(n1-si<0) break;

    			if((n1-si)%(j+1)==0)
    			{
    				ll xs = (n1-si)/(j+1);

    				string xv = "";

    				xv += char('0' + xs%9);
    				ll nu = xs/9;
    				f(pp,0,nu) xv+='9';

    				if(int(xv[nu]) + j >9)
    				{
    					xv[nu] = char(xv[nu] - j);
	    				ll pop = int(xv[0]-'0')+j;
	    				if(pop>9)
	    				{
	    					xv[0] = '9';

	    					xv = char('0'+ (pop-9)) + xv;
	    				}
	    				else xv[0] = char(xv[0]+j);
    				}
    				
    				
    				ll x = st_to_nu(xv);
    				if(sb(x+j+1,k-j)==n2)
    				{
    					if(ans!=-1) ans = min(ans,x);
    					else ans = x;
    					//cout<<"xx  "<<xv<<" "<<xs<<" "<<n1<<" "<<n2<<" "<<j<<endl;
    					//ans = x;
    					//break;
    				}
    			}

    		}
    		//if(ans!=-1) break;
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
