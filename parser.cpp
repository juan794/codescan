#include <iostream>
#include <string>

using namespace std;

void process_payload(const string& payload) {
    if (payload.length() >= 2 && payload[0] == 'X' && payload[1] == 'Y') {
        cout << "Critical execution path reached. Triggering crash..." << endl;
        volatile int *crash_ptr = nullptr;
        *crash_ptr = 0xDEADBEEF; 
    }
}

int main() {
    string buffer;
    if (getline(cin, buffer)) {
        if (buffer.length() >= 5 && buffer.substr(0, 4) == "AUTH") {
            if (buffer[4] == '2') {
                cout << "Auth version 2 accepted. Processing payload..." << endl;
                process_payload(buffer.substr(5));
            } else {
                cout << "Invalid version." << endl;
            }
        } else {
            cout << "Normal execution. Invalid or missing header." << endl;
        }
    }
    return 0;
}
