/*5. Write a C++ program to define a base class Item (item-no, name, price).
 Derive a class Discounted-Item (discount-percent). A customer purchases
'n' items. Display the item-wise bill and total amount using appropriate
format.*/
#include <iostream>
#include <cstring>
using namespace std;
void inputItem(int n, class Discounted_Item[]);
void DisplayItem(int n,class Discounted_Item[]);
class Item
{
    int item_no;
    char name[100];
    float price;

public:
    void setItem_no(int num)
    {
        item_no = num;
    }
    void setName(char *str)
    {
        strcpy(name, str);
    }
    void setPrice(float p)
    {
        price = p;
    }
    int getItem_no()
    {
        return item_no;
    }
    const char *getName()
    {
        return name;
    }
    float getPrice()
    {
        return price;
    }
};
class Discounted_Item : public Item
{
    float discount_percent,discount_price;

public:
    void setDiscountPercent(float p)
    {
        discount_percent = p;
        discount_price = this->getPrice() - ((this->getPrice()*discount_percent)/100.0);
    }
    float getDiscountPercent()
    {
        return discount_percent;
    }
    float getDiscountedPrice()
    {
        return discount_price;
    }
};
int main()
{
    int n;
    float total=0,totalDiscount=0;
    cout << "How many items you want to buy? : ";
    cin >> n;
    Discounted_Item item[n];
    for (int i = 0; i < n; i++)
        inputItem(i, item);
    for (int i = 0; i < n; i++)
        DisplayItem(i, item);
    for(int i=0;i<n;i++)
    {
        total +=item[i].getPrice();
        totalDiscount +=item[i].getPrice()-item[i].getDiscountedPrice();
    }
    cout<<"Total : "<<total<<endl;
    cout<<"Total Discount : "<<totalDiscount<<endl;
    system("pause");
    return 0;
}
void DisplayItem(int i,Discounted_Item item[])
{
    cout<<"Item Name : "<<item[i].getName()<<endl;
    cout<<"Item No. : "<<item[i].getItem_no()<<endl;
    cout<<"Item Price : "<<item[i].getPrice()<<endl;
    cout<<"Discount percent : "<<item[i].getDiscountPercent()<<endl;
    cout<<"Discounted price : "<<item[i].getDiscountedPrice()<<endl;
    cout<<"----------------------"<<endl;
}
void inputItem(int i, Discounted_Item item[])
{
    char name[100];
    int item_num;
    float price, discount_percent;
    cin.ignore();
    cout << "Enter Item Name : ";
    cin.getline(name, 100);
    cout << "Enter Item No.  : ";
    cin >> item_num;
    cout << "Enter Item price : ";
    cin >> price;
    cout << "Enter Discount Percent : ";
    cin >> discount_percent;
    cout<<endl<<"----------------------"<<endl<<endl;
    item[i].setName(name);
    item[i].setItem_no(item_num);
    item[i].setPrice(price);
    item[i].setDiscountPercent(discount_percent);
}