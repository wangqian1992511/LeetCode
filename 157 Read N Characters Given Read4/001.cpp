// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int p = 0, t = 4;
        while ((t == 4) && (n >= 4)) {
            t = read4(buf);
            buf += 4;
            p += t;
            n -= t;
        }
        if ((t == 4) && (n > 0)) {
            t = read4(buf);
            p += min(t, n);
            buf[min(t, n)] = 0;
        }
        return p;
    }
};