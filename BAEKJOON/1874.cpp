#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
#define LENGTH 100000
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 4 3 6 8 7 5 2 1 
    // + + + + -  -  + + -  + + -  -  -  -  -
    
    // 1 2 5 3 4
    // NO 5 다음에 3이 나올 수 없다.

    int comp = 0;   //push가 되는 요소
    int T;  cin >> T;
    int num[LENGTH];
    int diff;
    int n=0;
    stack <int> s;
    queue <char> q;
    
    for(int i=0;i<T;i++)
        cin >> num[i];  //input

    for(int i=0;i<T;i++)
    {
        diff = num[i] - comp;
        if(i == 0)
        {
            for(int j=0;j<num[0];j++)
            {
                comp += 1;
                s.push(comp);
                q.push('+');
            }
            s.pop();
            q.push('-');
        }
        else
        {
            if(num[i] > num[i-1])   //push
            {   
                if(diff < 0)
                {
                    cout << "NO" << '\n';
                    return 0;
                }
                else
                {
                    for(int k=0;k<diff;k++)
                    {
                        comp += 1;
                        s.push(comp);
                        q.push('+');
                    }
                    s.pop();
                    q.push('-');
                }
            }
            else if(num[i] < num[i-1])  //pop
            {
                while(s.top() != num[i])
                {
                    s.pop();
                    q.push('-');
                }
                s.pop();
                q.push('-');
            }
            else
            {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    while(!(q.empty()))
    {
        cout << q.front() << '\n';
        q.pop();
    }
    return 0;
}