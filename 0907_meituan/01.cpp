#include <iostream>
#include <sstream>
#include <cctype>
#include <string>

using namespace std;

// �����ʵ�����ĸ��д��������ĸСд
string capitalizeWord(const string& word) {
    if (word.empty()) return "";
    string result = word;
    result[0] = toupper(result[0]);  // ����ĸ��д
    for (size_t i = 1; i < result.size(); ++i) {
        result[i] = tolower(result[i]);  // ������ĸСд
    }
    return result;
}

//int main() {
//    string input;
//    getline(cin, input);  // ����һ���ַ���
//
//    istringstream iss(input);
//    string word;
//    string result;
//
//    // ����ÿ������
//    bool firstWord = true;  // ����Ƿ��ǵ�һ�����ʣ����ڱ��⿪ͷ����Ŀո�
//    while (iss >> word) {
//        if (!firstWord) {
//            result += " ";  // ����֮��ӿո�
//        }
//        result += capitalizeWord(word);  // �������ĵ��ʼ������ַ���
//        firstWord = false;
//    }
//
//    cout << result << endl;  // ����������ַ���
//
//    return 0;
//}
