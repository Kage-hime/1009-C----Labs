#include <iostream>

using namespace std;

int main() 
{
    int input;
    cin >> input;

    if(input < 100)
        cout << "Too small.";
    else
        cout << "Big enough.";

    return 0;
}