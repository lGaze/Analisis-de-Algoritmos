/**************************************************************************/
/* @filename Tree.h
/* @author Victor Flores 
/* @date 2019/07/11
/* @brief 
/*************************************************************************/
#pragma once

#include "Node.h"
#include <iostream>

class tree
{
public:

  tree();
  ~tree();

  void insert(int key);
  node *search(int key);
  void destroy_tree();

private:

  void destroy_tree(node * leaf);
  void insert(int key, node * leaf);
  node * search(int key, node * leaf);

  node * root;

};

