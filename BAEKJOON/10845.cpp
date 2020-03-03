#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    queue <int> q;
    int T; cin >> T;
    int num;   
    for(int i=0;i<T;i++)
    {
        string cmd; cin >> cmd;
        if(cmd == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if(cmd == "pop")
        {
            if(q.empty() == 1)
            {
                cout << "-1" << '\n';
                continue;
            }
            cout << q.front() << '\n';
            q.pop();
        }
        else if(cmd == "size")
        {
            cout << q.size() << '\n';
        }
        else if(cmd == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if(cmd == "front")
        {
            if(q.empty() == 1)
            {
                cout << "-1" << '\n';
                continue;
            }
            cout << q.front() << '\n';
        }
        else if(cmd == "back")
        {
            if(q.empty() == 1)
            {
                cout << "-1" << '\n';
                continue;
            }
            cout << q.back() << '\n';
        }
        else continue;
    }
}