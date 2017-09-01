#include <iostream>
#include <string>
#include <bitset>
#include <fstream>

using namespace std;

int main(){
  string line;
  ifstream input("input.txt");
  if(input.is_open())
  {
    while(getline (input, line))
    {

      for (size_t i = 0; i < line.size(); ++i){
        bitset<8> bitset1(line.c_str()[i]);
        if (bitset1[7] == 0){
          for(int k = 6; k >= 0; k--){cout << bitset1[k];}
          cout << line << endl;
        }
        else if(bitset1[7] == 1 && bitset1[6] == 1 && bitset1[5] == 1){
          cout << line <<" feed the stripped bitsets to an array" << endl;}
        //cout << line << " " << bitset1[7] << endl;
        //cout << line << " " << bitset1 << endl;
        //cout << line << " " << bitset1[7] << endl;
        // for(int j = 0; j < bitset1.size(); j++){
        //   if (bitset1[0] == 0) {cout << "zero";}
        // }
      }
    }
    input.close();
  }
}
