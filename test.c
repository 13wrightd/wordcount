#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct word_t {
	char *word;
	int count;
	struct word_t *next;
};

int main(int argc, char *argv[]) {
    int i = 0;
    FILE *fp;
    fp = fopen(argv[1], "r");
    char *str;
    char c;
    int numChar = 0;
    struct word_t *head;
    struct word_t *curr;
    bool found = false;

    head = (struct word_t *)malloc(sizeof(struct word_t));
    curr = head;

    str = (char *)malloc(sizeof(char));
    bool badCharacter=0;

    if (fp) {
        while ((c=fgetc(fp))!=EOF){
            if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)){
                str[numChar] = tolower(c);
                numChar++;
                str = (char *)realloc(str, numChar*sizeof(char));
                badCharacter=false;
            }

            else if((c == 32 || c == 10) && !badCharacter){
                badCharacter=true;
                str[numChar]='\0';
                numChar = 0;
                
                while(!found){

                	if(curr->word == NULL){
                		curr->word = str;
                		curr->count++;
                		found = true;
                	}
                	
            		else if(strcmp(str, curr->word) < 0){
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

                    
                    else if(strcmp(str, curr->word) > 0){
                        if(curr->next == NULL){
                                curr->next = (struct word_t *)malloc(sizeof(struct word_t));
                                curr->next->word = str;
                                curr->next->count++;
                                found = true;
                        }
                        else{
                                curr = curr->next;
                        }
                    }
                	
                    else{
                        curr->count++;
                        found = true;
                    }
               	}

               	found = false;
               	curr = head;
            	str = (char *)malloc(sizeof(char));
        	}
        }
    }
    fclose(fp);
    
    while(curr->next != NULL){
            printf("%s, %d\n", curr->word, curr->count);
            curr = curr->next;
    }
    
    return 0;
			
}