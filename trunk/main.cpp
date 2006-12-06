// On my honor: 
//
// - I have not used C++ language code obtained from another student,
// or any other unauthorized source, either modified or unmodified.
//
// - All C++ language code and documentation used in my program
// is either my original work, or was derived, by me, from the source
// code published in the textbook for this course.
//
// - I have not discussed coding details about this project with anyone
// other than my instructor, ACM/UPE tutors or the GTAs assigned to this
// course. I understand that I may discuss the concepts of this program
// with other students, and that another student may help me debug my
// program so long as neither of us writes anything during the discussion
// or modifies any computer file during the discussion. I have violated
// neither the spirit nor letter of this restriction.
 
/**
 * Project 3 for CS2606 Fall 2006
 * 
 * Programmer: codemac @ braundui
 * 
 * Purpose of Program: This project is to create a Buffer Pool and an overriding
 * Memory Manager to control the Buffer Pool.  The Memory Manager and Buffer
 * Pool are designed to minimize the number of disk accesses while reading
 * and writing to a file to improve efficiency. 
 * 
 * OS: Windows XP 
 * Compiler: Eclipse
 * Date of Completion: November 02, 2006
 */

#include <iostream>
#include <cstdlib>
#include "Parser.h"

int main(int argc, char* argv[])
{
	if( argc != 3 ) {
		std::cout << "Unknown Command. You need 2 arguments, file name and then the number of buffers used to store them." << std::endl;
		return 1;
	}
	//Parser bob(argv[0], atoi(argv[1]));
    Parser bob;
	bob.parse();
	return 0;
}
