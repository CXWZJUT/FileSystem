#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

void initial();//��ʼ��

fstream disk, user, control;//�ļ���

int main()
{
	control.open("control.txt", ios::in | ios::out | ios::_Nocreate);
	int i;
	control >> i;
	control.close();
	if (i != 0)
	{
		initial();
	}

	return 0;
}
void initial(){
	user.open("user.txt", ios::in | ios::out | ios::_Nocreate | ios::trunc);
	user << setw(6) << "adm";
	user << setw(6) << "123";
	user << setw(6) << "adm";
	user << setw(6) << "yq";
	user << setw(6) << "123";
	user << setw(6) << "adm";
	user << setw(6) << "chy";
	user << setw(6) << "123";
	user << setw(6) << "guest";
	user.close();

	disk.open("disk.txt", ios::in | ios::out | ios::_Nocreate | ios::trunc);
	if (!disk)
	{
		cout << "can't use the dosk " << endl;
		exit(1);
	}
	int i;
	for (i = 0; i < 100; i++)//��ȫ����ա�
	{
		disk << setw(512) << ' ';
		disk << '\n';
	}
	/*�������ʼ�� 0#�̿�*/
	disk.seekp(0);   //���н���ջ80*3=240 B��0 ~ 239��
	disk << setw(3) << -1;  //0# ��i�����ʹ�ã��͸�-1��0 ~ 2��
	for (i = 1; i <= 79; i++)
	{
		disk << setw(3) << i;
	}
	disk << setw(3) << 79;
}