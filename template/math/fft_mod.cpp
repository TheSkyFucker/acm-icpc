const db pi = acos(-1);
const int P = 1e9 + 7;
void pp(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
namespace FFT{
    const int N = (1 << 21) + 7;
    struct vir {
        db r, i;
        vir() {r = i = 0;}
        vir(db r, db i) : r(r),i(i){}
        vir operator+(const vir &p) const { return vir(r + p.r, i + p.i); }
        vir operator-(const vir &p) const { return vir(r - p.r, i - p.i); }
        vir operator*(const vir &p) const { return vir(r * p.r - i * p.i, r * p.i + i * p.r); }
    };
    inline vir conj(const vir &p) { return vir(p.r, -p.i); }
    vir w[N], A[N], B[N], dfa[N], dfb[N], dfc[N], dfd[N];
    int L, n, bitrev[N];
    void init(int len) {
        L = 0; while(1<<L<=len) ++L;
        n=1<<L;
        rep(i,0,n) bitrev[i] = (bitrev[i>>1]>>1)|((i&1)<<(L-1));
        rep(i,0,n) w[i] = vir(cos(2*pi*i/n), sin(2*pi*i/n));
    }
    void fft(vir *a, const int &n) {
        rep(i,0,n) if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
        for (int i=2,d=n>>1;i<=n;i<<=1,d>>=1)
            for (int j=0;j<n;j+=i) {
                vir *l=a+j,*r=a+j+(i>>1),*p=w;
                for (int k=0;k<(i>>1);++k) {
                    vir tmp=(*r)*(*p);
                    *r=*l-tmp,*l=*l+tmp;
                    ++l,++r,p+=d;
                }
            }
    }
    vi mul(const vi &a, const vi &b) {
        if((sz(a)<=100 && sz(b)<=100) || min(sz(a),sz(b))<=5){
            vi res(sz(a)+sz(b)-1,0);
            rep(i,0,sz(a)) rep(j,0,sz(b)) pp(res[i+j],1ll*a[i]*b[j]%P);
            return res;
        }
        init(sz(a)+sz(b));
        rep(i,0,n) A[i]=B[i]=vir(0,0);
        rep(i,0,sz(a)) A[i]=vir(a[i]&32767,a[i]>>15);
        rep(i,0,sz(b)) B[i]=vir(b[i]&32767,b[i]>>15);
        fft(A,n),fft(B,n);
        rep(i,0,n) {
            int j=(n-i)&(n-1);
            static vir da, db, dc, dd;
            da = (A[i] + conj(A[j])) * vir(0.5, 0);
            db = (A[i] - conj(A[j])) * vir(0, -0.5);
            dc = (B[i] + conj(B[j])) * vir(0.5, 0);
            dd = (B[i] - conj(B[j])) * vir(0, -0.5);
            dfa[j] = da * dc, dfb[j] = da * dd;
            dfc[j] = db * dc, dfd[j] = db * dd;
        }
        rep(i,0,n) {
            A[i]=dfa[i]+dfb[i]*vir(0, 1);
            B[i]=dfc[i]+dfd[i]*vir(0, 1);
        }
        fft(A,n),fft(B,n);
        vi ret(n,0);
        rep(i,0,n) {
            ll da = (ll) (A[i].r / n + 0.5) % P;
            ll db = (ll) (A[i].i / n + 0.5) % P;
            ll dc = (ll) (B[i].r / n + 0.5) % P;
            ll dd = (ll) (B[i].i / n + 0.5) % P;
            pp(ret[i], (da + ((db + dc) << 15) + (dd << 30)) % P);
        }
        return ret;
    }
}


