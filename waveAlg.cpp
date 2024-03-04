/*This program shows the action of the wave algorithm for finding the path from point A to point B.
Only the original field with barriers is displayed in the console. 
Next, we specify the position of point A, and then point B. 
If there is a barrier along the coordinate that we entered, then it is necessary to re-set the position of the point
In the file "out.txt "you can see every step of the algorithm. The path length is specified after the last step
*/
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>
#include <fstream>


int DRP_clone[25][25]{}; //If there is no way

int DRP[25][25] =
{
	{0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,0,0,0,0},
	{0,-1,0,0,0,0,0,0,0,0,-1,0,-1,0,0,0,-1,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,-1,-1,0,0,0,0,-1,0,0,0,-1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,-1,0,-1,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};


void print_DRP(int DRP[25][25])
{


	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			switch (DRP[i][j])
			{
			case 0:
				std::cout << std::setw(3) << std::right << (char)46;
				break;
			case -65:
				std::cout << std::setw(3) << std::right << (char)65;
				break;
			case -66:
				std::cout << std::setw(3) << std::right << (char)66;
				break;
			case -1:
				std::cout << std::setw(3) << std::right << (char)37;
				break;
			default:
				std::cout << std::setw(3) << std::right << DRP[i][j];
				break;
			}
		}
		std::cout << '\n';
	}
	std::cout << "\n\n\n";

};

void print_DRP_file(int DRP[25][25])
{
	std::ofstream file;

	file.open("out.log", std::ofstream::app);

	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			switch (DRP[i][j])
			{
			case 0:
				file << std::setw(3) << std::right << (char)46;
				break;
			case -65:
				file << std::setw(3) << std::right << (char)65;
				break;
			case -66:
				file << std::setw(3) << std::right << (char)66;
				break;
			case -1:
				file << std::setw(3) << std::right << (char)37;
				break;
			default:
				file << std::setw(3) << std::right << DRP[i][j];
				break;
			}
		}

		file << '\n';
	}
	file << "\n\n\n";
	file.close();
};

int getValue()
{
	while (true)
	{
		int value;
		std::cin >> value;

		if ((std::cin.fail()) || (value > 24) || (value < 0))
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cerr << "error please enter 0 to 24! \n";
		}
		else
			return value;
	}
}

bool equal_DRP(int DRP[25][25], int DRP_clone[25][25])
{
	bool flag{ true };
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			if (DRP[i][j] != DRP_clone[i][j])
				flag = false;
		}
	}
	return flag;
}


int main(int argc, char* argv[])
{

	print_DRP(DRP);

	print_DRP_file(DRP);

	//ввод А и В
	int A_x = 0;
	int A_y = 0;
	int B_x = 0;
	int B_y = 0;
	bool flag_A{ true };
	bool flag_B{ true };
	while (flag_A)
	{
		std::cout << "Point A \n";
		std::cout << "X:  ";
		A_x = getValue();
		std::cout << "Y:  ";
		A_y = getValue();

		if (DRP[A_x][A_y] < 0)
		{
			std::cout << "border error\n";
			continue;
		}

		DRP[A_x][A_y] = -65;
		flag_A = false;
	}
	while (flag_B)
	{
		std::cout << "Point B \n";
		std::cout << "X:  ";
		B_x = getValue();
		std::cout << "Y:  ";
		B_y = getValue();

		if (DRP[B_x][B_y] == DRP[A_x][A_y])
		{
			std::cout << "Points must have different coordinates\n";
			continue;
		}
		if (DRP[B_x][B_y] < 0)
		{
			std::cout << "border error\n";
			continue;
		}

		DRP[B_x][B_y] = -66;
		flag_B = false;
	}



	//точки рядом 
	if (DRP[A_x + 1][A_y] == -66 || DRP[A_x - 1][A_y] == -66 || DRP[A_x][A_y + 1] == -66 || DRP[A_x][A_y - 1] == -66)
	{
		//print_DRP(DRP);
		print_DRP_file(DRP);
		std::ofstream file;

		file.open("out.log", std::ofstream::app);

		file << "Path length: 1\n";
		file.close();
		std::cout << "Path length: 1\n";

		return 0;
	}

	//wave 
	int len_count = 0;
	//int while_count = 0;
	bool flag = true;
	while (flag)
	{

		for (int i = 0; i < 25; ++i)
		{
			for (int j = 0; j < 25; ++j)
			{
				DRP_clone[i][j] = DRP[i][j];
			}
		}

		//path way
		for (int i = 0; i < 25; ++i)
		{
			for (int j = 0; j < 25; ++j)
			{

				//start point
				if ((i == A_x && j == A_y && len_count == 0)) {

					if ((DRP[i][j + 1] >= 0) && ((j + 1) <= 24))
					{
						DRP[i][j + 1] = 1;
					}
					if ((DRP[i + 1][j] >= 0) && ((i + 1) <= 24))
					{
						DRP[i + 1][j] = 1;
					}
					if ((DRP[i - 1][j] >= 0) && ((i - 1) >= 0))
					{
						DRP[i - 1][j] = 1;
					}
					if ((DRP[i][j - 1] >= 0) && ((j - 1) >= 0))
					{
						DRP[i][j - 1] = 1;
					}
				}

				//middle points
				if (DRP[i][j] == len_count && len_count != 0)
				{
					if (((i + 1) <= 24) && DRP[i + 1][j] == 0 && DRP[i][j] != -1)
					{
						DRP[i + 1][j] = len_count + 1;
					}
					if (((j + 1) <= 24) && DRP[i][j + 1] == 0 && DRP[i][j] != -1)
					{
						DRP[i][j + 1] = len_count + 1;
					}
					if ((i - 1 >= 0) && DRP[i - 1][j] == 0 && DRP[i][j] != -1)
					{
						DRP[i - 1][j] = len_count + 1;
					}
					if ((j - 1 >= 0) && DRP[i][j - 1] == 0 && DRP[i][j] != -1)
					{
						DRP[i][j - 1] = len_count + 1;
					}
				}



				//final point
				if (i == B_x && j == B_y)
				{
					if (((i + 1) <= 24) && (DRP[i + 1][j] > 0 || DRP[i + 1][j] == -65))
					{
						//print_DRP(DRP);
						print_DRP_file(DRP);
						std::ofstream file;

						file.open("out.log", std::ofstream::app);

						file << "Path length: " << DRP[i + 1][j] + 1 << '\n';
						file.close();


						std::cout << "Path length: " << DRP[i + 1][j] + 1 << '\n';
						return 0;

					}
					if (((j + 1) <= 24) && (DRP[i][j + 1] > 0))
					{
						//print_DRP(DRP);
						print_DRP_file(DRP);
						std::ofstream file;

						file.open("out.log", std::ofstream::app);

						file << "Path length: " << DRP[i][j + 1] + 1 << '\n';
						file.close();
						std::cout << "Path length: " << DRP[i][j + 1] + 1 << '\n';
						return 0;
					}

					if (((i - 1) >= 0) && (DRP[i - 1][j] > 0))
					{

						//print_DRP(DRP);
						print_DRP_file(DRP);
						std::ofstream file;

						file.open("out.log", std::ofstream::app);

						file << "Path length: " << DRP[i - 1][j] + 1 << '\n';
						file.close();
						std::cout << "Path length: " << DRP[i - 1][j] + 1 << '\n';
						return 0;
					}

					if (((j - 1) >= 0) && ((DRP[i][j - 1] > 0)))
					{

						//print_DRP(DRP);
						print_DRP_file(DRP);
						std::ofstream file;

						file.open("out.log", std::ofstream::app);

						file << "Path length: " << DRP[i][j - 1] + 1 << '\n';
						file.close();
						std::cout << "Path length: " << DRP[i][j - 1] + 1 << '\n';
						return 0;
					}
				}

			}
		}

		if (equal_DRP(DRP, DRP_clone))
		{
			flag = false;
			//print_DRP(DRP);
			print_DRP_file(DRP);
			std::ofstream file;

			file.open("out.log", std::ofstream::app);

			file << "PATH DOES NOT EXIST " << '\n';
			file.close();
			std::cout << "PATH DOES NOT EXIST " << '\n';
			return 0;
		}
		len_count++;
		//print_DRP(DRP);
		print_DRP_file(DRP);

	}
	return 0;
}