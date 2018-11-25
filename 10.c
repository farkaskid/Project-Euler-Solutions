#include <stdio.h>

#define VAL 2000001

long compute() {
	int arr[VAL] = { 0 };
	long sum = 0;

	for (int i = 2; i < VAL; i++) {
		if (arr[i] == 1) {
			continue;
		}
		sum += i;
		for (int j = i; j < VAL; j += i) {
			arr[j] = 1;
		}
	}
	return sum;
}

int main() {
	printf("%ld\n", compute());
   	return 0;
}	
