# Sorch
This is a testing harness for people looking to improve their sorting algorithm prowess.

This program generates a random array(s), where you're instructed to solve this array (and insert your sorting code on line 58). At that point, the program tests if the resultant array is sorted or not. The sorting must be done in-place.

Using the preprocessor parameters, you are instructed to set your own as you see fit—I recommend using small values in the beginning so as to aid your debugging process. 

### Preprocessor Parameters

#### TES
This is the number of arrays to generate.

#### NUM
This is the number of integers that will be generated in each array. 

#### MIN and MAX
This represents an inclusive range for each number in the array. If you select MIN = 10 and MAX = 20, then numbers in generated arrays will be of the set {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}.

All arrays will only be generated if you successfully sort the last ones. If TES=10 and you fail on the fifth array, the program halts.

That means aside from the intermediate array printing that happens before the program's finish, you can only really feel confident about your algorithm if you see the text "All tests passed".

### Running
If you want to use the `makefile` you may run it by simply typing `make`, though if you just want to compile it, you may type `make compile`. By default, `make` will compile and run it. If you want to run it under `valgrind` then type `make valgrind`.
