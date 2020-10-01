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
bool bedi(string s, ll ch1, ll fi)
{
	cout<<s<<" bedi "<<ch1<<" "<<fi<<endl;
	ll l = s.length();
	f(i,0,l-1)
	{
		if(s[i]=='>') ch1--;
		else if(s[i]=='<') ch1++;

		if(ch1<0)
		{
			return 0;
		}
	}

	if(s[l-1]=='=' && ch1==fi) return 1;
	if(s[l-1]=='>' && ch1>fi) return 1;
	if(s[l-1]=='<' && ch1<fi) return 1;

	cout<<"fail"<<endl;
	return 0;

}
bool savish(ll a, string s, ll b)
{
	ll l = s.length();

	ll mi = a, ma = a;

	f(i,0,l)
	{
		if(s[i]=='<')
		{
			
			mi++;
			ma = mod;
		}
		else if(s[i]=='>')
		{
			mi = 0;
			ma--;
		}

		if(ma<0) return 0;
	}

	//cout<<s<<" "<<a<<" "<<b<<" "<<mi<<" "<<ma<<endl;
	if(b>=mi && b<=ma) return 1;
	return 0;
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
    	ll a[n];
    	f(i,0,n) cin>>a[i];
    	string s;
    	cin>>s;
    	s+="a";
    	bool ans =1;
    	ll ind = 0;
    	while(a[0]==-1)
    	{
    		if(s[ind]=='>') a[0]=mod;
    		else if(s[ind]=='<') a[0]=0;
    		else if(a[ind+1]!=-1) a[0] = a[ind+1];

    		ind++;
    		if(ind == n-1) break;
    	}
    	//cout<<ind<<" sss "<<endl;
    	ind = n-2;
    	while(a[n-1]==-1)
    	{
    		if(s[ind]=='>') a[n-1]=0;
    		else if(s[ind]=='<') a[n-1]=mod;
    		else if(a[ind]!=-1) a[n-1] = a[ind];
    		ind--;
    		if(ind<0) break;
    	}
    	
    	ll a1 = a[0],b;
    	string jo = "";
    	jo+=s[0];
    	for(ll i = 1;i<n;i++)
    	{
    		if(a[i]==-1) 
    		{
    			jo+=s[i];
    			continue;
    		}

    		b = a[i];

    		if(savish(a1,jo,b)==0)
    		{
    			ans = 0;
    			break;
    		}
    		a1 = b;
    		jo="";
    		jo+=s[i];
    	}

    	if(ans == 1)
    	{
    		cout<<"YES"<<endl;
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