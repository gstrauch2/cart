// George Strauch
// gets the price of order
// 03/27/2018

/* asks for number of items
 * makes an array of the prices with that many items
 * calculates sub total, shipping, and grand total
 * prints the result*/

#include <iostream>
using namespace std;


// gets the pointer of the array of prices (the address of the first element)
// I could just put 'dblPrices[]' in the arguments but for whatever reason Clion does not like that
double subTotal(double *dblPrices, int intLength){

    double dblSubTotal = 0;

    for(int i = 0; i < intLength; ++i){
        dblSubTotal += dblPrices[i];
    }

    return dblSubTotal;
}

// if the sub total is less that $50, shipping is $10  per item;
// else, it is free
double shipping(int intItems, double dblSubTotal, double *dblPrices){

    double dblShippping = 0;

    if(dblSubTotal >= 50){
        dblShippping = 0;
    }
    else{
        dblShippping = 10 * intItems;
    }

    return dblShippping;
}

// sub total + shipping
double grandTotal(double dblSubTotal, double dblShipping){
    double dbltotal = dblSubTotal + dblShipping;
    return dbltotal;
}


int main() {

    int intNumOfItems = 0;
    double dblShiping = 0;
    double dblsubtotal = 0;
    double dblTotal = 0;

    // gets num of items
    cout << "How many items did you buy? [enter an int]" << endl;
    cin >> intNumOfItems;

    //declaring down here to get length
    double dblItemPrice[intNumOfItems];

    // gets price of each item
    for(int i = 0; i < intNumOfItems; ++i){
        cout << "How much did item " << i+1 << " cost? [enter a double with 2 decimal places]" << endl;
        cin >> dblItemPrice[i];
    }

    // sets the values
    dblsubtotal = subTotal(dblItemPrice, intNumOfItems);
    dblShiping = shipping(intNumOfItems, dblsubtotal, dblItemPrice);
    dblTotal = grandTotal(dblsubtotal, dblShiping);

    // prints values
    cout << endl << endl;
    cout << "Sub total: " << dblsubtotal << endl;
    cout << "Shipping: " << dblShiping << endl;
    cout << "Total: " << dblTotal << endl;

    return 0;

}