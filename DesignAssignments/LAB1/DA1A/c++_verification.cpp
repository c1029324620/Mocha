#include <iostream>

using namespace std;

int main()
{
    long long int x = 0x5432FFFF;
    long long int y = 0x0010FF99;
    long long int z = x * y;
    cout << hex << z << endl;
    return 0;
}
