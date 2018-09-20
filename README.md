# CELL-Easy-Programming

This project aims to facilitate [Cell-BE programming](http://moss.csc.ncsu.edu/~mueller/cluster/ps3/CBE_Tutorial_v2.0_15December2006.pdf). [Cell Broadband Engine (Cell-BE)](https://en.wikipedia.org/wiki/Cell_(microprocessor)) is a multi-core processor that employs one large core (named PPU) and several small cores (named SPEs). Such a heterogeneous architecture provides excellent performance for important classes of applications. 

However, programming of this processor is more difficult than general-purpose programming. The main reason is that the programmer should handle nearly everything. Meanwhile, most of the programming difficulty comes from dealing with SPE threads. 

This project tackles the hardship of programming by providing a generic programming framework. For this reason, a specific Class (named ‫‪*CellBEAbstractAlgorithm‬‬*) is implemented for handling threads. The Class takes (1) SPE/PPU programs and (2) number of SPEs as inputs, and creates/assigns the required threads. Since this Class deals with threads, it inherits another Class which itself deals with *pthread* Class.

The source code of Classes and an example of usage is provided in this repo. 
