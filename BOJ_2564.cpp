#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
 
int calculRoundPos(int dir, int pos, int width, int height)
{
    int blockRound = 2 * (width + height);
    int roundPos = 0;
 
    switch (dir)
    {
        // 북
    case 1:
        roundPos = pos;
        break;
        // 남
    case 2:
        roundPos = blockRound - height - pos;
        break;
        // 서
    case 3:
        roundPos = blockRound - pos;
        break;
        // 동
    case 4:
        roundPos = width + pos;
        break;
    default:
        break;
    }
 
    return roundPos;
}
 
int main()
{
    int width = 0;
    int height = 0;
    cin >> width >> height;
 
    int cnt = 0;
    cin >> cnt;
    queue<pair<int, int>> storeInfo;
 
    while (cnt--)
    {
        int dir = 0;
        int pos = 0;
        cin >> dir >> pos;
        storeInfo.push({ dir, pos });
    }
 
    int startDir = 0;
    int startPos = 0;
    cin >> startDir >> startPos;
 
    int startRoundPos = calculRoundPos(startDir, startPos, width, height);
    int sum = 0;
    int blockRound = 2 * (width + height);
    
    while (!storeInfo.empty())
    {
        int storeDir = storeInfo.front().first;
        int storePos = storeInfo.front().second;
        storeInfo.pop();
 
        int storeRoundPos = calculRoundPos(storeDir, storePos, width, height);
        int dist = abs(startRoundPos - storeRoundPos);
 
        dist = min(dist, blockRound - dist);
 
        sum += dist;
    }
 
    cout << sum;
 
    return 0;
}
