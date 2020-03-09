// 11656번 접미사 배열
#include <bits/stdc++.h>
using namespace std;
void Swap(string arr[], int a, int b)
{
    string tmp;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string str; cin >> str;
    int length = str.length();
    string arr[length];

    for(int i=0;i<length;i++) // 0 is default
        arr[i] = str.substr(i);
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length-(i+1);j++)
        {
            if(arr[j].front() > arr[j+1].front())
                Swap(arr,j,j+1);
            else if(arr[j].front() == arr[j+1].front())
            {
                int k = 0;
                while(arr[j].substr(k).front() == arr[j+1].substr(k).front())
                    k += 1;
                if(arr[j].substr(k).front() > arr[j+1].substr(k).front())
                    Swap(arr,j,j+1);
            }
        }
    }
    for(int i=0;i<length;i++)
        cout << arr[i] << '\n';
}