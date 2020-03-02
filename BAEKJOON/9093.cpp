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
        getline(cin,str); //라인 전체를 str에 저장
        stringstream sstr1(str);    //str를 공백 기준으로 잘라서 sstr1에 임시로놓음
        while(sstr1 >> strBuff) //sstr1을 strBuff에 저장한다 하나씩
        {
            strcpy(ch,strBuff.c_str()); //strBuff를 char형으로 바꿔서 ch에 저장
            for(int j=0;j<strBuff.size();j++)       
                charStack.push(ch[j]);
                                                //단어 뒤집는 과정
            for(int k=0;k<strBuff.size();k++)
            {
                ch[k]=charStack.top();
                charStack.pop();
            }
            string resultBuff(ch);  //resultBuff에 char형인 ch의 데이터를 넣는다
            result.append(resultBuff);
            result.append(" ");
        }
        cout << result << '\n';
        result = "";
    }
}