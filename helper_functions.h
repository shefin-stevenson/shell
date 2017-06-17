/*
 *
 *@main   This is the header file declaring helper functions for the command-line
 *        shell program
 *
 *@author Shefin Stevenson
 *
 *@date   06-05-2017
 *
 */

#ifndef _HELPER_FUNC_
#define _HELPER_FUNC_

/* header includes */
#include <stdio.h>
#include <stdlib.h>

/* display shell prompt */
void display_prompt(void);

/* prompt user to enter a command */
void display_user_message(void);

/* read user a command and return the command string */
char* read_user_command(void);


/* parse command line and return commands */
char** parse_command(char*);


#endif /* _HELPER_FUNC_ */ 
