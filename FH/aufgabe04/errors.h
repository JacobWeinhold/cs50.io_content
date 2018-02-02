#ifndef __ERRORS_H__
#define __ERRORS_H__

/**
 * @file errors.h
 * Schnittstelle eines Moduls zur Fehlerbehandlung.
 *
 * Diese Datei darf nicht veraendert werden!
 *
 * @author Helga Karafiat
 */

/* ---------------------------*/
/* Deklaration von Datentypen */
/* ---------------------------*/

/**
 * Aufzaehlung von Fehlerfaellen.
 */
enum Errorcode
{
  /** kein Fehler. */
  ERR_NULL = 0,

  /** Es wurden falsche oder ungueltige Argumente eingegeben */
  ERR_WRONG_ARG,

  /** Das Lesen aus dem Stream ist fehlgeschlagen */
  ERR_READ_STREAM,

  /** Das Schreiben in den Stream ist fehlgeschlagen */
  ERR_WRITE_STREAM,

  /** Speicherleck **/
  ERR_MEMORY_LEAK,

  /** Fehler beim Allozieren von Speicher */
  ERR_OUT_OF_MEMORY
};

/**
 * Aufzaehlungstyp fuer Fehlerfaelle.
 */
typedef enum Errorcode Errorcode;


/* ----------------------------------------------------------------*/
/* --- Prototypen fuer Funktionen der Schnittstelle des Moduls --- */
/* ----------------------------------------------------------------*/

/**
 * Funktion zur Behandlung von Fehlerfaellen.
 *
 * In allen Fehlerfaellen wird lediglich eine aussagekraeftige Fehlermeldung
 * auf stderr ausgegeben.
 *
 * @param error Fehlercode.
 */
void err_printError (Errorcode error);

#endif
