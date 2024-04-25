#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 测试用例结构体
struct TestCase {
    std::string name;
    bool (*testFunction)();
    bool expectedOutcome;
};

// 测试函数原型
bool testIoStreams();
bool testVector();
bool testString();
bool testAlgorithms();

// 测试函数实现
bool testIoStreams() {
    std::cout << "Testing I/O streams..." << std::endl;
    
    // 测试输出流
    std::string hello = "Hello, World!";
    std::cout << hello << std::endl;

    // 测试输入流
    int inputNumber;
    std::cout << "Please enter a number: ";
    std::cin >> inputNumber;
    
    // 检查输入是否成功
    if (inputNumber == 42) { // 假设我们期望的输入是42
        return true;
    } else {
        return false;
    }
}

bool testVector() {
    std::cout << "Testing vector..." << std::endl;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    return !vec.empty() && vec.back() == 5;
}

bool testString() {
    std::cout << "Testing string..." << std::endl;
    std::string str = "Hello, World!";
    return str.length() == 13;
}

bool testAlgorithms() {
    std::cout << "Testing algorithms..." << std::endl;
    std::vector<int> vec = {10, 20, 30, 40, 50};
    std::sort(vec.begin(), vec.end());
    return vec == std::vector<int>({10, 20, 30, 40, 50});
}

// 运行测试用例
void runTestCases(const std::vector<TestCase>& cases) {
    for (const auto& testCase : cases) {
        bool result = testCase.testFunction();
        std::cout << (result == testCase.expectedOutcome ? "PASSED" : "FAILED") << ": " << testCase.name << std::endl;
    }
}

// 主函数
int main() {
    std::vector<TestCase> testCases = {
        {"I/O Streams", testIoStreams, true},
        {"Vector", testVector, true},
        {"String", testString, true},
        {"Algorithms", testAlgorithms, true}
    };

    runTestCases(testCases);
    return 0;
}