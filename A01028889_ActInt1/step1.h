// Ricardo Alfredo Calvo Pérez - A01028889
// Check if any line in the malicious code file (mcode_file) appears as a substring

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool compare_mcode_files(ifstream &transmission_file, ifstream &mcode_file)
{
  string mcode_current_string;

  while (getline(mcode_file, mcode_current_string))
  {
    char char_transmission;
    int position = 0, relative_position = 0;
    int mcode_length = mcode_current_string.size();

    // Reset transmission file to the beginning
    transmission_file.clear();
    transmission_file.seekg(0);

    while (transmission_file.get(char_transmission))
    {
      if (char_transmission == mcode_current_string[relative_position])
      {
        relative_position++;
        if (relative_position == mcode_length)
        {
          cout << "True in position: " << position + 1 << " with: " << mcode_current_string << endl;
          return true;
        }
      }
      else
      {
        position += 1 + relative_position;
        relative_position = 0;
      }
    }
  }
  cout << "False" << endl;
  return false;
}
