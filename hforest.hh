#pragma once
#include "htree.hh"
#include <vector>

class HForest {
 public:
    
    //Forests are composed of a vector of pointers to HTrees
    using tree_vec = std::vector<HTree::tree_ptr_t>;
    
    //constructor and destructor
    HForest(tree_vec collection);
    ~HForest();
    
    //returns the number of trees in a forest
    int size() const;
    
    //takes a tree_ptr_t (shared pointer) and adds it to the forest
    void add_tree(HTree::tree_ptr_t tree);
    
    //finds the highest-value tree in a forest, then returns a pointer to said tree and removes it from the forest
    HTree::tree_ptr_t pop_tree();
    
    //Extra helper function to get a pointer to the first tree of a forest
    //Just so checking for heap functionality is a little easier
    HTree::tree_ptr_t get_first() const;
    
 private:
    
    //This is simply the actual data of the forest, which is the vector of trees in it
    tree_vec collection_;
    
    
    
};

    //This helper function is used to make the forest vector into a heap; it is the comparator function used for the heap
    bool compare_trees(HTree::tree_ptr_t tree1, HTree::tree_ptr_t tree2);










