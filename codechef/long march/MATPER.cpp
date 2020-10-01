#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
ll n,m;
map<ll,bool> sb[14];
ll siz[14]={0};
//set<ll> ab[100002];
/*map<ll,ll> va;
ll co=0;*/
ll ans=0;
void solve(ll a, bool vi[14])
{
	/*ll val;
	if(va.count(a)) val=va[a];
	else
	{
		co++;
		va[a]=co;
		val=co;
	}*/

	ll ind=a/n;
	ll le = a - ind*n;
	ll re= le+siz[ind]-1;
	vi[ind]=1;

	ll vais=0;
	f(0,m) 
	{
		if(vi[i]==1) 
			{
				vais++;
				continue;
			}

			ll lgot = sb[i].upper_bound(re)->first;
			if(lgot<n)
			{
				vi[i]=1;
				ll nv = n*i+lgot;
				solve(nv,vi);
				vi[i]=0;
			}
	}

	if(vais==m) ans++;



}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif


 	
 	cin>>n>>m;
 	string s;
 	cin>>s;
 	ll h[n]={0};

 	ll pr=31;
 	ll pp[n];
 	pp[0]=31;

 	ll pi[n]={1};
 	f(1,n)
 	{
 		pp[i]=pp[i-1]*pr;
 		pp[i]=pp[i]%mod;
 		pi[i]=exp(pp[i-1],mod-2,mod);
 	}

 	f(0,n)
 	{
 		h[i]=((s[i]-'a')+1)*pp[i];

 		h[i]=h[i]%mod;
 	}

 	f(1,n) 
 	{
 		h[i]+=h[i-1];
 		h[i]=h[i]%mod;
 	}

 	ll hs[m]={0};

 	string sm[m];
 	f(0,m) 
 	{	
 		cin>>sm[i];
 		siz[i]=sm[i].length();
 		sb[i][n+1]=n+1;
 	}

 	for(ll j=0;j<m;j++)
 	{
 		ll calo=0;
 		for(ll k=0;k<siz[j];k++)
 		{
 			calo+=((sm[j][k]-'a')+1)*pp[k];
 			calo=(calo%mod);
 		}
 		hs[j]=calo;
 	}


 	for(ll j=0;j<m;j++)
 	{
 		ll sz=sm[j].length();
 		ll val2=hs[j];
 		for(ll k=0;k<=n-sz;k++)
 		{
 			bool ac=0;
 			
 			ll val1;
 			if(k>0) val1=h[k+sz-1]-h[k-1]+mod;
 			else val1=h[k+sz-1];
 			val1=val1%mod;

 			val1*=pi[k];

 			val1=val1%mod;

 			//cout<<"j= "<<j<<" k = "<<k<<" val1= "<<val1<<" val2= "<<val2<<endl;
 			if(val1!=val2) ac=1;

 			/*for(ll p=0;p<sz;p++)
 			{
 				if(sm[j][p]!=s[k+p])
 				{
 					ac=1; break;
 				}
 			}*/
 			if(ac==0)
 			{
 				//cout<<j<<" "<<k<<endl;
 				sb[j][k]=1;
 			}
 		}
 	}

 	/*f(0,m)
 	{
 		cout<<i<<endl;
 		for(auto a : sb[i])
 		{
 			cout<<a.ff<<" "<<a.ss<<endl;
 		}
 	}*/
 	bool hello[m]={0};
 	f(0,m)
 	{
 		if(sb[i].size())
 		{
 			hello[i]=1;
 			ll fi=sb[i].begin()->first;
 			solve(n*i+fi,hello);
 			hello[i]=0;
 		}
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