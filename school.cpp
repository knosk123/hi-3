#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

void setup_console_encoding() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

string& getLongerString(string &str1, string &str2) {
    if (str2.length() > str1.length()) {
        return str2;
    } else {
        return str1;
    }
}

int main() {
    setup_console_encoding();
    string s1, s2;
    cout << "????????: ";
    getline(cin, s1);
    cout << "????????: ";
    getline(cin, s2);

    cout << "\n?????:" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    string &longerStr = getLongerString(s1, s2);
    cout << "\n???????: " << longerStr << endl;

    // ???????
    longerStr += " [????]";

    cout << "\n???????:" << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    // ??????
    cout << "\n??????:" << endl;
    cout << "longerStr ???: " << &longerStr << endl;
    cout << "s1 ???: " << &s1 << endl;
    cout << "s2 ???: " << &s2 << endl;

    if (&longerStr == &s1) {
        cout << "longerStr ??? s1" << endl;
    } else if (&longerStr == &s2) {
        cout << "longerStr ??? s2" << endl;
    }

    return 0;
}
