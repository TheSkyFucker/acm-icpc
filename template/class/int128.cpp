#define ct const
struct int128 {
	static ct int B = 40;
	static ct ll  M = (1ll << B) - 1; // [0, M]
	ll h, l;
	int128(int l) : h(0), l(l) {}
	int128(ll h = 0, ll l = 0) : h(h), l(l) {}
	bool   operator ==(ct int128&d)ct{return h==d.h&&l==d.l;}
	int128 operator + (ct int128&d)ct{return int128(h+d.h+(l+d.l>M),l+d.l-(l+d.l>M?M:0));}
	int128 operator - (ct int128&d)ct{return int128(h-d.h-(l-d.l<0),l-d.l+(l<d.l?M+1:0));}
	int128 operator * (ct int128&d)ct{return d.h==0?*this*d.l:d*l;}
	//the folowing param(d) [0, 40]
	int128 operator <<(ct int&d)ct{return int128((h<<d)+(l>>(B-d)),(l<<d)&M);}
	int128 operator >>(ct int&d)ct{return int128(h>>d,(h&((1ll<<d)-1))<<(B-d)|l>>d);}
	//the folowing param(d) [1, 100w]
	int128 operator * (ct int&d)ct{ll dl=l*d; return int128(h*d+(dl>>B),dl&M);}
	int128 operator / (ct int&d)ct{return int128(h/d,((h%d)<<B|l)/d);}
	int    operator % (ct int&d)ct{return (int)(((h%d)<<B|l)%d);}
};
