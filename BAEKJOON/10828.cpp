#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int SizeOfCmd;
    int num;
    int stack[10000];
    int cur = 0;
    string cmd;

    cin >> SizeOfCmd;
    for(int i=0;i<SizeOfCmd;i++)
    {
        cin >> cmd;
        if(cmd == "push")
        {
            cin >> num;
            stack[cur] = num;
            cur += 1;
        }
        else if(cmd == "pop")
        {
            if(cur <= 0)
                {
                    cout << "-1" << "\n";
                }
            else
            {
                cout << stack[cur-1] << '\n';
                cur -= 1;
            }
        }
        else if(cmd == "size")
        {
            cout << cur << "\n";
        }
        else if(cmd == "empty")
        {
            if(cur == 0)
                cout << "1" << "\n";
            else   
                cout << "0" << "\n";
        }
        else if(cmd == "top")
        {
            if(cur <= 0)
                cout << "-1" << "\n";
            else
                cout << stack[cur-1] << "\n";
        }
        else
        {
            cout << "ERROR";
        }
        
    }


}