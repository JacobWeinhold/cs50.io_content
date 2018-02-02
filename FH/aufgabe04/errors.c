/**
 * @file errors.c 
 * Implementierung eines Moduls zur Fehlerbehandlung.
 *
 * Diese Datei darf nicht veraendert werden!
 *
 * @author Helga Karafiat 
 */

/* -----------------------------------------------------*/
/* Einbinden der Schnittstellen von System-Bibliotheken */
/* -----------------------------------------------------*/
#include <stdio.h>


/* ----------------------------------------------------*/
/* Einbinden der Schnittstellen von eigenen Modulen    */
/* ----------------------------------------------------*/
#include "errors.h"

/* ----------------------------------------------------*/
/* ---- Implementierung der Funktionen des Moduls ---- */
/* ----------------------------------------------------*/

void
err_printError (Errorcode error) {

  switch (error) {
    case ERR_NULL:
      fprintf (stderr, "Error! No Error - should not see me!\n");
      break;
    case ERR_WRONG_ARG:
      fprintf (stderr, "Syntax error! Wrong argument!\n");
      break;
    case ERR_READ_STREAM:
      fprintf (stderr, "Error! Could not read from stream!\n");
      break;
    case ERR_WRITE_STREAM:
      fprintf (stderr, "Error! Could not write to stream!\n");
      break; 
    case ERR_MEMORY_LEAK:
      fprintf (stderr, "Error! Memory Leak :( !\n");
      break; 
    case ERR_OUT_OF_MEMORY:
      fprintf (stderr, "PANIC! Out of memory!\n");
      break; 
    default: 
      fprintf (stderr, "Error! Unknown Errorcode - should not happen!\n");
      break;
  }

}
