/******************************************************************************
# Author:           Erin Egloff and Brandon Clyde
# Lab:              Discussion #2
# Date:             January 20, 2022
# Description:      This progam will calculate the total cost to drive 20, 75, and 500 miles using the mpg and price/gallon for a vehicle.
# Input:            double milesPerGallon, double pricePerGallon
# Output:           double costFor20Miles, double costFor75Miles, double costFor500Miles
# Sources:           https://stackoverflow.com/questions/257091/how-do-i-flush-the-cin-buffer
#******************************************************************************/

#include <iostream>
#include <iomanip>

/*** Function declarations ***/
double doubleInput (std::string msg);


/*** MAIN ***/
int main() {
  // Declare inputs
  double milesPerGallon = 0.0;
  double pricePerGallon = 0.0;

  // Declare outputs
  double costFor20Miles = 0.0;
  double costFor75Miles = 0.0;
  double costFor500Miles = 0.0;
  

  // Set precision
  std::cout << std::fixed 
            << std::setprecision(2);

  // Display description
  std::cout << "This program will calculate the total cost to drive 20, 75, and 500 miles using the mpg for a vehicle and price/gallon of fuel."
            << std::endl 
            << std::endl;

  // Get inputs
  milesPerGallon = doubleInput("Enter the mpg rating for your car: ");
  pricePerGallon = doubleInput("Enter the price per gallon for gas: ");

  // Calculate cost for each amount of miles
  costFor20Miles = (20 / milesPerGallon) * (pricePerGallon);

  costFor75Miles = (75 / milesPerGallon) * (pricePerGallon);

  costFor500Miles = (500 / milesPerGallon) * (pricePerGallon);


  std::cout << std::endl
            << "It will cost:" << std::endl 
            << costFor20Miles << " dollars to travel 20 miles " << std::endl
            << costFor75Miles << " dollars to travel 75 miles" << std::endl
            << costFor500Miles << " dollars to travel 500 miles." << std::endl;
    

  return 0;
}


/*** Function definitions ***/
/* 
doubleInput:
  Prompts user with an input message then 
  verifies that the input is of type double.
  Loops until a valid input is entered.
  Returns a validated double
*/
double doubleInput(std::string msg) {
  double tmp;

  // Prompt user with "msg" and get user input
  std::cout << msg;
  std::cin >> tmp;

  // Check for an error on the input via cin, then loop until the input is valid
  while(true){
    if (std::cin.fail()){
      // Clear and ignore buffer so it is not an endless loop
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      // Display error message and re prompt
      std::cout << "Invalid input! Input should be of type 'double'" 
                << std::endl
                << std::endl
                << msg;
      std::cin >> tmp;
    }
    else{
      break;
    }    
  }

  // return validated input
  return tmp;
}