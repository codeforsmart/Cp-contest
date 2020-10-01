#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
vector<ll> del;
vector<ll> tr[100001];
ll c[100005]={0};

void dfs(ll a)
{
	ll co=0;
	f(0,tr[a].size())
	{
		dfs(tr[a][i]);
		if(c[tr[a][i]]==1 ) co++;
	}

	if(co==tr[a].size() && c[a]==1) 
		{
			del.pb(a);
		//	return 1;
		}

		//return 0;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    cin>>n;
    ll x;
    ll root;
    f(1,n+1)
    {
    	cin>>x>>c[i];
    	if(x==-1) root=i;
    	else tr[x].pb(i);
    }
    
    dfs(root);

    //cout<<op<<endl;
    if(del.size()==0)
    {
    	cout<<-1<<endl;
    	return 0;
    }

    sort(del.begin(),del.end());

    f(0,del.size()) cout<<del[i]<<" ";
    cout<<endl;
    
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