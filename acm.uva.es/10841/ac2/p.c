#include <stdio.h>

static int max(int a, int b)
{
	return (a > b) ? a : b;
}

static int rdlist(int a[])
{
	static char buf[4096];
	char *p;
	int k;

	if (gets(buf) == NULL)
		return 0;

	for (k = 0, p = buf; ; k++) {
		while (*p && (*p < '0' || *p > '9')) p++;

		if (*p == '\0')
			return k;

		for (a[k] = 0; *p >= '0' && *p <= '9';)
			a[k] = a[k] * 10 + *p++ - '0';
	}
}

#define INF 0x1FFFFFFF

static int adj[128][128], tm[128], nstops[128], stop[128][128], nelev, dest;
static int used[128], dist[128], visit[128];

int main()
{

	int i, j, k, m;

	while (scanf("%d %d\n", &nelev, &dest) == 2) {
		rdlist(tm);
		for (i = 0; i < nelev; i++)
			nstops[i] = rdlist(stop[i]);

		for (i = 0; i < 100; i++) {
			for (j = 0; j < 100; j++)
				adj[i][j] = INF;
			adj[i][i] = 0;
			used[i] = 0;
		}
		used[0] = 1;

		for (k = 0; k < nelev; k++) {
			for (i = 0; i < nstops[k]; i++) {
				for (j = 0; j < nstops[k]; j++) {
					if (i == j || stop[k][j] == 0) continue;

					m = stop[k][j] - stop[k][i];
					if (m < 0) m = -m;

					m += max(
						stop[k][i] - stop[k][0],
						stop[k][nstops[k] - 1] - stop[k][i]
					);

					m *= tm[k];
					if (stop[k][i] != 0)
						m += 5;

					if (m >= adj[stop[k][i]][stop[k][j]])
						continue;

					adj[stop[k][i]][stop[k][j]] = m;
				}
				used[stop[k][i]] = 1;
				used[stop[k][j]] = 1;
			}
		}

		for (i = 0; i < 100; i++)
			visit[i] = !used[i];

		for (dist[0] = 0, i = 1; i < 100; i++)
			dist[i] = INF;

		for (;;) {
			for (k = 0; k < 100; k++)
				if(!visit[k]) break;
			if (k >= 100) break;

			for (i = k + 1; i < 100; i++)
				if (!visit[i] && dist[i] < dist[k]) k = i;

			if (dist[k] >= INF) break;

			for (visit[k] = 1, i = 0; i < 100; i++) {
				if ((dist[k] + adj[k][i]) < dist[i])
					dist[i] = dist[k] + adj[k][i];
			}
		}


		if (dist[dest] == INF) {
			printf("IMPOSSIBLE\n");
			continue;
		}

		printf("%d\n", dist[dest]);
	}

	return 0;
}
