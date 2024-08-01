#include <iostream>  
#include <vector>  
#include <string>  

using namespace std;

// 辅助函数：中心扩展法找以left和right为中心的所有回文子串  
void expandAroundCenter(const string& s, int left, int right, vector<pair<int, int>>& palindromes) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        palindromes.push_back({ left, right });
        left--;
        right++;
    }
}

// 主函数：计算符合条件的回文子串对数量  
long long countDistinctPalindromePairs(const string& s) {
    int n = s.size();
    vector<pair<int, int>> palindromes;

    // 遍历每个可能的中心（奇数个字符的中心和偶数个字符的中心）  
    for (int i = 0; i < n; ++i) {
        expandAroundCenter(s, i, i, palindromes); // 奇数长度  
        expandAroundCenter(s, i, i + 1, palindromes); // 偶数长度  
    }

    long long count = 0;
    for (size_t i = 0; i < palindromes.size(); ++i) {
        for (size_t j = i + 1; j < palindromes.size(); ++j) {
            // 确保两个子串不重叠  
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