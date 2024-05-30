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

		// Cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue is empty \n";
			return;
		}

		cout << "\nElements in the queue are...\n";

		// Jika Front <= REAR, iterasi dari FRONT hingga REAR
		if (FRONT <= REAR) {
			while (FRONT <= REAR) {
				cout << queue_array[FRONT] << "  ";
				FRONT++;
			}
			cout << endl;
		}
		else {
			// Jika FRONT > REAR, iterasi dari FRONT hingga akhir array
			while (FRONT <= max - 1) {
			};