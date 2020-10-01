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
    string s;
    cin>>s;
    ll nh = n/2;
    ll x1=0,n1=0,x2=0,n2=0;
    f(i,0,nh)
    {
    	if(s[i]=='?') x1++;
    	else n1+=s[i]-'0';
    }

    f(i,nh,n)
    {
    	if(s[i]=='?') x2++;
    	else n2+=s[i]-'0';
    }
    
    ll mi = min(x1,x2);

    x1-=mi;
    x2-=mi;

    if(x1==0)
    {
    	swap(x1,x2);
    	swap(n1,n2);
    }

    n2-=n1;

   //cout<<n2<<" "<<x1<<endl;
    if(x1%2==1 || (x1/2)*9!=n2)
    {
    	cout<<"Monocarp"<<endl;
    }
    else
    {
    	cout<<"Bicarp"<<endl;
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
