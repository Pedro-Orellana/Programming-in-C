//includes
#include <stdio.h>
#include <stdbool.h>

//prototypes
u_int8_t bitpat_search(unsigned int source, unsigned int pattern, u_int8_t n);
void print_binary(unsigned int word, bool show_trailing_zeroes);

int main() {

    printf("Printing 30 in binary:\n");
    print_binary(30, true);
    print_binary(30, false);

    bitpat_search(30, 30,8);

    return 0;
}

void print_binary(unsigned int word, bool show_trailing_zeroes) {
    bool start_printing_bits = show_trailing_zeroes;
    u_int8_t num_bits = (sizeof(word) * 8); //this will be different depending on which machine the program is running
    u_int8_t counter = 0;

    for(int8_t i = (num_bits - 1); i-- >= 0;) {
        u_int8_t current_bit = (word >> i) & 1;

        if(counter  == 4) {
            printf(" ");
            counter = 0;
        }

        if(start_printing_bits && show_trailing_zeroes) {
            printf("%d", current_bit);
            counter++;
        }

        if(current_bit && !start_printing_bits) {
            start_printing_bits = true;
        }

        if(start_printing_bits && !show_trailing_zeroes) {
            printf("%d", current_bit);
        }
    }

    printf("\n");
}

u_int8_t bitpat_search(unsigned int source, unsigned int pattern, u_int8_t n) {
    u_int8_t pattern_bits [n];

    //pattern extraction and saved into an array
    for(int8_t i  = 0; i < n; i ++) {
        u_int8_t current_bit = (pattern >> i) & 1;
        pattern_bits[i] = current_bit;
    }

    //testing
    for(int8_t i = 0; i < n; i ++) {
        printf("%d", pattern_bits[i]);
    }
    printf("\n");

    return 0;
}

