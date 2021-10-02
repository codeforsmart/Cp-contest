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
#define ub upper_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef pair<ll,ll> pl;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 
ll exp(ll a,ll b,ll m);

string vow = "AEIOU";

bool is_vowel(char a)
{
    for(auto v: vow) if(a==v) return 1;
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
    f(tt,1,t+1)
    {
        cout<<"Case #"<<tt<<": ";
        string s;
        cin>>s;

        ll a[26]={0};
        for(auto v: s)
        {
            a[v-'A']++;
        }
        ll n = s.size();
        

        ll sol = mod;
        f(i,0,26)
        {
            ll ans = 0;
            char po = 'A' + i;
            bool is_v = is_vowel(po);
            f(j,0,n)
            {
                if(s[j]==po) continue;

                bool is_v2 = is_vowel(s[j]);

                if(is_v2 == is_v) ans+=2;
                else ans++;

            }
            sol = min(sol,ans);
        }
        cout<<sol<<endl;

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
