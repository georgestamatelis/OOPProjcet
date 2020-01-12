
#pragma once

class Player;//forward declaretion

class phase4{
	private:
		Player **players;
		int num_of_players;
		void BuyProvince(Player &player);
		void BuyPersonality(Player &player);
		bool YesOrNo();
	public:
		phase4(Player **players,int num_of_players);
		void play();
		~phase4();
};
