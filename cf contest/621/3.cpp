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

    ll cot[n+1]={0};
    f(i,0,n) cot[a[i]]++;

    ll o =0, e = 0;

    f(i,1,n+1)
    {
    	if(cot[i]==0)
    	{
    		if(i%2==0) e++;
    		else o++;
    	}
    }
   // cout<<o<<e<<endl;
    f(i,0,n)
    {
    	if(a[i]>0)
    	{
    		if(a[i]%2==0) a[i]=2;
    		else a[i]=1;
    	}
    }

    ll fo[n+1]={0},ba[n+1]={0};

    fo[n]=0;

    for(ll i = n-1;i>=0;i--)
    {
    	fo[i] =fo[i+1];

    	if(a[i]) fo[i]=a[i];
    }

    ba[0]=0;
    f(i,1,n)
    {
    	ba[i]=ba[i-1];
    	if(a[i]) ba[i] = a[i];
    }
    
    //f(i,0,n) cout<<ba[i]<<" ";
    //cout<<endl;
    //f(i,0,n) cout<<fo[i]<<" ";
    //cout<<endl;

    bool khatam = 0;
    if(e==0 || o==0) khatam = 1;
    f(i,0,n)
    {
    	if(khatam) break;
    	if(fo[i]==ba[i] && fo[i] && a[i]==0)
    	{
    		if(fo[i]==1)
    		{
    			o--;
    			a[i]=1;
    			if(o==0)
    			{
    				khatam = 1;
    				break;
    			}
    		}
    		else if(fo[i]==2)
    		{
    			e--;
    			a[i]=2;
    			if(e==0)
    			{
    				khatam = 1;
    				break;
    			}
    		}
    	}
    }

   // cout<<o<<e<<endl;
    ll f1 =0,f2 = 0;
    ll in1= 0,in2 = 0;
    f(i,0,n)
    {
    	if(a[i]>0)
    	{
    		f1 = a[i];
    		in1 = i;
    		break;
    	}
    }

    f(j,0,n)
    {	ll i = n-j-1;
    	if(a[i]>0)
    	{
    		f2 = a[i];
    		in2 = j;
    		break;
    	}
    }
    ll co[3]={0};
    co[1]=o;
    co[2]=e;
   // cout<<o<<e<<endl;
   
    if(f1==f2 && f1)
    {
    	if(in1>in2)
    	{
    		while(co[f1]>0 && in2>0)
    		{
    			a[n-in2]=f1;
    			co[f1]--;
    			in2--;
    		}
    	}
    	else
    	{
    		while(co[f1]>0 && in1>0)
    		{
    			a[n-in1]=f1;
    			co[f1]--;
    			in1--;
    		}
    	}
    }

     ll ko = n;
   for(ll i = n-1;i>=0;i--)
   {
   		if(a[i]>0)
   		{
   			ko = i;
   			break;
   		}
   }
   ko++;
   while(ko<n && co[a[ko-1]]>0)
   {
   		a[ko] = a[ko-1];
   		co[a[ko]]--;
   }
    f(i,0,n)
    {
    	if(co[1]==0 || co[2]==0) break;
    	if(a[i]>0)
    	{
    		if(co[a[i]]==0) break;
    		for(ll j = i-1;j>=0;j--)
    		{
    			if(a[j]) break;
    			a[j] = a[j+1];

    			co[a[j]]--;
    			if(co[a[j]]) break;
    		}
    		if(co[a[i]]==0) break;
    		for(ll j = i+1;j<n;j++)
    		{
    			if(a[j]) break;
    			a[j] = a[j-1];

    			co[a[j]]--;
    			if(co[a[j]]) break;
    		}
    	}
    }


    f(i,0,n)
    {
    	if(a[i]==0)
    	{
    		if(co[1])
    		{
    			a[i]=1;
    			co[1]--;
    		}
    		else
    		{
    			a[i]=2;
    			co[2]--;
    		}
    	}
    }

    ll ans = 0;

    //  f(i,0,n) cout<<a[i]<<" ";
    //cout<<endl;
   // return 0;
    f(i,1,n)
    {
    	if(a[i]!=a[i-1]) ans++;
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
