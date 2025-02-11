#include <sstream>
#include "../dependencies/Functionalities.hpp"
#include "phase3.hpp"

using namespace std;

phase3::phase3(Player **pls, int n) : players(pls), num_of_players(n) {}

void phase3::Attack_Choice(int plindex)
{
  if (!players[plindex]->HasArmy())
  {
    cout << "Sorry you don't have army!" << endl;
    return;
  }
  int enemyIndex = -1;
  string enemyname;
  cout << "Which Player do you want to attack (please type his name as it was given [type=string])? ";
  enemyname = ReadString();
  for (int i = 0; i < num_of_players; i++)
    if (enemyname.compare(players[i]->GetName()) == 0)
      enemyIndex = i;
  while (enemyIndex < 0 || enemyIndex == plindex || enemyIndex >= num_of_players)
  {
    cout << "Wrong input. Please type the name of the player you want to attack: ";
    enemyname = ReadString();
    for (int i = 0; i < num_of_players; i++)
      if (enemyname.compare(players[i]->GetName())==0)
        enemyIndex = i;
  }
  cout << "Enemy Players Provinces are: " << endl;
  players[enemyIndex]->printProvinces();
  cout << "Which one do you want to attack: ";
  string answer;
  answer = ReadString();
  while (answer != "a" && answer != "b" && answer != "c" && answer != "d")
  {
    cout << "Sorry no such province. Try again: ";
    cin >> answer;
  }
  blackCard *underAttack = players[enemyIndex]->GetProvinces()[answer];
  if (underAttack->isKilled())
    return;
  bool input = false;
  vector<int> attackersVector;
  vector<Personality *> army = players[plindex]->getArmy();
  while (!input)
  {
	cout << "Your available army is: " << endl;
	players[plindex]->printArmy();
    int attackers;
    string answer;
    cout << "Which personality do you wanna use? ";
    attackers = ReadInt();
    if(attackers<=0 || attackers > army.size())
      cout<<"Sorry no such personality please try again"<<endl;
    if(find(attackersVector.begin(), attackersVector.end(), attackers - 1) != attackersVector.end())
      cout<<"You have already choosen that personality"<<endl;
    if (attackers >= 1 && attackers <= army.size() && find(attackersVector.begin(), attackersVector.end(), attackers - 1) == attackersVector.end())
      attackersVector.push_back(attackers - 1);
    cout << "Do you wanna use more personalities? (y/n): ";
    if (!YesOrNo())
      input = true;
  }
  //time for attack
  int totaldamage = 0;
  for (int i = 0; i < attackersVector.size(); i++)
  {
    if (army[attackersVector[i]]->canUse())
      totaldamage += army[attackersVector[i]]->getAttack();
  }

  bool loss = false;
  int provinceDefence = players[enemyIndex]->getInitalDefense();
  int personalityDefence = underAttack->getDefence();
  SetToRed();
  cout << "Total Damage " << totaldamage << "prD " << provinceDefence << "personD " << personalityDefence << endl;
  SetToDefault();
  if (totaldamage >= (personalityDefence + provinceDefence))
  {
    //attacker wins
    cout << "ATTACKER WINS THE BATTLE" << endl;
    players[enemyIndex]->looseDefencePersonalities(answer, personalityDefence + provinceDefence);
    players[enemyIndex]->looseProvince(answer);
    return;
  }
  else if (totaldamage >= personalityDefence && totaldamage < personalityDefence + provinceDefence)
  { //lose some attackers and all defenders
    loss = true;
    players[enemyIndex]->looseDefencePersonalities(answer, personalityDefence + provinceDefence);
    int totalLoss = totaldamage - personalityDefence; //+provincedefence;
    for (int i = 0; i < attackersVector.size(); i++)
    {
      totalLoss -= army[attackersVector[i]]->getAttack();
      players[plindex]->loosePersonalty(army[attackersVector[i]]->getname());
      if (totalLoss <= 0)
        break;
    }
  }
  else if (totaldamage == personalityDefence)
  {
    //lose
    loss = true;
    players[enemyIndex]->looseDefencePersonalities(answer, personalityDefence); //loose all defenders
    //+loose all attackeras
    for (int i = 0; i < attackersVector.size(); i++)
    {
      players[plindex]->loosePersonalty(army[attackersVector[i]]->getname());
    }
  }
  else if (totaldamage < personalityDefence)
  {
    loss = true;
    for (int i = 0; i < attackersVector.size(); i++)
    {
      players[plindex]->loosePersonalty(army[attackersVector[i]]->getname());
    }

    int totalLoss = personalityDefence - totaldamage;
    underAttack->loosePersonalties(totalLoss);
  }
  if (loss)
  {
     //attacking personalities that lost battle loose item durabilty and or items they get tapped and loosehonr
    players[plindex]->looseHonor();
    for (int i = 0; i < attackersVector.size(); i++)
    {
      if (!army[attackersVector[i]]->isKilled())
      {
        army[attackersVector[i]]->tapFollowers();
        army[attackersVector[i]]->tap();
        army[attackersVector[i]]->looseHonor();
        army[attackersVector[i]]->hurtItems(); //item durability -=1 for each item of personality
      }
    }
  }
}

void phase3::defence_Choise(int plindex)
{

  if (plindex >= num_of_players)
    return;
  if (!players[plindex]->HasArmy())
  {
    cout << "Sorry you don't have army" << endl;
    return;
  }

  Player *temp_p = players[plindex];
  unordered_map<string, blackCard *> &provinces = temp_p->GetProvinces();
  string prDef;

  cout << "Your  Province are :" << endl;
  players[plindex]->printProvinces();
  cout << "Which province do you wanna defend? "; //<<endl;
  cin >> prDef;
  while (provinces.find(prDef) == provinces.end())
  {
    cout << "Sorry there is no such province. Try again: ";
    cin >> prDef;
  }
  cout << "Your available army is: " << endl;
  players[plindex]->printArmy();
  blackCard *underAttack = (blackCard *)provinces[prDef];
  bool endinput = false;
  vector<int> defencePers;
  vector<Personality *> army = temp_p->getArmy();
  while (!endinput)
  {
    int defendant;
    //string defendant,answer;
    cout << "Which personalities will defend it? ";
    defendant = ReadInt();
    if (defendant >= 1 && defendant <= army.size())
      defencePers.push_back(defendant - 1);
    cout << "Do you wanna use more personalities? (y/n): ";
    if (!YesOrNo())
      break;
  }
  //done with input now time to add defendants to province
  for (int i = 0; i < defencePers.size(); i++)
    if (army[defencePers[i]]->canUse())
      underAttack->addDefandant(army[i]);
}

void phase3::play()
{
  SetToYellow();
  cout<<"┌────────────────────────┐\n"
	  <<"│ Phase 3 [Battle phase] │\n"
	  <<"V                        V\n"<<endl;
  SetToDefault();
  cin.clear();
  string line;
  int choice = 0;
  qsort(players, num_of_players, sizeof(Player *), Honorcompare);
  for (int i = 0; i < num_of_players; i++)
  {
    SetToYellow();
    cout << "Player '" << players[i]->GetName() << "' turn:" << endl;
    SetToDefault();
    cout << "Type 1 for attack options ,2 for defence options, 3 to end your turn: ";
    choice = ReadInt();
    while (choice < 1 || choice > 3)
    {
      cout << "Please type a number between 1 and 3. Try again: ";
      choice = ReadInt();
    }

    switch (choice)
    {
    case 1:
      Attack_Choice(i);
      break;
    case 2:
      defence_Choise(i);
      break;
    case 3:
      break;
    default:
      cout << "Something went wrong" << endl;
      break;
    }
  }
}

phase3::~phase3()
{
  cout << "End of phase 3" << endl;
}
