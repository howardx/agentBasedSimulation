/*
 * main.cpp
 *
 *  Created on: Oct 9, 2012
 *      Author: howard
 */
#include "Monticarlo.h"
#include <sstream>

int main(int argc, char * argv[])
{
  Dist D(time(0)); // creating a distribution class

  ofstream AgentFile;
  ofstream MarriageFile;
  ofstream BuyFile;
  AgentFile.open("/home/howard/workspace/THESIS/Model_Outputs/Absolute_Potential_Consumer.csv");
  MarriageFile.open("/home/howard/workspace/THESIS/Model_Outputs/Annual_New_Marriage.csv");
  BuyFile.open("/home/howard/workspace/THESIS/Model_Outputs/Housing_Starts.csv");

  /*
   *  2D array for return, each element is an array represent different outputs in one iteration/year
   *
   *  format of array "Results"
   *  Results[0] = [Agent count in 1st year, Agent count in 2nd year, Agent count in 3rd year, Agent count in 4th year ....] -- 1st run
   *  Results[1] = [Agent count in 1st year, Agent count in 2nd year, Agent count in 3rd year, Agent count in 4th year ....] -- 2nd run
   *  Results[2] = [Agent count in 1st year, Agent count in 2nd year, Agent count in 3rd year, Agent count in 4th year ....] -- 3rd run
   *   ....
   */

  for (int year = 0; year < Iteration; year++)
  {
    AgentFile << "ENDof" << year + 2010 << ",";
	MarriageFile << "ENDof" << year + 2010 << ",";
	BuyFile << "ENDof" << year + 2010 << ",";
  }
  AgentFile << "\n";
  MarriageFile << "\n";
  BuyFile << "\n";

  // start the 100 run here
  for (int run = 0; run < NumberofRuns; run++)
  {
    int ** buffer = monticarlo(D); // size of "result" is "Iteration"
    int * agent = buffer[0];
    int * marriage = buffer[1];
    int * buy = buffer[2];

    for (int i = 0; i < Iteration; i++)
    {
      AgentFile << agent[i] << ",";
      MarriageFile << marriage[i] << ",";
      BuyFile << buy[i] << ",";
	}
		AgentFile << "\n";
		MarriageFile << "\n";
		BuyFile << "\n";
	}
	AgentFile.close();
	MarriageFile.close();
	BuyFile.close();

	return 0;
}
