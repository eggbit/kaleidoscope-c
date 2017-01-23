#include "lexer.h"

enum Token {
    tok_eof,

    // commands
    tok_def,
    tok_extern,

    // primary
    tok_id,
    tok_num
};

static double num_value;
static char   id_value[255];

int
get_tok() {
    static char last_char = ' ';

    // Ignore all whitespace
    while(isspace(last_char)) {
        last_char = getchar();
    }

    // [a-zA-Z]
    if(isalpha(last_char)) {
        strncat(id_value, &last_char, 1);

        while(isalnum(last_char = getchar())) {
            strncat(id_value, &last_char, 1);
        }

        if(!strcmp(id_value, "def")) {
            return tok_def;
        }

        if(!strcmp(id_value, "extern")) {
            return tok_extern;
        }

        return tok_id;
    }

    // [0-9]
    if(isdigit(last_char) || last_char == '.') {
        char num_str[24];

        while(isdigit(last_char) || last_char == '.') {
            strncat(num_str, &last_char, 1);
            last_char = getchar();
        }

        num_value = strtod(num_str, 0);
        // printf("Number: %.4f\n", num_value);
        return tok_num;
    }

    // Comments
    if(last_char == '#') {
        while(last_char != EOF && last_char != '\n' && last_char != '\r') {
            last_char = getchar();
        }

        if(last_char != EOF) {
            return get_tok();
        }
    }

    // EOF
    if(last_char == EOF) {
        return tok_eof;
    }

    // Default
    int current_char = last_char;
    last_char = getchar();

    return current_char;
}
