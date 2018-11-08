//Binary Heap Class
#include <vector>
#include "htree.hh"

class Heap {
    
    public:
        using tree_vec = std::vector<HTree::tree_ptr_t>;
        
        //Constructor initializes the heap with an input vector
        Heap(std::vector<HTree::tree_ptr_t>);
        
        //returns number of elements in the heap
        int size() const;
        
        //adds a new tree to the heap
        void add_tree(HTree::tree_ptr_t);
        
        //returns and removes the tree with the greatest value
        //Also to make this heap functional I guess I have to add functionality
        //for this to re-establish heap property? Since it's no good to 
        //leave the greatest tree in the heap and it also uses a different
        //algorithm to heapify than add_tree (heapify) does.
        HTree::tree_ptr_t  pop_tree();
        
        //Helper func to get first tree
        HTree::tree_ptr_t get_first() const;           
        
    private:
    
        //collection of the trees in the heap
        std::vector<HTree::tree_ptr_t> elements_;
        
        //initializes the vector into a heap, called once after creation
        void build_heap();          
        
        //re-establishes heap property, called once after every add_tree
        //Also used in heap creation (ironically).
        //Argument specifies which node to look at for the newly added tree
        void heapify(int node);

};        







