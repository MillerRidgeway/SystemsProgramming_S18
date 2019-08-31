//
//  main.cpp
//  Lab9
//
//  Created by Computer Science on 2/1/16.
//  Copyright (c) 2016 Computer Science. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

int main(int argc, const char * argv[])
{
  LinkedList list;
  
  list.printList();
  
  for(int i=0; i < 10; i++)
  {
    list.insertAtHead(i);
    list.printList();
  }
  
  //list.printList();
  
  list.freeList();
  
  list.printList();
  
  return 0;
}
