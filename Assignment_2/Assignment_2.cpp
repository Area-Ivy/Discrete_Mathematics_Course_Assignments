#include <iostream>
using namespace std;

int main()
{
	cout << "�����Ԫ��ʾ���£�" << endl;
	cout << "A : ӪҵԱA͵���ֱ�" << endl;
	cout << "B : ӪҵԱB͵���ֱ�" << endl;
	cout << "C : ��������Ӫҵʱ��" << endl;
	cout << "D : B�ṩ��֤����ȷ" << endl;
	cout << "E : ����δ����" << endl;

	cout << endl;
	cout << "�����������Ԫ�Ķ�Ӧ��ʾΪ��" << endl;
	cout << "��1��ӪҵԱA��B͵���ֱ�                         ->   A  | B " << endl;
	cout << "��2����A����������������Ӫҵʱ��                ->   A -> C" << endl;
	cout << "��3����B�ṩ��֤����ȷ�������δ����            ->   D -> E" << endl;
	cout << "��4����B�ṩ��֤�ݲ���ȷ��������������Ӫҵʱ��  ->   !D->!C" << endl;
	cout << "��5������������                                 ->   !E" << endl;

	for (int A = 0; A <= 1; A++)
		for (int B = 0; B <= 1; B++)
			for (int C = 0; C <= 1; C++)
				for (int D = 0; D <= 1; D++)
					for (int E = 0; E <= 1; E++)
						if ((A || B) && (!A || C) && (!D || E) && (D || !C) && !E)  
						{
							cout << endl << "A=" << A << "��B=" << B << endl;
							cout << endl;
							if(A) cout << "A͵���ֱ�";  
							if(B) cout << "B͵���ֱ�";  
							cout << endl;
						}
	return 0;
}
