#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "Product.h"
#include "Computer.h"
#include "Smartphone.h"
#include "Television.h"
#include "User.h"
#include "Client.h"
#include "Individual.h"
#include "Company.h"
#include "Cart.h"
#include "Order.h"

using namespace std;

void login();
void AdminMenu();
void ClientMenu();
void writeProducts();
void readProducts();
void split(string str, char ch, vector<string> &strVec);
void writeUsers();
void viewClients();
void addToCart();
void newOrder(int id,int q);
void viewOrder();

int main() {
	char a;
	cout << "Press 1 to log in: " << endl;
	cout << "Press 2 to exit: " << endl;
	cin >> a;
	switch (a)
	{
	case '1':
		system("cls");
		login();
	case '2':
		return 0;
		break;
	default:
		break;
	}
	system("pause");
	return 0;
}

void login()
{
	string usr,pwd;
	cout << "Username: ";
	cin >> usr;
	
	cout << "Password: ";
	cin >> pwd;

	if (usr == "admin" && pwd == "tp3836") {
		system("cls");
		cout << "Welcome administrator " << endl;
		AdminMenu();
	}

	string userNpass = usr + '|' + pwd;
	int offset;
	string line;
	ifstream usersFile;
	usersFile.open("users.dat");

	bool found = false;
	if (usersFile.is_open()) {
		while (getline(usersFile, line)) {
			if (line.compare(userNpass) == 0) {
				found = true;
			}
		}
		usersFile.close();
		if (found) {
			system("cls");
			cout << "Welcome " << usr << endl;
			vector <User> users;
			users.push_back(User(usr, pwd));
			
			ClientMenu();
			
		}
		else {
			cout << "\nUsername and/or password incorrect!\n\n\n\n" << endl;
			login();
		}
	}
	else
		cout << "Unable to open userData.txt file." << endl;
}

void AdminMenu()
{
	do {
		char choice;
		cout << "Please type the number for the action you want to do" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "1: Create a new account                             " << endl;
		cout << "2: View the list of products                        " << endl;
		cout << "3: Add new products in the list of products         " << endl;
		cout << "4: View the list of clients                         " << endl;
		cout << "5: Log out                                          " << endl;
		cout << "----------------------------------------------------" << endl;
		cin >> choice;
		
		switch (choice) {
		case '1':
			writeUsers();
			break;	
		case '2':
			readProducts();
			break;
		case '3':
			writeProducts();
			break;
		case '4':
			viewClients();
			break;
		case '5':
			system("cls");
			login();
			break;
		default:
			cout << "This choice is not supported" << endl;
			break;
		}

	} while (1);
}

void ClientMenu()
{
	do {
		char choice;
		cout << "Please type the number for the action you want to do" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "1: View the list of products                        " << endl;
		cout << "2: Add a product to the shopping cart               " << endl;	
		cout << "3: View order status                                " << endl;
		cout << "4: Log out                                          " << endl;
		cout << "----------------------------------------------------" << endl;
		cin >> choice;

		
		switch (choice) {
		case '1':
			readProducts();
			break;
		case '2':
			addToCart();
			break;
		case '3':
			viewOrder();
			break;
		case '4':
			system("cls");
			login();
			break;
		default:
			cout << "This choice is not supported" << endl;
			break;
		}

	} while (1);
}

void writeProducts()
{
	char choice;
	cout << "What kind of product would you like to add ?        " << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "1: Computer                                         " << endl;
	cout << "2: Smartphone                                       " << endl;
	cout << "3: TV                                               " << endl;

	cout << "----------------------------------------------------" << endl;
	cin >> choice;
	
	ofstream outfile;

	bool read = true;

	switch (choice) {
		case '1':
			outfile.open("products.dat", ios::app);
			while (read) {
				
				Computer pc = Computer();
				cout << "Please enter the manufacturer: ";
				string manufacturer;
				cin >> manufacturer;
				pc.setManufacturer(manufacturer);
				cout << "Please enter the model: ";
				string model;
				cin >> model;
				pc.setModel(model);
				cout << "Please enter the description: " << endl;
				cout << " RAM Capacity: ";
				double ram;
				cin >> ram;
				pc.setRam(ram);
				cout << " Processor's speed: ";
				double cpu;
				cin >> cpu;
				pc.setCpu(cpu);
				cout << " Disk size: ";
				double hdd;
				cin >> hdd;
				pc.setDisk(hdd);
				cout << " Disk Type: ";
				string type;
				cin >> type;
				pc.setDiskType(type);
				cout << " Graphics card: ";
				string gpu;
				cin >> gpu;
				pc.setGpu(gpu);
				cout << "Please enter the price: ";
				double price;
				cin >> price;
				pc.setPrice(price);
				cout << "Is this product available (y/n)?: ";
				char a;
				cin >> a;
				bool av;
				if (a == 'y') {
				av = true;
				pc.setAvailability(av);
				}
				else {
				av = false;
				pc.setAvailability(av);
				}

				pc.save(outfile);
				char action;
				cout << "Would you like to add another computer? (y/n): ";
				cin >> action;

				if (action == 'y') {
					continue;
				}
				else {
					break;
				}
			}
			outfile.close();
			break;
		case '2':
			outfile.open("products.dat", ios::app);	
			while (read) {
				Smartphone sp = Smartphone();
				cout << "Please enter the manufacturer: ";
				string manufacturer;
				cin >> manufacturer;
				sp.setManufacturer(manufacturer);
				cout << "Please enter the model: ";
				string model;
				cin >> model;
				sp.setModel(model);
				cout << "Please enter the description: " << endl;
				
				cout << " Screen size: ";
				double screen;
				cin >> screen;
				sp.setScreen(screen);
				cout << " Battery's duration: ";
				double duration;
				cin >> duration;
				sp.setBattery(duration);
				cout << " Is this smartphone capable of capturing videos in 3D (y/n)?: ";
				char a;
				cin >> a;
				bool vid;
				if (a == 'y') {
					vid = true;
					sp.set3DCapture(vid);
				}
				else {
					vid = false;
					sp.set3DCapture(vid);
				}
				cout << "Please enter the price: ";
				double price;
				cin >> price;
				sp.setPrice(price);
				cout << "Is this product available (y/n)?: ";
				char b;
				cin >> b;
				bool av;
				if (b == 'y') {
					av = true;
					sp.setAvailability(av);
				}
				else {
					av = false;
					sp.setAvailability(av);
				}
				sp.save(outfile);
				char action;
				cout << "Would you like to add another smartphone? (y/n): ";
				cin >> action;

				if (action == 'y') {
					continue;
				}
				else {
					break;
				}
			}
			outfile.close();
			break;
		case '3':
			outfile.open("products.dat", ios::app);
			while (read) {
				Television tv = Television();
				cout << "Please enter the manufacturer: ";
				string manufacturer;
				cin >> manufacturer;
				tv.setManufacturer(manufacturer);
				cout << "Please enter the model: ";
				string model;
				cin >> model;
				tv.setModel(model);
				cout << "Please enter the description: " << endl;
				cout << "Please enter the screen size: ";
				double size;
				cin >> size;
				tv.setSize(size);
				cout << "Does this TV support 3D projection (y/n)?: ";
				char answer;
				bool projection3D;
				cin >> answer;
				if (answer == 'y') {
					projection3D = true;
					tv.set3D(projection3D);
				}
				else {
					projection3D = false;
					tv.set3D(projection3D);
				}
				cout << "Please enter the price: ";
				double price;
				cin >> price;
				tv.setPrice(price);
				cout << "Is this product available (y/n)?: ";
				char a;
				cin >> a;
				bool av;
				if (a == 'y') {
					av = true;
					tv.setAvailability(av);
				}
				else {
					av = false;
					tv.setAvailability(av);
				}
				tv.save(outfile);
				char action;
				cout << "Would you like to add another tv? (y/n): ";
				cin >> action;

				if (action == 'y') {
					continue;
				}
				else {
					break;
				}
			}
			outfile.close();
			break;
		default:
			cout << "This choice is not supported" << endl;
			break;
		}
}

void readProducts()
{
	vector<Product*> products;
	int id =1;
	ifstream infile;
	infile.open("products.dat");
	string str;
	cout << "This is a list of the products" << endl << "-----------------------------------------------" << endl;
	while (getline(infile, str)) {
		vector<string> line;
		split(str, '|', line);

		cout << id << ".";
		cout << "\n";
		if (line[0] == "pc") {
			Computer *pc = new Computer(str);
			products.push_back(pc);
		}
		else if(line[0] == "sm") {
			Smartphone *sp = new Smartphone(str);
			products.push_back(sp);
		}
		else if(line[0] == "tv"){
			Television *tv = new Television(str);
			products.push_back(tv);
		}
		id++;
	}
	infile.close();

}

void writeUsers()
{
	
	ofstream outfile, file;
	outfile.open("users.dat", ios::app);
	bool read = true;

	while (read) {
		User user = User();
		string usr, pwd;
		cout << "Please enter a new username: ";
		cin >> usr;
		user.setUser(usr);
		cout << "Please enter a new password: ";
		cin >> pwd;
		user.setPass(pwd);
		
		
		char choice;
		cout << "What kind of type of user account do you want to create ?  " << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "1: Individual                                       " << endl;
		cout << "2: Company                                          " << endl;

		cout << "----------------------------------------------------" << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
			while (read)
			{
				file.open("clients.dat", ios::app);
				Individual id = Individual();
				id.setUser(usr);
				id.setPass(pwd);
				cout << "Please enter the individual's full name: ";
				string fname,lname;
				cin >> fname >> lname;
				id.setName(fname,lname);
				cout << "Please enter the individual's  ID number: ";
				string idnum;
				cin >> idnum;
				id.setId(idnum);
				cout << "Please enter the individual's tax ID number: ";
				int tin;
				cin >> tin;
				id.setAfm(tin);
				cout << "Please enter the individual's phone number: ";
				int phone;
				cin >> phone;
				id.setPhoneNum(phone);
				cout << "Please enter the individual's  address: ";
				string addr;
				cin >> addr;
				id.setAddress(addr);

				id.save(file);
				break;
			}
			file.close();
			break;
		case '2':
			while (read)
			{
				file.open("client.dat", ios::app);
				Company com = Company();
				com.setUser(usr);
				com.setPass(pwd);
				cout << "Please enter the company's name: ";
				string comName;
				cin >> comName;
				com.setCompanyName(comName);
				cout << "Please enter the contact's  full name: ";
				string fname, lname;
				cin >> fname >> lname;
				com.setName(fname, lname);
				cout << "Please enter the discount: ";
				int dis;
				cin >> dis;
				com.setDiscout(dis);
				cout << "Please enter the company's fax number: ";
				int fax;
				cin >> fax;
				com.setFax(fax);
				cout << "Please enter the company's tax ID number: ";
				int tin;
				cin >> tin;
				com.setAfm(tin);
				cout << "Please enter the company's phone number: ";
				int phone;
				cin >> phone;
				com.setPhoneNum(phone);
				cout << "Please enter the company's  address: ";
				string addr;
				cin >> addr;
				com.setAddress(addr);

				com.save(file);
				break;
			}
			file.close();
			break;
		default:
			cout << "Error\n";
			break;
		}

		user.save(outfile);
		char action;
		cout << "Would you like to add another user? (y/n): ";
		cin >> action;

		if (action == 'y') {
			continue;
		}
		else {
			break;
		}
		
	}
	outfile.close();

}

void viewClients()
{
	vector<Client*> clients;
	ifstream infile;
	infile.open("clients.dat");
	string str;
	while (getline(infile, str)) {
		vector<string> line;
		split(str, '|', line);

		for (int i = 0; i < line.size(); i++)
		{
			cout << line[i] << " ";
		}
		cout << "\n";
		if (line[0] == "ind") {
			Individual *ind = new Individual(str);
			clients.push_back(ind);
		}
		else if (line[0] == "com") {
			Company *com = new Company(str);
			clients.push_back(com);
		}
	}
	infile.close();
}

void addToCart()
{
	readProducts();
	vector<Cart> cart;
	string manufacturer,model;
	int id, quantity;
	do {
		cout << "Please type the product id: ";
		cin >> id;
		cout << "Please type the quantity of products : ";
		cin >> quantity;
		cart.push_back(Cart(id, quantity));

		char action;
		cout << "Press y to continue shopping, or n to proceed order : ";
		cin >> action;


		if (action == 'y') {
			continue;
		}
		else {
			break;
		}
	} while (1);
	
	cout << "\n\n-----------------------------------------------\n\n";
	cout << "These are the contents of your cart" << endl << endl;
	if (cart.size() > 0) {
		for (int i = 0; i < cart.size(); i++) {
			cout << "Product Id: " << cart[i].getId() << "Quantity:" << cart[i].getQuantity() << endl;
		}
	}
	cout << "\n\n-----------------------------------------------\n\n";
	newOrder(id, quantity);
}

void newOrder(int id, int q)
{
	ofstream outfile, file;
	outfile.open("orders.dat", ios::app);
	bool read = true;

	while (read) {
		Order order = Order();
		string usr, pwd;
		order.setProdId(id);
		order.setQuantity(q);
		cout << "To complete your order you need to complete your info" << endl;
		cout << "Username: ";
		string uname;
		cin >> uname;
		order.setUsername(uname);
		string order_status = "Pending";
		order.setStatus(order_status);
		order.save(outfile);
	}
	outfile.close();
}

void viewOrder()
{
	vector<Order*> orders;
	ifstream infile;
	infile.open("orders.dat");
	string str;
	while (getline(infile, str)) {
		vector<string> line;
		split(str, '|', line);

		for (int i = 0; i < line.size(); i++)
		{
			cout << line[i] << " ";
		}
		cout << "\n";
		
			Order *ord = new Order(str);
			orders.push_back(ord);

	}
	infile.close();
}


void split(string inString, char inChar, vector<string> &inVector)
{
	stringstream ss(inString);
	string str;
	while (getline(ss, str, inChar))
	{
		inVector.push_back(str);
	}
}