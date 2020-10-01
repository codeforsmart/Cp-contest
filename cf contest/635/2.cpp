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

pair<ll,ll> sr(ll a,vector<ll> r)
{
	ll nr = r.size();
	if(a<=r[0]) return mp(0,0);
	if(a>=r[nr-1]) return mp(nr-1,nr-1);

	ll st = 0,en = nr-1;

	while(st<en)
	{
		ll mi = (st+en+1)/2;

		if(r[mi]>a) en = mi-1;
		else st = mi;
	}
	ll okk = st+1;
	
	if(a-r[st]>r[st+1]-a) st = okk;
	else if(a-r[st]<r[st+1]-a) okk = st;
	return mp(st,okk);
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
    while(t--)
    {
    	ll nr,ng,nb;
    	cin>>nr>>ng>>nb;

    	vector<ll> r,b,g;
    	ll x;
    	f(i,0,nr)
    	{
    		cin>>x;
    		r.pb(x);
    	}
    	f(i,0,ng)
    	{
    		cin>>x;
    		g.pb(x);
    	}
    	f(i,0,nb)
    	{
    		cin>>x;
    		b.pb(x);
    	}

    	sort(r.begin(),r.end());
    	sort(g.begin(),g.end());
    	sort(b.begin(),b.end());

    	ll minu = -1;
    	pair<ll,ll> r1[nr][2],b1[nb][2],g1[ng][2];
    	
    	f(i,0,nr) {r1[i][0] = mp(minu,minu) , r1[i][1] = mp(minu,minu);}
    	f(i,0,nb) {b1[i][0] = mp(minu,minu) , b1[i][1] = mp(minu,minu);}
    	f(i,0,ng) {g1[i][0] = mp(minu,minu) , g1[i][1] = mp(minu,minu);}
    	ll x1,y1;
    	f(i,0,nr)
    	{
    		r1[i][0] = sr(r[i],g);

    		x1 = r1[i][0].ff;
    		if(g1[x1][0] == mp(minu,minu) )
    		{
    			g1[x1][0] = {i,i};
    		}
    		else
    		{
    			if(abs(r[i]-g[x1])==abs(r[g1[x1][0].ff]-g[x1]))
    			{
    				g1[x1][0] = {min(i,g1[x1][0].ff),max(i,g1[x1][0].ss)};
    			}
    			else if(abs(r[i]-g[x1])<abs(r[g1[x1][0].ff]-g[x1]))
    			{
    				g1[x1][0] = {i,i};
    			}
    		}
    		x1 = r1[i][0].ss;
    		if(g1[x1][0] == mp(minu,minu) )
    		{
    			g1[x1][0] = {i,i};
    		}
    		else
    		{
    			if(abs(r[i]-g[x1])==abs(r[g1[x1][0].ff]-g[x1]))
    			{
    				g1[x1][0] = {min(i,g1[x1][0].ff),max(i,g1[x1][0].ss)};
    			}
    			else if(abs(r[i]-g[x1])<abs(r[g1[x1][0].ff]-g[x1]))
    			{
    				g1[x1][0] = {i,i};
    			}
    		}


    		r1[i][1] = sr(r[i],b);

    		x1 = r1[i][1].ff;
    		if(b1[x1][0]==mp(minu,minu))
    		{
    			b1[x1][0] = {i,i};
    		}
    		else
    		{
    			if(abs(r[i]-b[x1])==abs(r[b1[x1][0].ff]-b[x1]))
    			{
    				b1[x1][0] = {min(i,b1[x1][0].ff),max(i,b1[x1][0].ss)};
    			}
    			else if(abs(r[i]-b[x1])<abs(r[g1[x1][0].ff]-b[x1]))
    			{
    				b1[x1][0] = {i,i};
    			}
    		}
    		x1 = r1[i][1].ss;
    		if(b1[x1][0]==mp(minu,minu))
    		{
    			b1[x1][0] = {i,i};
    		}
    		else
    		{
    			if(abs(r[i]-b[x1])==abs(r[b1[x1][0].ff]-b[x1]))
    			{
    				b1[x1][0] = {min(i,b1[x1][0].ff),max(i,b1[x1][0].ss)};
    			}
    			else if(abs(r[i]-b[x1])<abs(r[g1[x1][0].ff]-b[x1]))
    			{
    				b1[x1][0] = {i,i};
    			}
    		}
    	}

    	f(i,0,ng)
    	{
    		if(g1[i][0]==mp(minu,minu)) g1[i][0] = sr(g[i],r);


    		g1[i][1] = sr(g[i],b);
    		
    		x1 = g1[i][1].ff;
    		if(b1[x1][1]==mp(minu,minu))
    		{
    			b1[x1][1] = {i,i};
    		}
    		else
    		{
    			if(abs(g[i]-b[x1])==abs(g[b1[x1][1].ff]-b[x1]))
    			{
    				b1[x1][1] = {min(i,b1[x1][1].ff),max(i,b1[x1][1].ss)};
    			}
    			else if(abs(g[i]-b[x1])<abs(g[b1[x1][1].ff]-b[x1]))
    			{
    				b1[x1][1] = {i,i};
    			}
    		}
    		x1 = g1[i][1].ss;
    		if(b1[x1][1]==mp(minu,minu))
    		{
    			b1[x1][1] = {i,i};
    		}
    		else
    		{
    			if(abs(g[i]-b[x1])==abs(g[b1[x1][1].ff]-b[x1]))
    			{
    				b1[x1][1] = {min(i,b1[x1][1].ff),max(i,b1[x1][1].ss)};
    			}
    			else if(abs(g[i]-b[x1])<abs(g[b1[x1][1].ff]-b[x1]))
    			{
    				b1[x1][1] = {i,i};
    			}
    		}
    	}

    	f(i,0,nb)
    	{
    		if(b1[x1][0]==mp(minu,minu))b1[i][0] = sr(b[i],r);
    		if(b1[x1][1]==mp(minu,minu))b1[i][1] = sr(b[i],g);
    	}

    	ll ans = (r[0]-b[0])*(r[0]-b[0]) + (b[0]-g[0])*(b[0]-g[0]) + (r[0]-g[0])*(r[0]-g[0]);

    	ll i1,j1,k1;
    	f(i,0,nr)
    	{
    		i1 = i;
    		ll ok[2]={r1[i][0].ff,r1[i][0].ss};
    		ll ok2[2]={r1[i][1].ff,r1[i][1].ss};
    		f(j,0,2)
    		{
    			if(j==1 && ok[j-1]==ok[j]) continue;
    			j1 = ok[j];
    			f(k,0,2)
    			{
    				if(k==1 && ok2[k-1]==ok2[k]) continue;
    				k1 = ok2[k];

    				ans = min(ans,(r[i1]-b[k1])*(r[i1]-b[k1]) + (b[k1]-g[j1])*(b[k1]-g[j1]) + (r[i1]-g[j1])*(r[i1]-g[j1]));
    			}
    		}
    	}
        
      /*  f(i,0,ng)
        {
            cout<<g1[i][1].ff<<" pol "<<g1[i][1].ss;
        }*/
       // cout<<ans<<endl;
    	f(i,0,ng)
    	{
    		j1 = i;
    		ll ok[2]={g1[i][0].ff,g1[i][0].ss};
    		ll ok2[2]={g1[i][1].ff,g1[i][1].ss};
    	//	cout<<ok2[0]<<" dddd "<<ok2[1]<<endl;
    		f(j,0,2)
    		{
    			if(j==1 && ok[j-1]==ok[j]) continue;
    			i1 = ok[j];
    			f(k,0,2)
    			{
    				if(k==1 && ok2[k-1]==ok2[k]) continue;
    				k1 = ok2[k];

    				ans = min(ans,(r[i1]-b[k1])*(r[i1]-b[k1]) + (b[k1]-g[j1])*(b[k1]-g[j1]) + (r[i1]-g[j1])*(r[i1]-g[j1]));
    			
    			 //   cout<<i1<<" "<<j1<<" "<<k1<<" "<<ans<<endl;
    			}
    		}
    	}
    // cout<<ans<<endl;
    	f(i,0,nb)
    	{
    		k1 = i;
    		ll ok[2]={b1[i][0].ff,b1[i][0].ss};
    		ll ok2[2]={b1[i][1].ff,b1[i][1].ss};
    		f(j,0,2)
    		{
    			if(j==1 && ok[j-1]==ok[j]) continue;
    			i1 = ok[j];
    			f(k,0,2)
    			{
    				if(k==1 && ok2[k-1]==ok2[k]) continue;
    				j1 = ok2[k];

    				ans = min(ans,(r[i1]-b[k1])*(r[i1]-b[k1]) + (b[k1]-g[j1])*(b[k1]-g[j1]) + (r[i1]-g[j1])*(r[i1]-g[j1]));
    			}
    		}
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
