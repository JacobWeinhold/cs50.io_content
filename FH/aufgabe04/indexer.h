#ifndef __INDEXER_H__
#define __INDEXER_H__
/**
 * Modul zur Indizierung von beliebigen Dateien als Liste von Worten mit ihren Vorkommen.
 *
 * @author Helga Karafiat
 */

#include <stdio.h>

#include "wordlist.h"
#include "errors.h"

/** Ein Index */
typedef WordList Index;

/**
 * Erzeugt zum Eingabestrom stream einen Index. Initial ist dazu ein Zeiger
 * auf einen leeren Index zu uebergeben. Nach Ablauf der Funktion zeigt
 * der Zeiger index auf den fertig erzeugten Index zu stream. 
 *
 * Im Stream werden Worte nach folgenden Regeln erkannt: Ein Wort 
 * ist eine mindestens einelementige Zeichenfolge, die lediglich aus Klein- 
 * und Grossbuchstaben (ASCII), also 'a' bis 'z' und ' A' bis 'Z', besteht. 
 * Zwei Worte werden durch eine mindestens einelementige Folge von Trennzeichen 
 * getrennt, wobei Trennzeichen alle Zeichen (bzw. Bytewerte) sind, die nicht
 * in Worten vorkommen koennen. Folgen von Trennzeichen koennen auch am Anfang
 * oder Ende des streams auftreten (muessen aber nicht). Zeilenumbrueche sind
 * Trennzeichen, die zugleich die Angabe zur Zeile, in der ein Wort vorkommt,
 * steuern. Als Zeilenumbruch wird ausschliesslich \n gewertet.
 *
 * Er werden lediglich Worte mit einer Mindestlaenge von min und einer 
 * Maximallaenge max in den Index aufgenommen. Worte, die kuerzer oder laenger
 * sind werden ohne Signalisierung eines Fehlers ueberlesen.
 *
 * @pre stream darf nicht NULL sein
 * @pre index ist ein Zeiger auf einen leeren Index
 * @pre min >= 1
 * @pre max >= min
 *
 * @param[in] stream der Dateistrom
 * @param[in/out] index Zeiger auf einen Index
 * @param[in] min kuerzeste zu indizierende Wortlaenge
 * @param[in] min laengste zu indizierende Wortlaenge
 *
 * @return ERR_NULL || ERR_READ_STREAM
 */
Errorcode index_make(FILE * stream, Index * index, unsigned long min, unsigned long max);

/**
 * Gibt den uebergebenen Index auf dem uebergebenen stream im CSV-Format aus.
 * Je Wort und Vorkommen des Wortes wird dazu eine Zeile erzeugt.
 *
 * Dabei besteht eine Zeile immer aus (ohne Leerzeichen):
 * Wort,Zeile,Position
 *
 * Die Sortierung der Worte und Wortvorkommen entspricht hierbei der Sortierung 
 * der entsprechenden Listen. D.h. z.B., dass die Zeilen zu den Vorkommen eines Wortes 
 * in einem Block nacheinander ausgegeben werden (entsprechend der Sortierung der Vorkommen).
 *
 * Als Zeilenumbruch wird \n verwendet. Nach jeder Zeile einschliesslich der letzten Zeile 
 * wird ein Zeilenumbruch ausgegeben. Daraus folgt, dass im Falle des leeren Index 
 * nichts ausgegeben wird.
 *
 * @pre stream darf nicht NULL sein
 *
 * @param[in] stream der Dateistream
 * @param[in] index  der Index
 *
 * @return ERR_NULL || ERR_WRITE_STREAM
 */
Errorcode index_printCSV(FILE * stream, Index index);

/**
 * Gibt den uebergebenen Index auf dem uebergebenen stream in einem fuer
 * Menschen gut lesbaren Format aus.
 *
 * @pre stream darf nicht NULL sein
 *
 * @param[in] stream der Dateistream
 * @param[in] index  der Index
 *
 * @return ERR_NULL || ERR_WRITE_STREAM
 */
Errorcode index_printPretty(FILE * stream, Index index);

/**
 * Loescht den index und gibt den durch ihn belegten
 * Speicher wieder frei.
 *
 * @param[in] index Index
 * @return leerer Index
 */
Index index_delete(Index index);

#endif
