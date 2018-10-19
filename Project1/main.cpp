#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[]){
  ifstream textFile1;
  ifstream textFile2;
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string fileCipher;
  string fileEncode;
  string fileDecode;
  string fileText;
  string fileMissingA;
  string fileMissingB;
  string tempDecode;
  string givenWord = argv[3];
  string lettersGivenA;
  string lettersGivenB;

  textFile1.open(argv[1]);
  if (!textFile1.is_open()) {
     cout << "Could not open file." << endl;
     return 1;
  }
  textFile1 >> fileCipher;
  //sort(fileCipher.begin(), fileCipher.end());
  textFile1 >> fileEncode;
  textFile1.close();

  textFile2.open(argv[2]);
  if (!textFile2.is_open()) {
     cout << "Could not open file." << endl;
     return 1;
  }
  textFile2 >> fileText;


while(textFile2.good()){
  tempDecode = tempDecode + " " + fileText;
  textFile2 >> fileText;
}
tempDecode.erase(tempDecode.begin() + 0);
textFile2.close();
//cout << tempDecode << endl;

//Sort
int n = fileCipher.size();
for(int i=0; i<(n-1); i++){
    for(int j=0; j<n-i-1; j++){
      if(fileCipher[j] > fileCipher[j+1]){
        swap(fileCipher[j], fileCipher[j+1]);
        swap(fileEncode[j], fileEncode[j+1]);
      }
    }
}

//missing letters from 1st line
for(int i=0, x=0; i<26; i++){
  if(fileCipher[x] == alphabet[i]){
    x++;
    }
  else
    fileMissingA = fileMissingA + alphabet[i];
}
//cout << fileMissingA << endl;


//missing letters from 2nd line
int len2 = fileEncode.size();
for(int i=0; i<26; i++){
  int x = 0;
  for(int j=0; j<len2; j++){
    if(alphabet[i] == fileEncode[j]){
      x++;
    }
  }
    if(x==0) {
      fileMissingB = fileMissingB + alphabet[i];
    }
}
//cout<< fileMissingB << endl;

//Replacing missing letters in Text with symbol
int len3 = fileMissingB.size();
  for(int j=0; j<len3; j++){
    replace(tempDecode.begin(), tempDecode.end(), fileMissingB[j], '_');
  }
  //cout << tempDecode << endl;

//Getting the missing letter by itself
int lenGiven = givenWord.size();
for(int i=0, x=0; i<lenGiven; i++){
  for(int j=0; j<len3+1; j++){
    if(fileMissingA[i] == givenWord[j]){
      lettersGivenA = lettersGivenA + fileMissingA[i];
      j = len3 + 1;
    }
    else if(x == lenGiven){
      lettersGivenB = lettersGivenB + fileMissingB[i];
      x=0;
    }
    else{
      x++;
    }
  }
}
//cout << lettersGivenA << " " << lettersGivenB << endl;
//close and reopen file2
textFile2.open(argv[2]);

//location of givenWord in file
int y = 0;
string tempWord;
//textFile2 >> fileText;
//cout << fileText << endl;
while(textFile2 >> fileText){
  //cout << fileText << endl;//
  int x = 0;
  int t = fileText.size();
  if(t == lenGiven){
    //cout << lenGiven << endl;//
    for(int i=0; i<lenGiven+1; i++){
      for(int j=0; j<len3; j++){
        //out << "Here1" << endl;//
        if(fileText[i] == fileMissingB[j]){
          x++;
          //cout << x << endl;//
        }
        else if(x > y){
          tempWord = fileText; //may want it as fileText
          //cout <<" temp"<< tempWord << endl;
          y = x;
        }
      }
    }
  }
}
//cout << tempWord << endl;
//cout << "HELLO HELLO" << endl;

//adding missing letters to file1

/*int yee = lettersGivenA.size();
for(int i=0; i<yee; i++){
  for(int j=0; j<lenGiven; j++){
    if(tempWord[i] == givenWord[j]){*/
      fileCipher = fileCipher + givenWord;
      fileEncode = fileEncode + tempWord;
  /*  }
  }
}*/
n = fileEncode.size();
for(int i=0; i<(n-1); i++){
    for(int j=0; j<n-i-1; j++){
      if(fileCipher[j] > fileCipher[j+1]){
        swap(fileCipher[j], fileCipher[j+1]);
        swap(fileEncode[j], fileEncode[j+1]);
      }
    }
}

//cout << fileCipher << endl;
//cout << fileEncode << endl;
//cout << "HELLO HELLO" << endl;


if(lettersGivenB.size() == 1){
  fileCipher = fileCipher + lettersGivenB;


len2 = fileEncode.size();
for(int i=0; i<len2; i++){
  int x = 0;
  for(int j=0; j<len2; j++){
    if(alphabet[i] == fileEncode[j]){
      x++;
    }
  }
    if(x==0) {
      fileEncode = fileEncode + alphabet[i];
    }
}
}
//cout << fileCipher << endl;
//cout << fileEncode << endl;


//Sort
n = fileEncode.size();
for(int i=0; i<(n-1); i++){
    for(int j=0; j<n-i-1; j++){
      if(fileCipher[j] > fileCipher[j+1]){
        swap(fileCipher[j], fileCipher[j+1]);
        swap(fileEncode[j], fileEncode[j+1]);
      }
    }
}

//Decoding the sentence
textFile2.close();
textFile2.open(argv[2]);
textFile2 >> fileText;
int len = fileText.size();
int lne = fileEncode.size();
string finalMessage;
//cout << fileText << endl;
while (textFile2.good()) {
  //cout << fileText << endl;
  for(int i=0; i<len; i++){
    for(int j=0; j<lne; j++){
      if(fileText[i] == fileEncode[j]){
        finalMessage = finalMessage + fileCipher[j];
        //cout << finalMessage << endl;
        j = 50;
      }
    }
  }
  finalMessage = finalMessage + " ";
  textFile2 >> fileText;
  len = fileText.size();
  }
textFile2.close();

//cout << "Cipher: " << fileCipher << endl;
//cout << "Encode: " << fileEncode << endl;
//cout << "Decode: " << finalMessage << endl;
//cout << "tempDecode: "  << tempDecode << endl;
//cout << "Missing: " << fileMissingA << " " << fileMissingB << endl;


cout << finalMessage << endl;
return 0;
}
