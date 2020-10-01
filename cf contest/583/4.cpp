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

int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,m;
    cin>>n>>m;
    string s[n];
    f(i,0,n) cin>>s[i];
    ll on = 1;
    ll ans = 2;
  	ll a[n][m];
  	ll b[n][m];
  	a[0][0] = 0;
  	ll co = 0;
  	f(i,0,n)	
  	{
  		a[i][0]=0;
  		if(s[i][0]=='#') a[i][0] = 1;
  		f(j,1,m)
  		{
  			if(s[i][j]=='#') {a[i][j] = 1; co++;}
  			else a[i][j] = a[i][j-1];
  			//if(i>0) a[i][j]+=a[i-1][j];
  			//cout<<a[i][j]<<" ";
  		}
  		//cout<<endl;

  	}

  	//cout<<endl;
  	b[0][0] = 0;
  	
  	f(j,0,m)	
  	{
  		b[0][j]=0;
  		if(b[0][j]=='#') b[0][j] = 1;
  		f(i,1,n)
  		{
  			if(s[i][j]=='#') b[i][j] = 1;
  			else b[i][j] = b[i-1][j];
  			//if(j>0) b[i][j]+=b[i][j-1];
  			
  		}
  	}

  	f(i,0,n)	
  	{
  		f(j,0,m)
  		{
  			if(i>0) a[i][j]+=a[i-1][j];
  			if(j>0) b[i][j]+=b[i][j-1];

  		}
  		//cout<<endl;
  	}
  //	cout<<endl;

  	f(i,0,n)	
  	{
  		f(j,0,m)
  		{
  			if(s[i][j]=='#') a[i][j]--,b[i][j]--;

  		}
  		//cout<<endl;
  	}
  	
  	f(i,0,n)	
  	{
  		f(j,0,m)
  		{
  			a[i][j]+=b[i][j];
  			if(i>0 && j>0) ans = min(ans,i+j-a[i][j]);
  			
  			cout<<a[i][j]<<" ";
  		}
  		cout<<endl;
  	}
  	//return 0;
  	f(i,0,n)
  	{
  		f(j,0,m)
  		{
  			s[i][j] = s[n-i-1][m-j-1];
  			a[i][j] = 0;
  			b[i][j] = 0;
  		}
  	}


  	if(n==1 || m==1)
  	{
  		if(co>0) cout<<0<<endl;
  		else cout<<1<<endl;
  		return 0;
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