#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> m;

    int rank = 0;
    for(auto &i : players) {
        m.insert({i, rank});
        rank++;
    }
                                                                          
    for(auto &i : callings) {
        int rank = m[i];
        string temp = players[rank-1];
        players[rank-1] = players[rank];
        players[rank] = temp;
        
        m[i] = rank-1;
        m[temp] = rank;
    }
    return players;
}
