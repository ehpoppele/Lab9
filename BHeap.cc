#include "BHeap.hh"

Heap::Heap(std::vector<HTree::tree_ptr_t> elements)
{
    elements_ = elements;
    build_heap();
}

int Heap::size() const
{
    return elements_.size();
}

//Adds the requested node into the heap structure
//Accomplishes this recursively by checking the value
//of the parent node
void Heap::heapify(int node)
{
    if (node == 0) return;//already the top node
    int parent = (node/2); //this should be a nice int divide; should also point right to the parent node, more on this in the README
    if (elements_[node]->get_value() > elements_[parent]->get_value())
    {
        auto temp_parent = elements_[parent];
        elements_[parent] = elements_[node];
        elements_[node] = temp_parent;
        heapify(parent);
    }
}

//To initialize the heap we begin with the given vector in whatever order it is passed
//We then "sift" from the bottom up, taking each child and checking if it is greater than
//it's root.
//To help visualize this process, we can describe our vector as a tree, with the first element
//being the main root, the next two being it's children, the next four being their respective
//children, and so on down, increasing by powers of two.
void Heap::build_heap()
{
    int size = this->size();//I think i need "this" for this line
    for (int node = size-1; node >= 0; --node) 
    {
        heapify(node);
    }
}

//Adds element to back of heap vector then adds calls heapify
//to maintian structure
void Heap::add_tree(HTree::tree_ptr_t tree)
{
    elements_.push_back(tree);
    heapify(this->size() - 1);
}
    
//So pop trees here first reduces the heap structure by switcthing the top node
//and the last node, then does a recursive check that's essentially a backwards 
//of add_node, only now treating the heap as size Heap.size - 1, so as not to
//compare with the node that is being removed.
//After this, we pull the node off the end of the vec and return it.
HTree::tree_ptr_t  Heap::pop_tree()
{
    int size = this->size();
    auto max_tree = elements_[0];//swap the nodes
    elements_[size - 1] = max_tree;
    elements_[0] = elements_[size - 1];
    elements_.pop_back();
    size = this->size();//redo size    
    //now we re-establish heap; there's a better way but for now we just redo 
    //something like a creation of heap initialization on everything
    //except for that last node
    for (int node = size-1; node >= 0; --node) 
    {
        heapify(node);
    }
    return max_tree;
}
        
HTree::tree_ptr_t Heap::get_first() const
{
    return elements_.front();
}









