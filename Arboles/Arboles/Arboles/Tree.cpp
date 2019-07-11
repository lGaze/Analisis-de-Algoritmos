#include "Tree.h"

tree::tree()
{
  root = nullptr;
}

tree::~tree()
{
  destroy_tree();
}

void tree::insert(int key)
{
  if (root != nullptr)
  {
    insert(key, root);
  }
  else
  {
    root = new node;
    root->key_value = key;
    root->left = nullptr;
    root->right = nullptr;
  }
}

node * tree::search(int key)
{
  return search(key, root);
}

void tree::destroy_tree()
{
  destroy_tree(root);
}

void tree::destroy_tree(node * leaf)
{
  if (leaf != nullptr)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void tree::insert(int key, node * leaf)
{
  if (key < leaf->key_value)
  {
    if (leaf->left != nullptr)
    {
      insert(key, leaf->left);
    }
    else
    {
      leaf->left = new node;
      leaf->left->key_value = key;
      leaf->left->left = nullptr;
      leaf->left->right = nullptr;

    }
  }
  else if (key >= leaf->key_value)
  {
    if (leaf->right != nullptr)
    {
      insert(key, leaf->right);
    }
    else
    {
      leaf->right = new node;
      leaf->right->key_value = key;
      leaf->right->left = nullptr;
      leaf->right->right = nullptr;
    }
  }
}

node * tree::search(int key, node * leaf)
{
  if (leaf != nullptr)
  {
    if (key == leaf->key_value)
    {
      return leaf;
    }
    if (key < leaf->key_value)
    {
      return search(key, leaf->left);
    }
    else
    {
      return search(key, leaf->right);
    }
  }

  else return nullptr;
}
