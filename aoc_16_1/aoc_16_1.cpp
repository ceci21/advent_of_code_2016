#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string line;
	ifstream file("input.txt");
	int facing = 0;
	int x = 0, y = 0;


	if (file.is_open()) {
		while (getline(file, line, ',')) {
			if (line[0] == ' ') {
				line = line.substr(1);
			}

			char direction = line[0];
			if (direction == 'L') {
				facing = (facing - 1) % 4;
				if (facing < 0) {
					facing += 4;
				}
			}
			else {
				facing = (facing + 1) % 4;
			}

			int magnitude = atoi(line.substr(1).c_str());

			if (facing == 0) {
				y = y + magnitude;
			}
			else if (facing == 1) {
				x = x + magnitude;
			}
			else if (facing == 2) {
				y = y - magnitude;
			}
			else if (facing == 3) {
				x = x - magnitude;
			}
		}
		file.close();

		cout << "\n\n" << abs(x) + abs(y) << "\n\n";
	}

	int n;
	cin >> n;
	return 0;
}