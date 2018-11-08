README!
----------Concerning the lab assignment-----------------
To whatever unfortunate soul has the pleasure of grading this:
I am just finishing this in a rush late at night so it's obviously
a bit of a mess. Essentially what I have done is taken my old HW 6,
documentation appearing below, and then replaced all of HForest with
this new Heap class, making the appropriate changes in the makefile
and testing file, though not all the names are properly changed, 
and a lot of places still say forest. Anyways, this is my attempt for
partial credit.
For implementing the Heap, I pretty much made my code just like HForest
which has design decisions below, but then wrote heap functionality myself.
I also pretty much have my vector so that it's a "tree condensed into a line;"
(this is also right on wikipedia but it's written much better) where the first
element can be written as the first row of my binary tree, the next two
elements the second row, the next four the third, and so on with powers of two.
This also means that the children are going to be equal to twice the node value
of their parent, plus 1 for left and plus 2 for right.

Finally, it should be noted that my add_tree and pop_tree methods do not appear
to actually work--they add and remove the appropriate items, but fail to establish
a heap, although it does appear that my heap initializer does make a heap to start
with, and is based off the same function. My testing file will confirm this.

You don't really need to read anything below this except compiling, and much info may
be incorrect.


----------Files in this repository----------------------

htree.hh-
    Header file for htree class and relevant functions

htree.cc-
    Implementation file for htree class and said functions

test_htree.cc-
    Testing file for htree, implemented with Catch2.

hforest.hh-
    Header file for hforest class

hforest.cc-
    Implementation file for hforest class

test_hforest.cc-
    Testing file for hforest, implemented with Catch2.

makefile-
    Makefile that compiles everything. This compiles all the above four .cc files into
objects and then makes a final test file binary, htest_all, out of them.

README.txt-
    The thing you're reading right now.
    
catch.hpp-
    This file implements the Catch2 framework used for my testing.
    
Any other file-
    Includes leftover object files and binaries (htest_all) and possible Russian viruses.
No need to deal with these.

--------------------------------------------------------

--------------------Compiling---------------------------
Compile the program with the makefile (make). I had run 
into an apparently cursed error earlier that was causing
my makefile to not work, resulting in an error of multiple
definitions of several functions in htree. I don't know why
this happened. I don't know where it came from, or where it
went, but cleaning my object files again seemed to work?
In any case, if this returns, another workaround I found was
to compile with a command line of:
g++ -o htest_all hforest.cc htree.cc test_hforest.cc test_htree.cc -Wall -Wextra -Werror -pedantic
--------------------------------------------------------

------------------Design Choices------------------------
I mostly just followed the instructions given for the
homework, and build htree in a very similar manner to the
tree class from last weeks homework, only now changing 
path_to to work with trees as a class with smart pointers.
I again included an extra helper function contains_key
to help with path_to.

For the hforest, I included the required methods, as well
as a constructor and destructor (the latter of which does
nothing beyond the default). I added a method to return
a pointer to the first tree in a forest, so I could ensure
that the forest was being stored as a heap. In addition, I
wrote a boolean function to use as a comparator for the heap
which compares the values of two trees. This is an extra
function that is not part of the HForest class because
it can't be called in relation to a forest, so instead it just
kinda floats out there in the hforest.hh file.
As for the forest itself, I represented it as a vector,
which seemed convenient because a vector destroys itself
and could function as an ordered list of trees, which
is really all that I needed. I then made that vector
into a heap.

For testing, I wrote the tests separately and just made
sure they covered all the methods that I wrote for 
each class and made sure that all those calls work.
--------------------------------------------------------















