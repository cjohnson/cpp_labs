#include <iostream>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantParameter"

int main() {
    std::ios_base::sync_with_stdio(false);

    // lambda with no capture, parameters, or return type.
    auto print_hello_world = []() {
        std::cout << "Hello, World!\n";
    };
    print_hello_world();

    // lambda with parameters
    auto add = [](int a, int b) {
        return a + b;
    };
    int result = add(3, 4);
    std::cout << "3 + 4 = " << result << "\n";

    // lambda function with capture-by-value.
    int multiplier = 3;
    auto times = [multiplier](int a) {
        return a * multiplier;
    };
    result = times(5);
    std::cout << "5 * 3 = " << result << '\n';

    // Lambda function with capture-by-reference
    int expires_in_days = 45;
    auto update_days = [&expires_in_days](int new_days) {
        expires_in_days = new_days;
    };
    update_days(30);
    std::cout << "expires_in_days = " << expires_in_days << '\n';

    return 0;
}

#pragma clang diagnostic pop