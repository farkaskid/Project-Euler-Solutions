#include <stdio.h>

int main() {
	for (int i = 1; i < 1000; i++) {
		for (int j = 1; j < 1000; j++) {
			if (i*j == 1000*(i+j-500)) {
				int k = 1000 - i - j;
				
				printf("%d\n", 1000*(i+j-500)*k);
				return 0;
			}
		}
	}
	return 1;
}

