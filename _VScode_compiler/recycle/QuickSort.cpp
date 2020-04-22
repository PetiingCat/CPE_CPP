#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
    int a[3] = {1, 2, 3};
    int *p[] = {0, 0, 0}; /* &a[0],&a[1],&a[2]*/
    //memset(p, 0, 3 * sizeof(int *));
    int x = 255;

    for (int i = 0; i < 3; i++)
    {
        cout << p[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < 3; i++)
    {
        p[i] = &a[i];
    }

    cout << *p[0] << " " << *p[1] << " " << *p[2] << " " << endl;

    p[3] = &x;
    cout << *p[3] << endl;
    return 0;
}