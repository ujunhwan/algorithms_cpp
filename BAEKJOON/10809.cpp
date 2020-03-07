// 10809번 알파벳 찾기
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector <int> ans(26,-1);
    string S; cin >> S;
    int index = 0;
    for(char ch : S)
    {
        if(ans[ch - 'a'] != -1)
        {
            index += 1;
            continue;
        }
        ans[ch - 'a'] = index++;
    }
    for(int i=0;i<26;i++)
        cout << ans[i] << " ";
    cout << '\n';
    return 0;
}