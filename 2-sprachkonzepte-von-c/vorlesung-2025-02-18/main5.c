#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main5(int argc, char **argv) {
    fprintf(stdout, "Hallo, du %der\n", 31);
    // Datei schreiben
    FILE *file = fopen("file.txt", "w");
    fprintf(file, "Hallo, du %der\n", 31);
    fprintf(file, "Richtig geiler Tag heute oder?\n");
    fclose(file);
    // Datei Zeichen für Zeichen lesen
    file = fopen("file.txt", "r");
    char c;
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }
    fclose(file);
    // Datei zeilenweise lesen
    file = fopen("file.txt", "r");
    char line[1024] = {0};
    while (fgets(line, sizeof(line) / sizeof(char), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
    // Datei ganz lesen (maximal 1024 Zeichen)
    file = fopen("file.txt", "r");
    char line2[1024] = {0};
    fread(line2, sizeof(char), sizeof(line2) / sizeof(char), file);
    printf("%s", line2);
    fclose(file);
    // Oder ganze Datei fancy und korrekt (Grüße ChatGPT)
    file = fopen("file.txt", "r");  // Open file in binary read mode
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }
    // Seek to the end of the file to get the size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);  // Get the file size
    rewind(file);  // Go back to the beginning of the file
    // Allocate memory to store the entire file contents
    char *buffer = malloc(fileSize);
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }
    // Initialize memory to 0
    memset(buffer, '\0', fileSize);
    // Read the entire file into the buffer
    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Failed to read the entire file");
        free(buffer);
        fclose(file);
        return 1;
    }
    // Optionally, print the contents
    printf("%s\n", buffer);
    // Clean up
    free(buffer);
    fclose(file);
    return 0;
}
