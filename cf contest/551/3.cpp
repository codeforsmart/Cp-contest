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

    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll a[n]={0};
    ll co=0;
    bool ans=1;
    if(s[0]=='(') a[0]=1;
    else if(s[0]==')') 
    	{
    		a[0]=-1;
    		ans=0;
    	}
    else co++;
    f(1,n)
    {
    	a[i]+=a[i-1];

    	if(s[i]=='(') a[i]++;
   		else if(s[i]==')') 
    	{
    		a[i]--;
    	}
    	else co++;
    }

    ll fi = a[n-1];
    ll ex = co;
    ll pfi = abs(fi);
    ll h2 = abs(pfi-ex);

  //  cout<<fi<<" "<<ex<<endl;
    if(ex<pfi || h2%2==1)
    {
    	cout<<":("<<endl;
    	return 0;
    }
    ll pr[n]={0};
    ll pp=0,nn=0;

    if(fi>0) 
    {
    	nn = pfi;
    	pp = h2/2;
    	nn += pp;
    }
    else
    {
    	pp = pfi;
    	nn = h2/2;
    	pp += nn;
    }
    ll cu=0;
    f(0,n)
    {
    	if(s[i]=='(')
    	{
    		cu++;
    		pr[i]=1;
    	}
    	else if(s[i]==')')
    	{
    		cu--;
    		pr[i]=-1;
    	}
    	else
    	{
    		if(pp>0) 
    		{
    			pp--;
    			cu++;
    			pr[i]=1;
    		}
    		else
    		{
    			cu--;
    			pr[i]=-1;
    		}
    	}
    	if(i!=n-1 && cu<=0 ) 
    	{
    		cout<<":("<<endl;
    		return 0;
    	}
    }

    f(0,n)
    {
    	if(pr[i]==1) cout<<'(';
    	else cout<<')';
    }
    cout<<endl;
    
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