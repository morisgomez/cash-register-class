//CASH REGISTER EXAMPLE FROM WEEK7 LECTURE21
#include <iostream>
using namespace std;

class CashRegister //we create a class with identifier 'CashRegister' - this is the template in which we can run objects through.
{
private: //attributes access specifier is private.
    int item_count; //will track the number of items.
    double total_price; //will track the total price.

public: //methods have public access specifier per usual bc we need to call them from main function.
    CashRegister () //constructor: automatically does what clear () does when object is created.
    //clear () would do the same thing but when called only. we can delete constructor in program for simplicity.
    {
        item_count = 0; //sets item count back to zero.
        total_price = 0; //sets total price back to zero.
    }
/*
///////////////////////////////
///////////////////////////////
///////////////////////////////
*/
    void clear () //no return value.
    //this is a mutator (set) function bc it changes the object's attributes.
    {
        item_count = 0; //sets item count back to zero.
        total_price = 0; //sets total price back to zero.
    }
/*
///////////////////////////////
///////////////////////////////
///////////////////////////////
*/
    void add_item (double total_price) //we would have to use explicit parameters here bc the local double variable has the same name as one of the member variables.
    //so far we've been using implicit parameters within member functions. this means the member variables have so far been manipulated when a function has been called.
    //however, in explicit parameter usage, we tell the computer that a certain variable in a function corresponds to a member variable.
    //mutator (set) function bc it changes object's attribute values.
    {
        item_count = item_count + 1; //adds 1 to item count.
        this->total_price = this->total_price + total_price; //adds the price of item to total price.
        //without this->, we would only be accessing local total_price throughout member function.
        //hence the global member variable total_price will stay zero (never really changed).
        //with this->, the line reads: member variable total_price = member variable total_price + local variable total_price.
        //it's helpful to use explicit parameters but not necessary.
    }
/*
///////////////////////////////
///////////////////////////////
///////////////////////////////
*/
    double get_total () const //has return value of double.
    //accessor (get) function, so we use const to keep object same.
    {
        return total_price; //how we get the total price.
    }
/*
///////////////////////////////
///////////////////////////////
///////////////////////////////
*/
    int get_count () const //has return value type int.
    //accessor func bc we are just getting the item count, no need to change object hence const usage.
    {
        return item_count; //tracks item #.
    }
};

int main ()
{
    //BELOW CREATES A GROCERY STORE OBJECT WITH 3 ITEMS.
    CashRegister grocery_cash_register; //we create an object grocery_cash_register w/ class CashRegister.
    grocery_cash_register.add_item (1.95); //Skittles: 0 + 1.95
    grocery_cash_register.add_item (2.00); //Bananas: 1.95 + 2.00
    grocery_cash_register.add_item (5.00); //Milk: 1.95 + 2.00 + 5.00

    //BELOW PRINTS THE TOTAL OF THE 3 ITEMS AND THE NUMBER OF ITEMS.
    cout << "Total price: " << grocery_cash_register.get_total () << endl; //total price = 1.95 + 2.00 + 5.00
    cout << "Amount of items: " << grocery_cash_register.get_count () << endl; //should be 3.

    //BELOW ADDS 1 MORE ITEM TO THE GROCERY STORE OBJECT.
    grocery_cash_register.add_item (3.00); //Napkins: 1.95 + 2.00 + 5.00 + 3.00
    cout << "Total price after napkins: " << grocery_cash_register.get_total () << endl; //should be 1.95 + 2.00 + 5.00 + 3.00
    cout << "Amount of items after napkins: " << grocery_cash_register.get_count () << endl; //should be 4 items.

    //BELOW EMPTIES GROCERY REGISTER OBJECT.
    grocery_cash_register.clear (); //resets items to zero and total price to zero.

    //BELOW PRINTS OBJECT AFTER CLEARING GROCERY.
    cout << "Total price after clearing: " << grocery_cash_register.get_total () << endl; //should be zero.
    cout << "Amount of items after clearing: " << grocery_cash_register.get_count () << endl; //should be zero.
    return 0;
}
