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

    ll n;
    cin>>n;
    ll a[n];
    f(i,0,n) cin>>a[i];

    map< vector<ll> , ll> sb1; 
    map< vector<ll> , ll> sb2; 
    
    ll nu = 1 << 15;
    ll ff = nu -1;
    ll fff = ff << 15;
   // cout<<ff<<" "<<fff<<endl;
    f(i,0,nu)
    {
    	vector<ll> msm;
    	vector<ll> msm2;
    	
    	ll i2 = i << 15;
    //	cout<<i<<" poc h "<<i2<<endl;
    	f(j,0,n)
    	{
    		ll n1 = a[j] & ff;
    		ll n2 = a[j] & fff;

    		n1^=i;
    		n2^=i2;
    		//cout<<n1<<" sss "<<n2<<endl;
    		//cout<<__builtin_popcount(n1)<<" sppop "<<__builtin_popcount(n2)<<endl;
    		msm.pb(__builtin_popcount(n1));
    		msm2.pb(__builtin_popcount(n2));
    	}

    	vector<ll> ms;
    	vector<ll> ms2;

    	f(j,1,n)
    	{
    		ms.pb(msm[0]-msm[j]);
    		ms2.pb(msm2[j]-msm2[0]);
    	}
    	if(sb1.count(ms)==0)sb1[ms]=i;
    	if(sb2.count(ms2)==0)sb2[ms2]=i2;
    	
    	/*f(i,0,n-1) cout<<ms2[i]<<" ";
    	cout<<endl;
    	f(i,0,n-1) cout<<ms[i]<<" s ";
    	cout<<endl;
    	if(i>=1)break;*/
    }


    for(auto c1 : sb1)
    {
    	if(sb2.count(c1.ff))
    	{
    	//	cout<<c1.ss<<" "<<c1.ff[0]<<" "<<sb2[c1.ff]<<endl;
    		cout<<(c1.ss | sb2[c1.ff])<<endl;
    		return 0;
    	}
    }
    cout<<-1<<endl;
    
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
