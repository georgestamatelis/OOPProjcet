#pragma once

class Player;//forward declaretion

class phase4{
	private:
		void BuyProvince(Player &player);
		void BuyPersonality(Player &player);
	public:
		phase4(Player &player);
		~phase4();	
};