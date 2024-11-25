#include <iostream>
#include <string>

using namespace std;

int main() {
	int twodim[5][5] = {
		{
			1, 2, 3, 4, 5
		},
		{
			6, 7, 8, 9, 10
		}
	};

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << i << ", " << j << ": " << twodim[i][j] << endl;
		}
	}

}
