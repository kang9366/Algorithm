#include <iostream>

int main() {
    int T;
    std::cin >> T;

    int sum = 0;
    int temp = 0;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < 10; j++) {
            std::cin >> temp;
            if (temp % 2 != 0) {
                sum += temp;
            }
        }
        std::cout << "#" << (i + 1) << " " << sum << std::endl;
        sum = 0;
    }

    return 0;
}
