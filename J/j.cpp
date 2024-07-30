#include<iostream>
using namespace std;
int main() {
	int N; cin >> N;
	int r[100]; int sc[100];
	for (int i = 0; i < N; i++) {
		cin >> r[i];
	}
	for (int i = 0; i < N; i++) {
		if (r[i] == 0)
			sc[i] = 0;
		else if (r[i] == 1)
			sc[i] = 60;
		else if (r[i] == 2 )
			sc[i] = 70;
		else if (r[i] == 3)
			sc[i] = 70;
		else if (r[i] == 4)
			sc[i] = 80;
		else if (r[i] == 5)
			sc[i] = 80;
		else if (r[i] == 6)
			sc[i] = 90;
		else if (r[i] == 7)
			sc[i] = 90;
		
		else
			sc[i] = 100;
		cout << sc[i] << endl;
	}

	return 0;
}