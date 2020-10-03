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
ll r,c;
ll a[100][100];
ll va[100][100][4];
bool ok = 1;

ll solve()
{
	vector< pair<ll,ll> > sb;

	f(i,0,r)
	{
		f(j,0,c)
		{
			if(a[i][j]==0) continue;
			ll avg = 0;
			ll n1 = 0;

			if(j-va[i][j][0]>=0)
			{
				avg+=a[i][j-va[i][j][0]];
				n1++;
			}
			if(j+va[i][j][1]<c)
			{
				avg+=a[i][j+va[i][j][1]];
				n1++;
			}
			if(i-va[i][j][2]>=0)
			{
				avg+=a[i-va[i][j][2]][j];
				n1++;
			}
			if(i+va[i][j][3]<r)
			{
				avg+=a[i+va[i][j][3]][j];
				n1++;
			}

			if(n1==0) continue;

			if(a[i][j]*n1<avg) sb.pb(mp(i,j));
		}
	}

	ll sz = sb.size();
	//f(i,0,sz) cout<<sb[i].ff<<" "<<sb[i].ss<<endl;
	//cout<<endl;
	if(sz==0)
	{
		ok = 0;
		return 0;
	}
	ll ans = 0;
	f(i,0,sz)
	{
		ans+=a[sb[i].ff][sb[i].ss];
		a[sb[i].ff][sb[i].ss]=0;
	}

	f(i,0,r)
	{
		f(j,0,c)
		{
			if(a[i][j]==0) continue;
			while(a[i][j-va[i][j][0]]==0 && j-va[i][j][0]>=0)
			{
				va[i][j][0]++;
			}
			while(j+va[i][j][1]<c && a[i][j+va[i][j][1]]==0)
			{
				va[i][j][1]++;
			}
			if(i-va[i][j][2]>=0 && a[i-va[i][j][2]][j]==0)
			{
				va[i][j][2]++;
			}
			if(i+va[i][j][3]<r && a[i+va[i][j][3]][j]==0)
			{
				va[i][j][3]++;
			}
		}
	}
	return ans;
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
    	cin>>r>>c;
    	if(r*c>100)
    	{
    		cout<<0<<endl;
    		continue;
    	}
    	
    	ok = 1;

    	

    	f(i,0,r) f(j,0,c) f(k,0,4) va[i][j][k] = 1;
    	ll su = 0;
    	f(i,0,r)
    	{
    		f(j,0,c)
    		{
    			cin>>a[i][j];
    			su+=a[i][j];
    		}
    	}
    	ll sum = su;
    	ll mi = 0;
    	while(ok) 
    		{
    			mi+=solve();
    			if(ok==0) break;
    			sum+=(su-mi);
    			//cout<<sum<<endl;
    		}

    	cout<<sum<<endl;

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
