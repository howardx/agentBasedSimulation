
#include "Dist.h"

Dist::Dist(int seed) :
seed(seed)
{
  PseudoGen.seed(seed); // seed the pseudo random number generator
}

Dist::~Dist()
{
}

double Dist::GetUnifDist(double min, double max)
{
  boost::uniform_real<> dist(min, max);
  boost::variate_generator<boost::mt19937&, boost::uniform_real<> >
  random(this -> PseudoGen, dist);
  return random();
}

double Dist::GetLogisDist(double location, double scale, double RandomVariable)
{
  boost::math::logistic_distribution<double> dist(location, scale);
  double randFromDist = cdf(dist, RandomVariable);
  return randFromDist;
}

//arrange certain percentage of agents to be married once created
bool Dist::ChooseMarriage(int age)
{
  if (age < 20)
  {
    return false;
  }
  else if (15 <= age && age < 20)
  {
    if (this -> GetUnifDist(0,1) <= MarriagePercentage[0])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (20 <= age && age < 25)
  {
    if (this -> GetUnifDist(0,1) <= MarriagePercentage[1])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (25 <= age && age < 30)
  {
    if (this -> GetUnifDist(0,1) <= MarriagePercentage[2])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (30 <= age && age < 35)
  {
    if (this -> GetUnifDist(0,1) <= MarriagePercentage[3])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (35 <= age && age < 40)
  {
    if (this -> GetUnifDist(0,1) <= MarriagePercentage[4])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (40 <= age && age < 45)
  {
    if (this -> GetUnifDist(0,1) <= MarriagePercentage[5])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (45 <= age && age < 50)
  {
    if (this -> GetUnifDist(0,1) <= MarriagePercentage[6])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (50 <= age && age < 55)
  {
    if (this -> GetUnifDist(0,1) <= MarriagePercentage[7])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (55 <= age && age < 60)
  {
    if (this -> GetUnifDist(0,1) <= MarriagePercentage[8])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (60 <= age && age < 65)
  {
    if (this -> GetUnifDist(0,1) <= MarriagePercentage[9])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (age >= 65)
  {
    if (this -> GetUnifDist(0,1) <= MarriagePercentage[10])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  return false;
}

// compare random number with death rate and return survival or not
bool Dist::ChooseSurvival(int age)
{
  if (age < 4)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[0])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (5 <= age && age < 10)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[1])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (10 <= age && age < 15)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[2])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (15 <= age && age < 20)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[3])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  if (20 <= age && age < 25)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[4])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (25 <= age && age < 30)
  {
    if ( this -> GetUnifDist(0,1)<= DeathRate[5])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (30 <= age && age < 35)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[6])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (35 <= age && age < 40)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[7])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (40 <= age && age < 45)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[8])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (45 <= age && age < 50)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[9])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (50 <= age && age < 55)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[10])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (55 <= age && age < 60)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[11])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (60 <= age && age < 65)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[12])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (65 <= age && age < 70)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[13])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (70 <= age && age < 75)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[14])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (75 <= age && age < 80)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[15])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (age >= 80)
  {
    if (this -> GetUnifDist(0,1) <= DeathRate[16])
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  return false;
}

// arrange certain percentage of agents to be live in apartments once created
bool Dist::ChooseBuyHouse(double location, double scale, int age)
{
  /*
   * mapping agent's age (from 20 to 99) to the range of
   * logistic distribution random varialbe, which is
   * -12 to 12
   */
  double RV = -12 + 23 * ((age-19)/80); //Random Variable mapping
  double Prob = GetLogisDist(location, scale, RV);
  double Roll = GetUnifDist(0,1);
  if (Roll <= Prob)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// compare random number with CHANCE OF GETTING MARRIED and arrange new weddings
bool Dist::GetMarried(int age)
{
  if (age < 20)
  {
    return false;
  }
  else if (20 <= age && age < 25)
  {
    if (this -> GetUnifDist(0,1) <= (MarriagePercentage[1]-MarriagePercentage[0])/5)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (25 <= age && age < 30)
  {
    if (this -> GetUnifDist(0,1) <= (MarriagePercentage[2]-MarriagePercentage[1])/5)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (30 <= age && age < 35)
  {
    if (this -> GetUnifDist(0,1) <= (MarriagePercentage[3]-MarriagePercentage[2])/5)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (35 <= age && age < 40)
  {
    if (this -> GetUnifDist(0,1) <= (MarriagePercentage[4]-MarriagePercentage[3])/5)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (age >= 40)
  {
    if (this -> GetUnifDist(0,1) <= MarriagePercentage[0]/5)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
return false;
}

// non home owners' decision making metric -- arrange new housing sales
bool Dist::GetHouse(double location, double scale, int age)
{
  /*
   * mapping agent's age (from 20 to 99) to the range of
   * logistic distribution random varialbe, which is
   * -12 to 12
   */
  double RV = -12 + 23 * ((age-19)/80); //Random Variable mapping
  double Prob = GetLogisDist(location, scale, RV);
  double Previous_Prob = 0.0;
  if (age > 20)
  {
    double Previous_RV = -12 + 23 * (((age-1)-19)/80); // Previous age
    double Previous_Prob = GetLogisDist(location, scale, Previous_RV);
  }
  double Probability=Prob-Previous_Prob;//if age 20 previous prob is 0
  double Roll = GetUnifDist(0,1);
  if (Roll <= Probability)
  {
    return true;
  }
  else
  {
    return false;
  }
}
