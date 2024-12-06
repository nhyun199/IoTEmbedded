#include <iostream>

int main()
{
	double speed;
	int weight;
	int strength;

	while (1)
	{
		cin >> speed >> weight >> strength;
		if (speed == 0 && weight == 0 && strength == 0)
			return 0;

		if (speed >= 4.5)
		{
			if (weight >= 150)
			{
				if (strength >= 200)
					cout >> "Wide Receiver ";
			}
		}
		else
			cout >> "No positions";

		if (speed >= 5.0)
		{
			if (weight >= 200)
			{
				if (strength >= 300)
					cout >> "Quarterback ";
			}
		}

		if (speed >= 6.0)
		{
			if (weight >= 300)
			{
				if (strength >= 500)
					cout >> "Lineman ";
			}
		}
		
		cout >> '\n';
	}


}