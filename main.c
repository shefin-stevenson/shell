/*
 *
 *@main   ENPM675 Programming Assignment 
 *
 *  	  This a simple command-line shell program that allows the user
 *  	  to start programs and perform several simple file manipulation tasks.
 *       
 * 
 *@author Shefin Stevenson
 * 
 *@date   06-05-2017
 *
 */

/* Header files */
#include <stdio.h>

#include "helper_functions.h" 

int main(int argc, char **argv)
{
	/* display shell prompt*/ 
	display_prompt();

	/* prompt user to enter a command */
	display_user_message();

	char *cmd_line = NULL;
	char **cmd_tokens = NULL;

	/* read user command */
	cmd_line = read_user_command();
	
	if (!cmd_line) { 
		return EXIT_FAILURE;
	}
	else { 
		//printf("%s",cmd_line);

		cmd_tokens = parse_command(cmd_line);
		
		int i=0;
        	while (cmd_tokens[i] != NULL) {
                printf("TOKENS[%d]: %s\n",i,cmd_tokens[i]);
                i++;
        	}

	}

	return 0;
}

