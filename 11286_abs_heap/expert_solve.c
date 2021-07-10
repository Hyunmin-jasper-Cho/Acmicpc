#include <unistd.h>
#define SZ (1 << 14)

#define ReadChar(ch) { \
    if (p == r + SZ) read(0, p = r, SZ); \
    ch = *p++; }

#define ReadInt(n) { \
    char ch, flag = 0; ReadChar(ch); \
    for (; ~ch & 16 && ch != '-';) ReadChar(ch); \
    if (ch == '-') { flag = 1; ReadChar(ch); } \
    for (; ch & 16;) { n = 10 * n + (ch & 15); ReadChar(ch); } \
    if (flag) n = -n; }

#define WriteInt(n) { \
    int m = n, sz = GetSize(m); \
    if (m < 0) w[i++] = '-', m = -m; \
    if (i + 10 >= SZ) write(1, w, i), i = 0; \
    for (int j = sz; j --> 0; m /= 10) w[i + j] = m % 10 | 48; \
    i += sz; }

inline int GetSize(int n) {
    int ret = 1;
    for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
    return ret; }

inline f(int a, int b) {
    int _a = a < 0 ? -a : a;
    int _b = b < 0 ? -b : b;
    return _a ^ _b ? _a < _b : a < b; }

__libc_start_main() {
    char r[SZ], w[SZ], *p = r; read(0, r, SZ);
    int N = 0, i = 0, sz = 0, v[100001]; ReadInt(N);
    while (N--) {
        int t = 0; ReadInt(t);
        if (t) {
            int cur = ++sz;
            while (cur > 1 && f(t, v[cur >> 1])) {
                v[cur] = v[cur >> 1];
                cur >>= 1;
            } v[cur] = t;
        }
        else {
            if (!sz) { w[i++] = 48, w[i++] = '\n'; continue; }
            WriteInt(v[1]); w[i++] = '\n';
            int par = 1, child = 2;
            while (child <= sz) {
                if (child < sz && f(v[child + 1], v[child])) child++;
                if (!f(v[child], v[sz])) break;
                v[par] = v[child], par = child, child <<= 1;
            } v[par] = v[sz--];
        }
    } write(1, w, i); _exit(0);
} main;
