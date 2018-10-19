#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


void print1(vector<int> printVector) { //print integers
  for(int i = 0; i < printVector.size(); i++) {
      cout << printVector[i] << endl;
    }
}


void print2(vector<string> printVector) { //print words
  for(int i = 0; i < printVector.size(); i++) {
      cout << printVector[i] << endl;
    }
}


vector<int> merge1(vector<int> left, vector<int> right) { //merge integers
   vector<int> res;
   while (left.size() > 0 || right.size() > 0) {
      if (left.size() > 0 && right.size() > 0) {
         if (left.front() <= right.front()) {
            res.push_back(left.front());
            left.erase(left.begin());
         }
         else {
           res.push_back(right.front());
           right.erase(right.begin());
         }
      }  else if (left.size() > 0) {
            for (int i = 0; i < left.size(); i++)
               res.push_back(left[i]);
            break;
      }  else if (right.size() > 0) {
            for (int i = 0; i < right.size(); i++)
               res.push_back(right[i]);
            break;
      }
    }
    return res;
  }


  vector<string> merge2(vector<string> left, vector<string> right) { //merge words
     vector<string> res;
     while (left.size() > 0 || right.size() > 0) {
        if (left.size() > 0 && right.size() > 0) {
           if (left.front() <= right.front()) {
              res.push_back(left.front());
              left.erase(left.begin());
           }
           else {
             res.push_back(right.front());
             right.erase(right.begin());
           }
        }  else if (left.size() > 0) {
              for (int i = 0; i < left.size(); i++)
                 res.push_back(left[i]);
              break;
        }  else if (right.size() > 0) {
              for (int i = 0; i < right.size(); i++)
                 res.push_back(right[i]);
              break;
        }
      }
      return res;
    }


vector<int> mergeSort1(vector<int> sortVector) { //mergeSort integers
   if (sortVector.size() <= 1) {
      return sortVector;
    }

   vector<int> left, right, res;
   int middle = (sortVector.size()+ 1) / 2;

   for (int i = 0; i < middle; i++) {
      left.push_back(sortVector[i]);
   }
   for (int i = middle; i < sortVector.size(); i++) {
      right.push_back(sortVector[i]);
   }

   left = mergeSort1(left);
   right = mergeSort1(right);
   res = merge1(left, right);

   return res;
}


vector<string> mergeSort2(vector<string> sortVector) { //mergeSort integers
   if (sortVector.size() <= 1){
      return sortVector;
    }

   vector<string> left, right, res;
   int middle = (sortVector.size()+ 1) / 2;

   for (int i = 0; i < middle; i++) {
      left.push_back(sortVector[i]);
   }
   for (int i = middle; i < sortVector.size(); i++) {
      right.push_back(sortVector[i]);
   }

   left = mergeSort2(left);
   right = mergeSort2(right);
   res = merge2(left, right);

   return res;
}


int main(int argc, char *argv[]) {
  ifstream file1;
  ifstream file2;
  string integer = "i";
  string word = "s";
  vector<int> temp1, temp2; //vector to hold all of file1/file2 integers
  vector<string> temp3, temp4; //vector to hold all of file1/file2 words
  vector<int> dest; //final vector integers
  vector<string> ination; //final vector words
  vector<int> v, w; //sorted vectors integers
  vector<string> x, y; //sorted vectors words
  int nums1, nums2; //integers
  string words1, words2; //words

//open the files and read in the first num or word
  file1.open(argv[2]);
  file2.open(argv[3]);

//if the files are numbers
  if (argv[1] == integer) {
    //cout << "Argument i" << endl;
//read in file1 into string
    while(file1 >> nums1) {
      temp1.push_back(nums1);
    }
    file1.close();
//read in file2 into string
    while(file2 >>nums2) {
      temp2.push_back(nums2);
    }
    file2.close();
//test strings by outputting
/*int len = temp1.size();
  for(int i=0; i<len; i++){
    cout << "1: " << temp1[i] << endl;
    cout << "2: " << temp2[i] << endl << endl;
}*/

//Print vectors before and after mergeSort
/*print(temp1);
print(temp2);
cout << "------------------" << endl;
*/

v = mergeSort1(temp1);
w = mergeSort1(temp2);

/*
print(v);
print(w);
*/

//find common integers
set_intersection(v.begin(), v.end(), w.begin(), w.end(), back_inserter(dest));
dest.erase(unique(dest.begin(), dest.end()), dest.end());
print1(dest);

return 0;
  }
//if the files are words
  if (argv[1] == word) {
    //cout << "Argument s" << endl;

    //read in file1 into string
        while(file1 >> words1) {
          temp3.push_back(words1);
        }
        file1.close();
    //read in file2 into string
        while(file2 >> words2) {
          temp4.push_back(words2);
        }
        file2.close();

//test strings by outputting
/* int len2 = temp3.size();
  for(int i=0; i<len2; i++){
    cout << "1: " << temp3[i] << endl;
    cout << "2: " << temp4[i] << endl << endl;
  } */

  //Print vectors before and after mergeSort

  /*print2(temp3);
  print2(temp4);
  cout << "------------------" << endl;*/

  x = mergeSort2(temp3);
  y = mergeSort2(temp4);

/*  print2(x);
  print2(y); */

  set_intersection(x.begin(), x.end(), y.begin(), y.end(), back_inserter(ination));
  ination.erase(unique(ination.begin(), ination.end()), ination.end());
  print2(ination);
  
  return 0;
  }
//if the file types are not given
  else{
    cout << "Argument 1 Invalid" << endl;
    return 0;
  }

return 0;
}
