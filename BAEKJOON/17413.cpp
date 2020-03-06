#include <iostream>
#include <stack>

using namespace std;
void print(stack <char> &s)
{
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    stack <char> s;
    string str;
    getline(cin,str);
    bool tag = false;

    for(char ch : str)
    {
        if(ch == '<')
        {
            tag = true;
            print(s);
            cout << ch;
        }
        else if(ch == '>')
        {
            tag = false;
            cout << ch;
        }
        else if(tag)
            cout << ch;
        else
        {
            if(ch == ' ')
            {
                print(s);
                cout << ch;
            }
            else
                s.push(ch);
        }
        
    }
    print(s);
    return 0;
}