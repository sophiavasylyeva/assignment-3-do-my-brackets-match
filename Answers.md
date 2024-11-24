# Assignment 3: Answers

**Complete this document, commit your changes to Github and submit the repository URL to Canvas.** Keep your answers short and precise.

Your Name: Sophia Vasylyeva

Used free extension: [ ] 24 hrs or [ ] 48 hrs

[X] Early submission (48 hrs)

[ ] Bonus work. Describe: ...

Place [x] for what applies.


## Answers
1. How long did the program take to check all three test files with each version?  Describe what differences in run time you expect for your implementation (use Big-O notation).

   > DSStack_array ran faster than DSList, but because of the push_front and pop_front functions implemented, both files use O(1) notation. 

2. Discuss the difference in memory usage based on **your** implementation.

   > DSList is a double-linked list that has nodes that point to previous, next, head, and tail nodes. The DSStack_array uses an array pointer. DSList uses more memory than DSStack_array because the list stores the data in its nodes through its pointer variables. 


3. Which version would you use in practice. Why?

   > I would DSStack_array in practice because its faster and is more versatile in its ability to insert data at the front and end of the array.

4. Make sure that your stack implementations does not have memory leaks.

   ```
   Paste the output of valgrind for running your tests for `DSStack_array` and `DSStack_list` here. 
   ```

   ==60206== Memcheck, a memory error detector
   ==60206== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
   ==60206== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
   ==60206== Command: ./check_brackets
   ==60206== 
   0.00035692==60206== 
   ==60206== HEAP SUMMARY:
   ==60206==     in use at exit: 0 bytes in 0 blocks
   ==60206==   total heap usage: 2 allocs, 2 frees, 73,728 bytes allocated
   ==60206== 
   ==60206== All heap blocks were freed -- no leaks are possible
   ==60206== 
   ==60206== For lists of detected and suppressed errors, rerun with: -s
   ==60206== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

5. Did you attempt any bonuses? If so, please give a brief description of what you did.

   > I attempted to check for comments in the data. This can be found in the check_brackets class. 
