/**********************************************
 * parse.c
 * 
 * Copyright: Björn Skoglund
 *
 **********************************************/

typedef struct _error_t {
  int position;
  char* description;
  struct _error_t* next;
} error_t;

void init_parser(op_t* program, int max_size);

void parse_char(char);

// returns program size
int check_program();

void drop_errors(error_t* errors);
