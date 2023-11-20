//Siddharth Jha

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

#define ll                       long long int
#define mod                      1000000007
#define inf                      1e18
#define pb                       push_back
#define vi                       vector<ll>
#define vs                       vector<string>
#define pii                      pair<ll,ll>
#define ump                      unordered_map
#define mp                       make_pair
#define pq_max                   priority_queue<ll>
#define pq_min                   priority_queue<ll,vi,greater<ll> >
#define all(n)                   n.begin(),n.end()
#define ff                       first
#define ss                       second
#define mid(l,r)                 (l+(r-l)/2)
#define bitc(n)                  __builtin_popcount(n)
#define SET(a)                   memset( a, -1, sizeof a )
#define CLR(a)                   memset( a,  0, sizeof a )
#define Pi                       3.141592653589793
#define loop(x,start,end)        for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define _fast                    ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
#define iter(container,it)       for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)             {string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)          for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
template <typename T> T          gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T          lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cout << *it << " = " << a << endl;
err(++it, args...);
}
vi ans;
map<ll,ll> freq;
void lowest_val (pii k) {
    if (k.ss == 1) freq.erase(k.ff);
    else freq[k.ff]--;
}
void subset(ll new_val) {
    loop(mask,0,(1<<ans.size())) {
        ll sum = new_val;
        loop(j,0,ans.size()) {
            if ((mask>>j)&(1)) sum += ans[j];
        }
        lowest_val(*freq.find(sum));
    }
}

void solve() {
    ans.clear();
    freq.clear();
    ll n,a; cin >> n;
   
    loop (i,0,(1<<n)) {
        cin >> a;
        freq[a]++;
    }
    freq[0]--;
    if (freq[0] <= 0) freq.erase(0);
    ans.pb((*freq.begin()).ff);
    lowest_val(*freq.begin());
    // ans.pb((*freq.begin()).ff);
    // lowest_val(*freq.begin());
    // lowest_val(*freq.find(ans[0]+ans[1]));

    for (ll i = 1; i < n; i++) {
        ll new_val = (*freq.begin()).ff;
        subset(new_val);
        ans.pb(new_val);
    }

    loop (i,0,n) cout << ans[i] << " ";
    cout << "\n";
}

int main(int argc, char const *argv[]){
    _fast
  //#ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
  //#endif
    ll t; cin>>t;
    while(t--){
     solve();
    }
  return 0;
}

/* 

1, 3, 5, 100

0 1 4 6 101 104 106 9 8 103 108 105 5 100 109  3
0 1 1+3 1+5 1+100 1+3+100 1+5+100 1+3+5 3+5 3+100 3+5+100 5 


*/