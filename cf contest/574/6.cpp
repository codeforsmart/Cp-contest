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
ll a1[3000][3000],b1[3000][3000];
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,m,a,b,g,x,y,z;
    cin>>n>>m>>a>>b>>g>>x>>y>>z;
    
    

    f(0,n)
    {
    	for(ll j=0;j<m;j++)
    	{
    		a1[i][j] = g;
    		g = (g*x + y)%z; 
    	}
    }

    f(0,n)
    {
    	deque<ll>q;
    	for(ll j=0;j<m;j++)
    	{
    		while(!q.empty() && q.back()>a1[i][j]) q.pop_back();
    		q.push_back(a1[i][j]);
    		if(j>=b && !q.empty() && q.front() == a1[i][j-b]) q.pop_front();
    		b1[i][j]=q.front();
    	}
    }
    ll ans = 0;
    f(b-1,m)
    {
    	deque<ll>q;
    	for(ll j=0;j<n;j++)
    	{
    		while(!q.empty() && q.back()>b1[j][i]) q.pop_back();
    		q.push_back(b1[j][i]);
    		if(j>=a && !q.empty() && q.front() == b1[j-a][i]) q.pop_front();
    		if(j>=a-1) ans+=q.front();
    	}
    }
    
    cout<<ans<<endl;
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