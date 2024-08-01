#include<iostream>
#include<queue>
using namespace std;
int main() {
    char key[100];
    queue<char>que;
    que.push('A'); que.push('B'); que.push('C'); que.push('D'); que.push('E');
    char m, o; m = 'A'; o = 'B';
    int num1 = 0;
    int num2 = 0;
    num1 = 50;
    num2 = 50;
    int N = 0;
    int swap1 = 0;
    int swap2 = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> key[i];
    }
    for (int i = 1; i <= N; i++) {
        if (num1 != 0) {
            switch (key[i]) {
            case 'a':
                num1--;
                break;
            case 'q':
                if (num1 > 10)
                    num1 = num1 - 10;
                else
                    num1 = 0;
                break;
            case 'w':
                swap1 = num1;
                num1 = num2;
                num2 = swap1;
                swap2 = m;
                m = o;
                o = swap2;
                break;

            }
        }
        else {
            num1 = 50;
            m = que.front();
        }



    }
    cout << m << " " << num1 << endl;
    cout << o << " " << num2 << endl;
    return 0;
}