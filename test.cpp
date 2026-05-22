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

class student {
private:
    int id;
    static int totalCount;
    string name;


    static int getCount(int totalCount) {
        return totalCount;
    }

public:

    student(int studentId, string Name)
        : id(studentId), name(Name) {
        totalCount++;
    }

    static int getTotalCount() {
        return totalCount;
    }


    int get_id() {
        return id;
    }


    string get_name() {
        return name;
    }

    void show() {
        cout << "??: " << id << ", ??: " << name << endl;
    }
};

int student::totalCount = 0;

int main() {
    setup_console_encoding();

    student s1(6, "??");


    s1.show();

    cout << "??: " << s1.get_id() << endl;
    cout << "??: " << s1.get_name() << endl;

    student s2(7, "??");
    student s3(8, "??");


    cout << "\n???: " << student::getTotalCount() << endl;
    cout << "??s1??: " << s1.getTotalCount() << endl;
    cout << "??s2??: " << s2.getTotalCount() << endl;
    cout << "??s3??: " << s3.getTotalCount() << endl;

    return 0;
}
