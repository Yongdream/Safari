#include <iostream>
#include <string>
using namespace std;

int minModifications(int n, const string& s) {
    int modifications = 0;  // ��¼��Ҫ�޸ĵĴ���
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {  // ��������ַ���ͬ
            ++modifications;     // �޸�����һ���ַ�
            ++i;  // ������һ���ַ������������޸�
        }
    }
    return modifications;
}

int main() {
    int n;
    string s;

    // ��ȡ����
    cin >> n >> s;

    // ������ٵ��޸Ĵ���
    cout << minModifications(n, s) << endl;

    return 0;
}
