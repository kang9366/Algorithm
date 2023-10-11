#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
 
using namespace std;
 
int N,A, B, C;
char M, R;
queue<char>q;
queue<char>q1;
 
void solution()
{
    while (q.size() > 4) 
    {
        A = q.size();
        for (int i = 0; i < A; i++)
        {
            if (!q.empty())
            {
                R = q.front();
                q.pop();
                if (q.empty())
                {
                    q1.push(R);
                    break;
                }
                else if (q.front() == R)
                {
                    q.pop();
                }
                else
                {
                    q1.push(R);
                }
            }
            else
            {
                break;
            }
             
        }
        B = q1.size();
        if (A == B)
        {
            for (int i = 0; i < B; i++)
            {
                q.push(q1.front());
                q1.pop();
                C = q.size();
            }
            return;
        }
         
        for (int i = 0; i < B; i++)
        {
            q.push(q1.front());
            q1.pop();
            C = q.size();
        }
    }
     
 
}
int main()
{
    for (int tc = 1; tc <= 10; tc++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> M;
            q.push(M);
        }
        cout << "#" << tc << " ";
        solution();
        for (int i = 0; i < C; i++)
        {
            cout << q.front();
            q.pop();
        }
        cout << endl;
 
    }
 
}