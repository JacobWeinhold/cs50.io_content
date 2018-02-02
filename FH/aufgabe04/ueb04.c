#include <stdio.h>
#include <limits.h>
#include <assert.h>

#include "errors.h"
#include "indexer.h"

extern int occlist_refs;
extern int wordlist_refs;
extern int word_refs;


/**
 * Gibt die Hilfe auf dem uebergebenen Stream aus.
 *
 * @param[in] stream Dateistrom
 */
static void printUsage ( FILE * stream );

/**
 * Prueft ob die angegebenen Grenzen gueltig sind:
 * - min muss mindestens eins sein
 * - max groesser gleich min
 *
 * @param[in] min Untergrenze
 * @param[in] max Obergrenze
 *
 * @return ERR_NULL wenn alles ok ist, oder im Fehlerfall ERR_WRONG_ARG
 */
static Errorcode checkBoundaries ( unsigned long min, unsigned long max );

/**
 * Liest einen einzelnen Wert aus argv an der Stelle index als
 * unsigned long Wert in value ein.
 *
 * @param[in] argv Programmargumente
 * @param[in] index Position
 * @value[in/out] value gelesener Wert, kann im Fehlerfal ungueltig sein
 * @return true wenn alles ok ist, im Fehlerfall false
 */
static int readBoundary ( char *argv[], int index, unsigned long *value );


static void
printUsage (FILE * stream)
{
  assert (stream != NULL);

  fprintf (stream, "Usage:\n");
  fprintf (stream, "       ueb04 [PARAM...]\n");
  fprintf (stream, "       \n");
  fprintf (stream, "       where PARAM is any of the following:\n");
  fprintf (stream, "       -h      prints this information to stderr\n");
  fprintf (stream, "       -w LONG Sets the minimum word length (LONG must be 1 or larger),\n");
  fprintf (stream, "       default is 1\n");
  fprintf (stream, "       -W LONG Sets the maxmimum word length (LONG must be 1 or larger)\n");
  fprintf (stream, "       default is ULONG_MAX\n");
  fprintf (stream, "       -H      prints a human readable format instead of CSV\n");
  fprintf (stream, "       -m      activates memory management\n");
  fprintf (stream, "       \n");
  fprintf (stream, "       reads a stream from stdin and generates an index of found words. \n");
  fprintf (stream, "       The output is written to stdout - either as CSV or in human readable format.\n");
}

static Errorcode
checkBoundaries ( unsigned long min, unsigned long max ) {

  return ( (min >= 1) && ( min <= max) ) ? ERR_NULL : ERR_WRONG_ARG;
}


static int
readBoundary ( char *argv[], int index, unsigned long *value ) {

  char
      check = '\0'
    ;

  return (sscanf(argv[index], "%lu%c", value, &check) == 1);
}

int
main ( int argc, char * argv[] ) {

  Errorcode
      error = ERR_NULL
    ;

  int
      i                 = 1
    , help_wanted       = 0
    , human_readable    = 0
    , memory_management = 0
    ;

  unsigned long
      min_wordlength    = 1
    , max_wordlength    = ULONG_MAX
    ;

  char
      opchar = '\0'
    , check  = '\0'
    ;

  Index
      index  = wordlist_empty();
    ;

  while (i < argc && ! error) {

    if ( (sscanf (argv[i], "-%c%c", &opchar, &check) == 1) ) {

      switch (opchar) {
        case 'w':
            if ( ! (( i < argc-1 ) && readBoundary( argv, ++i, &min_wordlength)) ) {
              error = ERR_WRONG_ARG;
            }
          break;
        case 'W':
            if ( ! (( i < argc-1 ) && readBoundary( argv, ++i, &max_wordlength)) ) {
              error = ERR_WRONG_ARG;
            }
          break;
        case 'h':
            help_wanted = 1;
          break;
        case 'H':
            human_readable = 1;
          break;
        case 'm':
            memory_management = 1;
          break;
        default:
          error = ERR_WRONG_ARG;
          break;
      }
    } else {
      error = ERR_WRONG_ARG;
    }
    i++;
  }

  if (! error ) {
    error = checkBoundaries( min_wordlength, max_wordlength );
  }

  if (! error ) {

    error = index_make( stdin, &index , min_wordlength, max_wordlength );

    if ( human_readable) {
      error = index_printPretty( stdout, index );
    } else {
      error = index_printCSV( stdout, index );
    }

    index = index_delete( index );
  }

  if ( memory_management ) {

    if (word_refs != 0 || occlist_refs != 0 || wordlist_refs != 0 ) {
      error = ERR_MEMORY_LEAK;
    }

    fprintf(stderr, "WordRefs: %d\n", word_refs);
    fprintf(stderr, "OccListRefs: %d\n", occlist_refs);
    fprintf(stderr, "WordListRefs: %d\n", wordlist_refs);

  }

  if ( ! error && help_wanted) {
      printUsage( stderr );
  }

  if ( error ) {
    err_printError( error ) ;
    printUsage( stderr );
  }

  return error;
}
