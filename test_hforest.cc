//#define CATCH_CONFIG_MAIN //Have catch provide our main function
#include "catch.hpp"
#include "BHeap.hh" 

TEST_CASE("Forests! Forests should be a collection of trees that we can manipulate. Trees themselves are not tested here.")
{
    /*First we set up our forests. To do this, we first create several trees to populate the forests, but trees
    are not being tested here so we use relatively simple ones. Then we create two forests which hold some combination
    of these trees.
    Our setup should look something like this:
    
    Trees!
    Legend- {key//value}, as we now care about the value in a tree as well as the key.
    
    Tree 1: {1//12}      Tree 2: {4//8}         Tree 3: {6//1}          Tree 4: {9//47}        Tree 5: {11/20}
             /    \              /    \                  /  \                   /     \                /     \
          {2//2}{3//3}        {5//5}{nullptr}        {7//7}{8//8}          {nullptr}{10//10}       {12//12}{13//13}
          
    Forests! (the internal ordering here might not be completely accurate, but what matters is they contain these elements with the biggest value at the front).
    And in each case we expect tree_4 to be at the front, as it contains the biggest value, 47.
    
    Forest 1: [ {Tree 4} {Tree 1} {Tree 2} {Tree 3} ]
    
    Forest 2: [ {Tree 4} {Tree 5} {Tree 3} ]
    
    And now the code to actually produce these trees and forests:
    */
    
    //Tree 1
    HTree::tree_ptr_t tree_1 (new HTree( 1, 12, 
                                        HTree::tree_ptr_t (new HTree(  2, 2)), 
                                        HTree::tree_ptr_t (new HTree(  3, 3)) ) );
    //Tree 2
    HTree::tree_ptr_t tree_2 (new HTree( 4, 8, 
                                        HTree::tree_ptr_t (new HTree(  5, 5)), 
                                        nullptr) );
    //Tree 3
    HTree::tree_ptr_t tree_3 (new HTree(6, 1, 
                                        HTree::tree_ptr_t (new HTree(  7, 7)), 
                                        HTree::tree_ptr_t (new HTree(  8, 8)) ) );
    //Tree 4
    HTree::tree_ptr_t tree_4 (new HTree( 9, 47, 
                                        nullptr, 
                                        HTree::tree_ptr_t (new HTree(  10, 10)) ) );
    //Tree 5
    HTree::tree_ptr_t tree_5 (new HTree( 11, 20, 
                                        HTree::tree_ptr_t (new HTree(  12, 12)), 
                                        HTree::tree_ptr_t (new HTree(  13, 13)) ) );    

    //Forest 1
    Heap::tree_vec forest_collection_1{tree_1, tree_2, tree_3, tree_4};
    Heap test_forest_1(forest_collection_1);
    //Forest 2
    Heap::tree_vec forest_collection_2{tree_3, tree_4, tree_5};
    Heap test_forest_2(forest_collection_2);
    
    SECTION("We should be able to test the size of a tree and confirm it has a heap structure.")
    {
        REQUIRE(test_forest_1.size() == 4);
        REQUIRE(test_forest_2.size() == 3);
        //Then we check to make sure the first tree in each forest is the tree with the highest value, tree_4, as expected
        REQUIRE(test_forest_1.get_first() == tree_4);
        REQUIRE(test_forest_2.get_first() == tree_4);
    }
    
    SECTION("Forests should be able to add and pop off trees, retaining a heap structure; size of a forest should be properly adjusted after pop and add.")
    {
        REQUIRE(test_forest_1.pop_tree() == tree_4);
        REQUIRE(test_forest_1.get_first() == tree_1);
        REQUIRE(test_forest_1.size() == 3);
        test_forest_1.add_tree(tree_5);
        REQUIRE(test_forest_1.size() == 4);
        REQUIRE(test_forest_1.get_first() == tree_5);
        //And then forest_2
        REQUIRE(test_forest_2.pop_tree() == tree_4);
        REQUIRE(test_forest_2.size() == 2);
        test_forest_2.add_tree(tree_1);
        REQUIRE(test_forest_2.size() == 3);
        REQUIRE(test_forest_2.get_first() == tree_5);
    }
    
}