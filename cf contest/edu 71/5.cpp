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

string solve(ll a)
{
	string s="";
	f(i,0,14)
	{
		if(a%2==0) s+="0";
		else s+="1";
		a/=2;
	}
	return s;
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	

   	cout<<"? ";
   	f(i,1,101) {cout<<128*i<<" ";}
   	cout<<endl;
   	cout<<flush;
   	ll s1;
   	cin>>s1;

   	string s;
   	s = solve(s1);
   	
   	ll ans= 0;
   	ll tw =1;
   	f(i,0,7)
   	{
   		ans+= (s[i]-'0'+0)*tw;
   		tw*=2;
   	}

   	cout<<"? ";
   	f(i,1,101) {cout<<i<<" ";}
   	cout<<endl;
   	cout<<flush;
    
    cin>>s1;
    s=solve(s1);
    

    f(i,7,14)
   	{
   		ans+= (s[i]-'0'+0)*tw;
   		tw*=2;
   	}

   	cout<<"! "<<ans<<endl;
   	cout<<flush;
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