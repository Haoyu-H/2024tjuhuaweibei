#include <iostream>  
#include <vector>  
#include <string>  

using namespace std;

// ����������������չ������left��rightΪ���ĵ����л����Ӵ�  
void expandAroundCenter(const string& s, int left, int right, vector<pair<int, int>>& palindromes) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        palindromes.push_back({ left, right });
        left--;
        right++;
    }
}

// ��������������������Ļ����Ӵ�������  
long long countDistinctPalindromePairs(const string& s) {
    int n = s.size();
    vector<pair<int, int>> palindromes;

    // ����ÿ�����ܵ����ģ��������ַ������ĺ�ż�����ַ������ģ�  
    for (int i = 0; i < n; ++i) {
        expandAroundCenter(s, i, i, palindromes); // ��������  
        expandAroundCenter(s, i, i + 1, palindromes); // ż������  
    }

    long long count = 0;
    for (size_t i = 0; i < palindromes.size(); ++i) {
        for (size_t j = i + 1; j < palindromes.size(); ++j) {
            // ȷ�������Ӵ����ص�  
            if (palindromes[j].first > palindromes[i].second) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    string s;
    cout << "Enter the string of colors: ";
    cin >> s;

    long long result = countDistinctPalindromePairs(s);
    cout << "Number of distinct palindrome pairs: " << result << endl;

    return 0;
}