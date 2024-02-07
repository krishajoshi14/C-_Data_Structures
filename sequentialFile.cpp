#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

const int RECORD_COUNT = 5;
const string FILENAME = "studentsfile.txt";

struct Student 
{
    string name;
    long long int prn;
};

int main() {
    FILE *fp = fopen(FILENAME.c_str(), "w");
    if (fp == NULL) 
    {
        std::cerr << "Failed to open file: " << FILENAME << std::endl;
        return 0;
    }
    fclose(fp);

    for (int i = 0; i < RECORD_COUNT; ++i) 
    {
        Student st;
        std::cout << "Enter Name: ";
        std::getline(std::cin, st.name);
        std::cout << "Enter PRN: ";
        std::cin >> st.prn;
        std::cin.ignore(); // to clear the newline character from the input stream
        cout << "Name: " << st.name << ", PRN: " << st.prn << std::endl;
        cout << std::endl;

        FILE *fp = fopen(FILENAME.c_str(), "a");
        if (fp == NULL) {
            std::cerr << "Failed to open file: " << FILENAME << std::endl;
            return 0;
        }

        fprintf(fp, "%s,%lld\n", st.name.c_str(), st.prn);
        fclose(fp);
    }

    std::cout << "\nTesting search record functionality.\n";
    long long int prn;
    std::cout << "Enter PRN: ";
    std::cin >> prn;

    fp = fopen(FILENAME.c_str(), "r");
    if (fp == NULL) {
        std::cerr << "Failed to open file: " << FILENAME << std::endl;
        return 0;
    }

    Student st;
    char name_buf[100];
    while (fscanf(fp, "%[^,],%lld\n", name_buf, &st.prn) == 2) {
        // == 2 indicated that read two values successfully 
        st.name = name_buf;
        if (prn == st.prn) {
            std::cout << "Match found: " << endl << "Name: " << st.name << ", PRN: " << st.prn << std::endl;
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    std::cout << "No match found for PRN " << prn << std::endl;

    return 0;
}
