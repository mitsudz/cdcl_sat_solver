/**
 * @file cnf.c
 * @brief intended for instantiations and basic functionality for NCNF forms.
 * @author Mittun Sudhahar
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "cnf.h"

#define OVERFLOW_ERROR 13 // Move this to another file later

NCNF init_cnf(uint8_t numVars) {
    NCNF cnf = {.variables = numVars};
    cnf.clauses = calloc(1, sizeof(Clause));
    cnf.clauses->literals = malloc(sizeof(Literal));
    return cnf;
}

void add_clause(NCNF* cnf, Clause clause) {
    cnf->clauses[cnf->numClauses++] = clause;
    cnf->clauses = realloc(cnf->clauses, sizeof(Clause) * (cnf->numClauses + 1));
}

void add_variable(NCNF* cnf) {
    cnf->variables++;
    if (!cnf->variables) {
        fprintf(stderr, "Error - added too many variables\n");
        exit(OVERFLOW_ERROR);
    }
}

void add_literal(Clause* clause, bool negate, uint8_t variable) {
    clause->literals[clause->numLiterals++] = (Literal){.negate = negate, .val = variable};
    clause->literals = realloc(clause->literals, sizeof(Literal) * (clause->numLiterals +1));
}
