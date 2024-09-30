#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;

int main() {
    ll N, H;
    cin >> N >> H;
    
    pair<ll, pair<ll, ll>> arr[N];

    ll st = 1;
    ll en = 0;
    for(int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second;
        if(arr[i].first == 1) en += (ll)arr[i].second.first * (ll)arr[i].second.second;
    }

    ll answer = __LONG_LONG_MAX__;

    while(st <= en) {
        ll mid = (st + en)/2;
        ll hp = mid;
        ll attack = H;
        for(int i = 0; i < N; i++) {
            if(arr[i].first == 1) {
                ll a = hp / arr[i].second.first;
                if(hp%arr[i].second.first != 0) a++;
                ll b = arr[i].second.second / attack;
                if(arr[i].second.second % attack != 0) b++;
                
                if(a >= b) hp -= (b-1)*arr[i].second.first;
                else {
                    hp = -1;
                    break;
                }
            } else if(arr[i].first == 2) {
                attack += arr[i].second.first;
                hp += arr[i].second.second;
                if(hp >= mid) hp = mid;
            }
        }

        if(hp == -1) {
            st = mid+1;
        } else {
            en = mid-1;
            answer = min(answer, mid);
        }
    }
    if(answer == __LONG_LONG_MAX__) cout << 0;
    else cout << answer;
}