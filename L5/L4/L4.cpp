#include <iostream>
#include <vector>
using namespace std;

void _install(vector<int> &computer_memory, vector<int> &program_size, vector<int> &install_program, int N, int install_program_count);

int main() {
	setlocale(LC_ALL, "RUS");
	int M; //���������� ����������� � ���������
	int N; //���������� ����������� ������(��������)

	vector<int> computer_memory; //������ ���������� ������ � �����������
	vector<int> program_size; //������ ���������
	vector<int> install_program; //������ ������������� ������� ( 1 - �����������, 0 ���)

	/*���������� ������ �� �����������*/
	cout << "���������� ����������� � ��������� = "; cin >> M;
	for (int i = 0; i < M; i++) {
		cout << "���������� ������ � ���������� " << i + 1 << " = ";
		computer_memory.push_back(0);
		cin >> computer_memory[i];
	}
	cout << endl;

	/*���������� ������ ��� ��������*/
	cout << "���������� ����������� ������ ��� ��������� = "; cin >> N;
	for (int i = 0; i < N; i++) {
		cout << "������ ��������� " << i + 1 << " ��� ��������� = ";
		program_size.push_back(0);
		cin >> program_size[i];
	}
	cout << endl;

	/*���������� ������������ �������*/
	for (int i = 0; i < N; i++) 		
		install_program.push_back(0);

	/*��������, ����� �������� �� ���� ������ �����������*/
	if (N > M)
		cout << "������ ���������� " << N << " ��������(�/�)!" << endl;
	else
		_install(computer_memory, program_size, install_program, N, 0);

	system("pause");
	return 0;
}

void _install(vector<int> &computer_memory, vector<int> &program_size, vector<int> &install_program, int N, int install_program_count) {
	int num_programm = -1; //�����(������) ������������� ���������, -1 - �������� �� ������������
	int border = 1000;

	for (int i = 0; i < N; i++)
		if (computer_memory[install_program_count] >= program_size[i] && install_program[i] == 0)
			if ((computer_memory[install_program_count] - program_size[i]) < border && (computer_memory[install_program_count] - program_size[i]) > -1) {
				border = computer_memory[install_program_count] - program_size[i];
				num_programm = i;
			}

	/*�������� �� ��������������� �������� ����� ����� ��� ������������ ������*/
	if (num_programm == -1) {
		cout << "������ ���������� " << N << " ��������(�/�)!" << endl;
		return;
	}

	install_program[num_programm] = 1; //������ 1, ��� �������������� �������� �� ����������
	install_program_count++; //����������� ���������� ������������� ��������

	/*�������� �� ��������������� ���� ��������*/
	if (install_program_count == N) {
		cout << "����� ���������� " << N << " ��������(�/�)!" << endl;
		return;
	}
	else
		_install(computer_memory, program_size, install_program, N, install_program_count);
	
}