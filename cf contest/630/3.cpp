#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll exp(ll a,ll b,ll m);

const ll maxn = 200005;
ll siz[maxn], parent[maxn];

void make_set(ll v) 
{
    parent[v] = v;
    siz[v] = 1;
}

ll find_set(ll v) 
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b) 
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
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
    	ll n,k;
    	cin>>n>>k;
    	string s;
    	cin>>s;

    	f(i,0,n+1) {siz[i]=0; parent[i]=0; make_set(i);}

    	for(ll i = 0; i <= (n+1)/2;i++)
    	{
    		union_sets(i,n-i-1);
    	}

    	f(i,0,k)
    	{
    		for(ll j = i; j<n;j+=k)
    		{
    			union_sets(i,j);
    		}
    	}

    	

    	ll sb[n][26];
    	ll co[n] = {0};


    	memset(sb,0,sizeof(sb));

    	set<ll> ans;
    	f(i,0,n)
    	{
    		sb[find_set(i)][s[i]-'a']++;
    		co[find_set(i)]++;
    		ans.insert(find_set(i));
    	}
    	ll anss = 0;
    	for(auto v: ans)
    	{
    		ll ma = 0;
    		f(i,0,26) ma = max(ma,sb[v][i]);

    		anss += co[v]-ma;
    	}

    	cout<<anss<<endl;


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
