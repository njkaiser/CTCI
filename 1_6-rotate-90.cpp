// Cracking the Coding Interview, Problem 1.6
// Given an image represented by an NxN matrix, where each pixel in the image is 4
// bytes, write a method to rotate the image by 90 degrees. Can you do this in
// place?

#include <iostream>
#include <vector>
#include <algorithm> // std::swap()

using namespace std;


void rotate_90(vector< vector<int> >& image) {
  int N = image.size();
  for(int i = 0; i < N/2; i++) {
    swap(image[i], image[N-1-i]);
  }

  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      swap(image[i][j], image[j][i]);
    }
  }
}


int main(int argc, char** argv)
{
  vector< vector<int> > image { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

  cout << "image before:" << endl;
  for(int i = 0; i < image.size(); i++) {
    for(int j = 0; j < image[0].size(); j++) {
      cout << image[i][j];
      if(j != image.size()-1) { cout << ", "; }
    }
    cout << endl;
  }
  cout << endl;

  rotate_90(image);

  cout << "image after:" << endl;
  for(int i = 0; i < image.size(); i++) {
    for(int j = 0; j < image[0].size(); j++) {
      cout << image[i][j];
      if(j != image.size()-1) { cout << ", "; }
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
