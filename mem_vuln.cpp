#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void trigger_vulnerabilities() {
    int *ptr_int = new int[10];
    ptr_int[0] = 123; 

    char *buf = new char[5];
    cout << "Enter a short word: ";
    string input;
    cin >> input;
    strcpy(buf, input.c_str());
    cout << "Copied string: " << buf << endl;

    char *ptr_char = new char[20];
    cout << "Enter secure data: ";
    cin >> input;
    strcpy(ptr_char, input.c_str());
    delete[] ptr_char; 

    cout << "Leaked after free: " << ptr_char[0] << endl; 
}

int main() {
    cout << "Starting dynamic memory analysis target..." << endl;
    trigger_vulnerabilities();
    cout << "Execution completed." << endl;
    return 0;
}
