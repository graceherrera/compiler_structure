# compiler_structure
Right now each node is specific for each structure and it lists their individual children
The goal is to create a vector of children so that the ast is easier to follow. 
tokens.l = flex file 
parser.y = bison file
Bison will create the parser.hpp file header for the flex file. 

