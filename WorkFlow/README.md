# Implementation of the Workflow Executor application

Workflow is a computational scheme consisting of a set of computational blocks and links between them. The workflow described in the file is served to the program.

In this task, the only type of workflow is considered – linear, i.e. pipeline.

The list of blocks used in the scheme (the set of blocks is being expanded):

1) readfile <filename> – reading a text file into memory, in its entirety.
   Input is missing, output is text.

2) writefile <filename> – writing text to a file.
   Input is text, output is missing.

3) grep <word> – selection from the input text of lines separated by line breaks containing the specified word <word>.
   Input – text, output – text.

4) sort – lexicographic sorting of the input set of strings.
   Input – text, output – text.

5) replace <word1> <word2> – replace the word <word1> with the word <word2> in the input text.
   Input – text, output – text.

6) dump <filename> - save the incoming text in the specified file and pass on.
   Input – text, output – text.

**Input file format:**

*desc # description of the scheme*

*id1 = block1*

*id2 = block2*

*…*

*idN = blockN*

*csed*

*idA -> idB -> idC -> … -> idZ # description of the schema structure*

Where:

1) *desc, csed* are keywords that restrict the section of workflow block descriptions.

2) *id1 ... idN* – integers, non-negative, non-repeating numbers.

3) *block1 ... blockN* – blocks from the list of blocks, with required parameters.

4) *idA, idB ... IdZ* are numbers belonging to the set id1...idN. They can be repeated, the length of the conveyor is unlimited.

5) *->* is a keyword denoting the connection of computing nodes.

**Sample Workflow file:**

workflow.txt

desc

*1 = readfile in_file.txt*

*2 = writefile out_file.txt*

*3 = sort*

*10 =  replace word1 word2*

*csed*

*1 -> 3 -> 10 -> 3 -> 2*


