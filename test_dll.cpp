#include "kvs.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <dlfcn.h>
#define KEY_SIZE 16
#define VAL_SIZE 99

int main(int argc, char* argv[]) {
        if(argc!=4) {
                perror("Usage: ./test_static put.txt get.txt test_static.txt");
                exit(1);
        }

	void *handle;
	int (*put)(char*, char*, int);
	char* (*get)(char*, int*);
	int (*open)();
	void (*close)();
	char *error;

	handle = dlopen("./libdll.so", RTLD_LAZY);
	if(!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	put = (int (*)(char*, char*, int))dlsym(handle, "put");
	get = (char* (*)(char*, int*))dlsym(handle, "get");
	open = (int (*)())dlsym(handle, "open");
	close = (void (*)())dlsym(handle, "close");
	if((error=dlerror()) != NULL) {
		fprintf(stderr, "%s\n", error);
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
                        }
                }
        }
        fclose(fp2);
        fclose(fp);

	close();

	if(dlclose(handle) < 0) {
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	return 0;
}
