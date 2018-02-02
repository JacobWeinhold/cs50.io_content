#include <stdlib.h>
#include <stdio.h>

#include "indexer.h"


/**
 * Liest aus dem uebergebenen Stream und ueberliest dabei alle Zeichen ausser
 * denen, die zu einem Wort (a-z,A-Z) gehoeren. Wird hierbei ein zu einem Wort
 * gehoeriges Zeichen z gefunden, so wird das Ueberlesen beendet und das zuletzt
 * gefundene Zeichen z wieder zurueck in den Stream geschrieben.
 * Zeilenumbrueche werden zwar auch ueberlesen, aber gleichzeitig wird
 * die Anzahl der ueberlesenen Zeilenumbrueche zurueckgegeben.
 *
 * Die Funktion darf nicht fuer einen Strom aufgerufen werden, der bereits das
 * Dateiende ueberschritten hat.
 *
 * @pre stream != NULL
 * @pre ! feof(stream)
 * @pre error != NULL
 *
 * @param[in/out] *stream Zeiger auf den Eingabestrom
 * @param[out]    *error  Zeiger auf einen Fehlercode
 * @return Anzahl der ueberlesenen Zeilenumbrueche
 */
static int
skip(FILE *stream, Errorcode *error);

/**
 * Liest aus dem uebergebenen Stream ein einzelnes Wort (a-z,A-Z) in einen
 * Puffer ein. Der Puffer nebst seiner Groesse bei Aufruf von readWord wird vom
 * Aufrufer per Parameter buffer und bufsize uebergeben. Der Puffer darf die
 * Groesse 0 haben, in diesem Fall muss *buffer dem NULL-Zeiger entsprechen.
 * Sofern der Puffer nicht ausreichend gross fuer das einzulesende Wort ist,
 * wird er von readWord geeignet vergroessert. Die neue Groesse des Puffers
 * (die groesser als fuer das Wort erforderlich ausfallen darf) und der
 * moeglicherweise neue Anfangszeiger des Puffers wird dem Aufrufer ueber die
 * Parameter buffer und bufsize zurueckgemeldet.
 *
 * Die Funktion readWord erzeugt im Puffer ein leeres Wort, wenn sie im Strom
 * unmittelbar auf ein Trennzeichen trifft.
 *
 * Die Funktion darf nicht fuer einen Strom aufgerufen werden, der bereits das
 * Dateiende ueberschritten hat.
 *
 * Wird beim Einlesen ein Trennzeichen t gefunden, so wird das Einlesen beendet und
 * das zuletzt gefundene Zeichen t wieder zurueck in den Stream geschrieben.
 *
 * @pre stream != NULL
 * @pre ! feof(stream)
 * @pre buffer != NULL
 * @pre bufsize != NULL
 * @pre error != NULL
 * @pre (*buffer != NULL) == (*bufsize > 0)
 *
 * @param[in/out] *stream Zeiger auf den Eingabestrom
 * @param[out]    *error Zeiger auf einen Fehlercode
 * @param[in/out] **buffer Zeiger auf einen Pufferanfangszeiger
 * @param[in/out] *bufsize Zeiger auf die Groesse des Puffers buffer
 * @return Laenge des in buffer eingelesenen Wortes
 */
static int
readWord(FILE *stream, Errorcode *error, char **buffer, unsigned int *bufsize);


static int
skip(FILE *stream, Errorcode *error) {
}


static int
readWord(FILE *stream, Errorcode *error, char **buffer, unsigned int *bufsize) {
}


Errorcode
index_make(FILE *stream, Index *index, unsigned long min, unsigned long max) {
  Errorcode
      error = ERR_NULL
    ;
  return error;
}

Errorcode
index_printCSV(FILE * stream, Index index) {
  Errorcode
      error = ERR_NULL
    ;

  return error;
}

Errorcode
index_printPretty(FILE * stream, Index index) {
}

Index
index_delete(Index index) {
}

