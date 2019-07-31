#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

vector<pii> vp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, cnt=0; cin >> n;
    fr(i, 0, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vp.pb({a*100+b, c*100+d});
    }
    sort(all(vp));
    int s_date = 301, f_date = 301, tmp=0, idx=0;
    while(s_date <= 1130) {
        fr(i, idx, n) {
            if(vp[i].first <= s_date && vp[i].second > f_date) {
                f_date = vp[i].second;
                idx = i;
            }
        }
        if(s_date == f_date) {
            pt('0');
            return 0;
        } else {
            cnt++;
            s_date = f_date;
        }
    }
    pt(cnt);
}