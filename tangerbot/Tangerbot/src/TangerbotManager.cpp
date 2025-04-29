#include <cstdio>
#include <iostream>

// int main(int argc, char ** argv)
// {
//   (void) argc;
//   (void) argv;

//   printf("Tangerbot Package, TangerbotManager Node is Starting! \n");
//   return 0;
// }

class TangerbotManager
{
  private:
    int robotID;
    int robotStatus;

  /**
  * *Constructor
  */
  public:
  // Constructor
  TangerbotManager(int id)
      : robotID(id), robotStatus(0) // Default to inactive
  {}

  // Set the status
  void setStatus(int status)
  {
      robotStatus = status;
  }

  // Report the status
  void printStatus() const
  {
      if (robotStatus == 1)
      {
          std::cout << "Robot " << robotID << " is active." << std::endl;
      }
      else
      {
          std::cout << "Robot " << robotID << " is inactive." << std::endl;
      }
  }
};


int main()
{
    std::cout << "Tangerbot Package, TangerbotManager Node is Starting!\n";

    TangerbotManager bot(42); // Create a robot with ID 42
    bot.printStatus();        // Should say inactive

    bot.setStatus(1);         // Activate robot
    bot.printStatus();        // Should say active

    return 0;
}