#include <iostream>
#include <stdexcept>

using namespace std;

char character(char start, int offset) {
    // Check if start is a letter
    if (!isalpha(start)) {
        // If not, throw an invalid_argument exception with an error message
        throw invalid_argument("Invalid Character Exception: Start must be a letter.");
    }

    // Calculate the target character by adding the offset to start
    char target = start + offset;

    // Check if the target is a letter
    if (!isalpha(target)) {
        // If not, throw an out_of_range exception with an error message
        throw out_of_range("Invalid Range Exception: Target is not a letter.");
    }

    // Check if the transition violates the upper- and lower-case rule
    if (isupper(start) && islower(target)) {
        // If it does, throw an out_of_range exception with an error message
        throw out_of_range("Invalid Range Exception: Cannot transition from uppercase to lowercase.");
    }
    if (islower(start) && isupper(target)) {
        // If it does, throw an out_of_range exception with an error message
        throw out_of_range("Invalid Range Exception: Cannot transition from lowercase to uppercase.");
    }

    // If no exceptions were thrown, return the target character
    return target;
}
