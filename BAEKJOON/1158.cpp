#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    queue <int> q;
    queue <int> result;
    int n,k; cin >> n >> k;
    int cnt = 0;
    int tmp;
    string resultStr;

    for(int i=0;i<n;i++)
        q.push(i+1);       

    resultStr += '<';
    while(!(q.empty()))
    {
        cnt++;
        if(cnt == k)
        {
            // cout << q.front() << '\n';
            string tmpStr = to_string(q.front());
            resultStr += tmpStr;
            resultStr += ", ";
            q.pop();
            cnt = 0;
            continue;
        }
        tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    resultStr.pop_back();
    resultStr.pop_back();
    resultStr += '>';
    cout << resultStr << '\n';
}