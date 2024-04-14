#ifndef MAINSTRUCT_H
#define MAINSTRUCT_H
using namespace std;

	struct setting {
		char loc[2][10] = {"canyon","forest"};
		char climate[4][30] = {"spring","summer","winter","fall"};
	};

	struct object { 
		string tree;
		string plant;
	};

	struct animal { /// animal float = hp
		float bear;
		float deer;
	};

	struct weapons { /// weapon float = damage
		float gun; 
		float dagger;
	};

	struct defense { /// defense float = armor
		float woodenArmor = 20.0;
		float steelArmor;
		float militaryArmor;
	};

	struct rule { /// mechanics 
		/// damage
		bool damaged;
		bool critical;
		bool stunned;
		bool lifesteal;
		bool missed;
	};        

	struct MoveChoice {
		bool attack;
		bool run;
	};

#endif
