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

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,q;
    cin>>n>>q;
    deque <ll> a;
    ll x;
    f(0,n) {cin>>x; a.push_back(x);}


    pair<ll,ll> ans[n];

    f(0,n)
    {
    	ll a1 = a.front();
    	a.pop_front();
    	ll a2 = a.front();
    	a.pop_front();
    	ans[i] = mp(a1,a2);
    	a.push_front(max(a1,a2));
    	a.push_back(min(a1,a2));
    }
    vector<ll> sb;
    while(a.size())
    {
    	sb.pb(a.front());
    	a.pop_front();
    }
    while(q--)
    {
    	cin>>x;
    	x--;
    	if(x<n)
    	{
    		cout<<ans[x].ff<<" "<<ans[x].ss<<endl;
    	}
    	else
    	{
    		cout<<sb[0]<<" ";
    		ll di = (x+1)-n;
    		di = (di-1)%(n-1);
    		di++;
    		cout<<sb[di]<<endl;
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