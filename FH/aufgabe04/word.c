#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "word.h"
#include "errors.h"

/* Referenzaehler fuer die gespeicherten Worte */
int word_refs = 0;

/**
 * Kopiert die uebergebene Zeichenkette in einen neu reservierten
 * Speicherbereich. Der Speicherbereich wird durch word_copy
 * reserviert.
 *
 * @param str die zu kopierende Zeichenkette
 * @return Zeiger auf das neue Wort
 */

Word
word_copy(char *str) {
    char* ptr = str;
    char* copy = NULL;
    int str_size = 0;
    int idx = 0;

    while (*ptr++ != '\0')
        str_size++;

    copy = (char*) malloc((str_size+1)*sizeof(char));

    copy[str_size] = '\0';

    ptr = str;
    while (*ptr != '\0')
        copy[idx++] = *ptr++;

    word_refs++;

    return copy;
}

/**
 * Gibt den vom Wort belegten Speicherbereich wieder frei.
 *
 * @param w Wort.
 * @return NULL
 */
Word
word_delete(Word w) {
    free(w);
    word_refs--;
    return NULL;
}
