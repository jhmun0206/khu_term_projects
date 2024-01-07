#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

const int dx[] = { 0,1,1,1,0,-1,-1,-1 };
const int dy[] = { 1,1,0,-1,-1,-1,0,1 };

const int Row = 8;
const int Col = 8;
using Matrix = char[Row][Col];


// 함수 프로토타입 선언
void _load_(Matrix board, string lines);
bool _touch_(Matrix board, string lines);
void display_board(Matrix board, string &s);
void minesweeper(const string commands, string output);


void _load_(Matrix board, string lines) {
	ifstream fin_load_board(lines);
	char c;
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			fin_load_board.get(c);
			board[i][j] = c;
		}
		fin_load_board.get(c);
	}
	fin_load_board.close();
}

bool _touch_(Matrix board, Matrix playboard, string lines) {
	int x = lines[2] - '0' - 1; // 좌표를 0부터 시작하도록 조정
	int y = lines[0] - '0' - 1;
	int count = 0;
	if (board[y][x] == '*') {
		playboard[y][x] = '*';
		return false;
	}
	else {
		for (int i = 0; i < Row; i++) {
			int curx = x + dx[i];
			int cury = y + dy[i];

			if (0 <= curx && curx < 8 && 0 <= cury && cury < 8 && board[cury][curx] == '*') {
				count++;
			}
			playboard[y][x] = count + '0';
		}
		return true;
	}
}


void display_board(Matrix playboard, string &s) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; ++j) {
			s+=playboard[i][j];
		}
		s += '\n';
	}
	s += '\n';
}


void minesweeper(const string commands, string output) {
	Matrix board, playboard;
	ifstream fin(commands);
	int touch_num = 0;
	string lines;
	string mine_output = "";
	bool result = true;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			playboard[i][j] = '.';
		}
	}
	while (getline(fin, lines)) {
		mine_output += "Command: " + lines + "\n";
		if (lines.find("load") != string::npos) {
			_load_(board, lines.substr(5));
		}
		else if (lines.find("touch") != string::npos) {
			++touch_num;
			result = _touch_(board, playboard, lines.substr(6));
			if (result == false)
				break;
		}
		else if (lines.find("display") != string::npos) {
			display_board(playboard, mine_output);
		}
	}
	fin.close();

	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			if (board[i][j] == '*' && playboard[i][j]!='*') {
				playboard[i][j] = '@';
			}
		}
	}

	// 게임 종료 후 결과 출력
	mine_output += "Game Over\n~~~~~~~~~\nFinal Board\n";
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Col; j++) {
			mine_output += playboard[i][j];
		}
		mine_output += '\n';
	}
	mine_output += '\n';
	mine_output += "Spaces touched: ";
	mine_output += to_string(touch_num);
	mine_output += '\n';
	
	ofstream fout(output);
	fout << mine_output;
}
