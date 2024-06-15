#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> m;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(auto &k : keymap) {
        for(int i = 0; i < k.size(); i++) {
            if(m.find(k[i]) != m.end() && m[k[i]] > i+1) {
                m.erase(k[i]);
            }
            m.insert({k[i], i+1});
        }
    }
    
    for(auto &t : targets) {
        int temp = 0;
        for(int i = 0; i < t.size(); i++) {
            if(m.find(t[i]) != m.end()) {
                temp += m[t[i]];   
            } else {
                temp = -1;
                break;
            }
        }
        answer.push_back(temp);
    }
    
    return answer;
}