#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

//Node structure for linked list
struct word_t {
	char *word;
	int count;
	struct word_t *next;
};

int main(int argc, char *argv[]) {
	if(argc != 4){ //The user has to run the program with 4 arguments
		printf("Invalid number of arguments. Please try running again with proper number of arguments.\narg1(input_file) arg2(output_file) arg3(output_file)\n");
	}
	else{

		clock_t begin, end;			//For recording execution time
		double totTime;				//to store the execution tme

		begin = clock();			//begin timing

	    FILE *fp;					//for the input file
	    fp = fopen(argv[1], "r");	//open the input file
	    char *str;					
	    char c;
	    int numChar = 0;			//Number of characters in a string
	    struct word_t *head;		//Linked link
	    struct word_t *curr;		//iterator
	    bool found = false;			//for searching linked list

	    head = (struct word_t *)malloc(sizeof(struct word_t));	//allocate space for the head
	    curr = head;											//start at the begining of the list

	    str = (char *)malloc(sizeof(char));						
	    bool badCharacter=false;								//for handling double \n

	    if (fp) {												//check if the file is open
	        while ((c=fgetc(fp))!=EOF){							//go through to the end of the file
	            if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)){	//check if the char is alphanumeric
	                str[numChar] = tolower(c);												//make it lowercase
	                numChar++;																//incerment numChar
	                str = (char *)realloc(str, (numChar+1)*sizeof(char));					//realocate for the next character
	                badCharacter=false;														//not a space or \n
	            }

	            else if((c == 32 || c == 10) && !badCharacter){								//if it is a space or \n 

	                badCharacter=true;														//handle for case of second \n
	                str[numChar]='\0';														//add null character to end the string
	                numChar = 0;															//start count for new word
	                
	                while(!found){															//go until the word is in the list

	                	if(curr->word == NULL){												//if the current is null add the word to the list
	                		curr->word = str;
	                		curr->count++;
	                		found = true;
	                	}
	                	
	            		else if(strcmp(str, curr->word) < 0){								//if str comes before curr->word insert it befor
	                        struct word_t *newNode;
	                        newNode = (struct word_t *)malloc(sizeof(struct word_t));
	                        newNode->word = curr->word;
	                        newNode->count = curr->count;

	                        curr->word = str;
	                        curr->count = 1;

	                        newNode->next = curr->next;
	                        curr->next = newNode;

	                        found = true;
	                    }

	                    
	                    else if(strcmp(str, curr->word) > 0){		//if the word comes after...
	                        if(curr->next == NULL){					//if null then creat new node and insert at the end of the list
	                                curr->next = (struct word_t *)malloc(sizeof(struct word_t));
	                                curr->next->word = str;
	                                curr->next->count++;
	                                found = true;
	                        }
	                        else{									//else move forward in the list
	                                curr = curr->next;
	                        }
	                    }

                    }
	                	
	                    else{										//if str == curr->word
	                        curr->count++;
	                        found = true;
	                    }
	               	}
	               	found = false;									//reset found
	               	curr = head;									//reset iterator
	            	str = (char *)malloc(sizeof(char));				//reset str
	            	
	        	}
	        }

	    }
	    fclose(fp);					//close the input file
	    
	    FILE *fp2;					//for output of words to file
	    fp2 = fopen(argv[2], "w");	//open in writing mode


	   	while(curr != NULL){		//go to the end of the list
	            fprintf(fp2, "%s, %d\n", curr->word, curr->count);	//print word and count to the file
	      	    curr = curr->next;									//incerment the iterator
	    }
	    fclose(fp2);												//close the file

	    end = clock();												//end the execution timer
	    totTime = (double)(end - begin)/CLOCKS_PER_SEC;				//calculate the execution time

	    FILE *fp3;													//file to store the runtime
	    fp3 = fopen(argv[3], "a");									//open in apend mode
	    
	    fprintf(fp3, "Total Time: %f\n", totTime);					//print the runtime to the file
	    fclose(fp3);												//close the file
	}
	return 0;
}