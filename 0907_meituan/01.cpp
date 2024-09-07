#include <iostream>
#include <sstream>
#include <cctype>
#include <string>

using namespace std;

// 将单词的首字母大写，其余字母小写
string capitalizeWord(const string& word) {
    if (word.empty()) return "";
    string result = word;
    result[0] = toupper(result[0]);  // 首字母大写
    for (size_t i = 1; i < result.size(); ++i) {
        result[i] = tolower(result[i]);  // 其余字母小写
    }
    return result;
}

//int main() {
//    string input;
//    getline(cin, input);  // 输入一行字符串
//
//    istringstream iss(input);
//    string word;
//    string result;
//
//    // 处理每个单词
//    bool firstWord = true;  // 标记是否是第一个单词，用于避免开头多余的空格
//    while (iss >> word) {
//        if (!firstWord) {
//            result += " ";  // 单词之间加空格
//        }
//        result += capitalizeWord(word);  // 将处理后的单词加入结果字符串
//        firstWord = false;
//    }
//
//    cout << result << endl;  // 输出处理后的字符串
//
//    return 0;
//}
