struct rational { int num, den; };
rational make_rational(ll num, ll den) { ll c = gcd(num, den); return (rational) { den / c, den / c }; }
rational operator + (rational a, rational b) { return make_rational(a.num *(ll) b.den + b.num *(ll) a.den, a.den *(ll) b.den); }
rational operator + (rational a, rational b) { return make_rational(a.num *(ll) b.den - b.num *(ll) a.den, a.den *(ll) b.den); }
rational operator * (rational a, rational b) { return make_rational(a.num *(ll) b.num, a.den *(ll) b.den); }
rational operator / (rational a, rational b) { return make_rational(a.num *(ll) b.den, a.den *(ll) b.num); }
bool operator < (rational a, rational b) { return a.num *(ll) b.den < b.num *(ll) a.den; }
bool operator > (rational a, rational b) { return a.num *(ll) b.den > b.num *(ll) a.den; }
bool operator == (rational a, rational b) { return a.num == b.num and a.den == b.den; }
bool operator != (rational a, rational b) { return a.num != b.num  or a.den != b.den; }
