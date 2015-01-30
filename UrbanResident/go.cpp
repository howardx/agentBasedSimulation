#include "go.h"

// function "go" only works for ONE iteration
void go(list<Resident>&RList,const int*Migration,bool migrant,Dist&D)
// pass by reference C++ style, use RList in function as ResidentList
{
  for (int Group = 0; Group < AgeGroup; Group ++)
  {
    int newAgent = 0; // create agents in the certain age group
    for (newAgent = 0; newAgent < Migration[Group]; newAgent ++)
    {
      /* this for loop is used for generating new agents annually
       * and add to the LIST
       *
       * "Group" is the index for array "Migration",
       * indicating the amount of agent in each age group
       * "Group" takes values 0,1,2, age range in Migration is 0-4, 5-9
       *  HENCE, age_min = ageGroup * 5,  age_max = age_min + 4
       */
      double age_min = Group * 5;
      double age_max = age_min + 4.0;
      // convert/cast the return type "double" into "int"
      int age = (int) D.GetUnifDist(age_min,age_max);

      /*
       * When agents are created, certain percentage of them are
       * already married (follows percentage of married people data)
       */
      bool Marry = D.ChooseMarriage(age);
      double L=D.GetUnifDist(Married_MinLocation,Married_MaxLocation);
      double S=D.GetUnifDist(Married_MinScale,Married_MaxScale);
      if (Marry == false)
      {
        double L=D.GetUnifDist(Single_MinLocation,Single_MaxLocation);
        double S=D.GetUnifDist(Single_MinScale,Single_MaxScale);
      }
      if (migrant == false)
      {
        /*
         * When agents are created, certain percentage of them
         * are already live in houses (follows the logistic CDF)
         *
         * may omit because of low housing sales and assume
         * once married the person gets a house
         */
        bool BuyHouse = D.ChooseBuyHouse(L,S,age);

        // creating one new resident agent
        Resident R(age, Marry, BuyHouse, migrant, L, S);
        RList.push_back(R);
      }
      else
      {
        Resident R(age, Marry, false, migrant, L, S);
        RList.push_back(R);
      }
    }
  }

  /*
   * The reason why there are two different sets of functions: "ChooseMarriage", "ChooseBuyHouse" and "GetMarried", "GetHouse";
   * is because during the first call of this function "go", agents created represent the BEGINNING STAGE of urban residents.
   *
   * At the BEGINNING STAGE of the simulation, all urban residents were created; excluding migrations. So at this time,
   * people selecting marriage status, or live in houses representing their "STATUS"
   * e.g. Martial status shows whether is "Married" or not
   *
   * At the following stages of simulation, all migrants could still be married when they are coming,
   * so when creating them, they should "roll the marriage dice" and see their "starting marriage status"
   *
   * BUT, they defiantly don't have a house, so their "housing dice" should be rolled with others later after creation
   */

  // For every iteration create a new Iterator
  list< Resident >::iterator IT = RList.begin(); 
  int temp = 0;

//whlie loop for iterating over LIST and call step function for agents
  while ( IT != RList.end())
  {
    bool Deletion = D.ChooseSurvival((*IT).getAge());
    if (Deletion == true)
    {
      RList.erase(IT++); // alternatively --> IT = RList.erase(IT);
      // removing an inactive agent since no longer survival
    }

    if ((*IT).getMarriage() == false)
    {
      // roll the marriage dice again
      bool Wedding = D.GetMarried((*IT).getAge()); 
      if (Wedding == true)
      {
        (*IT).setMarriage(Wedding);

        // buy house as soon as getting married
        (*IT).setInhouse(Wedding);

        // adjust probability of buy house (logistic distribution)
        (*IT).setLocation(D.GetUnifDist(Married_MinLocation,
        		                        Married_MaxLocation));
        (*IT).setScale(D.GetUnifDist(Married_MinScale,
        		                     Married_MaxScale));
      }
    }

    if ((*IT).getInhouse() == false)
    {
      bool BuyHouse = D.GetHouse((*IT).getLocation(),
    		                     (*IT).getScale(), (*IT).getAge());
      (*IT).setInhouse(BuyHouse);
    }

    if ((*IT).getInhouse() == false && (*IT).getAge() >= 20) // kids doesn't count
    {
      temp = temp + 1;
    }

    (*IT).step(); // let the agent grow old one year
    ++IT; // increment iterator
  }
  cout <<temp<<endl;
}
