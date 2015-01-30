/*
 * Monticarlo.cpp
 *
 *  Created on: Nov 3, 2012
 *      Author: howard
 */

#include "Monticarlo.h"

int ** monticarlo(Dist & D)
{
  // this function run the simulation for ALL iterations for ONE SINGLE TIME

  list< Resident > ResidentList; // doubly linked list
  /*
   * this std list is created WITHOUT "new"
   * so once exited the scope of this function, memory occupied by this list will be freed
   * exactly what the model's memory management need because of so many runs
   */

  int * AgentCount = new int[Iteration]; // amount of agents
  int * newMarriage = new int[Iteration]; // amount of new marriage happened in last iteration
  int * newBuy = new int[Iteration]; // housing starts -- amount of house purchased

  for (int i = 0; i < Iteration; i++)
  {
    int * AnnualMigration = new int[AgeGroup];
    for (int j = 0; j <= AgeGroup; j++)
    {
      AnnualMigration[j] = MigrantPercentage[j] * MigrantSum[i];
    }
    if (i == 0)
    {
      go(ResidentList, InitialAgents, false, D); // start the simulation, first iteration no migrants
    }
    else
    {
      go(ResidentList, AnnualMigration, true, D); // creating only migrants after first iteration
    }
    AgentCount[i] = 1;
    newMarriage[i] = 1;// first element is amount of new marriage happened, one integer
    newBuy[i] = 1; // second element is housing starts, also one integer
    }
    cout << "one run finishes here ______________________________________________"<<endl<<endl;

    int ** Results = new int * [3]; // 3 pointers to integer arrays

    Results[0] = AgentCount;
    Results[1] = newMarriage;
    Results[2] = newBuy;

    return Results;
}


