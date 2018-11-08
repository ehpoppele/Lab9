#include "hforest.hh"
#include <algorithm>

//Not actually a class function, this just returns true if the value
//of tree 1 is less than tree 2. Used for the heap.
bool compare_trees(HTree::tree_ptr_t tree1, HTree::tree_ptr_t tree2)
{
    return tree1->get_value() < tree2->get_value();
}

//Our constructor first assigns the data and then makes the vector into a heap
HForest::HForest(tree_vec collection)
{
    collection_ = collection;
    std::make_heap(collection_.begin(), collection_.end(), compare_trees);
}   
 
//Destructor function; doesn't need to do any work
HForest::~HForest()
{
    //Nothing to delete in our destructor;
    //Our vector is a smart data type thing that destroys itself
    //And the contents of our vector are shared pointers, which also don't need to be deleted
}

//Returns the number of trees in our forest
int HForest::size() const
{
    return collection_.size();
}

//Adds a tree to our forest and keeps forest as a heap
void HForest::add_tree(HTree::tree_ptr_t tree)
{
    collection_.push_back(tree);
    std::push_heap(collection_.begin(), collection_.end(), compare_trees);
}

//Removes and returns a tree pointer from the front of our forest while maintaining heap structure
HTree::tree_ptr_t HForest::pop_tree()
{
    std::pop_heap(collection_.begin(), collection_.end(), compare_trees);
    auto popped_tree = collection_.back();
    collection_.pop_back();
    return popped_tree;
}
    
//Extra method that returns the first tree in our collection
//Not a helper for any other method, but just makes testing for heap structure easier
HTree::tree_ptr_t HForest::get_first() const
{
    return collection_.front();
}













