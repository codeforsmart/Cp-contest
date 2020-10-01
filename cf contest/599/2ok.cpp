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

        if(a==b)
        {
            cout<<"Yes"<<endl;
            cout<<1<<endl;
            cout<<1<<" "<<1<<endl;
            continue;
        }
       vector< pair<ll,ll> > pr;
       vector<ll> as[26];
      // vector<ll> bs[26];
       
       f(i,0,n)
       {
        if(a[i]!=b[i])
        {
            as[a[i]-'a'].pb(i+1);
            as[b[i]-'a'].pb(i+1);
        }
       }
       bool ok = 1;
       f(i,0,26)
       {
        if(as[i].size()%2!=0)
        {
            ok = 0;
            break;
        }
        ll sz = as[i].size();
        f(j,0,sz) 
        {
            pr.pb(mp(bs[i][j],as[i][j]));
        }
       }

       if(ok==0 || pr.size()>2*n)
       {
        cout<<"NO"<<endl;
        continue;
       }

       cout<<"YES"<<endl;

      ll co = 0;
      vector<ll> hp;

      

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
