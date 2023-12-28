#include <iostream>

void bitwise_basics() {
    // Bitwise AND
    // -----------
    // 5 & 3 = 0b101 & 0b011 = 0b001 = 1
    int result_and = 5 & 3;
    std::cout << "5 & 3 = " << result_and << '\n';

    // Bitwise OR
    // ----------
    // 5 | 3 = 0b101 | 0b011 = 0b111 = 7
    int result_or = 5 | 3;
    std::cout << "5 | 3 = " << result_or << '\n';

    // Bitwise XOR
    // -----------
    // 5 ^ 3 = 0b101 | 0b011 = 0b110 = 6
    int result_xor = 5 ^ 3;
    std::cout << "5 ^ 3 = " << result_xor << '\n';

    // Bitwise NOT (8 bytes/int, signed integer)
    // -----------------------------------------
    // ~5 = ~0b101 = ~0b00000101 = 0b11111010 = -6
    int result_not = ~5;
    std::cout << "~5 = " << result_not << '\n';

    // Bitwise Left Shift
    // ------------------
    // 5 << 1 = 0b101 << 1 = 0b1010 = 10
    int result_left_shift = 5 << 1;
    std::cout << "5 << 1 = " << result_left_shift << '\n';

    // Bitwise Right Shift
    // -------------------
    // 5 >> 1 = 0b101 >> 1 = 0b10 = 2
    int result_right_shift = 5 >> 1;
    std::cout << "5 >> 1 = " << result_right_shift << '\n';

    std::cout << '\n';
}

void parity_by_bit() {
    // Checking the parity of an integer can be performed using bitwise operations:
    int even = 234232;
    int odd = 28986243;

    // What is the parity of 'even'?
    if (even & 0x1) {
        std::cout << "even is odd\n";
    }
    if ((even & 0x1) == 0) {
        std::cout << "even is even\n";
    }

    // What is the parity of 'odd'?
    if (odd & 0x1) {
        std::cout << "odd is odd\n";
    }
    if ((odd & 0x1) == 0) {
        std::cout << "odd is even\n";
    }

    std::cout << '\n';
}

void bit_fields() {
    // One Application of Bitwise Operations: Bit fields
    // --------------------------------------------
    // Common in some C interfaces - OpenGL is an example
    // Flags composed through bitwise OR are passed in a single integer,
    // possible representing many different possible configurations.
    //
    // Note that for all flags f, for every other flag f0 other than f, f & f0 == 0.
    int flag1 = 0b001; // 1
    int flag2 = 0b010; // 1 << 1
    int flag3 = 0b100; // 1 << 2

    // Compose setting of some flags.
    int setting = flag1 | flag3;
    // alternate method
    // int setting = 0;
    // setting |= flag1;
    // setting |= flag3;

    // (setting & flag1) is 0 if flag1 is not set, and (flag1) if flag1 is set. This is the trick behind
    // the `if(setting & flag) { ... }` notation.
    if (setting & flag1) {
        std::cout << "Setting has flag1 set.\n";
    } else {
        std::cout << "Setting does not have flag1 set.\n";
    }

    if (setting & flag2) {
        std::cout << "Setting has flag2 set.\n";
    } else {
        std::cout << "Setting does not have flag2 set.\n";
    }

    if (setting & flag3) {
        std::cout << "Setting has flag3 set.\n";
    } else {
        std::cout << "Setting does not have flag3 set.\n";
    }

    // Testing 2 flags
    if ((setting & (flag1 | flag3)) == (flag1 | flag3)) {
        std::cout << "flag1 and flag3 are set\n";
    } else {
        std::cout << "either flag1 is unset, flag3 is unset, or both!\n";
    }

    // Clear flag1 from setting
    std::cout << "Clearing flag 1...\n";
    setting &= ~flag1;

    if (setting & flag1) {
        std::cout << "Setting has flag1 set.\n";
    } else {
        std::cout << "Setting does not have flag1 set.\n";
    }

    if (setting & flag2) {
        std::cout << "Setting has flag2 set.\n";
    } else {
        std::cout << "Setting does not have flag2 set.\n";
    }

    if (setting & flag3) {
        std::cout << "Setting has flag3 set.\n";
    } else {
        std::cout << "Setting does not have flag3 set.\n";
    }
}

int main() {
    // Disable C IO sync
    std::ios_base::sync_with_stdio(false);

    std::cout << "Bitwise Operators Lab" << '\n';
    std::cout << "---------------------" << '\n';

    bitwise_basics();
    parity_by_bit();
    bit_fields();

    return 0;
}
