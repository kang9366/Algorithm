#include <iostream>

using namespace std;

int main() {
	int r, c, zr, zc; // r행을 zr배 확대, c열을 zc배 확대
	cin >> r >> c >> zr >> zc;

	char** article = new char*[r];  // 확대 전 신문기사
	for (int i = 0; i < r; i++)
	{
		article[i] = new char[c];
	}
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> article[i][j];
		}
	}

	char** zoomArt = new char*[r*zr]; // 확대된 신문기사
	for (int i = 0; i < r*zr; i++)
	{
		zoomArt[i] = new char[c*zc];
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			for (int k = 0; k < zr; k++)
			{
				for (int l = 0; l < zc; l++)
				{
					zoomArt[i*zr + k][j*zc + l] = article[i][j];
				}
			}
		}
	}

	for (int i = 0; i < r*zr; i++)
	{
		for (int j = 0; j < c*zc; j++)
		{
			cout << zoomArt[i][j];
		}
		if (i != r * zr - 1) cout << "\n";
	}
}
[출처] 백준 3035번 C++|작성자 컴공맨