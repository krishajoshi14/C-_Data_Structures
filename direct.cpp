/*
Direct File Access
- also known as random access or relative file organization
- allows random access to the data stored in a file
- records are stored randomly
- data can be read from or written to any part of the file
- no need of reading or writing the entire file sequentially
- achieved through use of file pointers pointing to specific position in the file
*/

/*
- creates an index table for students based on their PRN
- stores the data in a binary file
- When a new record is added, it calculates the key for the record (PRN modulo 100)
- checks if there is already a record with the same key in the index table.
- If the key is not in the table, the program adds the record to the end of the file
- and updates the index table with the file position where the record was added.
- If the key already exists in the table, the program prints a message saying so.

- while searching It looks up the file position for the record in the index table
- uses fseek to move to the corresponding position in the file
*/

#include <stdio.h>
#include <stdlib.h>

#define PRN_COUNT 80
const int RECORD_COUNT = 5;

const char *FILENAME = "students";

const char *STUDENT_FORMAT_IN = " %[^,], %lli";   // Input is expected of the form (Name, PRN)
const char *STUDENT_FORMAT_OUT = "Name: %s, PRN: %lli\n";

// Array to store the position of records in the file
int INDEX[PRN_COUNT];

typedef struct {
    char name[20];
    long long int prn;
} Student;

const int SIZE_OF_STUDENT = sizeof (Student);
int FILE_POINTER = 0;

// Search for entry in file
void search();

// Function to initialize INDEX
void initIndex() {
    for (int i = 0; i < PRN_COUNT; ++i) {
        INDEX[i] = -1;
    }
}


// PROGRAM DRIVER
int main(void) {

    // Initialize indices to -1
    initIndex();

    // Open file in write mode
    FILE *out;
    out = fopen(FILENAME, "w");

    // Check whether the file was opened successfully or not
    if (out == NULL) {
        exit(EXIT_FAILURE);
    }

    // Read records from STDIN and write to the FILE
    for (int i = 0; i < RECORD_COUNT; ++i) {

        Student st;

        // Get record
        printf("Enter record: ");
        scanf(STUDENT_FORMAT_IN, &st.name, &st.prn);

        // Set key to be the last two digits of the PRN
        int key = st.prn % 100;

        // Add record if the key is empty
        if (INDEX[key] == -1) {

            INDEX[key] = FILE_POINTER;
            fwrite(&st, SIZE_OF_STUDENT, 1, out);
            FILE_POINTER += SIZE_OF_STUDENT;
        }
        else {
            printf("The key already exists!\n");
        }
    }

    // Close the file
    fclose(out);

    // Display index table
    printf("\nINDEX table\n");
    for (int i = 0; i < PRN_COUNT; ++i) {
        printf("%d: %d\n", i, INDEX[i]);
    }

    // Test search functionality
    printf("\nTesting search record functionality.\n");
    search();
    search();
    search();

    return 0;
}

void search() {
    
    long long int prn;

    // Ask for PRN of record to be searched
    printf("Enter PRN: ");
    scanf("%lli", &prn);

    // Calculate key
    int key = prn % 100;

    // Get the position of the record in the file
    int position = INDEX[key];

    // Check whether the record exists or not
    if (position == -1) {
        printf("The record does not exist!\n");
    }
    else {

        FILE *in = fopen(FILENAME, "r");
        if (in == NULL) {
            exit(EXIT_FAILURE);
        }

        Student st;

        fseek(in, position, SEEK_SET);
        fread(&st, SIZE_OF_STUDENT, 1, in);
        fclose(in);
        
        printf(STUDENT_FORMAT_OUT, st.name, st.prn);
    }
}
