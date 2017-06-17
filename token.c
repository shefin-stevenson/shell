#include <stdio.h> 
#include <string.h> 
#include <stddef.h> 
#include <stdlib.h> 


int main()
{

	const char delimiters[] = " ";
	const char string[] = "words separated by spaces -- and, punctuation!";
	char *token, *cp;
        char *line_ptr = NULL;
        size_t buf_size = 0;

	printf("Enter a command:");
        getline(&line_ptr, &buf_size, stdin);
	
	if (line_ptr != NULL){

	//cp = strdup (line_ptr);                /* Make writable copy.  */
	cp = line_ptr;

	} else {
		printf("command line is empty\n");
		return EXIT_FAILURE;
	}
	

	size_t buf_size2 = 256;
        int position = 0;	
	char **tokens = malloc(buf_size2 * sizeof(char*));

	int i =0;
	do {
	
		token = strtok (cp, delimiters);      /* token => "words" */
		if ( token != NULL) {
			printf("token[%d]: %s\n",i,token);
			tokens[position++] = token; 
			cp = NULL;
			i++;
		}
		else 	{
			break;
		}	
	
	}while (token != NULL);


	i=0;
	while (tokens[i] != NULL) {
		printf("TOKENS[%d]: %s\n",i,tokens[i]);
		i++;
	}		

	return 0; 
}
