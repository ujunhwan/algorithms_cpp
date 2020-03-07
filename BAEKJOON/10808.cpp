// 10808번 알파벳 개수
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S; cin >> S;
    vector <int> alphabet(26);   
    for(char ch : S)
    {
        alphabet[ch - 'a'] += 1;
    }
    for(int i=0;i<26;i++)
        cout << alphabet[i] << " ";
    cout << '\n';
    return 0;
}