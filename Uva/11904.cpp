#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%I64d",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define INF                         (int)1e9
#define EPS                         1e-9
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define MOD                         1000000007
typedef long long ll;
/*For you see , each day i love you
 more.Today more than yesterday
  less than tomorrow.*/
using namespace std;

vector<ll> factorials;

void init(){
    factorials.push_back(1);
    for(int i = 1;i<=1000000;i++){
        ll val = (i*factorials.back())%MOD;
        factorials.push_back(val);
    }
}

ll exp(ll a, ll pow){
    if(pow == 0){
        return 1;
    }
    ll val = exp(a, pow/2);
    val = (val*val)%MOD;
    if(pow&1){
        val = (a*val)%MOD;
    }

    return val;
}

ll ncr(ll n, ll r){

    // This is equivalent to n! * modInv(r!) * modInv((n-r)!)

    ll val1 = factorials[n];
    ll val2 = exp(factorials[r], MOD-2);
    ll val3 = exp(factorials[n-r], MOD-2);

    val1 = (val1 * val2)%MOD;
    
    return (val1 * val3)%MOD;
}

int main()
{
	int t;cin>>t;
    init();
    for(int tt=1;tt<=t;tt++){

        int n;cin>>n;
        vector<ll> vec;

        for(int i = 0;i<n;i++){
            ll x;cin>>x;
            vec.push_back(x);
        }

        vector<ll> ans;
        ans.push_back(1);

        ll total = vec[0];
        for(int i = 1;i<n;i++){

            ll upper = total + vec[i]-1;
            ll down = vec[i]-1;

            ll ncrVal = ncr(upper, down);
            ans.push_back(
                (ans.back() * ncrVal)%MOD
            );

            total+=vec[i];
        }
        
        cout<<"Case "<<tt<<": "<<ans.back()<<endl;
    }
	return 0;
}