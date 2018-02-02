#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "wordlist.h"
#include "errors.h"

/* Referenzaehler fuer die gespeicherten Wortlistenelemente */
int wordlist_refs = 0;

WordList 
wordlist_empty() {
}

int 
wordlist_isEmpty(WordList l) {
}

Word 
wordlist_head_word(WordList l) {
}

OccList 
wordlist_head_occs(WordList l) {
}

WordList 
wordlist_tail(WordList l) {
}

WordList 
wordlist_cons(Word word, OccList occs, WordList l) {
}

WordList 
wordlist_insert(WordList l, Word word, Occurrence occ) {
}

WordList wordlist_delete(WordList l) {
}


