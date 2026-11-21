#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

void write_file(string file_name, int size, int numbers[])
{
    fstream file_w(file_name, ios::out | ios::binary);
    for (int i = 0; i < size; i++)
    {
        file_w.write((char*)&numbers[i], sizeof(numbers[i]));
    }
    file_w.close();
}
void read_file(string file_name, int size, int num[])
{
    fstream file_r(file_name, ios::in | ios::binary);
    for (int i = 0; i < size; i++)
    {
        file_r.read((char*)&num[i], sizeof(num[i]));
    }
    file_r.close();
}
int gip(int num[], int size)
{
    int max_num = 0;

	for (int i = 0; i != size; i++)
    {
		if (num[i] > max_num)
        {
			max_num = num[i];
        }
    }

    int res_kv = 0;
    for (int i = 0; i < size; i++) {
        if (num[i] != max_num) {
            res_kv += num[i] * num[i]; 
        }
    }

    int num_kvadret = max_num * max_num; 
    if (res_kv == num_kvadret)
    {
		cout << "Треугольник прямоугольный" << endl;
    }
    else
		cout << "Треугольник не прямоугольный" << endl;

	cout << "Сумма квадратов катетов: " << res_kv << endl;
	cout << "Квадрат гипотенузы: " << num_kvadret << endl;
    return res_kv == num_kvadret;

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 3;
    int numbers[size] = { 3,4,5 };
    int num[size];
    bool is_write;
    write_file("numbers.bin", size, numbers);
    read_file("numbers.bin", size, num);
    gip(numbers, size);


    return 0;
}

