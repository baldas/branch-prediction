A simple example showing the power of current processor's branch prediction.
A vector is initially setup with random values. The code then counts
(using an auxiliary array) how many items in the vector is less or equal than
a given value (from 0 to sizeof(vector)-1).

The Makefile generates a default version and a version in which the vector is
sorted (using qsort). Once the vector is sorted, the branch predictor is more
likely to figure out the jump direction in the inner branch.

Note that some compilers may already optimized the code and use some form of
conditional move.
