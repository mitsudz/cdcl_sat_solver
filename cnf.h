/**
 * @file cnf.c
 * @brief Contains struct definitions for N-CNF and 3-CNF boolean expressions.
 *
 * @author Mittun Sudhahar
 */

#pragma once

#define CNF_FIELDS                                                             \
  uint8_t variables;                                                           \
  Literal **clauses;

typedef struct Literal {
  bool negate;
  uint8_t val;
} Literal;

typedef struct NCNF {
  CNF_FIELDS
} NCNF;

typedef struct 3CNF { CNF_FIELDS }
3CNF;
