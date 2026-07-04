//includes
#include <stdio.h>

//prototypes
u_int8_t bit_test(u_int32_t word, u_int8_t bit_number);
u_int32_t bit_set(u_int32_t word, u_int8_t bit_number);
void print_binary(u_int32_t word);


int main() {
    
    printf("Testing number 30 \n");
    printf("Binary representation of 30:\n");
    print_binary(30);

    printf("check if bit number 28 is on or off:\n");
    if(bit_test(30, 28)) {
        printf("Bit 28 is set on!\n");
    } else {
        printf("Bit 28 is set off!\n");
    }

    printf("Check if bit 27 is on or off:\n");
    if(bit_test(30,27)){
        printf("Bit 27 is set on!\n");
    } else {
        printf("Bit 27 is set off!\n");
    }

    printf("Since bit 27 is off, set it on and check the new number:\n");
    u_int32_t new_word = bit_set(30, 27);
    printf("New number is %d\n", new_word);
    printf("Binary representation:\n");
    print_binary(new_word);
    return 0;
}


//custom functions
void print_binary(u_int32_t word) {
    u_int8_t num_bits = sizeof(word) * 8; //although because it's a u_int32_t type, we know it will always be 32 bits, but we still measure
    u_int8_t counter = 0;

    for(int i = (num_bits - 1); i >= 0; i--) {
            if(counter == 4) {
                printf(" ");
                counter = 0;
            }
            u_int8_t current_bit = (word >> i) & 1;
            printf("%d", current_bit);
            counter++;

    }
    printf("b\n");
}


u_int8_t bit_test(u_int32_t word, u_int8_t bit_number) {
    u_int8_t num_bits = (sizeof(word) * 8); //although since word is of type u_int32_t we know it will always be 32 bits, but we will still do this
    u_int8_t num_shift_right = (num_bits - bit_number);

    u_int8_t bit = (word >> num_shift_right) & 1;
    return bit;
}

u_int32_t bit_set(u_int32_t word, u_int8_t bit_number) {
    u_int8_t num_bits = (sizeof(word) * 8); //although since word is of type u_int32_t we know it will always be 32 bits, but we will still do this
    u_int8_t num_shift_left = (num_bits - bit_number);
    u_int32_t num_mask = (1 << num_shift_left);
    return (word | num_mask);
}
