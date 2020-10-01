#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = int(3e5) + 99;

int n, m, k;
int a[N];
ll bst[N];
ll psum[N];

ll sum(int l, int r){
    l = max(l, 0);
  return psum[r] - (l == 0? 0 : psum[l - 1]);
}

int main() {
  #ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

  cin >> n >> m >> k;
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    psum[i] = a[i] + (i == 0? 0 : psum[i - 1]);
  
}
  ll res = 0;
  for(int len = 1; len <= m && len <= n; ++len)
      res = max(res, sum(0, len - 1) - k);
  for(int i = 0; i < n; ++i){
    if(i + 1 >= m){
      ll nbst = sum(i - m + 1, i) - k;
      if(i - m >= 0) nbst += bst[i - m];
      bst[i] = max(bst[i], + nbst);
    }

    for(int len = 0; len < m && i + len < n; ++len)
      res = max(res, bst[i] + sum(i + 1, i + len) - k * (len > 0));
  } 

  cout << res << endl;
  return 0;
}            