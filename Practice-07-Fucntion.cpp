#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

// Ham chuyen doi he so, voi he so input la he 10
int convertCoefficient(int x, int y)
{
    char s[1000]; // mang luu ket qua
    int i = 0;
    int temp = 0; // bien luu phan du
    if (x == 0)
    {
        cout << "0";
    }
    else
    {
        while (x > 0)
        {
            temp = x % y; // lay phan du
            if (temp < 10)
            { // luu ket qua duoi dang chuoi
                s[i] = '0' + temp;
            }
            else
            {
                s[i] = 'A' + (temp - 10); // neu tu 10 tro len se luu ket qua duoi dang chu cai (VD: 11 --> A + 1 = B)
            }
            x /= y; // giam x di y lan
            i++;
        }
        s[i] = '\0'; // cat chuoi
    }
    cout << strrev(s);
    return 0;
}

// Ham tinh UCLN
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

// Ham kiem tra so nguyen to cung nhau
int checkCoprime(int n, int m)
{
    int result = calGCD(n, m);
    if (result == 1)
    {
        cout << n << " va " << m << " la hai so dong nguyen to";
    }
    else
    {
        cout << n << " va " << m << " khong phai la hai so dong nguyen to";
    }
    cout << endl;
    return 0;
}

// Ham kiem tra goc vuong cua tam giac can
float checkRightAngle(float a, float b, float c)
{
    // cong thuc cosin tinh goc
    int result = 0;
    if (a == b)
    {
        result = (a * a + b * b - c * c) / 2 * a * b; // tinh cos
    }
    else if (a == c)
    {
        result = (a * a + c * c - b * b) / 2 * a * c; // tinh cos
    }
    else
    {
        result = (b * b + c * c - a * a) / 2 * b * c; // tinh cos
    } 
    return int (acos(result) * 180 / 3.1415); // dung acos de lay goc ((int) lay goc la so nguyen)
}
// Ham kiem tra tam giac
float checkTriangle(float a, float b, float c)
{

    if (a + b > c && a + c > b && b + c > a) // xac dinh tam giac hop le
    {
        if (a != b && a != c && b != c)
        {
            cout << "1";
        }
        else if (a == b && a == c && b == c)
        {
            cout << "4";
        }
        else
        {
            if (checkRightAngle(a, b, c) == 90)
            {
                cout << "5";
            }
            else
            {
                cout << "2";
            }
        }
    }
    else
    {
        cout << "0";
    }

    cout << endl;
    return 0;
}

int main()
{
    // Chuyen doi co so
    // int x, y;
    // cout << "Chuyen doi he co so 10 sang he co so y" << endl;
    // cout << "Nhap vao he co so 10: ";
    // cin >> x;
    // cout << "Nhap vao he co so y can chuyen doi: ";
    // cin >> y;
    // convertCoefficient(x, y);
    cout << "==========================================" << endl;

    // Kiem tra 2 so dong nguyen to
    // int n, m;
    // cout << "Kiem tra hai so dong nguyen to" << endl;
    // cout << "Nhap vao hai so n, m: ";
    // cin >> n;
    // cin >> m;
    // checkCoprime(n, m);
    cout << "==========================================" << endl;

    // Tinh UCLN cua hai so
    // int a, b;
    // cout << "Nhap vao hai so de tinh UCLN: " << endl;
    // cin >> a;
    // cin >> b;
    // cout << "UCLN la: " << calGCD(a, b);
    // cout << "==========================================" << endl;

    // Kiem tra 3 diem a, b, c co tao thanh tam giac khong?
    float d1, d2, d3;
    cout << "Nhap vao ba so nguyen de kiem tra no co tao thanh tam giac hay khong: " << endl;
    cin >> d1;
    cin >> d2;
    cin >> d3;
    checkTriangle(d1, d2, d3);
    cout << "==========================================" << endl;

    system("pause");
    return 0;
}