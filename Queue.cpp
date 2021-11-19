
/*
	2001202259 - Chau Van Thinh
*/
#include<iostream>
using namespace std;
#include<ctime>
#include<string>
#include<iomanip>
#include<fstream>

// ---------------------- BT MAU ----------------------
struct QNodeInt
{
	int data;
	QNodeInt *next;
};

struct QueueInt
{
	QNodeInt *head, *tail;
};

// Tao node queue voi data x
QNodeInt* Create_QNodeInt(int x)
{
	QNodeInt *p = new QNodeInt;
	if (p == NULL)
		return NULL;
	p->next = NULL;
	p->data = x;
	return p;
}
// khoi tao queue rong
void initQueueInt(QueueInt &q)
{
	q.head = NULL;
	q.tail = NULL;
}
// kiem tra queue rong
bool isEmpty_QI(QueueInt q)
{
	if (q.head == NULL)
		return true;
	return false;
}
// them phan tu p co gia tri x vao queue
void Enqueue_QueueInt(QueueInt &q, QNodeInt *them)
{
	if (them == NULL)
		return;
	if (isEmpty_QI(q) == true)
	{
		q.head = q.tail = them;
	}
	else
	{
		q.tail->next = them;
		q.tail = them;
	}
}
// lay ra gia tri x va xoa QNode
void Dequeue_QueueInt(QueueInt &q, int &x)
{
	if (isEmpty_QI(q) == false)
	{
		x = q.head->data;
		QNodeInt* p = q.head;
		q.head = q.head->next;
		delete p;
	}
	else cout << "\nHang doi rong!\n";
}
// tao queue tu dong
void CreateQueueInt_Automatic(QueueInt &q)
{
	int n;
	cout << "\nBan hay cho biet so phan tu cua hang doi: ";
	cin >> n;
	initQueueInt(q);
	srand((unsigned)time(NULL));
	for (int i = 1; i <= n; i++)
	{
		// tao 1 so ngau nhien trong doan [-99,99]
		int x = rand() % 199 - 99;
		QNodeInt* p = Create_QNodeInt(x);
		Enqueue_QueueInt(q, p);// them vao cuoi queue
	}
}
// duyet va xem queue
void ShowQueueInt(QueueInt q)
{
	if (isEmpty_QI(q) == true)
	{
		cout << "\nHang doi rong!\n";
		return;
	}
	for (QNodeInt* k = q.head; k != NULL; k = k->next)
		cout << k->data << "\t";
	cout << endl;
}
// giai phong tat ca phan tu hang doi
void Destroy_QueueInt(QueueInt &q)
{
	while (isEmpty_QI(q) == false)
	{
		QNodeInt *p = q.head;
		q.head = q.head->next;
		p->next = NULL;
		delete p;
	}
	q.tail = NULL;
}
// ---------------------------------------------------------//

// ========================== BAI 1 VA BAI 2 ========================== //
void Xu_Ly_Bai2();
bool getHead_QueueInt(QueueInt q, int &gia_tri);
bool getTail_QueueInt(QueueInt q, int &gia_tri);
// ========================== BAI 3 ========================== //
struct QNodeString
{
	string data;
	QNodeString *next;
};

struct QueueString
{
	QNodeString *head, *tail;
};

// Tao node queue voi data x
QNodeString* Create_QNodeString(string x);
// khoi tao queue rong
void initQueueString(QueueString &q);
// kiem tra queue rong
bool isEmpty_QStr(QueueString q);
// them phan tu p co gia tri x vao queue
void Enqueue_QueueString(QueueString &q, QNodeString *them);
// lay ra gia tri x va xoa QNode
void Dequeue_QueueString(QueueString &q, string &x);
// duyet va xem queue
void ShowQueueString(QueueString q);
// giai phong tat ca phan tu hang doi
void Destroy_QueueString(QueueString &q);
// ---- thuc hien bai 3 --------
void Xu_Ly_Bai3();
void Tao_Mang_String(string str[], char c, int n);
void Sap_Lich_In(QueueString &d, string A[], int SL_A, string B[], int SL_B, string C[], int SL_C);
int rand_vi_tri(int soluong);
void Xoa_PT_Vi_Tri(string str[], int &soluong, int vitri);

// ========================== BAI 4 ========================== //
void Xu_Ly_Bai4();
// kiem tra su ton tai cua x
bool Kiem_Tra_Ton_Tai_Cua_X(QueueInt q, int x);
// dem so luong phan tu trong queue
int Dem_Node_QueueInt(QueueInt q);
// ========================== BAI 5 ========================== //
void Xu_Ly_Bai5();
struct Hang_Hoa
{
	string Ma_Hang; // 20
	string Ten_Hang; // 30
	string DVT; // 10
	float SoLuong;
};

struct QNodeHH
{
	Hang_Hoa data;
	QNodeHH* next;
};

struct QueueHH
{
	QNodeHH *head, *tail;
};
QNodeHH* Create_QNodeHH(Hang_Hoa x);
void initQueueHH(QueueHH &qhh);
void Enqueue_QueueHH(QueueHH &qhh, QNodeHH *them);
void Dequeue_QueueHH(QueueHH &qhh, Hang_Hoa &x);
bool isEmpty_QueueHH(QueueHH qhh);
void Destroy_QueueHH(QueueHH &qhh);

void DocFile_DSHH(QueueHH &qhh, char filename[]);
//a
void Nhap_DSHH(QueueHH &qhh);
//b
void Xuat_DSHH(QueueHH qhh);
void Xuat_Tieu_De_DSHH();
void Xuat_Hang_Cach();
//c
void Xuat_HH(QNodeHH *node);
//f
QNodeHH* Find_HH(QueueHH qhh, string Ma_Hang);

// --------- chuoi
void Chuan_Hoa_Chuoi(string &str);
void Chuan_Hoa_Ma(string &str);
void InHoa(char &c);
void Thuong(char &c);

// ======================= MAIN =======================
void main()
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t ---------------- MENU MAIN ----------------";
		cout << "\n\t\t 2. Bai 1 va bai 2.";
		cout << "\n\t\t 3. Bai 3.";
		cout << "\n\t\t 4. Bai 4.";
		cout << "\n\t\t 5. Bai 5.";
		cout << "\n\t\t 0. Thoat.";
		cout << "\n\t\t\t -------------------------------------------";
		cout << "\n\tNhap lua chon: ";
		cin >> luachon;

		if (luachon == 0)
		{
			break;
		}
		else if (luachon == 2)
		{
			Xu_Ly_Bai2();
		}
		else if (luachon == 3)
		{
			Xu_Ly_Bai3();
		}
		else if (luachon == 4)
		{
			Xu_Ly_Bai4();
		}
		else if (luachon == 5)
		{
			Xu_Ly_Bai5();
		}
		else
		{
			cout << "\nLua chon khong hop le!" << endl;
			system("pause");
		}
	}
}

// --------- chuoi
void Chuan_Hoa_Chuoi(string &str)
{
	// xoa khoang trang
	while (str[0] == ' ')
		str.erase(str.begin() + 0);
	while (str[str.length() - 1] == ' ')
		str.erase(str.begin() + str.length() - 1);
	for (int i = 0; i < str.length() - 1; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	// in hoa
	InHoa(str[0]);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
			InHoa(str[i + 1]);
		else Thuong(str[i + 1]);
	}
}
void Chuan_Hoa_Ma(string &str)
{
	for (int i = 0; i < str.length(); i++)
		InHoa(str[i]);
}
void InHoa(char &c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}
void Thuong(char &c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
}

// ========================== BAI 1 VA BAI 2 ========================== //
void Xu_Ly_Bai2()
{
	int luachon;
	QueueInt q;
	initQueueInt(q);
	system("cls");
	cout << "\n\t\t CHUONG TRINH RANDOM GIA TRI HANG DOI\n";
	CreateQueueInt_Automatic(q);
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t ------------------- MENU BAI 1-2 -------------------";
		cout << "\n\t\t 1. Them vao hang doi.";
		cout << "\n\t\t 2. Xem danh sach hang doi hien tai.";
		cout << "\n\t\t 3. Xem phan tu dau hang doi.";
		cout << "\n\t\t 4. Xem phan tu cuoi hang doi.";
		cout << "\n\t\t 5. Lay phan tu khoi hang doi.";
		cout << "\n\t\t 6. Xoa va xem toan bo hang doi.";
		cout << "\n\t\t 0. Thoat.";
		cout << "\n\t\t\t ----------------------------------------------------";
		cout << "\n\tNhap lua chon:";
		cin >> luachon;

		if (luachon == 0)
		{
			Destroy_QueueInt(q);
			break;
		}
		else if (luachon == 1)
		{
			int data;
			cout << "\n\tNhap gia tri muon them:";
			cin >> data;
			QNodeInt *them = Create_QNodeInt(data);
			if (them == NULL)
			{
				cout << "\n\tThem khong thanh cong!" << endl;
			}
			else
			{
				Enqueue_QueueInt(q, them);
				cout << "\n\tThem thanh cong.\n";
			}
		}
		else if (luachon == 2)
		{
			cout << "\n\tDanh sach hang doi hien tai la:";
			ShowQueueInt(q);
		}
		else if (luachon == 3)
		{
			int data;
			bool kt = getHead_QueueInt(q, data);
			if (kt == false)
				cout << "\n\tHang doi dang rong!" << endl;
			else
			{
				cout << "\n\tGia tri phan tu dau hang doi la:" << data << endl;
			}
		}
		else if (luachon == 4)
		{
			int data;
			bool kt = getTail_QueueInt(q, data);
			if (kt == false)
				cout << "\n\tHang doi dang rong!" << endl;
			else
			{
				cout << "\n\tGia tri phan tu cuoi hang doi la:" << data << endl;
			}
		}
		else if (luachon == 5)
		{
			if (isEmpty_QI(q) == false)
			{
				int data;
				Dequeue_QueueInt(q, data);
				cout << "\n\tPhan tu vua lay co gia tri la:" << data << endl;
			}
			else cout << "\n\tHang doi dang rong!" << endl;
		}
		else if (luachon == 6)
		{
			if (isEmpty_QI(q) == false)
			{
				cout << "\nHang doi xoa la:";
				ShowQueueInt(q);
				Destroy_QueueInt(q);
			}
			else cout << "\n\tHang doi dang rong!" << endl;
		}
		else
		{
			cout << "\n\tLua chon khong hop le!" << endl;
		}
		system("pause");
	}
}

bool getHead_QueueInt(QueueInt q, int &gia_tri)
{
	if (isEmpty_QI(q) == true)
		return false;
	gia_tri = q.head->data;
	return true;
}
bool getTail_QueueInt(QueueInt q, int &gia_tri)
{
	if (isEmpty_QI(q) == true)
		return false;
	gia_tri = q.tail->data;
	return true;
}

// ========================== BAI 3 ========================== //
// Tao node queue voi data x
QNodeString* Create_QNodeString(string x)
{
	QNodeString *p = new QNodeString;
	if (p == NULL)
		return NULL;
	p->next = NULL;
	p->data = x;
	return p;
}
// khoi tao queue rong
void initQueueString(QueueString &q)
{
	q.head = NULL;
	q.tail = NULL;
}
// kiem tra queue rong
bool isEmpty_QStr(QueueString q)
{
	if (q.head == NULL)
		return true;
	return false;
}
// them phan tu p co gia tri x vao queue
void Enqueue_QueueString(QueueString &q, QNodeString *them)
{
	if (them == NULL)
		return;
	if (isEmpty_QStr(q) == true)
	{
		q.head = q.tail = them;
	}
	else
	{
		q.tail->next = them;
		q.tail = them;
	}
}
// lay ra gia tri x va xoa QNode
void Dequeue_QueueString(QueueString &q, string &x)
{
	if (isEmpty_QStr(q) == false)
	{
		x = q.head->data;
		QNodeString* p = q.head;
		q.head = q.head->next;
		delete p;
	}
	else cout << "\nHang doi rong!\n";
}
// duyet va xem queue
void ShowQueueString(QueueString q)
{
	if (isEmpty_QStr(q) == true)
	{
		cout << "\nHang doi rong!\n";
		return;
	}
	for (QNodeString* k = q.head; k != NULL; k = k->next)
	{
		cout << k->data.c_str() << "\t";
	}
	cout << endl;
}
// giai phong tat ca phan tu hang doi
void Destroy_QueueString(QueueString &q)
{
	while (isEmpty_QStr(q) == false)
	{
		QNodeString *p = q.head;
		q.head = q.head->next;
		p->next = NULL;
		delete p;
	}
	q.tail = NULL;
}
// ---- thuc hien bai 3 --------
void Xu_Ly_Bai3()
{
	string A[9], B[9], C[9];
	int SL_A, SL_B, SL_C;
	system("cls");
	cout << "\n\t\t\t\tCHUONG TRINH MO PHONG LICH CHO IN\n";
	do
	{
		cout << "\nNhap so luong file client A:";
		cin >> SL_A;
		if (SL_A <= 0 || SL_A > 9)
		{
			cout << "\n\tVui long nhap so luong file cho phu hop!\n";
			system("pause");
		}
	} while (SL_A <= 0 || SL_A > 9);
	do
	{
		cout << "\nNhap so luong file client B:";
		cin >> SL_B;
		if (SL_B <= 0 || SL_B > 9)
		{
			cout << "\n\tVui long nhap so luong file cho phu hop!\n";
			system("pause");
		}
	} while (SL_B <= 0 || SL_B > 9);
	do
	{
		cout << "\nNhap so luong file client C:";
		cin >> SL_C;
		if (SL_C <= 0 || SL_C > 9)
		{
			cout << "\n\tVui long nhap so luong file cho phu hop!\n";
			system("pause");
		}
	} while (SL_C <= 0 || SL_C > 9);
	system("cls");
	cout << "\n\t\t\t\tCHUONG TRINH MO PHONG LICH CHO IN\n";
	Tao_Mang_String(A, 'A', SL_A);
	Tao_Mang_String(B, 'B', SL_B);
	Tao_Mang_String(C, 'C', SL_C);
	QueueString d;
	initQueueString(d);
	Sap_Lich_In(d, A, SL_A, B, SL_B, C, SL_C);
	int stt = 1;
	for (QNodeString *k = d.head; k != NULL; k = k->next)
	{
		cout << stt++ << "\t" << k->data.c_str() << endl;
	}
	Destroy_QueueString(d);
	system("pause");
}
void Tao_Mang_String(string str[], char c, int n)
{
	for (int i = 0; i < n; i++)
	{
		string tam = "  ";
		tam[0] = c;
		tam[1] = i + 1 + 48;
		str[i] = tam;
	}
}
void Sap_Lich_In(QueueString &d, string A[], int SL_A, string B[], int SL_B, string C[], int SL_C)
{
	srand((unsigned)time(NULL));
	int vitri;
	while (SL_A != 0 || SL_B != 0 || SL_C != 0)
	{
		int tam = rand() % (3 - 1 + 1) + 1; // 1 - A, 2 - B, 3 - C
		if (tam == 1)
		{
			if (SL_A != 0)
			{
				vitri = rand_vi_tri(SL_A);
				QNodeString* p = Create_QNodeString(A[vitri]);
				Enqueue_QueueString(d, p);
				Xoa_PT_Vi_Tri(A, SL_A, vitri);
			}
		}
		else if (tam == 2)
		{
			if (SL_B != 0)
			{
				vitri = rand_vi_tri(SL_B);
				QNodeString* p = Create_QNodeString(B[vitri]);
				Enqueue_QueueString(d, p);
				Xoa_PT_Vi_Tri(B, SL_B, vitri);
			}
		}
		else
		{
			if (SL_C != 0)
			{
				vitri = rand_vi_tri(SL_C);
				QNodeString* p = Create_QNodeString(C[vitri]);
				Enqueue_QueueString(d, p);
				Xoa_PT_Vi_Tri(C, SL_C, vitri);
			}
		}
	}
}
int rand_vi_tri(int soluong)
{
	int tam = rand() % (soluong - 1 - 0 + 1) + 0;
	return tam;
}
void Xoa_PT_Vi_Tri(string str[], int &soluong, int vitri)
{
	for (int i = vitri; i < soluong - 1; i++)
	{
		str[i] = str[i + 1];
	}
	soluong--;
}

// ========================== BAI 4 ========================== //
void Xu_Ly_Bai4()
{
	int luachon;
	QueueInt q;
	initQueueInt(q);
	int k;
	do
	{
		system("cls");
		cout << "\nNhap so luong thong bao :";
		cin >> k;
		if (k <= 0)
		{
			cout << "\n\tVui long nhap so luong nguyen duong!\n";
			system("pause");
		}
	} while (k <= 0);
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t -------------- MENU BAI 4 --------------";
		cout << "\n\t\t 1. Them tin nhan.";
		cout << "\n\t\t 0. Thoat.";
		cout << "\n\t\t\t ----------------------------------------";
		cout << "\n\tNhap lua chon:";
		cin >> luachon;

		if (luachon == 0)
		{
			Destroy_QueueInt(q);
			break;
		}
		else if (luachon == 1)
		{
			int sdt;
			cout << "\nNhap sdt:";
			cin >> sdt;
			bool kt = Kiem_Tra_Ton_Tai_Cua_X(q, sdt);
			if (kt == false)
			{
				QNodeInt *them = Create_QNodeInt(sdt);
				Enqueue_QueueInt(q, them);
				int tam;
				if (Dem_Node_QueueInt(q) > k)
					Dequeue_QueueInt(q, tam);
			}
			if (isEmpty_QI(q) == false)
			{
				/*cout << "\n\tThong bao tu phai sang trai:";
				ShowQueueInt(q);*/


				// copy sang mang thuong
				int tam[3];
				int dem = 0;
				for (QNodeInt *k = q.head; k != NULL; k = k->next)
				{
					tam[dem] = k->data;
					dem++;
					if (dem == 3)
						break;
				}
				cout << "\n\tThong bao hien tai la:" << endl;
				for (int i = dem - 1; i >= 0; i--)
					cout << "\t\t" << tam[i] << endl;
			}
			else cout << "\n\tKhong co thong bao!" << endl;
		}
		else
		{
			cout << "\n\tNhap lua chon khong hop le!\n";
		}
		system("pause");
	}
}
// kiem tra su ton tai cua x
bool Kiem_Tra_Ton_Tai_Cua_X(QueueInt q, int x)
{
	for (QNodeInt *k = q.head; k != NULL; k = k->next)
	{
		if (k->data == x)
			return true;
	}
	return false;
}
// dem so luong phan tu trong queue
int Dem_Node_QueueInt(QueueInt q)
{
	int dem = 0;
	for (QNodeInt *k = q.head; k != NULL; k = k->next)
		dem++;
	return dem;
}

// ========================== BAI 5 ========================== //
void Xu_Ly_Bai5()
{
	int luachon;
	QueueHH qhh;
	initQueueHH(qhh);
	DocFile_DSHH(qhh, "DSHH.txt");
	while (true)
	{
		system("cls");
		cout << "\n\t\t\t --------------- MENU BAI 5 ---------------";
		cout << "\n\t\t1. Nhap danh sach hang hoa.";
		cout << "\n\t\t2. Xuat danh sach hang hoa ton kho.";
		cout << "\n\t\t3. Xem thong tin hang hoa chuan bi xuat kho.";
		cout << "\n\t\t4. Xuat kho va cho xem thong tin.";
		cout << "\n\t\t5. Xuat thong tin hang hoa vua nhap kho.";
		cout << "\n\t\t6. Tim va xuat thong tin hang hoa.";
		cout << "\n\t\t7. Xuat toan bo hang hoa trong kho.";
		cout << "\n\t\t0. Thoat.";
		cout << "\n\t\t\t ------------------------------------------";
		cout << "\n\t >Nhap lua chon:"; cin >> luachon;
		rewind(stdin);

		if (luachon == 0)
		{
			break;
		}
		else if (luachon == 1)
		{
			Nhap_DSHH(qhh);
		}
		else if (luachon == 2)
		{
			if (isEmpty_QueueHH(qhh) == false)
			{
				cout << "\n\t\t\t\t DANH SACH HANG HOA TON KHO" << endl;
				Xuat_DSHH(qhh);
			}
			else cout << "\nDanh sach hang hoa dang rong!" << endl;
		}
		else if (luachon == 3)
		{
			if (isEmpty_QueueHH(qhh) == false)
			{
				cout << "\n\t\t\t\t HANG HOA CHUAN BI XUAT KHO" << endl;
				Xuat_HH(qhh.head);
			}
			else cout << "\nDanh sach hang hoa dang rong!" << endl;
		}
		else if (luachon == 4)
		{
			if (isEmpty_QueueHH(qhh) == false)
			{
				cout << "\n\t\t\t\t HANG HOA XUAT KHO" << endl;
				Xuat_HH(qhh.head);
				Hang_Hoa x;
				Dequeue_QueueHH(qhh, x);
			}
			else cout << "\nDanh sach hang hoa dang rong!" << endl;
		}
		else if (luachon == 5)
		{
			if (isEmpty_QueueHH(qhh) == false)
			{
				cout << "\n\t\t\t\t HANG HOA VUA NHAP VAO KHO" << endl;
				Xuat_HH(qhh.tail);
			}
			else cout << "\nDanh sach hang hoa dang rong!" << endl;
		}
		else if (luachon == 6)
		{
			if (isEmpty_QueueHH(qhh) == false)
			{
				string ma_hang;
				do
				{
					cout << "\n\tNhap ma hang hoa can tim:";
					getline(cin, ma_hang);
					Chuan_Hoa_Ma(ma_hang);
					if (ma_hang.length() > 20)
					{
						cout << "\nBan da nhap vuot qua so luong ky tu!" << endl;
						system("pause");
					}
				} while (ma_hang.length() > 20);
				QNodeHH* tam = Find_HH(qhh, ma_hang);
				if (tam == NULL)
				{
					cout << "\n\tMa hang hoa khong ton tai!" << endl;
				}
				else
				{
					cout << "\n\t\t\t\t HANG HOA CAN TIM" << endl;
					Xuat_HH(tam);
				}
			}
			else cout << "\nDanh sach hang hoa dang rong!" << endl;
		}
		else if (luachon == 7)
		{
			if (isEmpty_QueueHH(qhh) == false)
			{
				cout << "\n\t\t\t\t XUAT TOAN BO HANG HOA TON KHO" << endl;
				Xuat_DSHH(qhh);
				Destroy_QueueHH(qhh);
			}
			else cout << "\nDanh sach hang hoa dang rong!" << endl;
		}
		else
		{
			cout << "\nVui long nhap lua chon chinh xac!" << endl;
		}
		system("pause");
	}
}
QNodeHH* Create_QNodeHH(Hang_Hoa x)
{
	QNodeHH *p = new QNodeHH;
	if (p == NULL)
	{
		cout << "\n\tKhong du dung luong de cap phat!" << endl;
		return NULL;
	}
	p->data = x;
	p->next = NULL;
	return p;
}
void initQueueHH(QueueHH &qhh)
{
	qhh.head = qhh.tail = NULL;
}
void Enqueue_QueueHH(QueueHH &qhh, QNodeHH *them)
{
	if (them == NULL)
		return;
	if (isEmpty_QueueHH(qhh) == true)
	{
		qhh.head = qhh.tail = them;
	}
	else
	{
		qhh.tail->next = them;
		qhh.tail = them;
	}
}
void Dequeue_QueueHH(QueueHH &qhh, Hang_Hoa &x)
{
	if (isEmpty_QueueHH(qhh) == false)
	{
		x = qhh.head->data;
		QNodeHH *p = qhh.head;
		qhh.head = qhh.head->next;
		delete p;
	}
}
bool isEmpty_QueueHH(QueueHH qhh)
{
	if (qhh.head == NULL)
		return true;
	return false;
}
void Destroy_QueueHH(QueueHH &qhh)
{
	while (qhh.head != NULL)
	{
		QNodeHH *p = qhh.head;
		qhh.head = qhh.head->next;
		delete p;
	}
	qhh.tail = NULL;
}

void DocFile_DSHH(QueueHH &qhh, char filename[])
{
	ifstream In;
	In.open(filename, ios_base::in);
	if (!In)
	{
		cout << "\nLoi mo file de doc!" << endl;
		return;
	}
	while (In.eof() == false)
	{
		rewind(stdin);
		Hang_Hoa x;
		getline(In, x.Ma_Hang, ',');
		getline(In, x.Ten_Hang, ',');
		getline(In, x.DVT, ',');
		In >> x.SoLuong;
		In.ignore();
		QNodeHH *them = Create_QNodeHH(x);
		Enqueue_QueueHH(qhh, them);
	}
}

void Nhap_DSHH(QueueHH &qhh)
{
	int soluong;
	system("cls");
	cout << "\n\t\t\tTHUC HIEN NHAP SO LUONG HANG HOA\n";
	do
	{
		cout << "\n\tNhap so luong hang hoa nhap vao:";
		cin >> soluong;
		if (soluong <= 0)
		{
			cout << "\nVui long nhap so luong nguyen duong!\n";
			system("pause");
		}
	} while (soluong <= 0);
	system("cls");
	cout << "\n\t\t\tTHUC HIEN NHAP " << soluong << " HANG HOA\n";
	for (int i = 0; i < soluong; i++)
	{
		rewind(stdin);
		Hang_Hoa x;
		cout << "\n --------- Nhap hang hoa thu " << i + 1 << "---------" << endl;
		do
		{
			cout << "Nhap ma hang hoa:";
			getline(cin, x.Ma_Hang);
			Chuan_Hoa_Ma(x.Ma_Hang);
			if (x.Ma_Hang.length() > 20)
			{
				cout << "\nBan da nhap vuot qua so luong ky tu!" << endl;
				system("pause");
			}
		} while (x.Ma_Hang.length() > 20);
		do
		{
			cout << "Nhap ten hang hoa:";
			getline(cin, x.Ten_Hang);
			Chuan_Hoa_Chuoi(x.Ten_Hang);
			if (x.Ten_Hang.length() > 30)
			{
				cout << "\nBan da nhap vuot qua so luong ky tu!" << endl;
				system("pause");
			}
		} while (x.Ten_Hang.length() > 30);
		do
		{
			cout << "Nhap don vi tinh:";
			getline(cin, x.DVT);
			Chuan_Hoa_Chuoi(x.DVT);
			if (x.DVT.length() > 10)
			{
				cout << "\nBan da nhap vuot qua so luong ky tu!" << endl;
				system("pause");
			}
		} while (x.DVT.length() > 10);
		do
		{
			cout << "Nhap so luong:";
			cin >> x.SoLuong;
			if (x.SoLuong <= 0)
			{
				cout << "\nVui long nhap so luong nguyen duong!" << endl;
				system("pause");
			}
		} while (x.SoLuong <= 0);
		QNodeHH *them = Create_QNodeHH(x);
		Enqueue_QueueHH(qhh, them);
	}
}
//b
void Xuat_DSHH(QueueHH qhh)
{
	Xuat_Tieu_De_DSHH();
	Xuat_Hang_Cach();
	int i = 1;
	for (QNodeHH* k = qhh.head; k != NULL; k = k->next)
	{
		cout << "\t" << setw(5) << left << i++ << setw(20) << left << k->data.Ma_Hang << setw(30) << left << k->data.Ten_Hang << setw(10) << left << k->data.DVT << setw(10) << left << k->data.SoLuong << endl;
	}
	Xuat_Hang_Cach();
}
void Xuat_Tieu_De_DSHH()
{
	cout << "\t" << setw(5) << left << "STT" << setw(20) << left << "Ma Hang" << setw(30) << left << "Ten Hang" << setw(10) << left << "DVT" << setw(10) << left << "SL Ton" << endl;
}
void Xuat_Hang_Cach()
{
	int tam = 0;
	int end = 5 + 20 + 30 + 10 + 10;
	cout << "\t";
	while (tam < end)
	{
		cout << '-';
		tam++;
	}
	cout << endl;
}
//c
void Xuat_HH(QNodeHH *node)
{
	cout << "\t" << setw(20) << left << "Ma Hang" << setw(30) << left << "Ten Hang" << setw(10) << left << "DVT" << setw(10) << left << "SL Ton" << endl;
	Xuat_Hang_Cach();
	cout << "\t" << setw(20) << left << node->data.Ma_Hang << setw(30) << left << node->data.Ten_Hang << setw(10) << left << node->data.DVT << setw(10) << left << node->data.SoLuong << endl;
	Xuat_Hang_Cach();
}
//f
QNodeHH* Find_HH(QueueHH qhh, string Ma_Hang)
{
	for (QNodeHH *k = qhh.head; k != NULL; k = k->next)
	{
		if (k->data.Ma_Hang == Ma_Hang)
			return k;
	}
	return NULL;
}