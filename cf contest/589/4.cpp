#include<bits/stdc++.h>
#define ll int
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
vector<ll> tr[100001];
map<pair<ll,ll>,bool> sb;
 vector<ll> one;
    vector<ll> two;
    vector<ll> three;
bool ch()
{
	
	for(auto po : one)
	{
		for(auto pop : one)
		{
			if(sb[mp(min(po,pop),max(po,pop))]==1) return 0;
		}
	}
	for(auto po : two)
	{
		for(auto pop : two)
		{
			if(sb[mp(min(po,pop),max(po,pop))]==1) return 0;
		}
	}
	for(auto po : three)
	{
		for(auto pop : three)
		{
			if(sb[mp(min(po,pop),max(po,pop))]==1) return 0;
		}
	}
	for(auto po : one)
	{
		for(auto pop : three)
		{
			if(sb[mp(min(po,pop),max(po,pop))]!=1) return 0;
		}
	}
	for(auto po : one)
	{
		for(auto pop : two)
		{
			if(sb[mp(min(po,pop),max(po,pop))]!=1) return 0;
		}
	}
	for(auto po : two)
	{
		for(auto pop : three)
		{
			if(sb[mp(min(po,pop),max(po,pop))]!=1) return 0;
		}
	}
	return 1;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,m;
    cin>>n>>m;
    ll x,y;
    bool con[n+1]={0};
  //  bool con2[n+1]={0};
    
    f(i,0,m)
    {
    	cin>>x>>y;
    	tr[x].pb(y);
    	tr[y].pb(x);
    	if(x==1 || y==1)
    	{
    		con[x+y-1]=1;
    	}
    	
    	ll mi = min(x,y);
    	sb[mp(mi,x+y-mi)]=1;
    }
    ll ans[n+1]={0};
    ans[1]=1;
   
   // one.pb(1);
    if(tr[1].size())
    {
    	//two.pb(tr[1][0]);
    	ans[tr[1][0]]=2;
    	ll tw = tr[1][0];
    	f(i,0,tr[tw].size())
    	{
    		ll twi = tr[tw][i];
    		if(con[twi]==1)
    		{
    			ans[twi]=3;
    		}
    		else ans[twi]=1;
    	}


	    f(i,1,tr[1].size())
	    {
	    	ll mi = min(tr[1][i],tr[1][0]);
	    	if(sb[mp(mi,tr[1][i]+tr[1][0]-mi)]==1)
	    	{
	    		ans[tr[1][i]] = 3;
	    	}
	    	else 
	    	{
	    		if(ans[tr[1][i]]==3)
	    		{
	    			cout<<-1<<endl;
	    			return 0;
	    		}
	    		ans[tr[1][i]] = 2;
	    	}
	    }

    }


    f(i,1,n+1)
    {
    	if(ans[i]==0) 
    	{
    		cout<<-1<<endl;
    		return 0;
    	}
    	if(ans[i]==1) one.pb(i);
    	else if(ans[i]==2) two.pb(i);
    	else three.pb(i);
    }


    if(ch()==0 || two.size()==0 || three.size()==0) 
    {
    	cout<<-1<<endl;
    	return 0;
    }

     f(i,1,n+1)
    {
    	cout<<ans[i]<<" ";
    }
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
