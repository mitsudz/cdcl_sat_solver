/**
 * @file cnf.h
 * @brief Contains struct definitions and prototypes for CNF boolean expressions.
 *
 * @author Mittun Sudhahar
 */

#include <stdbool.h>

#pragma once

typedef struct {
  bool negate;
  uint8_t val;
} Literal;

typedef struct {
    size_t numLiterals;
    Literal* literals;
} Clause;

/* NCNF
 * Represents clause in conjunctive normal form.
 *
 * @param variables - Each variable is a uint8_t ranging from 1 to variables.
 * @param clauses - List of cnf clauses. Implicitly each clause
 *           is or'd together, and literals within the clauses are and'd together
 *           A clause ends with a Literal with false for negate and 0 for the variable.
 * @param numClauses - number of clauses
 */
typedef struct {
    uint8_t variables;
    Clause *clauses;
    size_t numClauses;
} NCNF;

NCNF init_cnf(uint8_t numVars);
void add_clause(NCNF* cnf, Clause clause);
void add_variable(NCNF* cnf);
void add_literal(Clause* clause, bool negate, uint8_t variable);
