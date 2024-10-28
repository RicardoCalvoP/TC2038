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
  file.close();
}