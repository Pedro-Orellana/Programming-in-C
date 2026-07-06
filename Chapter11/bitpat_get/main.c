//includes
#include <stdio.h>

//prototypes
void print_number(unsigned int word);
int bitpat_get(unsigned int source, u_int8_t starting_bit, u_int8_t bit_count);

int main() {
    print_number(30);
    int answer = bitpat_get(30, 29, 4);
    if(answer > 0) {
        print_number(answer);
    } else {
        printf("Could not get the specified bit pattern\n");
    }

    answer = bitpat_get(30, 29, 2);
      if(answer > 0) {
        print_number(answer);
    } else {
        printf("Could not get the specified bit pattern\n");
    }
    
    return 0;
}


void print_number(unsigned int word) {
    u_int8_t num_bits_word = sizeof(word) * 8;
    u_int8_t bit_counter = 0;

    printf("Number in decimal: %d\n", word);
    printf("Number in hex: 0x%.2X\n", word);

    //print binary
    printf("Number in binary: ");
    for(int8_t i = (num_bits_word - 1); i >= 0; i--) {
        u_int8_t current_bit = (word >> i) & 1U;

        if(bit_counter == 4) {
            printf(" ");
            bit_counter = 0;
        }
        printf("%d", current_bit);
        bit_counter++;
    }
    printf("\n");

}
int bitpat_get(unsigned int source, u_int8_t starting_bit, u_int8_t bit_count) {
    u_int8_t num_bits_source = sizeof(source) * 8;
    //create the mask
    unsigned int mask = (1U << bit_count) - 1;

    u_int8_t shift_count = starting_bit + bit_count;
    if(shift_count > num_bits_source) {
        return -1;
    }

    source = (source >> (num_bits_source - shift_count)) & mask;
    return source;
}