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
        mem = new char [4];
        offset = memM = 0;
    }
    int read(char *buf, int n) {
        int cnt = 0;
        if (offset <= n) {
            memcpy(buf, mem + memM, offset);
            cnt += offset;
            n -= offset;
            offset = 0;
            memM = 0;
        }
        else {
            memcpy(buf, mem + memM, n);
            cnt += n;
            offset -= n;
            memM += n;
            n = 0;
        }
        while (n) {
            int x = read4(mem);
            if (!x) break;
            if (x <= n) {
                memcpy(buf + cnt, mem, x);
                cnt += x;
                n -= x;
                offset = 0;
                memM = 0;
            }
            else {
                memcpy(buf + cnt, mem, n);
                cnt += n;
                offset = x - n;
                memM = n;
                n = 0;
            }
        }
        return cnt;
    }
private:
    char* mem;
    int offset, memM;
};
