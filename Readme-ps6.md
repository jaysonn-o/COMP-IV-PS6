# PS6: RandWriter

## Contact
Name: Jason Ossai
Section:201
Time to Complete: span of 2 days


## Description
In this project, a Markov text generator is implemented, which analyzes text to determine the likelihood of letter sequences occurring and generates a random text that resembles the input.

### Features 
For me it was exception handling, for invalid arguments (k-gram length)

### Testing
calculations, random character generation, text generation . My test passed 3 out of 5 on the autograder with only these 2 tests failing below:

1.4) Your Tests vs: Wrong Start (0/1)
Test Failed: True is not false : Passed a broken implementation
My generate() starts with the wrong string.
Running 5 test cases...

[1;32;49m*** No errors detected
[0;39;49m
1.5) Your Tests vs: Wrong Distribution (0/1)
Test Failed: True is not false : Passed a broken implementation
I generate letters with the wrong frequency.
Running 5 test cases...

[1;32;49m*** No errors detected
[0;39;49m   

### Lambda
I did not use any lambda expression

### Issues
 I had trouble with my test.cpp file because my generate() function kept starting with the wrong string, my tests also kept generating letters in  the wrong frequency. I also learnt more  about Markov models .

### Extra Credit
Non Attempted

## Acknowledgements
I had a bit of help from my instructor , James Daly regarding my test cases.
