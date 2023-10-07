#include <iostream>
#include <math.h>


using namespace std;

int calGCD(int num1, int num2)
{

    while (num1 != num2)
    {
        if (num1 > num2)
        {
            num1 -= num2;
        }
        else
        {
            num2 -= num1;
        }
    }
    return num1;
}
int main()
{
    float num1 = 27;
    float num2 = 9;

    // cout << calGCD(num1, num2);
    int  result = ((1*1 + 1 * 1 - 2 * 2) / 2 * 1 * 1);
    cout << result;
    cout << endl;
    cout << int (acos(result)* 180 / 3.1415);
    cout << endl;
    system("pause");
    return 0;
}