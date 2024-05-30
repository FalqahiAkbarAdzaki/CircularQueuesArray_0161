#include <iostream>
using namespace std;

class Queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	Queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a number: ";
		cin >> num;
		cout << endl;

		// Cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue overflow\n";
			return;
		}

		// cek apakah antrian kosng
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			// Jika REAR berada di psisi terkahir arry, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array[REAR] = num;
	}

	void remove() {
		// Cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue underflow\n";
			return;
		}
		cout << "\nTher element deleted from the queue is: " << queue_array[FRONT] << "\n";

		// Cek jika antrian hanya memiliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			// Jika elmen yang dihapus berada di posisi akhir array, kembali ke asal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

	void display() {

		int FRONT_Position = FRONT;
		int REAR_Position = REAR;

		// Cek apakah antrian kosong
		if (FRONT_Position == -1) {
			cout << "Queue is empty \n";
			return;
		}

		cout << "\nElements in the queue are...\n";

		// Jika Front <= REAR, iterasi dari FRONT hingga REAR
		if (FRONT_Position <= REAR_Position) {
			while (FRONT_Position <= REAR_Position) {
				cout << queue_array[FRONT_Position] << "  ";
				FRONT_Position++;
			}
			cout << endl;
		}
		else {
			// Jika FRONT > REAR, iterasi dari FRONT hingga akhir array
			while (FRONT_Position <= max - 1) {
				cout << queue_array[FRONT_Position] << "  ";
				FRONT_Position++;
			}

			FRONT_Position = 0;

			// Iterasi dari awal array hingga REAR
			while (FRONT_Position <= REAR_Position) {
				cout << queue_array[FRONT_Position] << "  ";
				FRONT_Position++;
			}
			cout << endl;
		}
	}
};

int main() {
	Queues q;
	char ch;

	while (true) {
		try {
			cout << "Menu" << endl;
			cout << "1. Implement insert operation" << endl;
			cout << "2. Implement selete operation" << endl;
			cout << "3. Display values" << endl;
			cout << "4. Exit" << endl;
			cout << "Enter your choice (1-4): ";
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {

				q.insert();
				break;
			}
			case '2': {
				q.remove();
				break;
			}
			case '3': {
				q.display();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option!!" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << "Check for the Values entered." << endl;
		}
	}

	return 0;