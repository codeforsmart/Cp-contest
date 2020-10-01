#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
vector<ll> tr[100005];
bool vis[100005]={0};

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;

    ll co[n+1]={0};

    ll x,y,z;
    ll on = 1;
    f(i,0,n-2)
    {
    	cin>>x>>y>>z;
    	tr[x].pb(y);
    	tr[y].pb(x);

    	tr[x].pb(z);
    	tr[z].pb(x);

    	tr[y].pb(z);
    	tr[z].pb(y);
    	co[x]++;
    	co[y]++;
    	co[z]++;
    }

    f(i,1,n+1)
    {
    	//cout<<co[i]<<" ";
    	if(co[i]==1)
    	{
    		on = i;
    		break;
    	}
    }
   // cout<<endl;
    
    ll tw = 1;

    for(ll j = 0;j<tr[on].size();j++)
    {
    //	cout<<tr[on][j]<<" ";
    	if(co[tr[on][j]]==2)
    	{
    		tw = tr[on][j];
    		break;
    	}
    }

    cout<<on<<" ";
    cout<<tw<<" ";
    vis[on] = 1;
    vis[tw] = 1;
    ll cou = 2;

    ll sum = (n*(n+1))/2;
    sum-=on;
    sum-=tw;
   // return 0;
    while(cou!=n-1)
    {
    	//cout<<on<<" sss "<<tw<<" "<<cou<<endl;
    	ll sz = tr[on].size();
    	for(ll i = 0; i < sz;i++)
    	{
    		if(vis[tr[on][i]]==1) continue;
    		else
    		{
    			cout<<tr[on][i]<<" ";
    			ll dop = tr[on][i];
    			vis[tr[on][i]] = 1;
    			sum-=tr[on][i];
    			cou++;
    			on = tw;
    			tw = dop;
    			break;
    		}
    	}
    //	return 0;
    }

    cout<<sum<<endl;
    
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
