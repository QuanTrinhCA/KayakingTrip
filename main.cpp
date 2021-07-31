#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

std::vector<int> getInput(int times)
{
	std::vector<int> input(times);
	std::string buffer;
	std::getline(std::cin, buffer);
	for (int i = 0; i < times; i++)
	{
		if (i < times - 1)
		{
			input[i] = stoi(buffer.substr(0, buffer.find(" ")));
			buffer.erase(0, buffer.find(" ") + 1);
		}
		else if (i == times -1)
		{
			input[i] = stoi(buffer.substr(0, buffer.length()));
		}
	}
	return input;
}

std::vector<int> routesNumCal(int stationNum)
{
	std::vector<int> routeNum(stationNum);
	routeNum[stationNum - 1] = 1;
	routeNum[stationNum - 2] = 1;
	routeNum[0] = 2;
	int temp{ 1 };
	for (int i{ stationNum - 3 }; i >= 1 ; i--)
	{
		temp = temp * 2;
		routeNum[i] = temp;
		routeNum[0] += temp;
	}
	return routeNum;
}

std::vector<std::vector<int>> routePlanner(std::vector<int> routeNum, int stationNum)
{
	std::vector<std::vector<int>> routes(routeNum[0]);
	int routeTracker{ 0 };
	int stationTracker{ 1 };
	int progressTracker{ 0 };

	for (int i{ 0 }; i < routeNum[0]; i++)
	{
		routes[i].push_back(1);
	}

	for (int i{ 0 }; i <= routeNum[0] && progressTracker != routeNum[0]; i++)
	{
		if (i == routeNum[0])
		{
			progressTracker = 0;
			for (int i2{ 0 }; i2 < routeNum[0]; i2++)
			{
				progressTracker += std::count(routes[i2].begin(), routes[i2].end(), 8);
				std::cout << progressTracker << "\n";
			}
			i = 0;
		}
		if (routes[i].back() != 8 && progressTracker != routeNum[0])
		{
			if (routeTracker == 0)
			{
				if (stationTracker == 8)
				{
					stationTracker = routes[i].back();
				}
				routeTracker = routeNum[stationTracker];
					stationTracker += 1;
			}
			routes[i].push_back(stationTracker);
			routeTracker -= 1;
		}
	}
	return routes;
}

std::vector<std::vector<int>> priceCal(std::vector<std::vector<int>> input, std::vector<std::vector<int>> routes)
{
	int base{ 0 };
	int result{ 1000000 };
	int tracker{ 0 };
	std::vector<std::vector<int>> output(2);
	for (int i{ 0 }; i < routes.size(); i++)
	{
		base = 0;
		for (int i2{ 0 }; i2 < routes[i].size() - 1; i2++)
		{
			base += input[routes[i][i2]][routes[i][i2 + 1] - routes[i][i2] - 1];
		}
		if (base < result)
		{
			tracker = i;
			result = base;
		}
	}
	output[0] = routes[tracker];
	output[1].push_back(result);
	return output;
}

int main()
{
	std::vector<std::vector<int>> input(1);
	std::vector<std::vector<int>> output(2);
	std::cout << "Please enter the input:\n";
	input[0] = getInput(1);
	input.resize(input[0][0]);
	for (int i{ 1 }; i < input[0][0]; i++)
	{
		input[i] = getInput(input[0][0] - i);
	}
	output = priceCal(input, routePlanner(routesNumCal(input[0][0]), input[0][0]));
	for (int i{ 0 }; i < output[0].size(); i++)
	{
		std::cout << std::to_string(output[0][i]) << " ";
	}
	std::cout << "\n" << output[1][0] << "\nPlease press enter to exit...\n";
	std::getchar();
	return EXIT_SUCCESS;
}