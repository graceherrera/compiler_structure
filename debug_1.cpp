#include <iostream>
#include <fstream>
#include <stdint.h>
#include <stdlib.h>

using namespace std;

void print_bits(unsigned char ch){
  int i;
  for (i = 7; i >= 0; i--){
    cout << ((ch >> i) & 1);
  }
  cout << endl;
}

void print_bits_32(uint32_t ch32){
  int i;
  for (i = 32; i >= 0; i--){
    cout << ((ch32 >> i) & 1);
  }
  cout << endl;
}

int main(){
unsigned char ch = 0;
uint32_t codepoint, temp;


ifstream input;
input.open("input.txt", ios::binary);
while(input >> ch){
  if((ch & 0b10000000) == 0){
    cout << "you have a one byte character: ";
    cout << ch << ": " << hex << int(ch) << endl;
  }
  else if ((ch & 0b11110000) == 0b11110000){
    cout << "You have a four byte character: ";
    ch = (ch & 0b00000111);
    codepoint = ch;
    codepoint = (codepoint << 6);
    input >> ch;
    ch = (ch & 0b00111111);
    temp = ch;
    codepoint = codepoint | temp;
    codepoint = codepoint << 6;
    input >> ch;
    ch = (ch & 0b00111111);
    temp = ch;
    codepoint = codepoint | temp;
    codepoint = codepoint << 6;
    input >> ch;
    ch = (ch & 0b00111111);
    temp = ch;
    codepoint = codepoint | temp;
    cout << codepoint << endl;
  }
  else if ((ch & 0b11100000) == 0b11100000){
    cout << "You have a three byte character: ";
    ch = (ch & 0b00001111);
    codepoint = ch;
    codepoint = (codepoint << 6);
    input >> ch;
    ch = (ch & 0b00111111);
    temp = ch;
    codepoint = codepoint | temp;
    codepoint = codepoint << 6;
    input >> ch;
    ch = (ch & 0b00111111);
    temp = ch;
    codepoint = codepoint | temp;
    cout << codepoint << endl;
  }
  else if ((ch & 0b11000000) == 0b11000000){
    cout << "You have a two byte character: ";
    ch = ch & 0b00011111;
    codepoint = ch;
    codepoint = (codepoint << 6);
    input >> ch;
    ch = (ch & 0b00111111);
    temp = ch;
    codepoint = codepoint | temp;
    cout <<codepoint << endl;
  }

  //ch = ~ch;
  // ch = (ch | 0b11111111);
  //ch = (ch & 0b11111111); mask -- because it allows us to control the ones and discard extra stuff
  // ch = (ch << 1);
  // print_bits(ch);
  // ch = (ch >> 16);
  // print_bits(ch);

}



  return 0;
}
