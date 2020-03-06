// 17298번 오큰수
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int i; //index
    int N; cin >> N;
    stack <int> s;
    vector <int> A(N);
    vector <int> NGE(N);

    for(int i=0;i<N;i++)
    {
        cin >> A[i];
    }
    s.push(0);
    for(i=1;i<N;i++)
    {
        if(s.empty())
            s.push(i);
            
        while(!s.empty() && A[s.top()] < A[i])
        {
            NGE[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        NGE[s.top()] = -1;
        s.pop();
    }
    for(int i=0;i<N;i++)
    {
        cout << NGE[i] << ' ';
    }
    cout << '\n';
}