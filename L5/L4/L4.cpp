#include <iostream>
#include <vector>
using namespace std;

void _install(vector<int> &computer_memory, vector<int> &program_size, vector<int> &install_program, int N, int install_program_count);

int main() {
	setlocale(LC_ALL, "RUS");
	int M; //количество компьютеров в аудитории
	int N; //количество программных систем(программ)

	vector<int> computer_memory; //вектор количества памяти в компьютерах
	vector<int> program_size; //размер программы
	vector<int> install_program; //вектор установленных програм ( 1 - установлена, 0 нет)

	/*Заполнение данных по компьютерам*/
	cout << "Количество компьютеров в аудитории = "; cin >> M;
	for (int i = 0; i < M; i++) {
		cout << "Количество памяти в компьютере " << i + 1 << " = ";
		computer_memory.push_back(0);
		cin >> computer_memory[i];
	}
	cout << endl;

	/*Заполнение данных для программ*/
	cout << "Количество программных систем для установки = "; cin >> N;
	for (int i = 0; i < N; i++) {
		cout << "Размер программы " << i + 1 << " для установки = ";
		program_size.push_back(0);
		cin >> program_size[i];
	}
	cout << endl;

	/*заполнение проверочного вектора*/
	for (int i = 0; i < N; i++) 		
		install_program.push_back(0);

	/*проверка, чтобы программ не было больше компьютеров*/
	if (N > M)
		cout << "Нельзя установить " << N << " программ(у/ы)!" << endl;
	else
		_install(computer_memory, program_size, install_program, N, 0);

	system("pause");
	return 0;
}

void _install(vector<int> &computer_memory, vector<int> &program_size, vector<int> &install_program, int N, int install_program_count) {
	int num_programm = -1; //номер(индекс) установленной программы, -1 - программ не установленно
	int border = 1000;

	for (int i = 0; i < N; i++)
		if (computer_memory[install_program_count] >= program_size[i] && install_program[i] == 0)
			if ((computer_memory[install_program_count] - program_size[i]) < border && (computer_memory[install_program_count] - program_size[i]) > -1) {
				border = computer_memory[install_program_count] - program_size[i];
				num_programm = i;
			}

	/*проверка на установленность программ после цикла для определенной машины*/
	if (num_programm == -1) {
		cout << "Нельзя установить " << N << " программ(у/ы)!" << endl;
		return;
	}

	install_program[num_programm] = 1; //ставим 1, для уставновленных программ на компьютеры
	install_program_count++; //увеличиваем количество установленных программ

	/*проверка на установленность всех программ*/
	if (install_program_count == N) {
		cout << "Можно установить " << N << " программ(у/ы)!" << endl;
		return;
	}
	else
		_install(computer_memory, program_size, install_program, N, install_program_count);
	
}