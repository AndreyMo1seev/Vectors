#include <iostream>
#include <clocale>
#include <cstdlib>
#include "Vector.h"
using namespace std;

void main(){
	try {
	Vector<double> v1, v3(-8), v2, a;
	cout << "Vectors v1 and v2: size = 3, type of el - double" << endl;
	cout << "Enter v1 and v2" << endl;
	cin >> v1 >> v2;  
	
		
		a = v1 + v2;
		cout << "a = v1 + v2 = " << a << endl;
		a = v1 - v2;
		cout << "a = v1 - v2 = " << a << endl;
	
	cout << "Vectors v1Int and v2Int: size = 3, type of el - int" << endl;
	Vector<int> v1Int(3), v2Int(3);
	int num = 3;
	v1Int.SetElem(0, 1);
	v1Int.SetElem(1, 1);
	v1Int.SetElem(2, 1);
	v2Int = v1Int * num;
	cout << "v2Int = (1, 1, 1) * 3 = " << v2Int << endl;
	v2Int = num * v1Int;
	cout << "v2Int = 3 * (1, 1, 1) = " << v2Int << endl;
	int resELEM;
	resELEM = v2Int.GetElem(1);
	cout << "v2Int element(1) = " << resELEM << endl;
	Vector<int> v3Int;
	cout << "Add 5 to every element"<<endl;
	cout << "Enter v3Int size = 3" << endl;
	cin >> v3Int;
	for (int i = 0; i < 5; i++)
	{
		v3Int++;
	}
	cout << "v3Int = " << v3Int << endl;
	cout << "Vectors c1 and c2 : size = 3, type of el - char" << endl;
	Vector<char> c1;
	//c1.SetElem(0, 'a');
	c1[0] = 'a';
	c1.SetElem(1, 'b');
	c1.SetElem(2, 'c');
	cout << "c1 = " << c1 << endl;
	Vector<char> c2(c1);
	cout << "Vector<char> c2(c1) \nc2 = " << c2 << endl;
	cout << "Vectors v1Int and v2Int: size = 3, type of el - unsigned long int" << endl;
	Vector<unsigned long int> vli1, vli2;
	cout << "Enter vli1 и vli2 " << endl;
	cin >> vli1 >> vli2;
	cout << "(vli1, vli2) = " << vli1 * vli2 << endl;
	cout << "v3 = " << v3 << endl;
	v3.ReSize(-5);
	cout << "v3.ReSize(3) \nv3 = " << v3 << endl;
		//Vector<double> a(-4);
	}
	catch (int i) {
		if (i = 123) {
			cout << "ERROR " <<i<<  endl;
		}
		else {
			if (i = 124) {
				cout << "ERROR "<< i;

			}
		}
	}
	system("pause");
	
}
