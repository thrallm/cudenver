// Calculate tax and total price.
// Author: Mason Thrall, mason.thrall@ucdenver.edu 
#include <iostream>
using namespace std;

int main() {
  double state_tax_rate, county_tax_rate; 
  double state_tax, county_tax, total_tax, purchase_price;
  cout << "What was the cost of the purchase?" << endl;
  cin >> purchase_price;
  cout << "What is the state sales tax rate?" << endl;
  cin >> state_tax_rate;
  cout << "What is the county sales tax rate?" << endl;
  cin >> county_tax_rate;
  state_tax = purchase_price * state_tax_rate; 
  county_tax = purchase_price * county_tax_rate;
  total_tax = state_tax + county_tax;
  cout << "total tax was: " << total_tax << " dollars." << endl;
  cout << "grand total was: " << purchase_price + total_tax << " dollars." << endl;
  return 0;
}
