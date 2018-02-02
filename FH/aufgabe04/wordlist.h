#ifndef __WORDLIST_H__
#define __WORDLIST_H__
/**
 * Liste von Worten und ihren Vorkommen.
 *
 * @author Helga Karafiat
 *
 */

#include "word.h"
#include "occlist.h"


/* TODO Typdefinition Liste */

/**
 * Erzeugt eine leere Liste.
 * Da eine Liste nur ein Zeiger auf ein Element ist, ist die leere Liste
 * der Nullzeiger.
 *
 * @return Leere Liste
 */
WordList wordlist_empty();

/**
 * Prueft ob die Liste leer ist.
 *
 * @param[in] l Zu pruefende Liste
 * @return True, wenn die Liste leer ist, sonst false
 */
int wordlist_isEmpty(WordList l);

/**
 * Liefert das Wort am Kopf der Liste.
 *
 * @pre Die Liste darf nicht leer sein.
 *
 * @param[in] l Liste
 * @return Wort des ersten Elements
 */
Word wordlist_head_word(WordList l);

/**
 * Liefert die Vorkommensliste am Kopf der Wortliste.
 *
 * @pre Die Liste darf nicht leer sein.
 *
 * @param[in] l Liste
 * @return Liste von Vorkommen
 */
OccList wordlist_head_occs(WordList l);

/**
 * Liefert die Liste ohne das Kopf-Element.
 *
 * @pre Die Liste darf nicht leer sein.
 *
 * @param[in] l Liste
 * @return Der Rest
 */
WordList wordlist_tail(WordList l);

/**
 * Fuegt das Element (Wort & Vorkommen) vorne an der Liste an und
 * gibt einen Zeiger auf den neuen Listenanfang zurueck.
 *
 * Das Wort bzw. die Vorkommensliste werden nicht kopiert.
 * Fuer die spaetere Speicherfreigabe des Wortes und der 
 * Vorkommensliste ist die Wortliste verantwortlich.
 *
 * @param[in] word das Wort
 * @param[in] occs Die Liste mit den Vorkommen des Wortes
 * @param[in] l Wortliste
 * @return veraenderte Liste
 */
WordList wordlist_cons(Word word, OccList occs, WordList l);

/**
 * Fuegt das Vorkommen eines Wortes in die Liste ein. Falls das Wort
 * noch nicht vorhanden ist, wird das Wort aufsteigend sortiert, 
 * entsprechend des Ergebnisses von strcmp, mit seinem Vorkommen 
 * in die Liste eingefuegt.
 * Sofern das Wort schon enthalten ist, wird das Vorkommen entsprechend
 * der Sortierung von occlist_insert in die Vorkommensliste des bereits
 * vorhandenen Wortes eingefuegt.
 * Die Funktion gibt den Zeiger auf die veraenderte Liste zurueck. 
 *
 * Das Wort wird nicht kopiert.
 * Fuer die spaetere Speicherfreigabe des Wortes die Wortliste 
 * verantwortlich.
 *
 * @param[in] l Liste
 * @param[in] w das Wort
 * @param[in] occ Vorkommen des Wortes
 * @return veraenderte Liste
 */
WordList wordlist_insert(WordList l, Word word, Occurrence occ);

/**
 * Loescht die gesamte Liste und gibt ihren belegten
 * Speicher wieder frei.
 *
 * @param[in] l Liste
 * @return leere Liste
 */
WordList wordlist_delete(WordList l);


#endif
