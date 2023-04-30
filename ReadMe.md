# Operating Systems - Assignement 2 - Building Tools & Shell.

_In this assignement, we have developed various beneficial tools for users._
_Make sure to take a look at the following explanation in order to fathom the tools that we created and how they work:_

## Tool 1 - cmp

- **Objective** 
This tool compares the content of two given files according to a given command.
- **How To Use** 
The general usage format is as follows: ./cmp <first_file_name> <second_file_name> <command>
e.g, ./cmp firstFile.txt secondFile.txt -v
e.g, ./cmp firstFile.txt secondFile.txt -i

In your terminal, first enter the "./cmp", then, provide another two consecutive arguemnts which are representing the two files names that you desire to compare. Lastly, insert one of the two commands: -v or -i.

Difference between -v and -i:
-v command - makes the tool to support verbose output and prints out "equal" if the two files contain the same content.
-i command - makes the tool to perform ignore-case which compares the two files by considering the two files contents as lowercase.

## Tool 2 - copy

- **Objective**
This tool copies the first given file's content into the second given file's content.
- **How To Use**
The general usage format is as follows: ./copy <source_file_name> <destination_file_name> <command>
e.g, ./copy firstFile.txt secondFile.txt -v
e.g, ./copy firstFile.txt secondFile.txt -f

Usage of this tool is pretty similar to cmp tool's usage. However, it differs in terms of the given commands, which are: -v or -f

Difference between -v and -f:
-v command - makes the tool to support verbose output and prints out "success" if the content was successfully copied to the destination file
or "taget file exist" if the destination file already exists.
-f command - makes the tool to force overwriting the destination file even if it exists.

## Tool 3 - encode/decode

- **Objective**
This tool holds two dynamic libraries which contain two different algorithms that are performed on a given string:
    1. codecA - Converting all uppercase letters to lowercase letters and vice versa.
    2. codecB - Converting all characters to the 3rd next ASCII value and vice versa.
The above mentioned algorithms support encoding and decoding.

- **How To Use**
The general usage format is as follows: <encode/decode> <codecA/codecB> <string>
e.g, ./encode codecA bbbAAA
e.g, ./encode codecB kkk123
e.g, ./decode codecA BBBaaa
e.g, ./decode codecB xyzABC

## Tool 4 - stshell

- **Objective**
This tool is basically a shell providing us to run tools - either the above mentioned tools or linux-based tools.

- **How To Use**
Simply typing ./stshell in your terminal and you can start running any tool you desire.

**-------------------------------------------------------------------------------------------------------------------------------------------**

# NOTICE

_A complete makefile is given that compiles everything for us and prepares the whole tools to be runnables._
_In order to be able to use the whole tools, make sure to compile the whole tools by typing "make all" in your main terminal._
