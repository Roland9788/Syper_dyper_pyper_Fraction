#include<iostream>
using namespace std;

template<class T>
class Fraction
{
private:
	T numerator;
	T denumerator;
	void Nod()
	{
		T n = numerator;
		T d = denumerator;
		while (n != 0 && d != 0)
		{
			if (n > d)
			{
				n = fmod(d,n);
			}
			else
			{
				d = fmod(d, n);
			}
		}
		numerator = numerator / (n + d);
		denumerator = denumerator / (n + d);
	}
public:

	Fraction(T numerator = 0, T denumerator = 1)
	{
		this->numerator = numerator;
		if (denumerator != 0)
		{
			this->denumerator = denumerator;
		}
		else
			this->denumerator = 1;
		if (this->numerator > 0)
		{
			Nod();
		}
	}
	void setdernumerator(T denumerator)
	{
		if (denumerator != 0)
		{
			this->denumerator = denumerator;
		}
		else
			this->denumerator = 1;
		Nod();
	}
	void setnumerator(T numerator)
	{
		this->numerator = numerator;
		Nod();
	}
	int getnumerator() { return numerator; }
	int getdernumerator() { return denumerator; }
	void print()
	{
		cout << numerator << "/" << denumerator << "\n";
	}

	static Fraction add(const Fraction& fodj1, const Fraction& fodj2)
	{
		return Fraction(fodj1.numerator * fodj2.denumerator + fodj2.numerator * fodj1.denumerator, fodj1.denumerator * fodj2.denumerator);
	}

	static Fraction sub(const Fraction& fodj1, const Fraction& fodj2)
	{
		return Fraction((fodj1.numerator * fodj2.denumerator) - (fodj2.numerator * fodj1.denumerator), fodj1.denumerator * fodj2.denumerator);
	}

	static Fraction mult(const Fraction& fodj1, const Fraction& fodj2)
	{
		return Fraction(fodj1.numerator * fodj2.numerator, fodj1.denumerator * fodj2.denumerator);
	}

	static Fraction div(const Fraction& fodj1, const Fraction& fodj2)
	{
		return Fraction(fodj1.numerator * fodj2.denumerator, fodj2.numerator * fodj1.denumerator);
	}

	static bool ravni(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) == (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static bool bolse(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) > (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static bool menche(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) < (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static bool bolseiliravni(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) >= (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static bool mencheiliravni(const Fraction& fodj1, const Fraction& fodj2)
	{
		if ((fodj1.denumerator * fodj2.denumerator) <= (fodj1.numerator * fodj2.numerator))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	static Fraction plusplus(Fraction& fodj1)
	{
		fodj1.numerator = fodj1.numerator + fodj1.denumerator;
		return fodj1;
	}

	static Fraction minysminys(Fraction& fodj1)
	{
		fodj1.numerator = fodj1.numerator - fodj1.denumerator;
		return fodj1;
	}

	static Fraction pow(Fraction& fodj1)
	{
		return fodj1 * fodj1;
	}

	static Fraction sqrt1(Fraction& fodj1)
	{
		return Fraction(sqrt(fodj1.numerator), sqrt(fodj1.denumerator));
	}


	static Fraction Ne(Fraction& fodj1)
	{
		if (fodj1.numerator > 0)
		{
			return Fraction(fodj1.denumerator, fodj1.numerator);
		}
		else
		{
			return Fraction(fodj1.numerator, fodj1.denumerator);
		}
	}


	friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2)
	{
		return add(fraction1, fraction2);
	}

	friend Fraction operator-(const Fraction& fraction1, const Fraction& fraction2)
	{
		return sub(fraction1, fraction2);
	}

	friend Fraction operator*(const Fraction& fraction1, const Fraction& fraction2)
	{
		return mult(fraction1, fraction2);
	}

	friend Fraction operator/(const Fraction& fraction1, const Fraction& fraction2)
	{
		return div(fraction1, fraction2);
	}

	friend ostream& operator<<(ostream& output, const Fraction& fraction1)
	{
		output << fraction1.numerator << "/" << fraction1.denumerator;
		return output;
	}
	friend istream& operator>> (std::istream& in, Fraction& fraction1)
	{
		in >> fraction1.numerator;
		in >> fraction1.denumerator;
		return in;
	}
	friend bool operator== (const Fraction& fraction1, const Fraction& fraction2)
	{
		return ravni(fraction1, fraction2);
	}

	friend bool operator> (const Fraction& fraction1, const Fraction& fraction2)
	{
		return bolse(fraction1, fraction2);
	}

	friend bool operator< (const Fraction& fraction1, const Fraction& fraction2)
	{
		return menche(fraction1, fraction2);
	}

	friend bool operator>= (const Fraction& fraction1, const Fraction& fraction2)
	{
		return bolseiliravni(fraction1, fraction2);
	}

	friend bool operator<= (const Fraction& fraction1, const Fraction& fraction2)
	{
		return mencheiliravni(fraction1, fraction2);
	}

	friend Fraction operator++ (Fraction& fraction1)
	{
		return plusplus(fraction1);
	}

	friend Fraction operator-- (Fraction& fraction1)
	{
		return minysminys(fraction1);
	}

	friend Fraction pow1 (Fraction& fraction1)
	{
		return pow(fraction1);
	}

	friend Fraction sqrt1(Fraction& fraction1)
	{
		return sqrt1(fraction1);
	}

	friend Fraction operator!(Fraction& fraction1)
	{
		return Ne(fraction1);
	}



};


int main()
{
	setlocale(LC_ALL, "Rus");
	int vibor = 0;
	cout << "�������� ��� ������ ����� �����(int)-1, ����� � ��������� ������(double)-2, ����� � ������(float)-3";
	cin >> vibor;
	if (vibor == 1)
	{
		Fraction<int> drob1{};
		Fraction<int> drob2{};
		cout << "������� ������ �����\n";
		cin >> drob1;
		cout << "������� ������ �����\n";
		cin >> drob2;

		cout << "\n�����1= ";
		cout << drob1;
		cout << "\n�����2= ";
		cout << drob2;

		cout << "\n\n�������������� ��������\n";
		cout << "\n��������= " << drob1 + drob2 << "\n";
		cout << "���������= " << drob1 - drob2 << "\n";
		cout << "�������= " << drob1 / drob2 << "\n";
		cout << "���������= " << drob1 * drob2 << "\n";
		cout << "�������= " << pow1(drob2) << "\n";
		cout << "������= " << sqrt1(drob2) << "\n";
		cout << "\n\n�������� ���������\n";
		if (drob1 == drob2)
		{
			cout << "\n������ � ������ ����� �����\n";
		}
		else
		{
			cout << "\n������ � ������ ����� �������\n";
		}

		if (drob1 > drob2)
		{
			cout << "\n������ ����� ������ ������ �����\n";
		}
		else
		{
			cout << "\n������ ����� ������ ������ �����\n";
		}

		if (drob1 < drob2)
		{
			cout << "\n������ ����� ������ ������ �����\n";
		}
		else
		{
			cout << "\n������ ����� ������ ������ �����\n";
		}

		if (drob1 >= drob2)
		{
			cout << "\n������ ����� ������ ��� ����� ������ �����\n";
		}
		else
		{
			cout << "\n������ ����� ������ ��� ����� ������ �����\n";
		}

		if (drob1 <= drob2)
		{
			cout << "\n������ ����� ������ ��� ����� ������ �����\n";
		}
		else
		{
			cout << "\n������ ����� ������ ��� ����� ������ �����\n";
		}
		cout << "\n\n������� ��������\n";
		cout << "\n!������ �����= " << !drob1;
		cout << "\n!������ �����= " << !drob2;
		cout << "\n++������ �����= " << ++drob1;
		cout << "\n++������ �����= " << ++drob2;
		cout << "\n--������ �����= " << --drob1;
		cout << "\n--������ �����= " << --drob2;

	}

	if (vibor == 2)
	{
		Fraction<double> drob1{};
		Fraction<double> drob2{};
		cout << "������� ������ �����\n";
		cin >> drob1;
		cout << "������� ������ �����\n";
		cin >> drob2;

		cout << "\n�����1= ";
		cout << drob1;
		cout << "\n�����2= ";
		cout << drob2;

		cout << "\n\n�������������� ��������\n";
		cout << "\n��������= " << drob1 + drob2 << "\n";
		cout << "���������= " << drob1 - drob2 << "\n";
		cout << "�������= " << drob1 / drob2 << "\n";
		cout << "���������= " << drob1 * drob2 << "\n";
		cout << "�������= " << pow1(drob2) << "\n";
		cout << "������= " << sqrt1(drob2) << "\n";
		cout << "\n\n�������� ���������\n";
		if (drob1 == drob2)
		{
			cout << "\n������ � ������ ����� �����\n";
		}
		else
		{
			cout << "\n������ � ������ ����� �������\n";
		}

		if (drob1 > drob2)
		{
			cout << "\n������ ����� ������ ������ �����\n";
		}
		else
		{
			cout << "\n������ ����� ������ ������ �����\n";
		}

		if (drob1 < drob2)
		{
			cout << "\n������ ����� ������ ������ �����\n";
		}
		else
		{
			cout << "\n������ ����� ������ ������ �����\n";
		}

		if (drob1 >= drob2)
		{
			cout << "\n������ ����� ������ ��� ����� ������ �����\n";
		}
		else
		{
			cout << "\n������ ����� ������ ��� ����� ������ �����\n";
		}

		if (drob1 <= drob2)
		{
			cout << "\n������ ����� ������ ��� ����� ������ �����\n";
		}
		else
		{
			cout << "\n������ ����� ������ ��� ����� ������ �����\n";
		}
		cout << "\n\n������� ��������\n";
		cout << "\n!������ �����= " << !drob1;
		cout << "\n!������ �����= " << !drob2;
		cout << "\n++������ �����= " << ++drob1;
		cout << "\n++������ �����= " << ++drob2;
		cout << "\n--������ �����= " << --drob1;
		cout << "\n--������ �����= " << --drob2;
	}

	if (vibor == 3)
	{
		Fraction<float> drob1{};
		Fraction<float> drob2{};
		cout << "������� ������ �����\n";
		cin >> drob1;
		cout << "������� ������ �����\n";
		cin >> drob2;

		cout << "\n�����1= ";
		cout << drob1;
		cout << "\n�����2= ";
		cout << drob2;

		cout << "\n\n�������������� ��������\n";
		cout << "\n��������= " << drob1 + drob2 << "\n";
		cout << "���������= " << drob1 - drob2 << "\n";
		cout << "�������= " << drob1 / drob2 << "\n";
		cout << "���������= " << drob1 * drob2 << "\n";
		cout << "�������= " << pow1(drob2) << "\n";
		cout << "������= " << sqrt1(drob2) << "\n";

		cout << "\n\n�������� ���������\n";
		if (drob1 == drob2)
		{
			cout << "\n������ � ������ ����� �����\n";
		}
		else
		{
			cout << "\n������ � ������ ����� �������\n";
		}

		if (drob1 > drob2)
		{
			cout << "\n������ ����� ������ ������ �����\n";
		}
		else
		{
			cout << "\n������ ����� ������ ������ �����\n";
		}

		if (drob1 < drob2)
		{
			cout << "\n������ ����� ������ ������ �����\n";
		}
		else
		{
			cout << "\n������ ����� ������ ������ �����\n";
		}

		if (drob1 >= drob2)
		{
			cout << "\n������ ����� ������ ��� ����� ������ �����\n";
		}
		else
		{
			cout << "\n������ ����� ������ ��� ����� ������ �����\n";
		}

		if (drob1 <= drob2)
		{
			cout << "\n������ ����� ������ ��� ����� ������ �����\n";
		}
		else
		{
			cout << "\n������ ����� ������ ��� ����� ������ �����\n";
		}

		cout << "\n\n������� ��������\n";
		cout << "\n!������ �����= " << !drob1;
		cout << "\n!������ �����= " << !drob2;
		cout << "\n++������ �����= " << ++drob1;
		cout << "\n++������ �����= " << ++drob2;
		cout << "\n--������ �����= " << --drob1;
		cout << "\n--������ �����= " << --drob2;
	}


	return 0;
}