/*
 *
 *@main   This is the source file that defines helper functions for the command-line
 *        shell program
 *
 *@author Shefin Stevenson
 *
 *@date   06-05-2017
 *
 */

#include "helper_functions.h" 
#include <stddef.h> 
#include <string.h> 

/* display shell prompt*/
void display_prompt(void)
{
	char *login_name = getenv("USER");
	printf("%s@shell>",login_name);
}

/*prompt user to enter a command*/
void display_user_message(void)
{
	printf("Enter a command:");
}

/* read user a command and return the command string 
 * This function reads an entire line from stream, storing the text (including the newline 
 * and a terminating null character) in a buffer and storing the buffer address in *line_ptr.
 */

char* read_user_command(void)
{
	char *line_ptr = NULL;
	size_t buf_size = 0;

	/* store the user command in line_ptr */ 
	getline(&line_ptr, &buf_size, stdin);
	
	return line_ptr;
}

/* parse command line and return commands 
 * This function takes the commands from the shell and uses space to tokenize them and returns 
 * the tokens  
 */
char** parse_command(char* cmd_line)
{
	/* white space is the delimiter */
	const char delimiters[] = " \n";

        char *token = NULL;
        size_t tok_buf_size = 256;
        int position = 0;

        char **tokens = malloc(tok_buf_size * sizeof(char*));

        do {
		/* get the first token in the command line */
                token = strtok (cmd_line, delimiters); 
        
		/* store tokens from the user command */
		if ( token != NULL) {
                       
		       	tokens[position++] = token;
                        cmd_line = NULL;
                }
                else    {
                        break;
                }

        }while (token != NULL);

	return tokens;
}

