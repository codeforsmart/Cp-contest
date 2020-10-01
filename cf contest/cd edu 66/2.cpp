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

    ll bap = 4294967296;
    string over = "OVERFLOW!!!";

    ll n;
    cin>>n;

    vector<ll> mul;
    mul.pb(1);
    ll ans=0;
    vector<ll> sb;
    string s; ll x;
    ll ind = 0; 
    ll ex = 0;
    while(n--)
    {
    //	f(0,mul.size()) cout<<mul[i]<<" ";
    	cout<<endl;
    	cin>>s;
    	if(s=="for")
    	{
    		cin>>x;
    		sb.pb(x);

    		if(mul[mul.size()-1]*x>=bap)
    		{
    			mul.pb(x);
    		}
    		else 
    		{
    			mul[mul.size()-1] = mul[mul.size()-1]*x;
    		}
    		
    	continue;
    	}

    	if(s == "end")
    	{
    		ll po = sb[sb.size()-1];
    		 sb.pop_back();
    		
    		if(mul[mul.size()-1]%po!=0)
    		{
    			mul.pop_back();
    			mul[mul.size()-1]/=po;

    		}
    		else
    		{
    			mul[mul.size()-1]/=po;
    		}
    		continue;
    	}
    	//cout<<"dsndjsdn "<<ind<<" "<<mul<<endl;
    	//cout<<"yo"<<endl;
    	ll mult = 1 ;

    	f(0,mul.size())
    	{
    		if(mul[i]>= bap/mult) 
    		{
    			mult = bap+2;
    			break;
    		}
    		mult*=mul[i];
    	//cout<<mult<<endl;
    		if(mult>=bap) break;
    	}

    	ans+=mult;

    	if(ans>=bap)
    	{
    		cout<<over<<endl;
    		return 0;
    	}
    	//cout<<ans<<endl;
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