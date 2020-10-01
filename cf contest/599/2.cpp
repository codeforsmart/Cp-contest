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
    	ll n;
    	cin>>n;
    	
        string a,b;
        cin>>a>>b;

        vector< pair<char,char> > di;
        ll co = 0;
        f(i,0,n)
        {
            if(a[i]!=b[i])
            {
                di.pb(mp(a[i],b[i]));
            }
            else co++;
        }
        ll sz = di.size();
        if(sz==1 || sz>=3)
        {
            cout<<"No"<<endl;
            continue;
        }

        if(sz==0)
        {
            if(co>0)
            {
                cout<<"Yes"<<endl;
            }
            else cout<<"NO"<<endl;
            continue;
        }

        if(di[0].ff == di[1].ff && di[0].ss == di[1].ss)
        {
            cout<<"Yes"<<endl;
        }
        else cout<<"NO"<<endl;
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
