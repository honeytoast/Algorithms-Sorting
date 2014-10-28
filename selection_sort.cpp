//compile this file with the c++11 flag

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

void selectionSort(string* words, int size)
{
  string temp;
  int least_index;

  for (int i = 0; i < size; i++)
  {
    least_index = i;
    for (int j = i+1; j < size; j++)
    {
      if (words[j] < words[least_index])
        least_index = j;
    }
    temp = words[i];
    words[i] = words[least_index];
    words[least_index] = temp;
  }
}

void printTenWords(string* words)
{
  cout << "first 10 words:";
  for (int i = 0; i < 10; i++)
    cout << "[" << words[i] << "]";
  cout << "\n";
}

int main(int argc, const char* argv[])
{
  /* Check number of arguments and exit if requirements not met */
  if (argc != 3)
  {
    cout << "Error, must supply 2 arguments.\n";
    cout << "Usage: ./< executable name > < text_file > < n >\n";
    exit(1);
  }
  
  int size = atoi(argv[2]);
  ifstream ifs;
  string* words = new string[size];

  /* Open file and read words into the array */
  ifs.open(argv[1], ifstream::in);
  for (int i = 0; i < size; i++)
  {
    ifs >> words[i];
  }
  
  /* Close file */
  ifs.close();

  /* Print input information and first 10 words of input list */
  cout << "requested n = " << size << "\n";
  cout << "loaded " << size << " lines from '" << argv[1] << "'\n";
  printTenWords(words);
  cout << "selection sort...\n";

  /* Run and time the selection sort algorithm */
  auto start = chrono::high_resolution_clock::now();
  selectionSort(words, size);
  auto end = chrono::high_resolution_clock::now();

  /* Print run time information and the first 10 sorted words */
  printTenWords(words);
  int microseconds = chrono::duration_cast<chrono::microseconds>(end - 
                                                                 start).count();
  double seconds = microseconds / 1E6;
  cout << "elapsed time: " << seconds << " seconds" << endl;
  
  /* Deallocate memory */
  delete[] words;

  return 0;
}
