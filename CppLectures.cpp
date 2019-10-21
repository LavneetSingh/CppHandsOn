// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
using namespace std;

void f(int&);

float average(const float values[], const size_t& size)
{
	float avg = { 0.0 };
	for (int i = 0; i < size; ++i)
		avg += values[i];

	return avg / size;
}

void twice(float values[], const size_t& size)
{
	for (int i = 0; i < size; ++i)
		values[i] *= 2;
}

float average2d(const float values[][5], const size_t& rows)
{
	float avg = { 0.0 };
	int row = {};
	for (; row < rows; row++)
		for (auto eleVal : values[row]) {
			avg += eleVal;
		}

	float avg2 = { 0.0 };
	int col = {};
	for (row = 0; row < rows; row++)
		for (col = 0; col < std::size(values[row]); ++col)
			avg2 += values[row][col];

	_ASSERT(avg == avg2);
	auto count = rows * size(values[0]);
	return avg / count;
}

void functions()
{
	float vals[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
	cout << average(vals, std::size(vals)) << endl;
	twice(vals, std::size(vals));
	for (auto v : vals)
		cout << v << ' ';

	float vals2d[4][5]{
		{1.0,1.1,1.2,1.3,1.4},
		{2.0,2.1,2.2,2.3,2.4},
		{3.0,3.1,3.2,3.3,3.4},
		{4.0,4.1,4.2,4.3,4.4},
	};
	cout << endl;
	cout << average2d(vals2d, std::size(vals2d));
}

void f(int& a)
{
	a += 10;
}

void constness() 
{
	int i = 10;
	int* p = &i;
	const int* cp1;
	cp1 = &i;
	int* const cp2 = &i;
	int j = 20;
	const int* const cp3 = &i;
	p = &j;
	cp1 = &j;
	//*cp1 = 30;
	//cp2 = &j;
	*cp2 = 30;
	//cp3 = &j;
	//*cp3 = 40;
	i = 50;

	const int& ri = i;
	i = 60;
	//ri = 70;

	int& const rii = i;

	rii = 80;



}
void refs()
{
	// references
	int i = 10;
	int& ri = i;

	int* p = NULL;
	int* & rp = p;
	rp = &i;

	cout << i << endl;
	cout << ri << endl;
	cout << &i << endl;
	cout << &ri << endl;
	cout << p << endl;
	cout << rp << endl;
	cout << *p << endl;
	cout << *rp << endl;
}

void sort()
{
	char names[5][50] = { "a b", "x y", "p q", "s t", "m n" };
	char dest[5][50];
	char n[50];
	for (int i = 0; i < 5; ++i) {
		strcpy_s(dest[i], 50, names[i]);
		for (int j = i+1; j < 5; j++)
		{
			if (strcmp(dest[i], names[j]) > 0) {
				strcpy_s(n, 50, dest[i]);
				strcpy_s(dest[i], 50, names[j]);
				strcpy_s(names[j], 50, n);
			}
		}
	}

	//for (int i = 0; i < 5; i++)
	//	cin.getline(names[i], 50);

	//for (auto name : names)
	//	cin.getline(name, 50);
}

void reversewords()
{
	char s[100];
	char d[100];
	cin.getline(s, 100);

	char* q = NULL;
	char* p = s;
	char* dp = d;
	p += strlen(s);
	while (p >= s) {
		while (*p != ' ') {
			p--;
			if (p-- == s) break;
		}
		q = p + 1;
		strcpy_s(dp, strlen(q)+1, q);
		dp += strlen(dp) + 1;
		*(dp - 1) = ' ';
		*p = NULL;
	}
}

void bitwise()
{
	// Theme
	const unsigned int ThemeDark = 0b00;
	const unsigned int ThemeLight = 0b01;
	const unsigned int ThemeBlue = 0b10;
	const unsigned int ThemeContrast = 0b11;

	// Wifi
	const unsigned int Wifi = 0b100;

	// Tablet mode
	const unsigned int TabletMode = 0b1000;

	unsigned int input = 0;
	// create input
	// Ex1. T-Blue,Wifi-On, Tab-Off
	input = ThemeBlue;
	input |= Wifi;
	//no op for changing Tablet mode - its already 0


	// 1. Find the theme
	// 1.a. 
	const unsigned int ThemeMask = 0b11;
	auto theme = input & ThemeMask;
	if (theme == ThemeBlue)
		std::cout << "Blue Theme";
	else if (theme == ThemeDark)
		std::cout << "Dark Theme";
	else if (theme == ThemeLight)
		std::cout << "Light Theme";
	else if (theme == ThemeContrast)
		std::cout << "Contrast Theme";
	std::cout<<std::endl;
	//2. Find Wifi bit set or not
	auto wifi = input & Wifi;
	if (wifi == 0)
		std::cout << "Wifi OFF";
	else
		std::cout << "Wifi ON";
	std::cout << std::endl;
	//3. Tablet mode
	auto tablet = input & TabletMode;
	if (tablet == 0)
		std::cout << "Table Mode OFF";
	else
		std::cout << "Table Mode ON";
	std::cout << std::endl;

	// Ex2. Wifi - OFF, Theme - Light, Tab - ON
	auto mask = ~Wifi;
	input &= mask;
	input |= TabletMode;
	
	mask = ~0b11;
	input &= mask;
	input |= ThemeLight;


}

#pragma region RGB Problem
const char* BasicColors[] = {
	"Black", "White", "Red", "Lime", "Blue", "Yellow", "Cyan", "Magenta", "Silver",
	"Grey", "Maroon", "Olive", "Green", "Purple", "Teal", "Navy"
};
//0-"Black", 1-"White", 2-"Red", 3-"Lime", 4-"Blue", 5-"Yellow", 6-"Cyan", 7-"Magenta",
// 8-"Silver", 9-"Grey", 10-"Maroon", 11-"Olive", 12-"Green", 13-"Purple", 14-"Teal", 15-"Navy"

const int P = 3, R = 3, C = 3, LEN = 20, COLS = 4, PIX = R*C;

const int RGB2Name[][COLS] = {
	{0,0,0,reinterpret_cast<int>(BasicColors[0])},
	{0,0,128,reinterpret_cast<int>(BasicColors[15])},
	{0,0,255,reinterpret_cast<int>(BasicColors[4])},
	{0,128,0,reinterpret_cast<int>(BasicColors[12])},
	{0,128,128,reinterpret_cast<int>(BasicColors[14])},
	{0,255,0,reinterpret_cast<int>(BasicColors[3])},
	{0,255,255,reinterpret_cast<int>(BasicColors[6])},
	{128,0,0,reinterpret_cast<int>(BasicColors[10])},
	{128,0,128,reinterpret_cast<int>(BasicColors[13])},
	{128,128,0,reinterpret_cast<int>(BasicColors[11])},
	{128,128,128,reinterpret_cast<int>(BasicColors[9])},
	{192,192,192,reinterpret_cast<int>(BasicColors[8])},
	{255,0,0,reinterpret_cast<int>(BasicColors[2])},
	{255,0,255,reinterpret_cast<int>(BasicColors[7])},
	{255,255,0,reinterpret_cast<int>(BasicColors[5])},
	{255,255,255,reinterpret_cast<int>(BasicColors[1])},
};
void FindAndCopyColorName(const int& r, const int& g, const int& b, char* const dest)
{
	bool found = false;
	for (int i = 0; i < 15; i++) {
		if (RGB2Name[i][0] == r && RGB2Name[i][1] == g && RGB2Name[i][2] == b) {
			// found matching RGB, copy name
			strcpy_s(dest, 20, reinterpret_cast<char*>(RGB2Name[i][3]));
			found = true;
			break;
		}
	}
	if (!found)
		strcpy_s(dest, 20, reinterpret_cast<char*>(RGB2Name[0][3]));
}

void RGBtoColorNames(
	const unsigned int rgb[][R][C], 
	const int& pageCount, 
	char colorNames[][20], 
	const int& n)
{
	for (int i = 0, row = 0; row < R; row++) {
		for (int col = 0; col < C; col++) {

			int r = rgb[0][row][col];
			int g = rgb[1][row][col];
			int b = rgb[2][row][col];
			FindAndCopyColorName(r, g, b, colorNames[i++]);
		}
	}
}

void ConvertToRGB3ByteRep(
	const unsigned int rgb[][R][C],
	const int& pages,
	unsigned int rgb3[][C],
	const int& rows);

void RgbProblem()
{
	unsigned int rgb[P][R][C]{
		{{0,  0,  0}, {0,   128, 192}, {255, 0,   255}},
		{{128,128,0}, {128, 128, 192}, {0,   0,   255}},
		{{128,0,  0}, {0,   128, 192}, {255, 255, 255}}
	};
	unsigned int rgbOutput[R][C];

	char colorNames[PIX][LEN] = {};
	ConvertToRGB3ByteRep(rgb, P, rgbOutput, PIX);

	RGBtoColorNames(rgb, P, colorNames, PIX);

	for (int i = 0; i < PIX; i++) {
		cout << colorNames[i] << endl;
	}
}

void ConvertToRGB3ByteRep(
	const unsigned int rgb[][R][C],
	const int& pages,
	unsigned int rgb3[][C],
	const int& rows)
{
	//const unsigned int(*p)[R][C] = rgb;
	auto (*p)[R][C] = rgb;
	auto (*po)[C] = rgb3;

	int i, j;
	const int BYTE = 8;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int pixelR = *(*(*(p + 0) + i) + j);
			int pixelG = *(*(*(p + 1) + i) + j);
			int pixelB = *(*(*(p + 2) + i) + j);

			auto& rgbCell = *(*(po + i) + j);
			rgbCell = pixelR;
			rgbCell |= pixelG << BYTE;
			rgbCell |= pixelB << 2 * BYTE;
		}
	}

}
#pragma endregion

void twodRandomFill()
{
	float twod[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			twod[i][j] = rand() % 100;

	cout << "Using array notation: " << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << twod[i][j] << ' ';
		cout << endl;
	}
	cout << endl;

	cout << "Using pointer notation: " << endl;
	float (*p)[10] = twod;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << *(*(p + i) + j) << ' ';
		cout << endl;
	}
	cout << endl;

}

void threedRandomFill()
{
	const int ROWS{ 10 }, COLS{ 10 }, PAGES{ 3 };

	unsigned int threed[PAGES][ROWS][COLS];
	for (int p = 0; p < PAGES; p++)
		for (int i = 0; i < ROWS; i++)
			for (int j = 0; j < COLS; j++)
				threed[p][i][j] = rand() % 100;

	cout << "Using array notation: " << endl;
	for (int p = 0; p < PAGES; p++) {
		cout << "Page: " << p << endl;
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++)
				cout << threed[p][i][j] << ' ';
			cout << endl;
		}
		cout << endl;
	}


	cout << endl;

	cout << "Using pointer notation: " << endl;
	unsigned int(*p)[ROWS][COLS] = threed;
	for (int i = 0; i < PAGES; i++) {
		auto rowP = *(p + i);
		cout << "Page: " << i << endl;
		for (int j = 0; j < ROWS; j++) {
			auto oneDP = *(rowP + j);
			for (int k = 0; k < COLS; k++) {
				auto cell = *(oneDP+k);
				//cout << *(*(*(p + i) + j) + k) << ' ';
				cout << cell << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

typedef unsigned int uint;
struct Student {
	uint id;
	char* name;
	float cpi;
};

Student* GetStudentData(uint id, char name[100], float cpi)
{
	Student* ps = new Student;

	ps->id = id;
	ps->cpi = cpi;

	ps->name = new char[strlen(name)+1];
	strcpy_s(ps->name, strlen(name)+1, name);

	return ps;
}

void proj()
{
	uint id = 201812001;
	char name[100]{ "Krima Shah" };
	float cpi = 8.9;
	auto all = reinterpret_cast<Student**>(std::malloc(sizeof(Student*) * 10));

	for (int i = 0; ; i++) {
		auto pst = GetStudentData(id, name, cpi);
		cout << "Name: " << pst->name << " ID: " << pst->id << " CPI: " << pst->cpi << endl;
		all[i] = pst;
		// if end of file
		// break;
		if (i % 10 == 0) {
			std::realloc(all, sizeof(Student*) * 10 + sizeof(Student*) * i);
		}
	}

	//auto t = pst->name;

	//delete pst;
	//pst = nullptr;

	//delete[] t;
	//t = nullptr;

}

void main()
{
}