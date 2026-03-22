#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

// Function: Copies one string to another
void copyString(char destination[], const char source[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; // Complete the copy
}

int main() {
    // 1. Example: String Copying
    cout << "1: String Copying" << endl;
    char source1[] = "Techland";
    char destination1[100] = "C & C++";
    copyString(destination1, source1); // Perform copy
    cout << "Copied String: " << destination1 << endl;

    // 2. Example: Copying the First 5 Characters
    cout << "2: Copying the First 5 Characters" << endl;
    char source2[100] = "C & C++";
    char destination2[100];
    strncpy(destination2, source2, 5); // Copy only the first 5 characters
    destination2[5] = '\0'; // Add null character
    cout << "Copied String: " << destination2 << endl;

    // 3. Example: String Concatenation
    cout << "3: String Concatenation" << endl;
    char combined[200] = "Hello "; // String ready for concatenation
    char append[100] = "C & C++";
    strcat(combined, append); // Concatenate
    cout << "Concatenated String: " << combined << endl;

    // 4. Example: Changing All Characters to 'w'
    cout << "4: Changing All Characters to 'w'" << endl;
    char replaceChar[100] = "Ahmet";
    strset(replaceChar, 'w'); // Change all characters to 'w'
    cout << "Modified String: " << replaceChar << endl;

    // 5. Example: Reversing a String
    cout << "5: Reversing a String" << endl;
    char reverseString[100] = "C & C++";
    strrev(reverseString); // Reverse the string
    cout << "Reversed String: " << reverseString << endl;

    // 6. Example: Converting to Lowercase
    cout << "6: Converting to Lowercase" << endl;
    char lowerString[100] = "C & C++";
    strlwr(lowerString); // Convert to lowercase
    cout << "Lowercase String: " << lowerString << endl;

    // 7. Example: Converting to Uppercase
    cout << "7: Converting to Uppercase" << endl;
    char upperString[100] = "C & C++";
    strupr(upperString); // Convert to uppercase
    cout << "Uppercase String: " << upperString << endl;

    return 0;
}