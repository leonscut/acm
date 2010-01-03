#include <stdio.h>

typedef long long num;

int isqrt(num a)
{
	num x, y;

	for (x = a; x > 1; x = y)
		if ((y = (x + (a / x)) >> 1) >= x) break;

	return (int)x;
}

int divisors(num r[], num x)
{
	static num a[64], b[64];
	static int c[64], e[64];
	int i, k, n;

	if (x == 0) {
		r[0] = 1;
		r[1] = 0;
		return 1;
	}

	if (x < 0)
		x = -x;

	if ((x & 1) == 0)
		for (b[0] = 2, e[0] = 0, n = 1; (x & 1) == 0; x >>= 1) e[0]++;
	else
		n = 0;

	for (i = 3, k = isqrt(x) + 1; i <= k; i += 2) {
		if ((x % i) == 0) {
			for (b[n] = i, e[n] = 1, x /= i; (x % i) == 0; e[n]++)
				x /= i;
			n++;
			k = isqrt(x);
		}
	}

	if (x > 1)
		b[n] = x, e[n] = 1, n++;

	for (k = 0, i = 0; i < n; i++)
		a[i] = 1, c[i] = 0;

	do {
		for (r[k] = 1, i = 0; i < n; i++)
			r[k] *= a[i];

		for (k++, i = 0; i < n; i++) {
			if (++c[i] <= e[i]) {
				a[i] *= b[i];
				break;
			} else {
				a[i] = 1;
				c[i] = 0;
			}
		}
	} while (i < n);

	r[k] = 0;
	return k;
}

void sort(num a[], int n)
{
	int i, j;
	num t;

	for (i = 1; i < n; i++) {
		for (t = a[i], j = i - 1; j >= 0 && a[j] > t; j--)
			a[j + 1] = a[j];
		a[j + 1] = t;
	}
}

num gcd(num x, num y)
{
	int k;

	for (k = 0; ((x | y) & 1) == 0; k++, x >>= 1, y >>= 1);

	for (;;) {
		if (x == 0) return (y << k);
		if (y == 0) return (x << k);

		while ((x & 1) == 0) x >>= 1;
		while ((y & 1) == 0) y >>= 1;

		if (x > y)
			x -= y;
		else
			y -= x;
	}
}

num coef[1024], roots[1024];
int deg, nroots;

int eval(num p0, num q0, unsigned m)
{
	static unsigned pw[1024], qw[1024];
	unsigned i, p, q, s, t;

	if (p0 >= 0)
		p = p0 % m;
	else {
		p = m - ((-p0) % m);
		if (p == m) p = 0;
	}

	if (q0 >= 0)
		q = q0 % m;
	else {
		q = m - ((-q0) % m);
		if (q == m) q = 0;
	}

	for (pw[0] = 1, i = 0; i < deg; i++)
		pw[i + 1] = (pw[i] * p) % m;

	for (qw[0] = 1, i = 0; i < deg; i++)
		qw[i + 1] = (qw[i] * q) % m;

	for (s = 0, i = 0; i <= deg; i++) {
		if (coef[i] >= 0)
			t = coef[i] % m;
		else
			t = m - ((-coef[i]) % m);
		s = (s + ((t * pw[deg - i]) % m) * qw[i]) % m;
	}

	return (s == 0);
}

int check(num p, num q)
{
	return eval(p, q, 32749) && eval(p, q, 32719) && eval(p, q, 32693) &&
	       eval(p, q, 32531);
}

void solve()
{
	static num p[16384], q[16384];
	int i, j;

	nroots = 0;

	while (deg > 0 && coef[deg] == 0) {
		roots[nroots++] = 0;
		deg--;
	}

	if (deg < 1)
		return;

	divisors(p, coef[deg]);
	divisors(q, coef[0]);

	for (i = 0; p[i] != 0; i++) {
		if ((coef[deg] % p[i]) != 0) continue;
		for (j = 0; q[j] != 0; j++) {
			if ((coef[0] % q[j]) != 0 || gcd(p[i], q[j]) != 1)
				continue;

			while (check(p[i], q[j])) {
				roots[nroots++] = (coef[0] / q[j]) * p[i];
				break;
			}

			while (check(-p[i], q[j])) {
				roots[nroots++] = (coef[0] / q[j]) * p[i];
				break;
			}
		}
	}
}

int main()
{
	int i, t;

	for (t = 0; scanf("%d %lld", &deg, &coef[0]) == 2 && deg > 0; t++) {
		if (t > 0)
			printf("\n");

		for (i = 1; i <= deg; i++) {
			scanf("%lld", &coef[i]);
			if (i & 1) coef[i] = -coef[i];
		}

		solve();

		if (nroots == 0)
			printf("No solution.\n");
		else {
			sort(roots, nroots);
			for (i = 0; i < nroots; i++)
				printf(i ? " %lld" : "%lld", roots[i]);
			printf("\n");
		}
	}

	return 0;
}
