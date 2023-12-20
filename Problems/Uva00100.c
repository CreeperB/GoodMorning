#include <stdio.h>

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        int n_pr = n, m_pr = m, max = 0;
        if (m < n) n = m_pr, m = n_pr;
        for (int count = 1, i = n; i <= m; count > max ? max = count : NULL, count = 1, i++)
            for (int temp = i; temp != 1; count++) temp = (temp % 2 == 0) ? (temp / 2) : (temp * 3 + 1);
        printf("%d %d %d\n", n_pr, m_pr, max);
    }
}