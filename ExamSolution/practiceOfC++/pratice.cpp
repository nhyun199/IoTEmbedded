#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <>
using namespace std;

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int gcd_three(int a, int b, int c)
{
	return gcd(gcd(a, b), c);
}

vector<int> cd(int gcd)
{
	int value = gcd;
	vector<int> cds;

	for (int i = 1; i * i <= value; i++)
	{
		if (value % i == 0)
		{
			cds.push_back(i);
			if (i != value / i)
			{
				cds.push_back(value / i);
			}
		}
	}
	return cds;
}

int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int countDiv(int n)
{
	int count = 0;

	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (i == n / i)
				count++;
			else
				count += 2;
		}
	}
	return count;
}

vector<int> findDiv(int n)
{
	vector<int> divs;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			divs.push_back(i);
			if (i != n / i)
				divs.push_back(n / i);
		}
	}
	sort(divs.begin(), divs.end());
	return divs;
}

void printDiv(vector<int> nums)
{
	for (int i : nums)
		cout << i << ' ';
	cout << '\n';
}

int valueLOVE(string name, string teamName)
{
	int love[4] = { 0 };
	int value = 0;
	for (int i = 0; i < name.size(); i++)
	{
		switch (name[i])
		{
		case 'L':
			love[0]++;
			break;
		case 'O':
			love[1]++;
			break;
		case 'V':
			love[2]++;
			break;
		case 'E':
			love[3]++;
			break;
		}
	}

	for (int i = 0; i < teamName.size(); i++)
	{
		switch (teamName[i])
		{
		case 'L':
			love[0]++;
			break;
		case 'O':
			love[1]++;
			break;
		case 'V':
			love[2]++;
			break;
		case 'E':
			love[3]++;
			break;
		}
	}

	value = ((love[0] + love[1]) * (love[0] + love[2]) * (love[0] + love[3]) *
			 (love[1] + love[2]) * (love[1] + love[3]) * (love[2] + love[3]));

	return value % 100;
}

int revNum(string X)
{
	reverse(X.begin(), X.end());
	int x = stoi(X);
	return x;
}

int main()
{
	
	//while (1)
	//{
	//	string bit;
	//	int one = 0;
	//	
	//	cin >> bit;

	//	if (bit == "#")
	//		return 0;

	//	for (int i = bit.length() - 2; i >= 0; i--)
	//	{
	//		
	//		if (bit[i] == '1')
	//			one++;
	//		
	//	}

	//	if (one % 2 == 0)
	//	{
	//		if (bit[bit.length() - 1] == 'e')
	//		{
	//			bit[bit.length() - 1] = '0';
	//		}
	//		else
	//		{
	//			bit[bit.length() - 1] = '1';
	//		}
	//	}
	//	else
	//	{
	//		if (bit[bit.length() - 1] == 'e')
	//		{
	//			bit[bit.length() - 1] = '1';
	//		}
	//		else
	//		{
	//			bit[bit.length() - 1] = '0';
	//		}
	//	}
	//	cout << bit << '\n';
	//}

	/*double A, B;
	cin >> A >> B;
	double M = (B - A) / 400.0;
	double POW = 1.0 / (1.0 + pow(10, M));
	cout << POW;*/

	/*double N, B, M;
	while (cin >> N >> B >> M)
	{
		int year = 0;
		double ratio = B * pow(100, -1);
		double sum = N;
		while (sum < M)
		{
			sum += N * ratio;
			N = sum;
			year++;
		}
		cout << year << '\n';
	}*/
	
	//int N;
	//cin >> N;

	//for (int i = 0; i < N; i++)
	//{
	//	string question;
	//	int front, back;
	//	cin >> question;

	//	if (question == "P+NP")
	//	{
	//		cout << "skipped\n";
	//		continue;
	//	}
	//		
	//	int oper = question.find("+");
	//	front = stoi(question.substr(0, oper));
	//	back = stoi(question.substr(oper + 1));

	//	cout << front + back << '\n';
	//}

	//int n;
	//cin >> n;
	//cin.ignore();

	//for (int i = 0; i < n; i++)
	//{
	//	string hero;
	//	int g = 0;
	//	int b = 0;

	//	
	//	getline(cin, hero);

	//	for (auto it = hero.begin(); it != hero.end(); it++)
	//	{
	//		if (*it == 'B' || *it == 'b')
	//			b++;
	//		else if (*it == 'G' || *it == 'g')
	//			g++;
	//	}

	//	if (g > b)
	//		cout << hero << " is GOOD\n";
	//	else if (b > g)
	//		cout << hero << " is A BADDY\n";
	//	else
	//		cout << hero << " is NEUTRAL\n";
	//}

	//while (1)
	//{
	//	int n;
	//	cin >> n;

	//	if (n == 0)
	//		return 0;

	//	int* num = new int[n];
	//	for (int i = 0; i < n; i++)
	//	{
	//		cin >> num[i];
	//	}

	//	int i = 0;
	//	while (i < n)
	//	{
	//		if (num[i] == num[i + 1]) {}
	//		else
	//			cout << num[i] << ' ';

	//		i++;
	//	}
	//	cout << "$\n";
	//	delete[] num;
	//}
	
	/*string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'D')
			s[i] -= 3;
		else
			s[i] += 23;
	}
	cout << s;*/
	
	int caseNum = 1;
	
	/*while (1)
	{
		int a = 0, b = 0;
		string oper = " ";
		bool result;
		cin >> a >> oper >> b;
		
		if (oper == "E")
			return 0;

		if (oper == ">")
		{
			result = (a > b);
		}
		else if (oper == ">=")
		{
			result = (a >= b);
		}
		else if (oper == "<")
		{
			result = (a < b);
		}
		else if (oper == "<=")
		{
			result = (a <= b);
		}
		else if (oper == "==")
		{
			result = (a == b);
		}
		else if (oper == "!=")
		{
			result = (a != b);
		}
		
		if (result)
			cout << "Case " << caseNum << ": true\n";
		else
			cout << "Case " << caseNum << ": false\n";

		caseNum++;
	}*/

	//string dial;
	//cin >> dial;
	//// UNUCIC
	//int totalTime = 0;

	//for (int i = 0; i < dial.size(); i++)
	//{
	//	if (dial[i] <= 'C')
	//		totalTime += 3;
	//	else if (dial[i] <= 'F')
	//		totalTime += 4;
	//	else if (dial[i] <= 'I')
	//		totalTime += 5;
	//	else if (dial[i] <= 'L')
	//		totalTime += 6;
	//	else if (dial[i] <= 'O')
	//		totalTime += 7;
	//	else if (dial[i] <= 'S')
	//		totalTime += 8;
	//	else if (dial[i] <= 'V')
	//		totalTime += 9;
	//	else
	//		totalTime += 10;
	//}
	//cout << totalTime;
	
	//int n;
	//cin >> n;

	//int a = 0, b = 0, c = 0;
	//int value = 0;
	//vector<int> cds;

	//if (n == 2)
	//{
	//	cin >> a >> b;
	//	value = gcd(a, b);
	//}
	//else
	//{ 
	//	cin >> a >> b >> c;
	//	value = gcd_three(a, b, c);
	//}

	//cds = cd(value);

	//sort(cds.begin(), cds.end());

	//for (int i = 0; i < cds.size(); i++)
	//	cout << cds[i] << '\n';

	//while (1)
	//{
	//	string s; // a = 97 
	//	getline(cin, s);
	//	bool zero = false;

	//	if (s == "*")
	//		return 0;

	//	int alphabet[26] = { 0 };
	//	for (char ch : s)
	//	{
	//		if (ch == ' ')
	//			continue;

	//		alphabet[ch - 'a']++;
	//	}

	//	for (int i : alphabet)
	//	{
	//		if (i == 0)
	//			zero = true;
	//	}

	//	if (zero)
	//		cout << "N\n";
	//	else
	//		cout << "Y\n";
	//}

	//string music = "CD|EC|CD|EC|EF|G|EF|G|GAGF|EC|GAGF|EC|CG|C|CG|C";
	/*string music = "AEB|C";
	
	istringstream iss(music);
	string token;

	int cmajor = 0;
	int aminor = 0;
	while (getline(iss, token, '|'))
	{
		if (token[0] == 'A' || token[0] == 'D' || token[0] == 'E')
			aminor++;
		else if (token[0] == 'C' || token[0] == 'F' || token[0] == 'G')
			cmajor++;
	}
	char last = token.back();

	if (cmajor > aminor)
		cout << "C-major";
	else if (cmajor < aminor)
		cout << "A-minor";
	else if (cmajor == aminor)
	{
		if (last == 'A' || last == 'D' || last == 'E')
			cout << "A-minor";
		else if (last == 'C' || last == 'G' || last == 'F')
			cout << "C-major";
	}*/
	
	//int N;
	//cin >> N;

	//vector<int> realDivs;

	//for (int i = 0; i < N; i++)
	//{
	//	int num;
	//	cin >> num;
	//	realDivs.push_back(num);
	//}
	//sort(realDivs.begin(), realDivs.end());

	//int len = realDivs.size();

	//if (N == 1)
	//	cout << realDivs[0] * realDivs[0];
	//else if (N >= 2)
	//	cout << realDivs[0] * realDivs[len - 1];

	//int N;
	//cin >> N;
	//int origin = N;
	//int front;
	//int back;
	//int add;
	//int newNum;
	//int cycle = 0;

	///*if (N == 0)
	//{
	//	cout << 1;
	//	return 0;
	//}*/

	//while (1)
	//{
	//	if (N < 10)
	//	{
	//		front = 0;
	//		back = N;
	//	}
	//	else
	//	{
	//		front = N / 10;
	//		back = N % 10;
	//	}
	//	
	//	add = front + back;
	//	
	//	if (add < 10)
	//	{
	//		newNum = back * 10 + add;
	//	}
	//	else
	//	{
	//		newNum = back * 10 + add % 10;
	//	}

	//	cycle++;

	//	if (newNum == origin)
	//	{
	//		cout << cycle;
	//		return 0;
	//	}
	//	else
	//		N = newNum;
	//}
	
	//int A, B;
	//int sum = 0;
	//cin >> A >> B;

	//int* arr = new int[B];
	//int val = 1;

	//for (int i = 0; i < B;)
	//{
	//	for (int j = 0; j < val && j < B; j++)
	//		arr[i++] = val;
	//	val++;
	//}

	//for (int i = A - 1; i < B; i++)
	//	sum += arr[i];

	//cout << sum;
	
	//string name;
	//int N;
	//int maxPercent = 0;
	//vector<pair<string, int>> team;

	//cin >> name;
	//cin >> N;

	//for (int i = 0; i < N; i++)
	//{
	//	string teamName;
	//	cin >> teamName;

	//	if (N == 1)
	//	{
	//		cout << teamName;
	//		return 0;
	//	}

	//	team.push_back(make_pair(teamName, valueLOVE(name, teamName)));
	//	if (maxPercent < team[i].second)
	//		maxPercent = team[i].second;
	//}

	//sort(team.begin(), team.end());

	//for (pair<string, int> p : team)
	//{
	//	if (p.second == maxPercent)
	//	{
	//		cout << p.first;
	//		return 0;
	//	}
	//}


	/*string X, Y;
	cin >> X >> Y;

	cout << revNum(to_string(revNum(X) + revNum(Y)));*/

	//int N;
	//cin >> N;
	//int max = 4;
	//

	//for (int i = 4; i <= N; i++)
	//{
	//	bool isTrue = true;
	//	for (char j : to_string(i))
	//	{
	//		if (j != '4' && j != '7')
	//		{
	//			isTrue = false;
	//			break;
	//		}
	//		else
	//			isTrue = true;
	//	}
	//	if (isTrue)
	//	{
	//		if (max < i)
	//			max = i;
	//	}
	//}
	//cout << max;

	int N;
	cin >> N;
	int A, B;
	cin >> A >> B;
	
	
}