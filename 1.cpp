#include <cstdlib>
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

void setup_console_encoding() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

// ???????
typedef struct {
    char date[20];           // ??(YYYY-MM-DD)
    char study_content[100]; // ????
    char study_effect[20];   // ????
    char activity_name[100]; // ????
    char activity_summary[200]; // ????
} PersonalRecord;

PersonalRecord my_record;  // ??????
int has_record = 0;        // ????????(0=?,1=?)

// ??????:???????
void get_input(char *buf, int len) {
    fgets(buf, len, stdin);
    buf[strcspn(buf, "\n")] = '\0';
}

// ANSI??:?????(??Linux/macOS???Windows PowerShell)
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[H\033[2J");
    fflush(stdout);
#endif
}

// ????????(??10?+?????)
int is_valid_date(const char *date) {
    return strlen(date) == 10 && date[4] == '-' && date[7] == '-';
}

int main() {
    setup_console_encoding();
    int choice;
    while (1) {
        clear_screen();

        // ???
        printf("========================================\n");
        printf("          ????????\n");
        printf("========================================\n\n");
        printf("1. ????\n2. ????\n3. ????\n4. ????\n5. ????\n\n");
        printf("?????(1-5):");
        scanf("%d", &choice);
        getchar(); // ????????

        switch (choice) {
            case 1: { // ????
                clear_screen();
                printf("=== ?????? ===\n\n");

                char temp_date[20];
                do {
                    printf("??(YYYY-MM-DD):");
                    get_input(temp_date, sizeof(temp_date));
                    if (!is_valid_date(temp_date))
                        printf("? ????!????2025-12-25???\n");
                } while (!is_valid_date(temp_date));
                strcpy(my_record.date, temp_date);

                printf("????:"); get_input(my_record.study_content, sizeof(my_record.study_content));
                printf("????:"); get_input(my_record.study_effect, sizeof(my_record.study_effect));
                printf("????:"); get_input(my_record.activity_name, sizeof(my_record.activity_name));
                printf("????:"); get_input(my_record.activity_summary, sizeof(my_record.activity_summary));

                has_record = 1;
                printf("\n? ????!\n");
                break;
            }
            case 2: { // ????
                clear_screen();
                printf("=== ?????? ===\n\n");
                if (!has_record) printf("? ????!\n");
                else {
                    memset(&my_record, 0, sizeof(PersonalRecord));
                    has_record = 0;
                    printf("? ????!\n");
                }
                break;
            }
            case 3: { // ????
                clear_screen();
                printf("=== ?????? ===\n\n");
                if (!has_record) printf("? ????,????!\n");
                else {
                    char temp_date[20];
                    do {
                        printf("????:%s\n???(YYYY-MM-DD):", my_record.date);
                        get_input(temp_date, sizeof(temp_date));
                        if (!is_valid_date(temp_date))
                            printf("? ????!?????\n");
                    } while (!is_valid_date(temp_date));
                    strcpy(my_record.date, temp_date);

                    printf("?????:"); get_input(my_record.study_content, sizeof(my_record.study_content));
                    printf("?????:"); get_input(my_record.study_effect, sizeof(my_record.study_effect));
                    printf("?????:"); get_input(my_record.activity_name, sizeof(my_record.activity_name));
                    printf("?????:"); get_input(my_record.activity_summary, sizeof(my_record.activity_summary));

                    printf("\n? ????!\n");
                }
                break;
            }
            case 4: { // ????
                clear_screen();
                printf("=== ?????? ===\n\n");
                if (!has_record) printf("????!\n");
                else {
                    printf("========================================\n");
                    printf("??:%s\n????:%s\n????:%s\n",
                           my_record.date, my_record.study_content, my_record.study_effect);
                    printf("????:%s\n????:%s\n",
                           my_record.activity_name, my_record.activity_summary);
                    printf("========================================\n");
                }
                break;
            }
            case 5: { // ????
                clear_screen();
                printf("========================================\n");
                printf("          ????!\n");
                printf("========================================\n");
                return 0;
            }
            default: printf("? ????,???1-5!\n");
        }

        printf("\n?????????...");
        getchar();
    }
}
