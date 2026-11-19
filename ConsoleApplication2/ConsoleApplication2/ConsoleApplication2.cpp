#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

class NumberReturning {
private:
	bool NrPrim(int nr)
	{
		if (nr < 2)
			return false;
		for (int i = 2; i <= nr / 2; i++)
			if (nr % i == 0)
				return false;
		return true;
	}
public:
	bool Moderat1(int n)
	{
		if (n == 6)
			return 1;
		else if (n <= 14)
			return 0;

		if (n % 2 == 0)
			return 0;

		int i = 5, k = 0, d, produs = 1, prec = 3;
		while (produs != n)
		{
			k = 0;
			for (d = 1; d * d <= i; d++)
				if (i % d == 0)
				{
					k++;
					break;
				}
			if (k == 2)
			{
				produs = i * prec;
				prec = i;
			}

			i++;
		}
		return 1;
	}

	bool Moderat(int n)
	{
		int p = 2;
		while (p * (p + 1) <= n)
		{
			int q = p + 1;
			while (q <= n / p)
			{
				bool prim1 = true, prim2 = true;
				for (int d = 2; d * d <= p; d++)
					if (p % d == 0)
						prim1 = false;
				for (int d = 2; d * d <= q; d++)
					if (q % d == 0)
						prim2 = false;
				if (prim1 && prim2 && p * q == n)
					return true;
				q++;
			}
			p++;
		}
		return false;
	}

	int ascendent(int x, int y, int n)
	{
		int s = 0, i, ci;
		int ucn = n % 10, uci;
		bool conf = false;
		for (i = x; i <= y; i++)
		{
			ci = i;
			while (ci != 0)
			{
				uci = ci % 10;
				if (uci >= ucn)
					conf = true;
				else
				{
					conf = false;
					break;
				}
				ci /= 10;
			}
			if (conf)
				s += i;
		}
		return s;
	}

	int a_prim(int n)
	{
		int d, p = 0;
		for (d = 2; d * d <= n; d++)
			if (n % d == 0)
			{
				if (d != n / d)
				{
					int x = n / d;
					bool prim1 = true, prim2 = true;
					for (int i = 2; i * i <= d; i++)
						if (d % i == 0)
							prim1 = false;
					for (int i = 2; i * i <= x; i++)
						if (x % i == 0)
							prim2 = false;
					if (prim1 && prim2)
						return 1;
				}
			}
		return 0;
	}

	int resturi(int n, int x, int y, int r)
	{
		int a = x, b = y;
		while (b > 0)
		{
			int t = a % b;
			a = b;
			b = t;
		}
		int cmmmc = x / a * y;
		return (n - r) / cmmmc + 1;
	}

	int baza_bac(int n, int b)
	{
		while (n)
		{
			if (n % 10 > b)
				return -1;
			n /= 10;
		}
		return 1;
	}

	bool pagini_bac(int n)
	{
		if (n % 4 == 0)
		{
			int k = 0, nr = n / 4;
			for (int d = 1; d <= nr; d++)
				if (nr % d == 0)
					k++;
			if (k == 2)
				return 1;
			else
				return 0;
		}
		else
			return 0;
	}

	int Fibo(int n)
	{
		int a = 1, b = 1, c;
		while (n > 0)
		{
			if (a % 2 == 1)
				n--;
			if (n == 0)
				return a;
			c = a + b;
			a = b;
			b = c;
		}

		return a;
	}

	int interval(int n)
	{
		int x = n + 1;
		int nr = 0;
		if (NrPrim(n))
			nr = 1;
		while (true)
		{
			if (NrPrim(x))
				nr++;
			if (nr == 1 && !NrPrim(x))
				return x;
			x++;
		}
	}

	int nz(int n)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			int ci = i;
			while (ci % 5 == 0)
			{
				cnt++;
				ci = ci / 5;
			}
		}
		return cnt;
	}

	int nr_prim(int n)
	{
		int i;
		for (i = n + 1; NrPrim(i) == false; i++);
		return i;
	}

	int NrPrime(int n)
	{
		int k = 0;
		while (n)
		{
			if (NrPrim(n % 10) == true)
				k++;
			n /= 10;
		}
		return k;
	}

	int majImp(int a, int b)
	{
		for (int x = a; x <= b; x++)
		{
			int s1 = 0, s2 = 0;
			for (int d = 2; d < x; d++)
				if (x % d == 0)
				{
					if (d % 2 == 1)
						s1 += d;
					else
						s2 += d;
				}
			if (s1 > s2)
				return x;
		}
		return 0;
	}

	int multiplu(int n) {
		int i = static_cast<int>(sqrt(n));
		while (true) {
			int nr = i * i;
			if (nr % n == 0)
				return nr;
			else
				i++;
		}
	}

	bool baza(int n, int b) {
		bool test = true;
		while (n) {
			if (n % 10 > b - 1) {
				test = false;
				break;
			}
			n /= 10;
		}
		if (test)
			return 1;
		else
			return 0;
	}

	int impar(int n) {
		int cn = n, nr = 0, p = 1;
		while (n) {
			if ((n % 10) % 2 == 1) {
				nr = nr + p * (n % 10);
				p *= 10;
				n /= 10;
			}
			else {
				n /= 10;
			}
		}
		int nr2 = 0;
		p = 1;
		while (cn) {
			if ((cn % 10) % 2 == 0) {
				nr2 = nr2 + p * (cn % 10);
				p *= 10;
				cn /= 10;
			}
			else {
				cn /= 10;
			}
		}
		p = 1;
		swap(nr, nr2); // e mai usor decat sa rescriu
		while (nr) {
			n = n + p * (nr % 10);
			p *= 10;
			nr /= 10;
		}
		while (nr2) {
			n = n + p * (nr2 % 10);
			p *= 10;
			nr2 /= 10;
		}
		return n;
	}

	int Phi(int n) {
		int nr = n;
		for (int d = 2; 1LL * d * d <= n; d++) // 1LL = long long 1
			if (n % d == 0) {
				nr = nr / d * (d - 1);
				while (n % d == 0)
					n /= d;
			}
		if (n > 1)
			nr = nr / n * (n - 1);
		return nr;
	}

	long long power(long long num, int ord) {
		long long result = 1;
		while (ord--)
			result *= num;
		return result;
	}
	long long nroot(int n, long long x) {
		long long i;
		for (i = 0; power(i + 1, n) <= x; i++);
		return i;
	}

	int PM(int n)
	{
		int v[10], k = 0;
		while (n > 0)
		{
			v[k++] = n % 10;
			n /= 10;
		}
		if (k % 2 == 0)
			return 0;
		for (int i = 0; i < k / 2; i++)
			if (v[i] != v[k - 1 - i])
				return 0;
		for (int i = 1; i < k / 2; i++)
			if (v[i] <= v[i - 1])
				return 0;
		return 1;
	}

	int NrDiv(int n)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (n % i == 0)
				cnt++;
		return cnt;
	}
	int NextNrDiv(int n)
	{
		int nr = NrDiv(n);
		int i = n + 1;
		while (NrDiv(i) != nr)
			i++;
		return i;
	}
	int PrevNrDiv(int n)
	{
		int nr = NrDiv(n);
		for (int i = n - 1; i >= 1; i--)
			if (NrDiv(i) == nr)
				return i;
		return -1;
	}

	
	bool abundent(int n)
	{
		int Sumdiv = 0,k;
		float Raport1;
		for (int i = 1; i <= n; i++)
			if (n % i == 0)
				Sumdiv += i;
		Raport1 = Sumdiv / n;
		float Raport2;
		for (k = 1; k <= n - 1; k++)
		{
			Sumdiv = 0;
			for (int i = 1; i <= k; i++)
				if (k % i == 0)
					Sumdiv += i;
			Raport2 = Sumdiv / k;
			if (Raport2 > Raport1)
				return false;
		}
		return true;
	}
};

class Statics {
public:
	static bool NrPrim(int nr)
	{
		if (nr < 2)
			return false;
		for (int i = 2; i <= nr / 2; i++)
			if (nr % i == 0)
				return false;
		return true;
	}
};

class Voids {
public:
	void FRadical(int n, int& x, int& y)
	{
		int nr = n;
		x = 1;
		for (int d = 2; d * d <= n; d++)
		{
			int p = 0;
			while (n % d == 0)
			{
				n /= d;
				p++;
			}
			for (int i = 0; i < p / 2; i++)
				x *= d;
		}
		y = nr / (x * x);
	}

	void Plus(int& n)
	{
		int v[11];
		int N = n;
		int i = 1;
		while (N > 0)
		{
			v[i] = N % 10;
			N /= 10;
			i++;
		}
		for (int j = 1; j < i - 1; j++)
		{
			if (v[j] == 5 && v[j + 1] == 2)
				v[j]++;
		}
		n = 0;
		for (int j = i - 1; j >= 1; j--)
			n = n * 10 + v[j];
	}

	void teren(int x, int y)
	{
		int valmax = x * y;
		for (int d = 2; d <= valmax / 2; d++)
			if (valmax % d == 0 && d % 2 == 0 && valmax / d > d)
				cout << d << " parcele de arie " << valmax / d << "\n";
	}

	void afisare(int a, int b)
	{
		if (a > b)
			swap(a, b);
		for (int i = a; i <= b; i++)
			if (i % 2 == 0)
				cout << i << " ";
	}

	void sub(int n, int k)
	{
		for (int i = n; i >= 1; i--)
			cout << i * k << " ";
	}

	void NrUniform_bac(int n, int& a, int& b)
	{
		int NrPar[11], NrImp[11];
		int cn = n, k = 0;
		while (cn)
		{
			k++; //CLOSE THIS WHILE U CAN
			cn /= 10;
		}
		int p = 0, q = 0;
		for (int i = k - 1; i >= 0; i--)
		{
			int cifra = (n / static_cast<int>(pow(10, i))) % 10;
			if (cifra % 2 == 0)
				NrPar[p++] = cifra;
			else
				NrImp[q++] = cifra;
		}
		for (int i = 0; i < p; i++)
			a = a * 10 + NrPar[i];
		for (int i = 0; i < q; i++)
			b = b * 10 + NrImp[i];
	}

	void DNPI(int n)
	{
		for (int i = 1; i <= n; i += 2)
			if (n % i == 0 && Statics::NrPrim(i) == false)
				cout << i << " ";
	}
};

int main()
{
	NumberReturning Auto;
	Voids Void;
	Void.DNPI(90);
}
