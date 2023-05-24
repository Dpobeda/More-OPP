#include <iostream>
#include <string>
#include <vector>
#include <iterator>

// ������������ ������.
class person {
public:
	std::string _name;
	int _age;
public:
	void print(std::string name, int age)
	{
		_name = name;
		_age = age;
	}

	void ShowAll(std::string name, int age)
	{
		std::cout << "Name: " << name << "\n";
		std::cout << "Age: " << age << "\n";
	}

	void GetName(std::string name)
	{
		_name = name;
	}

	void Getage(int age)
	{
		_age = age;
	}
};

class Pupil {
public:
	std::string _name;
	int _age;
	std::vector <int> _marks = {};
public:
	void print1(std::string name, int age, std::vector <int> marks)
	{
		_name = name;
		_age = age;
		_marks = marks;

	}

	void ShowAll1(std::string name, int age)
	{
		std::cout << "Name: " << name << "\n";
		std::cout << "Age: " << age << "\n";
		std::cout << "Marks: ";
		std::vector <int> vec = { 7 , 8 , 9 }; 
		for (int i = 0; i < vec.size(); ++i)
			std::cout << vec.at(i) << " ";
	}

	void GetName1(std::string name)
	{
		_name = name;
	}

	void GetName1(int age)
	{
		_age = age;
	}

	void GetMarks1(std::vector <int> marks)
	{
		_marks = marks;
	}

};

class Proffecor {
public:
	std::string _name;
	std::string _degree;
public:
	void print2(std::string name, std::string degree)
	{
		_name = name;
		_degree = degree;
	}

	void ShowAll2(std::string name, std::string degree)
	{
		std::cout << "\nName: " << name << "\n";
		std::cout << "Degree: " << degree << "\n";
	}

	void GetName2(std::string name)
	{
		_name = name;
	}

	void Getdegre2(std::string degree)
	{
		_degree = degree;
	}
};

// �������� ������.
class Client
{
private:
	std::string _name;
	int _age;
	double _bill;
public:
	Client(std::string name, int age, double bill)
	{
		_name = name;
		_age = age;
		_bill = bill;
	}

	void ShowData() 
	{
		std::cout << "Names's client: " << _name << "\n";
		std::cout << "Client's age: " << _age << "\n";
		std::cout << "Client's bill: " << _bill << "\n\n";
	}
};

class Bank 
{
private:
	std::vector <Client*> _clients;
public:

	void AddClient(Client* client)
	{
		_clients.push_back(client);
	}

	void ShowClients() {
		// ��� ���� ����� ��� � �����, ������� � �� ���������� �������.
		
		// std::vector<Client*>::iterator it;
		// for (it = _clients.begin(); it != _clients.end(); ++it) 
			// (*it)->ShowData();

		for (const auto &it: _clients) 
			it->ShowData();
	}

	void ShowClient(int index) // ���������� ������� ����� ������.
	{
		if (index > _clients.size())
			return;
		_clients.at(index - 1)->ShowData();
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	// ������������ ������.
	/*	{
		person people;
		people.ShowAll("Andrey ", 30);
		std::cout << std::endl;
	}

	{
		Pupil pupil;
		pupil.ShowAll1("Oleg", 24);
		std::cout << std::endl;
	}

	{
		Proffecor proffecor;
		proffecor.ShowAll2("Dc.Malahov", "Doctor");
		std::cout << std::endl;
	}*/

	// �������� ������.
	Bank* bank = new Bank();
	Client* client1 = new Client("Dave", 30, 242145);
	Client* client2 = new Client("Nicolay", 45, 62445);
	Client* client3 = new Client("Vasy", 18, 421245);
	Client* client4 = new Client("Alex", 78, 53566);
	Client* client5 = new Client("Bob", 21, 42424);
	bank->AddClient(client1);
	bank->AddClient(client2);
	bank->AddClient(client3);
	bank->AddClient(client4);
	bank->AddClient(client5);
	bank->ShowClients();
	bank->ShowClient(2);

	return {};
}