#include "filesFunctions.h"
#include "step1.h"
#include "step2.h"
#include "step3.h"
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
     system("cls");

     string transmission_files[2] = {
         "../TestDocuments/transmission1.txt",
         "../TestDocuments/transmission2.txt"};

     string mcode_files[3] = {
         "../TestDocuments/mcode1.txt",
         "../TestDocuments/mcode2.txt",
         "../TestDocuments/mcode3.txt"};

     for (int i = 0; i < 2; i++)
     {
          ifstream transmission_file;
          open_file(transmission_file, transmission_files[i]);

          // Clear, formatted section for the current transmission file
          cout << endl
               << "========================================================" << endl;
          cout << "Analyzing Transmission File: " << transmission_files[i] << endl;
          cout << "========================================================" << endl;

          // Step 1: Check mcode strings
          cout << endl
               << endl;
          cout << "Step 1: Checking for Malicious Code Strings" << endl;
          cout << "--------------------------------------------------------" << endl;
          for (int j = 0; j < 3; j++)
          {
               ifstream mcode_file;
               open_file(mcode_file, mcode_files[j]);
               cout << "- Checking against mcode file: " << mcode_files[j] << endl;
               compare_mcode_files(transmission_file, mcode_file);
               close_file(mcode_file);
          }

          // Step 2: Check for palindromic sequences
          cout << endl
               << endl;
          cout << "Step 2: Searching for Longest Palindromic Substring" << endl;
          cout << "--------------------------------------------------------" << endl;

          transmission_file.clear();
          transmission_file.seekg(0);
          string transmission_content;
          getline(transmission_file, transmission_content);

          cout << "- Searching palindrome within the file content..." << endl;
          find_inner_palindrome(transmission_content);

          close_file(transmission_file);

          // End section for the current file
          cout << endl
               << "========================================================" << endl;
          cout << "End of Analysis for: " << transmission_files[i] << endl;
          cout << "========================================================" << endl;
     }

     // Step 3: Check for palindromic sequences
     cout << endl
          << endl;
     cout << "Step 3: Find Substring in Transmission Files" << endl;
     cout << "--------------------------------------------------------" << endl;

     string str1 = "ABCDEFGFEDCBA12345";
     string str2 = "XYZDEF123456789ABC123XYZZYX321DEF";

     string result = find_longest_common_substring(str1, str2);

     return 0;
}
