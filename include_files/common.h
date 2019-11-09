#ifndef __COMMONCODE__
#define __COMMONCODE__

/*
Create a structure to hold the inputted characters 
(Float, Int, Operator, Bracket) from the file and store them in a struct
*/
typedef struct _CharacterType {
    int pointer;
    int type;
    char content[50];
} CharacterType;


CharacterType *newCharacterType();
void resetCharacterType(CharacterType *charType);
void resultToFile(FILE *outputFile, CharacterType *charType, char * keys[]);

#endif