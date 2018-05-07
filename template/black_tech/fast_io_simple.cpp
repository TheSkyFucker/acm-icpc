struct IO {
    static const int IO_N = 1<<23;
    int wt,ss[19];
    char fl[IO_N], *A;
    void init() { A=fl; *(fl + fread(fl, 1, IO_N, stdin)) = EOF; }
    void read(int &x){
        char c;
        for(x = 0; '0' > (c = *A++) || c > '9'; );
        for(; '0' <= c && c <= '9'; c = *A++) x = (x << 3) + (x << 1) + c - 48;
    }
    void print(int x){
        if(!x) putchar(48); else {
            for(wt = 0; x; ss[++wt] = x % 10, x /= 10);
            for(; wt; putchar(ss[wt--] + 48));
        }
    }
}   io;
