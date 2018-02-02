#ifndef __WORD_H__
#define __WORD_H__
/**
 * Ein Wort.
 *
 * @author Helga Karafiat
 *
 */

/**
 * Typedefinition fuer ein Wort.
 */
typedef char * Word;

/**
 * Kopiert die uebergebene Zeichenkette in einen neu reservierten
 * Speicherbereich. Der Speicherbereich wird durch word_copy 
 * reserviert.
 *
 * @param str die zu kopierende Zeichenkette
 * @return Zeiger auf das neue Wort
 */
Word word_copy(char *str);

/**
 * Gibt den vom Wort belegten Speicherbereich wieder frei.
 *
 * @param w Wort.
 * @return NULL
 */
Word word_delete(Word w);

#endif
