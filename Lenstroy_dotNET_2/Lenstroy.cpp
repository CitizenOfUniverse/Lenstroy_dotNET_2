#include "Lenstroy.h"

namespace Lenstroy {
	using namespace::std;

	typedef long long ll;
	typedef long long ull;
	typedef long double ld;
	typedef pair<int, int> pii;
	typedef pair<ll, ll> pll;
	typedef unsigned int uint;

	const int INF = numeric_limits<int>::max();
	//const ll INFn = numeric_limits<ll>::min();
	//const ll ll_INFn = numeric_limits<ll>::min() / 10;

	void problem();


	ll gcd(ll a, ll b) {
		return b ? gcd(b, a % b) : a;
	}

	vector<int> seed(int n) {
		vector<bool> isPrime(n + 1, true);
		vector<int> ans;
		for (int i = 2; i <= n; i++) {
			if (isPrime[i]) {
				ans.pb(i);
				for (int j = i; j <= n; j += i) {
					isPrime[j] = false;
				}
			}
		}
		return ans;
	}

	typedef tuple<int, int, int> point_t;

	point_t check(int a, int b) {
		if (b == 0) {
			return make_tuple(1, 0, a);
		}
		int q = a / b;
		int r = a % b;
		point_t check_rec = check(b, r);
		return make_tuple(get<1>(check_rec), get<0>(check_rec) - q * get<1>(check_rec), get<2>(check_rec));
	}

	point_t add_pt(point_t p, point_t q, int a, int b, int m) {
		int n, d;
		if (get<2>(p) == 0) {
			return q;
		}
		if (get<2>(q) == 0) {
			return p;
		}
		if (get<0>(p) == get<0>(q)) {
			if ((get<1>(p) == get<1>(q)) % m == 0) {
				return make_tuple(0, 1, 0); // infinity
			}
			n = (((3 * get<0>(p)) % m * get<0>(p)) % m + a) % m;
			d = (2 * get<1>(p)) % m;
		}
		else {
			n = ((get<1>(q) - get<1>(p)) % m + m) % m;
			d = ((get<0>(q) - get<0>(p)) % m + m) % m;
		}
		point_t chk_bez = check(d, m);
		if (get<2>(chk_bez) > 1) {
			return make_tuple(0, 0, d);
		}
		int nx = (n * get<0>(chk_bez)) % m;
		int z = (((nx * nx) % m - get<0>(p) - get<0>(q)) % m + m) % m;
		return make_tuple(z, ((nx * (get<0>(p) - z) - get<1>(p)) % m + m) % m, 1);
	}

	point_t mul(int k, point_t p, int a, int b, int m) {
		point_t r = make_tuple(0, 1, 0);
		while (k > 0) {
			if (get<2>(p) > 1) {
				return p;
			}
			if (k % 2 == 1) {
				r = add_pt(p, r, a, b, m);
			}
			k /= 2;
			p = add_pt(p, p, a, b, m);
		}
		return r;
	}

	int lenstroy(int n, int limit) {
		int g = n;
		while (g == n) {
			point_t q = make_tuple(rand() % n, rand() % n, 1);
			int a = rand() % n;
			int q1_2 = (get<1>(q) * get<1>(q)) % n;
			int q0_2 = (get<0>(q) * get<0>(q)) % n;
			int q0_3 = (q0_2 * get<0>(q)) % n;
			int b = (((q1_2 * q0_3) % n - (a * get<0>(q)) % n) % n + n) % n;
			int a3 = (((a * a) % n) * a) % n;
			int b2 = (b * b) % n;
			int g = gcd(((4 * a3) % n + (27 * b2) % n) % n, n);
			if (g > 1) {
				return g; //lucky factor
			}
			vector<int> primes = seed(n);
			for (int p : primes) {
				int pp = p;
				while (pp < limit) {
					point_t q = mul(p, q, a, b, n);
					if (get<2>(q) > 1) {
						return gcd(get<2>(q), n);
					}
					pp = p * pp;
				}
			}
		}
		return -1; //no divisor found
	}

	bool check_is_prime(int n) {
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				return false;
			}
		}
		return true;
	}

	void problem() {
		for (int i = 2; i < 500000; i++) {
			//int test = 235 * 19;
			int test = i;
			int ans = lenstroy(test, sqrt(test) + 1);
			cout << ans << "\n";
			bool p = check_is_prime(test);
			assert((ans != -1 && !p && (i % ans == 0)) || (ans == -1 && p) || (ans == i && p));
		}
		return;
	}
}