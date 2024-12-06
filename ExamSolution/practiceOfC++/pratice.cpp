#include <algorithm>
#include <cctype>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <set>
#include <numeric>
#include <unordered_set>
#include <climits>
//int board[1002][1002];

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

int triangleNum(int T)
{
	int num;
	num = T * (T + 1) / 2;
	return num;
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
	
	/*int N;
	string keyward = "Simon says";
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++)
	{
		string S;
		string result;
		getline(cin, S);
		
		if (S.find(keyward) != string::npos)
		{
			result = S.substr(S.find(keyward) + keyward.length());
			cout << result << '\n';
		}
	}*/
	
	//int N;
	//cin >> N;
	/*map<string, int> captin;

	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;

		if (name.length() == 3)
		{
			captin.insert({ name, i });
		}
	}

	cout << captin.begin()->first;*/

	//vector<string> captin;

	//for (int i = 0; i < N; i++)
	//{
	//	string name;
	//	cin >> name;

	//	if (name.length() == 3)
	//	{
	//		captin.push_back(name);
	//	}
	//}

	//sort(captin.begin(), captin.end());

	//cout << captin[0];

	// 1월 1일은 월요일
	// 1월 1일 -> 1
	// 1 2 3 4 5 6 7
	/*int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int mon, day;
	cin >> mon >> day;
	int result = 0;
	
	for (int i = 0; i < mon; i++)
	{
		result += month[i];
	}

	result = (result + day) % 7;

	switch (result)
	{
	case 1: 
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	case 0:
		cout << "SUN";
		break;
	}*/
	

	/*int N;
	int x, y, w, h;
	
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> x >> y >> w >> h;
		for (int a = x; a < x + w; a++)
		{
			for (int b = y; b < y + h; b++)
			{
				board[a][b] = i;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		for (int a = 0; a < 1002; a++)
		{
			for (int b = 0; b < 1002; b++)
			{
				if (board[a][b] == i)
					sum++;
			}
		}
		cout << sum << '\n';
	}*/
	
	/*double A = 25;
	double B = 7;
	double result = A / B;
	int N = 5;
	cout << setprecision(20) << A / B << endl;*/
	
	/*int N;
	string search;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string fileName;
		cin >> fileName;

		if (i == 0)
		{
			search = fileName;
		}
		else
		{
			for (int j = 0; j < fileName.size(); j++)
			{
				if (search[j] != fileName[j])
					search[j] = '?';
			}
		}
	}
	cout << search;*/

	/*int a, b, c, d, e;
	int count = 0;
	int mostlyMultiple = 0;
	cin >> a >> b >> c >> d >> e;

	while (count < 3)
	{
		count = 0;
		mostlyMultiple++;

		if (mostlyMultiple % a == 0)
			count++;

		if (mostlyMultiple % b == 0)
			count++;

		if (mostlyMultiple % c == 0)
			count++;

		if (mostlyMultiple % d == 0)
			count++;

		if (mostlyMultiple % e == 0)
			count++;
	}
	cout << mostlyMultiple;*/

	//string binary;
	//string octal;
	//int decimal = 0;
	//cin >> binary;
	//
	//reverse(binary.begin(), binary.end());
	//
	//for (int i = 0; i < binary.size(); i++)
	//{
	//	if (binary[i] == '1')
	//		decimal += pow(2, i);
	//}

	//while (decimal != 0)
	//{
	//	int num;
	//	num = decimal % 8;
	//	decimal /= 8;
	//	octal += to_string(num);
	//}
	//reverse(octal.begin(), octal.end());
	//cout << octal;

	/*int a, b;
	cin >> a >> b;
	int defense = a - (a * b / 100);
	if (defense >= 100)
		cout << 0;
	else
		cout << 1;*/

	// 조건 내일 기온 영하이고 풍속 초당 10 이상
	// 내일의 기온이 오늘보다 낮을 때
	// 내일의 풍속이 오늘보다 높을 때
	// 어떤 것도 충족되지 않을 때
	
	/*int t1, t2, v1, v2;
	cin >> t1 >> v1 >> t2 >> v2;

	if (t2 < 0 && v2 >= 10)
		cout << "A storm warning for tomorrow! Be careful and stay home if possible!";
	else if (t2 < t1)
		cout << "MCHS warns! Low temperature is expected tomorrow.";
	else if (v2 > v1)
		cout << "MCHS warns! Strong wind is expected tomorrow.";
	else
		cout << "No message";*/

	/*int n;
	cin >> n;
	int count = 0;

	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			if (n - i - j == 0)
				count++;
		}
	}
	cout << count;*/
	
	// i 미터를 가면 i^2의 에너지를 소모함

	/*int n;
	int energy = 0;
	int start = 0;
	int next = 0;
	int previous = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			cin >> start;

		else if (i == 1)
		{
			cin >> next;
			energy += (next - start) * (next - start);
			previous = next;
		}
		
		else
		{
			cin >> next;
			energy += (next - previous) * (next - previous);
			previous = next;
		}
	}
	cout << energy;*/

	/*int N;
	int score = 0;
	int bonusScore = 0;
	string result;
	cin >> N >> result;

	for (int i = 0; i < N; i++)
	{
		int baseScore = i + 1;
		if (result[i] == 'O')
		{
			score += baseScore + bonusScore;
			bonusScore++;
		}
		else
		{
			bonusScore = 0;
		}
	}
	cout << score;*/
	
	/*int N;
	cin >> N;
	vector<int> interest(N);
	vector<int> isRegistered(N);
	int totalInterest = 0;
	int totalUnregistered = 0;
	
	for (int i = 0; i < N; i++)
	{
		cin >> interest[i];
		totalInterest += interest[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> isRegistered[i];

		if (!isRegistered[i])
			totalUnregistered += interest[i];
	}
	cout << totalInterest << '\n' << totalUnregistered;*/

	//vector<int> height(9);
	//int a = 0;
	//int b = 0;
	//int sum = 0;

	//for (int i = 0; i < 9; i++)
	//{
	//	cin >> height[i];
	//	sum += height[i];
	//}

	//sort(height.begin(), height.end());

	//for (int i = 0; i < 9; i++)
	//{
	//	for (int j = 0; j < 9; j++)
	//	{
	//		if (i != j && (height[i] + height[j] == sum - 100))
	//		{
	//			a = i;
	//			b = j;
	//			break;
	//		}
	//	}
	//	if (a != 0 || b != 0)
	//		break;
	//}

	//for (int i = 0; i < 9; i++)
	//{
	//	if (i != a && i != b)
	//		cout << height[i] << '\n';
	//}
	
	/*int N, K;
	int max = 0;
	cin >> N >> K;
	vector<int> temperature(N);

	for (int i = 0; i < N; i++)
	{
		cin >> temperature[i];
	}
	
	for (int i = 0; i <= N - K; i++)
	{
		int sum = temperature[i];
		for (int j = i + 1; j < i + K; j++)
		{
			sum += temperature[j];
			
		}

		if (i == 0)
			max = sum;

		if (max < sum)
			max = sum;
	}
	cout << max;*/
	
	/*int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		vector<int> A(10);
		int count = 0;

		for (int j = 0; j < 10; j++)
		{
			cin >> A[j];
		}

		sort(A.begin(), A.end(), greater<>());

		for (int k = 0; k < 10; k++)
		{
			if (A[k] > A[k + 1])
				count++;

			if (count == 2)
			{
				cout << A[k + 1] << '\n';
				break;
			}
		}
	}*/

	/*string source;
	string BUG = "BUG";
	
	while(getline(cin, source))
	{
		while (source.find(BUG) != string::npos)
		{
			source.erase(source.find(BUG), 3);
		}

		cout << source << endl;
	}*/

	/*int N;
	cin >> N;
	
	string source;
	cin.ignore();
	getline(cin, source);

	int R = 0;
	
	for (int i = 0; i < source.size(); i++)
	{
		if (source[i] != '#')
			R++;
	}
	double X = (double)R / (double)source.size() * 100;
	double percent = round(X);

	cout << "Efficiency ratio is " << X << "%\n";*/

	//int C;
	//cin >> C;
	//cout << fixed << setprecision(3);

	//for (int i = 0; i < C; i++)
	//{
	//	int N;
	//	int sum = 0;
	//	double average = 0;
	//	int up = 0;
	//	cin >> N;
	//	vector<int> score(N);

	//	for (int j = 0; j < N; j++)
	//	{
	//		cin >> score[j];
	//		sum += score[j];
	//	}
	//	
	//	average = sum / N;

	//	for (int k = 0; k < N; k++)
	//	{
	//		if (score[k] > average)
	//			up++;
	//	}

	//	cout << up / (double)N * 100 << "%\n";
	//}
	
	//double speed;
	//int weight;
	//int strength;

	//while (1)
	//{
	//	cin >> speed >> weight >> strength;
	//	if (speed == 0 && weight == 0 && strength == 0)
	//		return 0;

	//	bool positionFound = false;

	//	if (speed <= 4.5)
	//	{
	//		if (weight >= 150)
	//		{
	//			if (strength >= 200)
	//			{
	//				cout << "Wide Receiver ";
	//				positionFound = true;
	//			}
	//			
	//		}
	//	}
	//	
	//	if (speed <= 5.0)
	//	{
	//		if (weight >= 200)
	//		{
	//			if (strength >= 300)
	//			{
	//				cout << "Quarterback ";
	//				positionFound = true;
	//			}
	//				
	//		}
	//	}

	//	if (speed <= 6.0)
	//	{
	//		if (weight >= 300)
	//		{
	//			if (strength >= 500)
	//			{
	//				cout << "Lineman ";
	//				positionFound = true;
	//			}
	//				
	//		}
	//	}
	//	
	//	if (!positionFound)
	//		cout << "No position";

	//	cout << '\n';
	//}

	//int T;
	//cin >> T;
	//int totalA = 0;
	//int totalB = 0;
	//int totalC = 0;
	//int setA, setB, setC;
	//
	//for (int i = 0; i < T; i++)
	//{
	//	cin >> setA >> setB >> setC;
	//	totalA += setA;
	//	totalB += setB;
	//	totalC += setC;
	//	int minTotal = min(totalA, totalB, totalC);

	//	if (totalA >= 30 && totalB >= 30 && totalC >= 30)
	//	{
	//		cout << minTotal << '\n';
	//		totalA -= minTotal;
	//		totalB -= minTotal;
	//		totalC -= minTotal;
	//	}
	//	else
	//		cout << "NO\n";
	//}

	//int T;
	//cin >> T;

	//for (int i = 0; i < T; i++)
	//{
	//	string A, B;
	//	cin >> A >> B;

	//	if (A.size() != B.size())
	//	{
	//		cout << A << " & " << B << " are NOT anagrams.\n";
	//		continue;
	//	}

	//	string beforeSortA = A;
	//	string beforeSortB = B;

	//	sort(A.begin(), A.end());
	//	sort(B.begin(), B.end());

	//	if (A == B)
	//		cout << beforeSortA << " & " << beforeSortB << " are anagrams.\n";
	//	else
	//		cout << beforeSortA << " & " << beforeSortB << " are NOT anagrams.\n";
	//}

	//int n;
	//
	//while (1)
	//{
	//	cin >> n;
	//	
	//	if (n == -1)
	//		return 0;

	//	int sum = 0; // n의 약수들의 합
	//	vector<int> divisor; // 약수들을 담을 배열
	//	
	//	for (int i = 1; i * i < n; i++)
	//	{
	//		if (n % i == 0)
	//		{
	//			divisor.push_back(i);
	//			sum += i;
	//			if (i != n / i && n / i != n)
	//			{
	//				divisor.push_back(n / i);
	//				sum += n / i;
	//			}
	//		}
	//	}

	//	if (sum == n) // n이 완전수인가
	//	{
	//		sort(divisor.begin(), divisor.end());
	//		cout << n << " = ";
	//		for (int i = 0; i < divisor.size(); i++)
	//		{
	//			cout << divisor[i];
	//			if (i != divisor.size() - 1)
	//				cout << " + ";
	//		}
	//		cout << '\n';
	//	}
	//	else
	//		cout << n << " is NOT perfect.\n";
	//}
	

	//string S;
	//string happy = ":-)";
	//string sad = ":-(";
	//int hap = 0;
	//int sa = 0;
	//getline(cin, S);

	//size_t pos_happy = S.find(happy);
	//size_t pos_sad = S.find(sad);
	//
	//while (pos_happy != string::npos)
	//{
	//	hap++;
	//	pos_happy = S.find(happy, pos_happy + 1);
	//}

	//while (pos_sad != string::npos)
	//{
	//	sa++;
	//	pos_sad = S.find(sad, pos_sad + 1);
	//}

	//if (hap == 0 && sa == 0)
	//	cout << "none";
	//else if (hap - sa == 0)
	//	cout << "unsure";
	//else if (hap - sa > 0)
	//	cout << "happy";
	//else
	//	cout << "sad";

	//string S;
	//string input;
	//int sum = 0;

	//while (cin >> input)
	//{
	//	S += input;
	//}

	//int START = 0;
	//int END = S.find(',');
	//int num;

	//while (END != string::npos)
	//{
	//	num = stoi(S.substr(START, END - START));
	//	sum += num;
	//	START = END + 1;
	//	END = S.find(',', START);
	//}

	//if (START < S.size())
	//{
	//	num = stoi(S.substr(START));
	//	sum += num;
	//}

	//cout << sum;

	/*int N, B;
	cin >> N >> B;
	string convert;
	
	while (N != 0)
	{
		int n = N % B;
		N /= B;
		string str;

		if (n > 9)
		{
			str = n - 10 + 'A';
		}
		else
			str = to_string(n);

		convert += str;
		
	}
	reverse(convert.begin(), convert.end());
	cout << convert;*/

	//int T;
	//int N, M;
	//cin >> T;

	//for (int i = 0; i < T; i++)
	//{
	//	cin >> N >> M;
	//	int count = 0;
	//	for (int j = N; j <= M; j++)
	//	{
	//		for (char c : to_string(j))
	//		{
	//			if (c == '0')
	//				count++;
	//		}
	//	}
	//	cout << count << '\n';
	//}

	/*int N;
	int decimal = 0;
	string binary;
	cin >> N;

	while (N != 0)
	{
		string str = to_string(N % 2);
		binary.insert(0, str);
		N /= 2;
	}

	for (int i = 0; i < binary.size(); i++)
	{
		if (binary[i] == '1')
			decimal += pow(2, i);
	}

	cout << decimal;*/

	/*int N, M;
	vector<string> origin;
	vector<string> magnify;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		origin.push_back(input);
	}

	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		magnify.push_back(input);
	}

	vector<string> convert(N);
	bool isEyfa = true;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			convert[i] += origin[i][j];
			convert[i] += origin[i][j];
		}
		
		if (convert[i] != magnify[i])
		{
			isEyfa = false;
			break;
		}
	}

	if (isEyfa)
		cout << "Eyfa";
	else
		cout << "Not Eyfa";*/


	//int N;
	//int i = 2;
	//cin >> N;

	//if (N == 1)
	//	return 0;

	//while (N != 1)
	//{
	//	if (N % i == 0)
	//	{
	//		cout << i << '\n';
	//		N /= i;
	//	}
	//	else
	//		i++;
	//}

	//string S;
	//vector<int> finger(8, 0);

	//cin >> S;

	//for (char c : S)
	//{
	//	switch (c)
	//	{
	//	case'1':case'Q':case'A':case'Z':
	//		finger[0]++;
	//		break;
	//	case'2':case'W':case'S':case'X':
	//		finger[1]++;
	//		break;
	//	case'3':case'E':case'D':case'C':
	//		finger[2]++;
	//		break;
	//	case'4':case'5':case'R':case'T':
	//	case'F':case'G':case'V':case'B':
	//		finger[3]++;
	//		break;
	//	case'6':case'7':case'Y':case'U':
	//	case'H':case'J':case'N':case'M':
	//		finger[4]++;
	//		break;
	//	case'8':case'I':case'K':case',':
	//		finger[5]++;
	//		break;
	//	case'9':case'O':case'L':case'.':
	//		finger[6]++;
	//		break;
	//	case'0':case'-':case'=':case'P':
	//	case'[':case']':case';':case'\'':
	//	case'/':
	//		finger[7]++;
	//		break;
	//	}
	//}

	//for (int i = 0; i < 8; i++)
	//	cout << finger[i] << '\n';

	//string A;
	//string B;
	//int i = 1;

	//while (1)
	//{
	//	cin >> A >> B;

	//	if (A == "END" && B == "END")
	//		return 0;

	//	if (A.size() != B.size())
	//	{
	//		cout << "Case " << i << ": different\n";
	//		i++;
	//	}
	//	else
	//	{
	//		sort(A.begin(), A.end());
	//		sort(B.begin(), B.end());
	//		if (A == B)
	//		{
	//			cout << "Case " << i << ": same\n";
	//			i++;
	//		}
	//		else
	//		{
	//			cout << "Case " << i << ": different\n";
	//			i++;
	//		}
	//	}
	//}

	// 1 1 2 2 3 3
	// 1 2 3
	// 1 2
	// 결과
	
	//int A, B, C;
	//cin >> A >> B >> C;
	//int result = A ^ B;

	//for (int i = 0; i < C-1; i++)
	//{
	//	result ^= B;
	//}

	//cout << result;
	
	//int N;
	//int n;
	//string pass;
	//string plainText;
	//int upper = 'A' - 1;
	//int lower = 'a' - 1;
	//cin >> N;

	//for (int i = 0; i < N; i++)
	//{
	//	cin >> n;
	//	if (n == 0)
	//		pass.push_back(' ');
	//	else if(n < 27)
	//		pass.push_back(upper+n);
	//	else
	//	{
	//		n -= 26;
	//		pass.push_back(lower + n);
	//	}
	//}
	//
	//cin.ignore();
	//getline(cin, plainText);
	//sort(pass.begin(), pass.end());
	//sort(plainText.begin(), plainText.end());

	//if (pass == plainText)
	//	cout << 'y';
	//else
	//	cout << 'n';
	
	//int T;
	//int N;
	//int sum;
	//
	//cin >> T;
	//
	//for (int i = 0; i < T; i++)
	//{
	//	unordered_set<int> mulitple;
	//	cin >> N;

	//	for (int a = 3; a <= N; a += 3)
	//		mulitple.insert(a);
	//	
	//	for (int b = 7; b <= N; b += 7)
	//		mulitple.insert(b);
	//	
	//	sum = accumulate(mulitple.begin(), mulitple.end(), 0);
	//	cout << sum << '\n';
	//}
	
	/*int n;
	int a, b;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		int multiple = a * b;

		while (b != 0)
		{
			int temp = b;
			b = a % b;
			a = temp;
		}

		cout << multiple / a << '\n';
	}*/

	//int M;
	//cin >> M;
	//vector<int> haveCards;

	//for (int i = 0; i < M; i++)
	//{
	//	int m;
	//	cin >> m;
	//	haveCards.push_back(m);
	//}
	//sort(haveCards.begin(), haveCards.end());
	//
	//int N;
	//cin >> N;
	//vector<int> find;

	//for (int i = 0; i < N; i++)
	//{
	//	int n;
	//	cin >> n;
	//	find.push_back(n);
	//}

	//for (int i = 0; i < N; i++)
	//{
	//	auto first = lower_bound(haveCards.begin(), haveCards.end(), find[i]);
	//	auto last = upper_bound(haveCards.begin(), haveCards.end(), find[i]);
	//	int count = last - first;
	//	cout << count << ' ';
	//}

	//int T;
	//cin >> T;
	//string brakets;

	//int openCount;
	//int closeCount;

	//for (int i = 0; i < T; i++)
	//{
	//	cin >> brakets;
	//	openCount = count(brakets.begin(), brakets.end(), '(');
	//	closeCount = count(brakets.begin(), brakets.end(), ')');
	//	bool isVPS = false;

	//	if (openCount != closeCount)
	//	{
	//		cout << "NO\n";
	//		continue;
	//	}

	//	openCount = 0;
	//	closeCount = 0;

	//	for (char ch : brakets)
	//	{
	//		if (ch == '(')
	//			openCount++;
	//		else
	//			closeCount++;

	//		if (openCount < closeCount)
	//		{
	//			isVPS = false;
	//			break;
	//		}
	//	}

	//	if (openCount == closeCount)
	//		isVPS = true;

	//	if (isVPS)
	//		cout << "YES\n";
	//	else
	//		cout << "NO\n";
	//}

	/*int N, I;
	cin >> N >> I;
	vector<string> handles;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		handles.push_back(s);
	}
	sort(handles.begin(), handles.end());

	cout << handles[I - 1];*/

	//int a, x, b, y;
	//int T;
	//cin >> a >> x >> b >> y >> T;

	//int day_a = (T - 30) * x;
	//int day_b = (T - 45) * y;

	//if (day_a < 0)
	//	day_a = 0;
	//if (day_b < 0)
	//	day_b = 0;

	//cout << a + day_a * 21 << ' ' << b + day_b * 21;

	//int T;
	//string S;
	//cin >> T;
	//cin.ignore();

	//for (int i = 0; i < T; i++)
	//{
	//	getline(cin, S);
	//	if (S[S.size() - 1] != '.')
	//	{
	//		S.push_back('.');
	//		cout << S << '\n';
	//	}
	//	else
	//		cout << S << '\n';
	//}
	
	//int N;
	//int sum;
	//int count = 0;
	//cin >> N;

	//for (int i = 1; i <= N; i++)
	//{
	//	sum = 0;
	//	int temp = i;
	//	while (temp != 0)
	//	{
	//		sum += temp % 10;
	//		temp /= 10;
	//	}

	//	if (i % sum == 0)
	//		count++;
	//}

	//cout << count;
	
	//int x, y, N;
	//int tx, ty; 
	//int minX, minY;
	//int minDistance = 2147483647;
	//cin >> x >> y >> N;

	//for (int i = 0; i < N; i++)
	//{
	//	cin >> tx >> ty;
	//	int distance = abs(x - tx) + abs(y - ty);

	//	if (minDistance > distance)
	//	{
	//		minDistance = distance;
	//		minX = tx;
	//		minY = ty;
	//	}
	//}
	//cout << minX << ' ' << minY;
	
	//int score = 0;
	//vector<int> scoreW;
	//vector<int> scoreK;

	//for (int i = 0; i < 20; i++)
	//{
	//	cin >> score;
	//	if (i < 10)
	//		scoreW.push_back(score);
	//	else
	//		scoreK.push_back(score);
	//}
	//sort(scoreW.begin(), scoreW.end());
	//sort(scoreK.begin(), scoreK.end());

	//int sumW = scoreW[7] + scoreW[8] + scoreW[9];
	//int sumK = scoreK[7] + scoreK[8] + scoreK[9];

	//cout << sumW << ' ' << sumK;

	//int n;
	//string S;
	//vector<int> numbers;
	//cin >> n;
	//
	//while (n > 0)
	//{
	//	numbers.push_back(n % 10);
	//	n /= 10;
	//}
	//sort(numbers.begin(), numbers.end(), greater<int>());

	//for (int i = 0; i < numbers.size(); i++)
	//{
	//	S.push_back(numbers[i] + '0');
	//}

	//cout << S;

	//int X;
	//int Y;
	//int sum = 0;
	//int convert = 0;
	//cin >> X;


	//while (1)
	//{
	//	while (X > 0)
	//	{
	//		sum += X % 10;
	//		X /= 10;
	//	}
	//	convert++;

	//	if (sum > 9)
	//	{
	//		X = sum;
	//		sum = 0;
	//	}
	//	else
	//	{
	//		Y = sum;
	//		break;
	//	}
	//}
	//
	//cout << convert << endl;
	//if (Y % 3 == 0)
	//	cout << "YES";
	//else
	//	cout << "NO";
	
	//int T;
	//string password;
	//cin >> T;
	//cin.ignore();

	//for (int i = 0; i < T; i++)
	//{
	//	int maxCount = 0;
	//	char maxChar;
	//	bool multiMax = false;
	//	unordered_set<char> s;
	//	getline(cin, password);
	//	
	//	for (int j = 0; j < password.size(); j++)
	//	{
	//		if (password[j] != ' ')
	//			s.insert(password[j]);
	//	}

	//	for (auto it = s.begin(); it != s.end(); it++)
	//	{
	//		int _count = count(password.begin(), password.end(), *it);

	//		if (_count > maxCount)
	//		{
	//			maxCount = _count;
	//			multiMax = false;
	//			maxChar = *it;
	//		}
	//		else if(_count == maxCount)
	//		{
	//			multiMax = true;
	//		}
	//	}

	//	if (multiMax)
	//		cout << "?\n";
	//	else
	//		cout << maxChar << endl;
	//}


	//int n;
	//cin >> n;
	//string student;
	//map<string, int> popularity;
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> student;
	//	popularity.insert({student, 0});
	//}

	//cin.ignore();
	//while (cin >> student)
	//{
	//	auto it = popularity.find(student);
	//	it->second++;
	//}

	//vector<pair<string, int>> sorted(popularity.begin(), popularity.end());
	//sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b) {return a.second > b.second;});

	//for (const auto& pair : sorted)
	//{
	//	cout << pair.first << ' ' << pair.second << '\n';
	//}

	//int n;
	//int p;
	//int k;
	//vector<int> papers;
	//cin >> n;

	//for (int i = 0; i < n; i++)
	//{
	//	cin >> p;
	//	papers.push_back(p);
	//}

	//int T1, F1, S1, P1, C1;
	//int T2, F2, S2, P2, C2;
	//int sum1;
	//int sum2;

	//cin >> T1 >> F1 >> S1 >> P1 >> C1;
	//cin >> T2 >> F2 >> S2 >> P2 >> C2;

	//sum1 = (T1 * 6) + (F1 * 3) + (S1 * 2) + (P1 * 1) + (C1* 2);
	//sum2 = (T2 * 6) + (F2 * 3) + (S2 * 2) + (P2 * 1) + (C2 * 2);
	//cout << sum1 << ' ' << sum2;
	
	//long long N;
	//cin >> N;

	//if (N >= SHRT_MIN && N <= SHRT_MAX)
	//	cout << "short";
	//else if (N >= INT_MIN && N <= INT_MAX)
	//	cout << "int";
	//else
	//	cout << "long long";

	//int T;
	//cin >> T;
	//
	//for (int i = 0; i < T; i++)
	//{
	//	int result = 0;
	//	int N, d;
	//	cin >> N;

	//	for (int j = 0; j < N; j++)
	//	{
	//		cin >> d;
	//		result += (d * 100);
	//	}

	//	if (result > 0)
	//		cout << "Right\n";
	//	else if (result == 0)
	//		cout << "Equilibrium\n";
	//	else
	//		cout << "Left\n";
	//}

	//int N;
	//int score = 0;
	//cin >> N;

	//if (N == 1)
	//{
	//	cout << 0;
	//	return 0;
	//}

	//while (N != 1)
	//{
	//	if (N % 2 != 0)
	//		N = N * 3 + 1;
	//	else
	//		N /= 2;

	//	score++;
	//}
	//cout << score;

	//int N, M, K;
	//int num;
	//vector<vector<int>> A;
	//vector<vector<int>> B;
	//vector<vector<int>> result;

	//cin >> N >> M;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < M; j++)
	//	{
	//		cin >> num;
	//		A[i].push_back(num);
	//	}
	//}

	//cin >> M >> K;

	//for (int i = 0; i < M; i++)
	//{
	//	for (int j = 0; j < K; j++)
	//	{
	//		cin >> num;
	//		B[i].push_back(num);
	//	}
	//}

	//// A의 행의 요소와 B의 열의 요소를 곱함?

	//for (int i = 0; i < N; i++)
	//{
	//	int sum = 0;
	//	for (int j = 0; j < K; j++)
	//	{
	//		sum += (A[i][j] * B[j][i]);
	//	}

	//	result[i].push_back(sum);
	//}

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < K; j++)
	//	{
	//		cout << result[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	//string normal;
	//string pass;

	//getline(cin, normal);
	//getline(cin, pass);

	//int length = pass.length();

	//for (int i = 0; i < normal.size(); i++)
	//{
	//	char ch;

	//	if (normal[i] == ' ')
	//	{
	//		ch = ' ';
	//		cout << ' ';
	//	}

	//	else if (normal[i] - pass[i % length] > 0)
	//	{
	//		ch = normal[i] - pass[i % length] + 96;
	//		cout << ch;
	//	}
	//		
	//	else
	//	{
	//		int temp = pass[i % length] - normal[i];
	//		ch = 'z' - temp;
	//		cout << ch;
	//	}
	//}

	//string A;
	//string B;
	//cin >> A >> B;
	//int size = A.size() > B.size() ? A.size() : B.size();

	//if (A.size() != B.size())
	//{
	//	int temp = abs(int(A.size() - B.size()));
	//	if (A.size() > B.size())
	//	{
	//		for (int i = 0; i < temp; i++)
	//			B = '0' + B;
	//	}
	//	else
	//	{
	//		for (int i = 0; i < temp; i++)
	//			A = '0' + A;
	//	}
	//}

	//for (int i = 0; i < size; i++)
	//{
	//	int num = (A[i] - '0') + (B[i] - '0');
	//	cout << num;
	//}

	//int N, R;
	//int _return;
	//vector<int> all;
	//cin >> N >> R;

	//if (N == R)
	//{
	//	for (int i = 0; i < N; i++)
	//		cin >> _return;

	//	cout << "* ";
	//	return 0;
	//}

	//for (int i = 0; i < N; i++)
	//	all.push_back(i + 1);

	//for (int i = 0; i < R; i++)
	//{
	//	cin >> _return;
	//	all[_return - 1] = 0;
	//}

	//for (int i = 0; i < N; i++)
	//{
	//	if (all[i] != 0)
	//		cout << all[i] << ' ';
	//}

	//int N;
	//string bit;
	//string deleted;
	//
	//cin >> N >> bit >> deleted;

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < bit.size(); j++)
	//	{
	//		if (bit[j] == '1')
	//			bit[j] = '0';
	//		else
	//			bit[j] = '1';
	//	}
	//}
	//
	//if (bit == deleted)
	//	cout << "Deletion succeeded";
	//else
	//	cout << "Deletion failed";

	/*string X;
	int num;
	cin >> X;

	if (X[0] == '0')
	{
		if (X[1] == 'x')
		{
			num = stoi(X, nullptr, 16);
		}
		else
		{
			num = stoi(X, nullptr, 8);
		}
		cout << num;
	}
	else
		cout << X;*/

	string A, B;
	cin >> A >> B;
	int n = A.size();
	int m = B.size();
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			result += (A[i] - '0')*(B[j] - '0');
		}
	}
	cout << result;
}	