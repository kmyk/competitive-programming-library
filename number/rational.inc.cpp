struct rational { int num, den; };
rational make_rational(int num, int den = 1) { return (rational) { num, den }; }
rational operator + (rational a, rational b) { return make_rational(a.num *(ll) b.den + b.num *(ll) a.den, a.den *(ll) b.den); }
rational operator - (rational a, rational b) { return make_rational(a.num *(ll) b.den - b.num *(ll) a.den, a.den *(ll) b.den); }
rational operator * (rational a, rational b) { return make_rational(a.num *(ll) b.num, a.den *(ll) b.den); }
rational operator / (rational a, rational b) { return make_rational(a.num *(ll) b.den, a.den *(ll) b.num); }
bool operator < (rational a, rational b) { return a.num *(ll) b.den < b.num *(ll) a.den; }
bool operator > (rational a, rational b) { return a.num *(ll) b.den > b.num *(ll) a.den; }
bool operator == (rational a, rational b) { return a.num == b.num and a.den == b.den; }
bool operator != (rational a, rational b) { return a.num != b.num  or a.den != b.den; }
ostream & operator << (ostream & out, rational a) { if (a.den == 0) return out << "invalid"; return out << a.num << '/' << a.den; }
