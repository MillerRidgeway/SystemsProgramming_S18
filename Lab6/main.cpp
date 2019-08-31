#include <iostream>
#include <stdio.h>
#include <cstdint>

#include "PackedArray.h"
#include "TestLab6.h"


int main(int argc, const char * argv[])
{

  // Run tests with various size PackedArray
  std::cout << "Tests running.\n";

//    PackedArray a = CreateArray(1);
//
//    SetEntry(a,0,0,3);
//    SetEntry(a,0,1,3);
//
//    std::cout << GetEntry(a, 0, 0) << std::endl;
//    std::cout << GetEntry(a, 0, 1) << std::endl;

  TestLab6(4);

  TestLab6(6);

  TestLab6(2);

  TestLab6(64);

  TestLab6(32);

  TestLab6(33);

  TestLab6(1001);

  std::cout << "Testing complete.\n";
}
