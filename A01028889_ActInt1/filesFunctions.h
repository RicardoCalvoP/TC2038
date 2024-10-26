#include <fstream> // Library to open files
#include <iostream>
#include <string>
using namespace std;

void open_file(ifstream &file, string &to_open_file)
{
  file.open(to_open_file);

  if (!file.is_open())
  {
    cout << "Unable to open file: " << to_open_file << endl;
  }
}

void close_file(ifstream &file)
{
  // Close file
  file.close();
  if (!file.is_open())
  {
    cout << "File closed successfully." << endl;
  }
  else
  {
    cout << "Error: File could not be closed." << endl;
  }
}

bool compare_mcode_files(ifstream &transmission_file, ifstream &mcode_file)
{
  char char_transmission, char_mcode;
  // Get the first character from the malicious code (mcode) file
  mcode_file.get(char_mcode);
  int position = 0, relative_position = 0;
  // Traverse the transmission file character by character
  while (transmission_file.get(char_transmission))
  {
    if (char_transmission == char_mcode)
    {
      // If the characters match, get the next character from mcode
      if (!mcode_file.get(char_mcode))
      {
        // If we reach the end of the mcode file, it means we found the entire malicious code
        cout << "true in position: " << position << endl;
        return true;
      }
      relative_position += 1;
    }
    else
    {
      // Reset the search in the mcode file
      mcode_file.clear();         // Clears any error flags that may be set
      mcode_file.seekg(0);        // Resets the position of the mcode file to the beginning
      mcode_file.get(char_mcode); // Re-read the first character of the mcode file
      position += 1 + relative_position;
      relative_position = 0;
    }
  }

  // If we reach here, it means the entire malicious code was not found in the transmission file
  cout << "false" << endl;
  return false;
}

void search_for_coincidences(string transmission_files[], string mcode_files[])
{
  for (int i = 0; i < 2; i++)
  {
    ifstream transmission_file, mcode_file; // Open current transmission file

    // Print current transmission file name
    open_file(transmission_file, transmission_files[i]);
    cout << endl
         << "-------------------------------------------" << endl;
    cout << "File: " << transmission_files[i] << endl;
    cout << "-------------------------------------------" << endl;

    // PART 1 (search for malicious content in our transmission files)
    for (int j = 0; j < 3; j++)
    {
      open_file(mcode_file, mcode_files[j]);              // Open current mcode file
      compare_mcode_files(transmission_file, mcode_file); // Search if mcode content is on transmission file
      close_file(mcode_file);                             // Close current mcode file
    }

    // PART 2 (search for palindroms)

    close_file(transmission_file); // Close current transmission file
  }
}
