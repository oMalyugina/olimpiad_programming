//
// Created by olga on 13/06/19.
//

#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int a;
            std::cin >> a;
            sum += a;
        }
    std::cout << sum / 2;
    return 0;
}