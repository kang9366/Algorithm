#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = {1, 2, 3, 4, 5};
vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int first = 0;
    int second = 0;
    int third = 0;
    
    for(int i = 0; i < answers.size(); i++) {
        if(one[i%one.size()]==answers[i]) {
            first++;
        }
        
        if(two[i%two.size()]==answers[i]) {
            second++;
        }

        if(three[i%three.size()]==answers[i]) {
            third++;
        }
    }
    
    vector<int> temp = {first, second, third};
    int max = *max_element(temp.begin(), temp.end());

    for(int i = 0; i < temp.size(); i++) {
        if(max==temp[i]) {
            answer.push_back(i+1);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}