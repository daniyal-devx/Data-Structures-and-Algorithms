#include <iostream>
#include <fstream>
#include <vector>
#include<stdio.h>
#include<windows.h>
#include <stdexcept>
#include<cstring>
using namespace std;
struct Student
{
	int roll;
	char name[30];
	Student() :roll(0)
	{
		strcpy_s(name, sizeof(name), "none");
	}
};
void addToStudentUnBuffered(int N)
{
	ofstream  ofs("studentdatabase.txt", ios::binary | ios::out);
	Student s;
	for (int i = 1; i < N; i++)
	{
		s.roll = i;
		ofs.write((char*)(&s), sizeof(Student));
	}
	ofs.close();
}
void addToStudentBuffered(int N) {
	ofstream  ofs("studentdatabase.txt", ios::binary | ios::out);
	Student s;
	vector<Student>buffer;
	for (int i = 1; i < N; i++)
	{
		s.roll = i;
		buffer.push_back(s);
		if (buffer.size() == 10000) {
			ofs.write((char*)buffer.data(), buffer.size() * sizeof(Student));
			buffer.clear();
		}
	}
	ofs.close();

}
void readAllRecordsUnBuffered() {
	ifstream ifs("studentdatabase.txt", ios::binary | ios::in);
	Student s;
	while(ifs.read((char*)(&s),sizeof(Student))) {
		cout<<"Roll: " << s.roll << ", Name: " << s.name << endl;
	}
	ifs.close();
}
void readAllRecordsBuffered() {
	ifstream ifs("studentdatabase.txt", ios::binary | ios::in);
	vector<Student> buffer(1000000);
	while (ifs.read((char*)buffer.data(), buffer.size() * sizeof(Student))) {
		size_t bytesRead = ifs.gcount();
		size_t recordsRead = bytesRead / sizeof(Student);
		for (size_t i = 0; i < recordsRead; ++i) {
			cout << "Roll: " << buffer[i].roll << ", Name: " << buffer[i].name << endl;
		}
	}
	ifs.close();

}
int main() {
	SYSTEMTIME systime;
	cout << "\nWriting Records to File one by one";
	GetLocalTime(&systime);
	cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
	addToStudentBuffered(100000000);
	GetLocalTime(&systime);
	cout << endl << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
	readAllRecordsBuffered();
	return 0;
}