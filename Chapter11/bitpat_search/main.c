//includes
#include <stdio.h>
#include <stdbool.h>

//prototypes
int8_t bitpat_search(unsigned int source, unsigned int pattern, u_int8_t n);
void print_binary(unsigned int word, bool show_trailing_zeroes);

int main() {

    printf("Printing 30 in binary:\n");
    print_binary(30, true);
    print_binary(30, false);

    int8_t answer = bitpat_search(30, 30,8);
    printf("Answer should be 24. Answer: %d", answer);

    return 0;
}

void print_binary(unsigned int word, bool show_trailing_zeroes) {
    bool start_printing_bits = show_trailing_zeroes;
    u_int8_t num_bits = (sizeof(word) * 8); //this will be different depending on which machine the program is running
    u_int8_t counter = 0;

    for(int8_t i = (num_bits - 1); i >= 0; i--) {
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

int8_t bitpat_search(unsigned int source, unsigned int pattern, u_int8_t n) {
    u_int8_t num_bits_source = (sizeof(source) * 8);
    u_int8_t pattern_bits [n];
    int8_t answer = -1;

    //pattern extraction and saved into an array
    for(int8_t i  = 0; i < n; i ++) {
        //from LSB to MSB
        u_int8_t current_bit = (pattern >> i) & 1;
        //save on array as MSB to LSB
        pattern_bits[(n-1)-i] = current_bit;
    }

    for (int8_t i = (num_bits_source - 1); i >= 0; i --) {

        if(answer != -1) {
            return answer;
        }

        u_int8_t current_bit_source = (source >> i) & 1;

        for(int8_t j = 0; j < n; j++) {
            u_int8_t current_bit_pattern = pattern_bits[j];
            if(j == 0 && (current_bit_source == current_bit_pattern)){
                answer = (num_bits_source - i - 1);
            }

            if (current_bit_source != current_bit_pattern) {
                answer = -1;
                break;
            }
            current_bit_source = (source >> (i - j - 1)) & 1;
        }
    }

    return answer;
}

