#include <stdio.h>
#include <stdlib.h>

#define MAXN 524288

int read(int, char *, int);

static long long r;
static int input[MAXN], tmp[MAXN];

/* Merge sort; uses temporary storage in tmp[]
   O(n log n) time, O(n) extra space */
static void msort(int a[], int n)
{
	int *left, *right, *t;
	int i, j;

	if (n <= 40) {
		/* Insertion sort for small subarrays */
		register int k;

		for (i = 1; i < n; i++) {
			for (k = a[i], j = i - 1; j >= 0 && a[j] > k; j--, r++)
				a[j + 1] = a[j];
			a[j + 1] = k;
		}

		return;
	}

	/* Split into two subarrays, recursively sort and count inversions */

	i = n >> 1;
	left = a;
	msort(left, i);

	right = a + i;
	j = n - i;
	msort(right, j);

	/* Merge in temporary storage, count inversions */
	for (t = tmp;;) {
		if (*left <= *right) {
			*t++ = *left++;
			if (--i == 0) break;
		} else if (*right < *left) {
			*t++ = *right++;
			r += i;
			if (--j == 0) break;
		}
	}

	while (i-- > 0)
		*t++ = *left++;

	while (j-- > 0)
		*t++ = *right++;

	/* Copy result back to a[] */
	for (i = 0, t = tmp; i < n; i++)
		*a++ = *t++;
}

int main()
{
	static char inbuf[65536];
	static int isdig[256], intmp, n;
	register char *inptr;
	register int inleft, i;

	for (i = 0; i < 256; i++)
		isdig[i] = (i >= '0' && i <= '9');

#define READ(var, eofcode)\
{\
	for (;;) {\
		if (inleft == 0) {\
			inleft = read(0, inptr = inbuf, sizeof(inbuf));\
			if (inleft <= 0) { eofcode; break; }\
		}\
		if (isdig[(unsigned)*inptr]) break; else {inptr++; inleft--;}\
	}\
	for (intmp = *inptr++ - '0', inleft--;;) {\
		if (inleft == 0) {\
			inleft = read(0, inptr = inbuf, sizeof(inbuf));\
			if (inleft <= 0) { eofcode; break; }\
		}\
		if (isdig[(unsigned)*inptr]) {\
			intmp = intmp * 10 + *inptr++ - '0';\
			inleft--;\
		} else {\
			break;\
		}\
	}\
        (var) = intmp;\
}

	inptr = inbuf;
	inleft = 0;

	for (;;) {
		READ(n, { return 0; });

		if (n <= 0)
			break;

		for (i = 0; i < n; i++) {
			READ(input[i], { return 0; });
		}

		r = 0;
		msort(input, n);

		printf("%lld\n", r);
	}

	return 0;
}
