// Written by Aaron Barge
// Copyright 2019
#ifndef _TREE_TESTING_CC_
#define _TREE_TESTING_CC_
#include <iostream>
#include "Tree.h"
#include "BinaryTree.h"
#include "DoublyLinkedTree.h"
#include "Huffman.h"
#include "AVLTree.h"
#include "TwoThreeTree.h"
#endif

bool testBinaryTree(Tree<int>* t);
bool testDoublyLinkedTree(Tree<int>* t);
bool testHuffmanTree(Tree<int>* t);
bool testAVLTree(Tree<int>* t);
bool testTTTree(Tree<int>* t);

int main(int argc, char** argv) {
  Tree<int>* Tree = new BinaryTree<int>();
  testBinaryTree(Tree);
  delete Tree;
  Tree = new DLTree<int>();
  if (!testDoublyLinkedTree(Tree)) {
    std::cout << "Doubly Linked Tree testing has failed" << std::endl;
  }
  return 0;
}
bool testBinaryTree(Tree<int>* t) {
  std::cout << "Testing Binary Search Tree" << std::endl;
  bool result = true;
  std::cout << "Adding values..." << std::endl;
  t->Add(5);
  t->Add(4);
  t->Add(19);
  t->Add(2);
  t->Add(7);
  t->Add(12);
  t->Add(1);
  t->Add(3);
  t->Add(10);
  t->Add(6);
  std::cout << "Values added successfully" << std::endl;
  t->Print();
  std::cout << "The size of the tree is currently: " << t->Size() << std::endl;
  std::cout << "The maximum depth of the tree is currentlty: " << t->MaxDepth() << std::endl;
  if (!t->Contains(5)) {
    std::cout << "Contains contained value test failed" << std::endl
        << "  Expected: " << true << std::endl
        << "  Actual: " << t->Contains(5) << std::endl;
    result = false;
  }
  if (t->Contains(100)) {
    std::cout << "Contains not contained value test failed" << std::endl
        << "  Expected: " << false << std::endl
        << "  Actual: " << t->Contains(100) << std::endl;
    return false;
  }
  std::cout << "Removing 10" << std::endl;
  t->Remove(10);
  t->Print();
  if (t->Contains(10)) {
    std::cout << "Value removal was unsuccessful" << std::endl
        << "  Expected: " << false << std::endl
        << "  Actual: " << t->Contains(10) << std::endl;
    result = false;
  }
  std::cout << "Removing 2" << std::endl;
  t->Remove(2);
  t->Print();
  if (t->Contains(2)) {
    std::cout << "Value removal was unsuccessful" << std::endl
              << "  Expected: " << false << std::endl
              << "  Actual: " << t->Contains(2) << std::endl;
    result = false;
  }
  std::cout << "Removing value not contained in tree" << std::endl;
  t->Remove(100);
  t->Print();
  std::cout << "The size of the tree is currently: " << t->Size() << std::endl;
  std::cout << "The maximum depth of the tree is currentlty: " << t->MaxDepth() << std::endl;
  std::cout << "Popping off root" << std::endl;
  int old_root = t->Pop();
  t->Print();
  std::cout << "Making sure root was removed successfully" << std::endl;
  if (t->Contains(old_root)) {
    std::cout << "Value removal was unsuccessful" << std::endl
              << "  Expected: " << false << std::endl
              << "  Actual: " << t->Contains(old_root) << std::endl;
    result = false;
  }
  std::cout << "The size of the tree is currently: " << t->Size() << std::endl;
  std::cout << "The maximum depth of the tree is currentlty: " << t->MaxDepth() << std::endl;
  std::cout << "Binary Search Tree testing has " << (result ? "PASSED" : "FAILED") << std::endl;
  return result;
}
bool testDoublyLinkedTree(Tree<int>* t) {
  
}