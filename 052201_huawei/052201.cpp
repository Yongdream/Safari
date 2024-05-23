#include <iostream>
#include <string>
#include <set>

int main() {
    std::string nums1, nums2;

    // 从标准输入读取两个字符串
    std::getline(std::cin, nums1);
    std::getline(std::cin, nums2);

    // 创建一个集合来存储nums1的所有子串
    std::set<std::string> s;
    int n = nums1.length();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            s.insert(nums1.substr(i, j - i));
        }
    }

    std::string res;
    int m = nums2.length();

    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            std::string temp = nums2.substr(i, j - i);
            if (s.find(temp) != s.end() && temp.length() > res.length()) {
                res = temp;
            }
        }
    }

    if (!res.empty()) {
        std::cout << res << std::endl;
    }
    else {
        std::cout << -1 << std::endl;
    }

    return 0;
}