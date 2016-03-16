#ifndef CART_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Cart : public Product
{
public:
	Cart();
	Cart(int id, int quantity);
	Cart(string strCart);

	void setId(int id);
	int getId();

	void setQuantity(int quantity);
	int getQuantity();

	void addProduct(Product p);
	vector<Product> getProducts();

	void save(ofstream &outfile);
	string toString();
private:
	vector<Product> products;
	int quantity;
	int id;
};
#endif // !CART_H

