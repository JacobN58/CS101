#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char *argv[]){
  ifstream textFile1;
  ifstream textFile2;
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string fileCipher;
  string fileEncode;
  string fileDecode;
  string fileText;

  textFile1.open(argv[1]);
  if (!textFile1.is_open()) {
     cout << "Could not open file." << endl;
     return 1;
  }
  textFile1 >> fileCipher;
  textFile1 >> fileEncode;
  textFile1.close();

  textFile2.open(argv[2]);
  if (!textFile2.is_open()) {
     cout << "Could not open file." << endl;
     return 1;
  }

while (textFile2.good()) {
  textFile2 >> fileText;

  for(int i=0; i<26; i++){
    for(int j=27; j>0; j--){
      if(fileCipher[i] == fileText[j]){
        fileDecode[i] = fileCipher[i];
        i = 58;
      }
    }
  }
}

textFile2.close();

cout << "Alphabet: " << alphabet << endl;
cout << "Cipher: " << fileCipher << endl;
cout << "Encode: " << fileEncode << endl;
cout << "Decode: " << fileDecode << endl;
cout << "Text: " << fileText << endl;

return 0;
}
