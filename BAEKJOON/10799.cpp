#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    stack <int> s;
    int result = 0;
    int i,j,k;
    int num;
    string str;
    getline(cin,str);
    i=0;
    for(char ch : str)
    {
        if(ch == '(')
            s.push(i);

        else if(ch == ')')
        {
            num = i-s.top();
            s.pop();
            if(num == 1) //laser
                result += s.size();
            else
                result += 1;
        }
        i += 1;   
    }
    cout << result << '\n';
    return 0;
}