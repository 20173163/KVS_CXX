#include "kvs.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#define KEY_SIZE 16
#define VAL_SIZE 99

int main(int argc, char* argv[]) {
	if(argc!=4) {
		perror("Usage: ./test_static put.txt get.txt test_static.txt");
		exit(1);
	}

	open();	

	FILE* fp = fopen(argv[1], "r");
	if(fp != NULL) {
		while(1) {
			if(feof(fp)) break;
			else {
				char str[KEY_SIZE];
				char str2[VAL_SIZE];
				fscanf(fp, "%s %s\n", str, str2);
				int l = strlen(str2);
				char* strd = new char[l+1];
				strcpy(strd,str2);
				if(put(str,strd,l)!=0) {
					printf("put error");
					exit(1);
                                }
			}
                }
        }
        fclose(fp);

	fp = fopen(argv[2], "r");
	FILE* fp2 = fopen(argv[3], "w");
	if(fp != NULL) {
		while(1) {
			if(feof(fp)) break;
			else {
				char str[KEY_SIZE];
				char str2[VAL_SIZE];
				int k=0;
				int* l=&k;
				fscanf(fp, "%s\n", str);
				strcpy(str2, get(str, l));
				fprintf(fp2, "%s\n", str2);
			}
		}
	}
	fclose(fp2);
	fclose(fp);
	
	close();
}
