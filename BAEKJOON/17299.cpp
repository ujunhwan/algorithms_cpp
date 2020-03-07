// 17299번 오등큰수
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int F[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int i,j,k;
    int cnt;
    int N; cin >> N;

    stack <int> s;
    vector <int> A(N);
    vector <int> NGF(N);

    for(i=0;i<N;i++) // A
    {
        cin >> A[i];
        F[A[i]] += 1;
    }
    s.push(0);
    for(i=1;i<N;i++) // NGF
    {
        if(s.empty()) 
            s.push(i);
        while(!s.empty() && F[A[i]] > F[A[s.top()]])
        {
            NGF[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        NGF[s.top()] = -1;
        s.pop();
    }
    for(i=0;i<N;i++)
        cout << NGF[i] << " ";

    cout << '\n';
    return 0;
}