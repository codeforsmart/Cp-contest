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
    string s,s1;
    cin>>s>>s1;
    ll ab = 0,ba = 0;
    vector<ll> sb[4];

    f(i,0,n)
    {
    	if(s[i]=='a' && s1[i]=='b') {ab++; sb[0].pb(i);}
    	else if(s[i]=='b' && s1[i]=='a') {ba++; sb[1].pb(i);}
    	else
    	{
    

    		if(s[i]=='a') sb[2].pb(i);
    		else sb[3].pb(i);
    	}
    }
    vector< pair<ll,ll> > ans;
    for(ll j = 0; j+1 <sb[0].size();j+=2)
    {
    	ans.pb(mp(sb[0][j],sb[0][j+1]));

    	swap(s[sb[0][j]],s1[sb[0][j+1]]);
    }

    for(ll j = 0; j+1 <sb[1].size();j+=2)
    {
    	ans.pb(mp(sb[1][j],sb[1][j+1]));

    	swap(s[sb[1][j]],s1[sb[1][j+1]]);
    }
    
    ll i1=n,i2=n,a=n,b=n;

   // cout<<s<<" "<<s1<<endl;
    f(i,0,n)
    {
    	if(s[i]=='a' && s1[i]=='b') {i1 = i;}
    	else if(s[i]=='b' && s1[i]=='a') {i2 = i;}
    	else
    	{
    		

    		if(s[i]=='a')a = i;
    		else b = i;
    	}
    }

    if((i1!=n && i2==n) || (i2!=n && i1==n))
    {
    	cout<<-1<<endl;
    	return 0;
    }

    if(i1!=n && i2!=n)
    {
    	
    		ans.pb(mp(i2,i2));
    		ans.pb(mp(i1,i2));
    	
    }

    cout<<ans.size()<<endl;

    f(i,0,ans.size())
    {
    	cout<<ans[i].ff+1<<" "<<ans[i].ss+1<<endl;
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
