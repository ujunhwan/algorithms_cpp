#include <iostream>
#include <stack>
#include <sstream>
#include <cstring>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack <char>charStack;
    string strBuff;
    int T;
    string result;
    string str;
    char ch[10000];
    cin >> T;
    cin.ignore();

    for(int i=0;i<T;i++)
    {
        getline(cin,str);
        stringstream sstr1(str);
        while(sstr1 >> strBuff)
        {
            strcpy(ch,strBuff.c_str());
            for(int j=0;j<strBuff.size();j++)       
                charStack.push(ch[j]);

            for(int k=0;k<strBuff.size();k++)
            {
                ch[k]=charStack.top();
                charStack.pop();
            }
            string resultBuff(ch);
            result.append(resultBuff);
            result.append(" ");
        }
        cout << result << '\n';
        result = "";
    }
}