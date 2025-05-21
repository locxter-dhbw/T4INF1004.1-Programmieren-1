#include "bitmap.h"

// Aufrufen über probeklausur text.txt output.bmp
int main(int argc, char **argv) {
	// Kommandozeilenargumente einlesen
	if (argc < 3) {
		printf("Zu wenig Argumente, bitte Input und Output-Datei angeben.\n");
		return 1;
	}
	char *inputFilename = argv[1];
	char *outputFilename = argv[2];
	printf("Input: %s\n", inputFilename);
	printf("Output: %s\n", outputFilename);
	// Daten aus Textdatei einlesen
	char *inputData = readInput(inputFilename);
	long inputSize = getInputSize(inputFilename);
	char *outputData = generateBmp(inputData, inputSize);
	long outputWidth = getOutputWidth(inputSize);
	long outputSize = getOutputSize(inputSize);
	writeBmp(outputFilename, outputData, outputSize, outputWidth);
	// Speicher wieder freigeben
	free(inputData);
	free(outputData);
	printf("Konvertierung erfolgreich, bitte %s angucken.\n", outputFilename);

	printf("01:%f|\n", 123.456);
	printf("02:%e|\n", 12.34);
	printf("03:%6.2f|\n", 123.4);
	printf("04:%9.4f|\n", 123.4);
	printf("05:%6.2f|\n", -1.2);
	printf("06:%06.2f|\n", -.1234);
	printf("07:% 6.2f|\n", 1234.);
	printf("08:%-9.2f|\n", 1234.);
	printf("09:%03.2e|\n", -12.34);
	printf("10:%9.1E|\n", 12.34);

	return 0;
}
