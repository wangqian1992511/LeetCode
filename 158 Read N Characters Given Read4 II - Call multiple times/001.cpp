// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    Solution () {
        offset = memM = 0;
    }
    int read(char *buf, int n) {
        int out, cnt = 0;
        copyData(buf, cnt, n, offset);
        while (n && (out = read4(mem)))
            copyData(buf, cnt, n, out);
        return cnt;
    }
private:
    char mem[4];
    int offset, memM;
    void copyData(char *buf, int &cnt, int &want, int out) {
        int x = min(out, want);
        memcpy(buf + cnt, mem + memM, x);
        offset = max(0, out - want);
        memM = offset ? memM + x : 0;
        cnt += x;
        want -= x;
    }
};