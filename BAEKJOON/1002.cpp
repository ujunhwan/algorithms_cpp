// 1002번 터렛
// 변수 distance를 double로 선언하지 않아서 계속 틀렸음
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    typedef long long ll;
    int T; cin >> T;
    int x1,x2,y1,y2,r1,r2;
    double distance,longR,shortR;
    int result;
    
    while(T--)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        distance = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        longR = max(r1, r2);
        shortR = min(r1, r2);
        if(distance == 0)
        {
            if(longR == shortR)
                result = -1;
            else
                result = 0;
        }
        else
        {
            if(longR-shortR < distance && longR+shortR > distance)
                result = 2;
            else if(longR+shortR == distance || longR-shortR == distance)
                result = 1;
            else
                result = 0;
        }
        cout << result << '\n';
    }
    return 0;
}