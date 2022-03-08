#include <fstream>
#include <iostream>

using namespace std;

int main()
{

    ofstream filecreate;
    filecreate.open("example.txt");
    if(filecreate.fail())
    {
        cout << "Error opening file";
        return 1;
    }

    filecreate << "Wilson" << endl << "New line";
    filecreate.close();

    return 0;
}