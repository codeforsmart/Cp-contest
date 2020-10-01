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
ll gcd(ll a, ll b)
{
	if(a==0) return b;
	return gcd(b%a,a);
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
    	ll n;
    	cin>>n;

    	ll p[n];
    	f(i,0,n) cin>>p[i];

    	ll a,b,x,y;
    	cin>>x>>a>>y>>b;
    	ll k;
    	cin>>k;
    	ll l = (a*b)/gcd(a,b);

    	if(x<y)
    	{
    		swap(a,b);
    		swap(x,y);
    		// x is bigger
    	}
    	sort(p,p+n);

    	ll pre[n+1]={0};
    	pre[0]=0;

    	f(i,0,n) pre[i+1] = pre[i]+p[i];
    	//f(i,0,n+1) cout<<pre[i]<<" ";
    	//cout<<endl;
    	ll ind = -1;
    	ll ans;
    	f(i,1,n+1)
    	{
    		ll nl = i/l;
    		ll al = i/a - nl;
    		ll bl = i/b - nl;
    		ans = ((x+y)*(pre[n]-pre[n-nl]))/100;
    		ans += (x*(pre[n-nl]-pre[n-nl-al]))/100;
    		ans += (y*(pre[n-nl-al]-pre[n-nl-al-bl]))/100;
    		if(ans>=k)
    		{
    			ind = i;
    			break;
    		}
    		//cout<<i<<" "<<ans<<endl;
    	}

    	cout<<ind<<endl;
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
