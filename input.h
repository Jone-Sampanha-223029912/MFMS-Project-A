#ifndef INPUT_H
#define INPUT_H

int readInt(const char *prompt, int minimum, int maximum);

double readNonNegativeDouble(const char *prompt);

void readText(
    const char *prompt,
    char *buffer,
    int size
);

#endif