## Parallel Algorithms For Matrix-Matrix Multiplication

It appears that most parallel algorithms for matrix-matrix multiplication are concerned with a memory bottleneck. A naive way to handle matrix multiplication would be to simply assign processor cores to different quadrants of the final matrix. Because entries in the product matrix are not reliant upon one another, this seems like it ought to work well enough. What this does not take into account is the fact that the processors will often be attempting to access the same blocks of memory simultaneously. This induces a memory bottleneck rather than a computational one. Hence, it seems most parallel algorithms for matrix-matrix multiplication are more interested in way to manage memory so as to minimize memory access overlap. Some parallel algorithms that employ more sophisticated methods of memory management are the Fox algorithm and the Cannon algorithm [Source](http://www.hpcc.unn.ru/mskurs/ENG/DOC/pp08.pdf).

## Parallel Algorithms for Matrix-Vector Multiplication

The issues associated with matrix-vector multiplication are very similar to those with matrix-matrix multiplication. In the case of matrix-vector multiplication, however, they are less severe. This is due to there being less overlap between memory accesses. None of the algorithms seem to have specific names, but they can be found in the attached source. [Source](http://www.hpcc.unn.ru/mskurs/ENG/DOC/pp07.pdf)