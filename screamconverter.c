#include <stdio.h>
#include <stdlib.h>

struct config {
	int scream;
	char one;
	char zero;
};

void toBinary(int input, int* arr);
void readConfig(struct config* config);

int main(int argc, char* argv[]) {
	FILE* pIn;
	char inputFile[] = "input.txt";
	FILE* pOut;
	char outputFile[] = "output.txt";
	int failure = 0;
	int binArray[] = { 0,0,0,0,0,0,0,0 };
	char screamArray[] = "aaaaaaaa";
	int i;
	int j;
	char c = '0';
	struct config config;
	config.scream = 0;
	config.zero = '0';
	config.one = '1';

	pIn = fopen(inputFile, "r");
	if (pIn == NULL) {
		printf("Failed to open %s for reading.\n", inputFile);
		failure = 1;
	}
	pOut = fopen(outputFile, "w");
	if (pOut == NULL) {
		printf("Failed to open %s for reading.\n", outputFile);
		failure = 1;
	}

	readConfig(&config);

	if (failure) {
		exit(1);
	}
	
	for (i = 0; c != EOF; i++) {
		c = fgetc(pIn);
		printf("%c", c);
		if (/*c != '\n' && c != ' ' && */c != EOF) {
			toBinary((int)c, binArray);
			if (config.scream) {
				for (j = 0; j < 8; j++) {
					if (binArray[j] == 0) {
						screamArray[j] = config.zero;
					}
					if (binArray[j] == 1) {
						screamArray[j] = config.one;
					}
				}
				for (j = 0; j < 8; j++) {
					fprintf(pOut, "%c", screamArray[j]);
				}
			}
			else {
				for (j = 0; j < 8; j++) {
					fprintf(pOut, "%d", binArray[j]);
				}
			}
			fprintf(pOut, " ");
		}
		if (c == '\n') {
			fprintf(pOut, "\n");
		}
		if (c == ' ') {
			fprintf(pOut, " ");
		}
	}
	if (c == EOF) {
		i--;
	}
	printf("\n\n%d character(s) converted.", i);

	fclose(pIn);
	fclose(pOut);
	return 0;
}

void toBinary(int input, int* arr) {
	int n;
	int i = 7;
	int j;
	//this loop resets the array before entering anything
	for (j = 0; j < 8; j++) {
		arr[j] = 0;
	}
	do {
		n = input % 2;
		input = input / 2;
		arr[i] = n;
		i--;
	} while (input != 0);
}


void readConfig(struct config* config) {
	FILE* pConfig;
	char configFile[] = "config.txt";
	char scream;
	pConfig = fopen(configFile, "r");
	if (pConfig == NULL) {
		printf("Failed to open %s for reading.\n", configFile);
		exit(1);
	}
	scream = fgetc(pConfig);
	if (scream == '0') {
		config->scream = 0;
	}
	else {
		config->scream = 1;
	}
	config->zero = fgetc(pConfig);
	config->one = fgetc(pConfig);
	fclose(pConfig);
}
