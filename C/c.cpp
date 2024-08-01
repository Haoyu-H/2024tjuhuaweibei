#include <iostream>
using namespace std;

int stairs(int level, int count,int top) {
	
	if (level == 0) {
		count = stairs(1,count,top);
	}
	else if (level == 1)
		count = stairs(0, count, top)+ stairs(2, count, top);
	else if (level == 2)
		count = stairs(1, count, top)+ stairs(0, count, top) + stairs(3, count, top);
	else if (level == 3)
		count = stairs(1, count, top) + stairs(0, count, top) + stairs(4, count, top)+ stairs(2, count, top);
	else if (level == 4)
		count = stairs(1, count, top) + stairs(0, count, top) + stairs(3, count, top) + stairs(2, count, top) + stairs(5, count, top);
	else if (level == top)
		count = stairs(top-1, count, top) + stairs(top-2, count, top) + stairs(top-3, count, top) + stairs(top-4, count, top) ;
	else
		count = stairs(level - 1, count, top) + stairs(level - 2, count, top) + stairs(level - 3, count, top) + stairs(level - 4, count, top)+stairs(level+1,count,top);
	return count;
}
int main() {
	int N;
	int level[1001];
	int ans[1001];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> level[i];
	}
	for (int i = 0; i < N; i++) {
		ans[i] = stairs(level[i], 0, level[i]);
		cout << ans[i]% 1000000007 << endl;
	}
}