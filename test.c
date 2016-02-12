#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
				printf("%s ", str);
				numChar = 0;
				free(str);
				str = (char *)malloc(sizeof(char));
			}
			
		}
	}


	
	// for (i = 0; i < argc; i++)
	// 	printf("\n%s", argv[i]);
	
	return 0;

}
