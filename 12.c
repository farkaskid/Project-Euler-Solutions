#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PRIME_LIMIT 100

struct Node {
	int val;
	struct Node *next;
};

typedef struct Node *node;

node createNode(int val) {
	node temp = (node)malloc(sizeof(struct Node));
	temp->val = val;
	temp->next = NULL;
	return temp;
}

void create_primes(node tail) {
	int arr[PRIME_LIMIT+1] = { 0 };

	for (int i = 2; i < PRIME_LIMIT+1; i++) {
		if (arr[i] == 1) {
			continue;
		}
		tail->next = createNode(i);
		tail = tail->next;
		for (int j = i; j < PRIME_LIMIT+1; j += i) {
			arr[j] = 1;
		}
	}
}

int count_divisors(int x, node primes) {
	int result = 0;
	node head = primes;
	int prime = primes->val;
	int num = x;

	while (prime <= num) {
		if (num % prime == 0) {
			result++;
			num = num / prime;
		} else {
			primes = primes->next;
			prime = primes->val;
		}
	}

	return 1 << result;
}

int main() {
	node head = createNode(1);
	create_primes(head);
	printf("%d\n", count_divisors(28, head->next));	
	return 0;
}
