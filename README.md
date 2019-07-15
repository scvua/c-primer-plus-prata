# Solutions to exercises from the "C Primer Plus" by Stephen Prata

This repository contains my solutions to exercises presented in the [_C Primer Plus, 6th edition_](https://www.amazon.com/gp/product/0321928423/) by Stephen Prata.
All solutions was compiled and tested on _macOS High Sierra (ver.10.13.6)_, _Xcode 10.1_, using the clang compiler _Apple LLVM version 10.0.0 (clang-1000.11.45.5)_.


### Sections

* [03. Data and C](src/pset03/)
* [04. Character Strings and Formatted Input/Output](src/pset04/)
* [05. Operators, Expressions, and Statements](src/pset05/)
* [06. C Control Statements: Looping](src/pset06/)
* [07. C Control Statements: Branching and Jumps](src/pset07/)
* [08. Character Input/Output and Input Validation](src/pset08/)
* [09. Functions](src/pset09/)
* [10. Arrays and Pointers](src/pset10/)
* [11. Character Strings and String Functions](src/pset11/)
* [12. Storage Classes, Linkage, and Memory Management](src/pset12/)
* [13. File Input/Output](src/pset13/)
* [14. Structures and Other Data Forms](src/pset14/)
* [15. Bit Fiddling](src/pset15/)
^ **Note**: Exercises to chapters 15 - 17 are in the process


### Extras

[Extras Folder](src/extras/) contains my test programs or experiments:

* __filecopy.c__: implementation of the *ex11_02* with `getc()` and `putc()` functions.
* __persons.c__: a warm-up program before doing *ex14_07*.
* __printer.c__: prints contents of the text file, but replaces each invisible `\n` character with the visible `\n` output.
* __revstr.c__: the `revstr()` function (*ex11_09*) with a temporary VLA array.
* __spacer.c__: inserts whitespace characters between the characters of the text file.


### Data and Test Files

[Data Folder](data/) contains text and data files.
Files with `.dat` extension are the parts of some exercises and contain the data for the program execution.  
Text files are provided to support manually testing the exercises.

* __/flights__: the folder contains data files for the *ex14_09* execution. Each file has the data of the Colossus Airlines flight with the corresponding flight number.
* __alphabet.txt__: 26 lines with the alphabetic characters.
* __book.dat__: the books database for *ex14_07*.
* __digits.spaced.txt__: input file for *ex13_12*, *ex13_13*, and *ex13_14*. The file was created by applying `spacer.c` on `digits.txt`.
* __digits.txt__: 20x30 digits file with no spaces.
* __fewlines.txt__: few lines of the text.
* __flight.dat__: the database for the first Colossus Airlines flight (*ex14_08*).
* __persons.dat__: is used by `persons.c` (feed the address to the file as a command-line argument).
* __softball.txt__: the softball team statistics, for use with the *ex14_06*.


### License

These solutions are copyright under the terms of the MIT LICENSE (see [LICENSE](LICENSE.md)) with the following exception:

* The source code of this project is directly the answers for the exercises presented in the book "C Primer Plus, 6th edition" by Stephen Prata (2014). The text of most of the opening comments of the solutions, which contain the exercise conditions, can partially or completely recite the corresponding fragments of the book with the original exercise conditions. Therefore, before-mentioned fragments of comments fall under the influence of the publisher's copyright.
