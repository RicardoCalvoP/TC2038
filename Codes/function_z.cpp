#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void Show(char S[], int size) // Complexity O(n)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << S[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

void Show(int list_numbers[], int size) // Complexity O(n)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << list_numbers[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

void z_function(char S[], int size) // Changed S type to array
{
    int z[size];
    z[0] = -2004; // The first Z value must be 0 because there are no matches at the same position

    // We traverse the string starting from the second character
    for (int i = 1; i < size; i++)
    {
        int matches = 0;
        // Compare the prefix with the substring starting at i
        while (i + matches < size && S[matches] == S[i + matches])
        {
            matches++; // Count matches
        }
        z[i] = matches; // Store the number
    }

    Show(z, size); // Display the entire Z array
}

void create_string()
{
    char letters[] = {'a', 'b', 'c', 'd', 'e'};

    int length = 6 + rand() % 10; // Generate a random length between 6 and 15

    char *S = new char[length]; // Dynamically allocate the array S
    for (int i = 0; i < length; i++)
    {
        int rand_letter = rand() % 5; // Generate an index between 0 and 4
        S[i] = letters[rand_letter];
    }

    Show(S, length);       // Display the generated string
    z_function(S, length); // Call the Z function to calculate matches

    delete[] S; // Free the dynamically allocated memory
}

int main()
{
    system("cls");               // Clear the terminal (on Windows)
    srand((unsigned)time(NULL)); // Initialize the seed for random numbers

    create_string(); // Call the function to generate and display the string

    return 0;
}
