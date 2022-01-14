#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct config {
	char one;
	char zero;
};

void readConfig(struct config* config);
void wait(int delay);
int readBinary(FILE* fp, struct config config);

int main(int argc, char* argv[]) {
	FILE* pIn;
	char inputFile[] = "input.txt";
	FILE* pOut;
	char outputFile[] = "output.txt";
	
	int failure = 0;
	char c = '0';
	int i = 0;

	struct config config;
	config.zero = '0';
	config.one = '1';
	readConfig(&config);

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
	if (failure) {
		exit(1);
	}
	printf("Decoded text:\n\"");
	while (c != EOF) {
		c = readBinary(pIn, config);
		if (c != EOF) {
			i++;
			fprintf(pOut, "%c", c);
			printf("%c", c);
		}
	}
	printf("\"\n\n");

	printf("%d character(s) decoded.\n", i);

	fclose(pIn);
	fclose(pOut);
	wait(5);

	return 0;
}

int readBinary(FILE* fp, struct config config) {
	char c;
	int i;
	int j;
	int binArray[] = { 0,0,0,0,0,0,0,0 };
	int output = 0;
	for (i = 0; i < 8; i++) {
		c = fgetc(fp);
		if (!(isspace(c)) && c != EOF) {
			if (c == config.zero) {
				binArray[i] = 0;
			}
			if (c == config.one) {
				binArray[i] = 1;
			}
		}
		else if (isspace(c)){
			i--;
		}
	}
	for (i = 7, j = 1; i > 0; i--) {
		output = output + binArray[i] * j;
		j = j * 2;
	}

	if (c == EOF){
		output = EOF;
	}
	return output;
}

void readConfig(struct config* config) {
	FILE* pConfig;
	char configFile[] = "config.txt";
	pConfig = fopen(configFile, "r");
	if (pConfig == NULL) {
		printf("Failed to open %s for reading.\n", configFile);
		exit(1);
	}
	config->zero = fgetc(pConfig);
	config->one = fgetc(pConfig);
	fclose(pConfig);
}

void wait(int delay) {
	time_t t;
	time_t startTime;
	time_t currentTime;
	startTime = time(&t);
	currentTime = startTime;
	while (currentTime != (startTime + delay)) {
		currentTime = time(&t);
	}
}