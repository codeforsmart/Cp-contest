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
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
ll a[51][51];
 ll n,m;
bool ch(ll x1, ll y1)
{
	if(x1<0 || y1<0 || x1>=n || y1>=m) return 0;

	if(a[x1][y1]==1) return 1;

	return 0;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

   
    cin>>n>>m;
    ll o = 0;
    

    f(i,0,n)
    {
    	f(j,0,m) cin>>a[i][j];
    }

    vector< pair<ll,ll> > sb;
    bool ans = 1;
    f(i,0,n)
    {
    	f(j,0,m)
    	{
    		if(a[i][j]==0) continue;

    		if((ch(i+1,j+1) && ch(i+1,j) && ch(i,j+1))) sb.pb(mp(i+1,j+1));
    		else if((ch(i-1,j-1) && ch(i-1,j) && ch(i,j-1)) || ((ch(i+1,j-1) && ch(i+1,j) && ch(i,j-1)))){ans = 1;}
    		else if((ch(i-1,j+1) && ch(i-1,j) && ch(i,j+1)) ) { ans = 1;}
    		else ans = 0;

    		if(ans==0)
    		{
    			cout<<-1<<endl;
    			return 0;
    		}

    	}
    }
    
    cout<<sb.size()<<endl;
    f(i,0,sb.size())
    {
    	cout<<sb[i].ff<<" "<<sb[i].ss<<endl;
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