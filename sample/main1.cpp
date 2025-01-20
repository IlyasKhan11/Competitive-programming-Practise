#include <iostream>
#include <vector>
#include <cmath>
#include <string>

int main() {
    int T;
    std::cin >> T;
    for (int test = 0; test < T; ++test) {
        std::string S1, S2;
        std::cin >> S1 >> S2;
        
        int count_B_S1 = 0, count_B_S2 = 0;
        for (char c : S1) if (c == 'B') ++count_B_S1;
        for (char c : S2) if (c == 'B') ++count_B_S2;
        if (count_B_S1 != count_B_S2) {
            std::cout << -1 << '\n';
            continue;
        }
        
        std::vector<int> pos_S1, pos_S2;
        for (int i = 0; i < S1.size(); ++i) {
            if (S1[i] == 'B') pos_S1.push_back(i);
        }
        for (int i = 0; i < S2.size(); ++i) {
            if (S2[i] == 'B') pos_S2.push_back(i);
        }
        
        int total_ops = 0;
        for (size_t i = 0; i < pos_S1.size(); ++i) {
            int distance = abs(pos_S1[i] - pos_S2[i]);
            int ops = (distance + 1) / 2; 
            total_ops += ops;
        }
        std::cout << total_ops << '\n';
    }
    return 0;
}