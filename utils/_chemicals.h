#include <map>

int acetylcholine() { return 7; }

int arsenic() { return 7; }

int chemical(std::string n) { return 7; }

int fusion(bool cycle = true) { return 7; }

int gold() { return 7; }

int iron() { return 7; }
/*
    // amino acids
    {"arginine", acid + (6+14+4+2) },
    {"histidine", acid + (6+9+3+2) },
    {"lysine", acid + (6+14+2+2) },
    {"aspartic acid", acid + (4+7+4) },
    {"NMDA", acid + (5 + 9 + 1 + 4) },
    {"glutamic acid", acid + (5+9+4) },
    {"serine", acid + (3+7+3) },
    {"threonine", acid + (4+9+3) },
    {"asparagine", acid + (4+8+2+3)},
    {"glutamine", acid + (5+10+2+3) },
    {"cysteine", acid + (4+7+2) },
    {"glycine", acid + (2+5+2) },
    {"proline", acid + (5+9+2)},
    {"alanine", acid + (3+7+2) },
    {"valine", acid + (5+11+2) },
    {"isoleucine", acid + (6+13+2) },
    {"leucine", acid + (6+13+2) },
    {"methionine", acid + (5+11+2) },
    {"phenylalanine", acid + (9+11+2) },
    {"tyrosine", acid + (9+11+3) },
    {"tryptohen", acid + (11+12+2+2) },

    // blood
    {"nitrogen", 2},
    {"carbon", 1},
    {"iron", 1},
    // milk chemicals
    {"Na", 1},
    {"K", 1},
    {"Ca", 1},
    {"Mg", 1},
    {"P", 1},
    {"C1", 1},
    // milk proteins
    {"casein", 81 + 125 + 22 + 39 + 1 },
    {"a-lactalbumin", 123 + 4 },
    {"lactoferrin", 35 + 53 + 9 + 12 },
    {"secretory immunoglobulin IgA", (1+1+2+3)*4 + (1+1)},
    {"lysozyme", 99 + 159 + 37 + 23 },
    {"serum albumin", 123 + 193 + 35 + 37},
    // lactose synthase (milk synthesis)
    {"N-acetyllactosamine", 14 + 25 + 1 + 11 },
    {"alpha-lactalbumin", 123 + 4 },

    // ...
    {"immunoglobulin", (1+1+2+3)*4 + (1+1)},
    {"epinephrine", 9+13+3 },
    {"norepinephrine", 8+11+3 },
    {"half-cystine", 6 + 12 + 2 + 4 + 2 },
    {"leucine", 6 + 13 + 1 + 2},
    {"keratin", 28 + 48 + 2 + 32 + 4},

    // vaginal fluid
    {"sialoglycoprotein", 12 + 19 + 11 },
    {"albumin", 6 + 8 + 2 + 4 },
    {"urea", 1 + 4 + 2 },


    {"GABA", 4+9+2 },
    {"Substance P", 63+98+18+13 },
    {"Neuropeptide Y", 189 + 285 + 55 + 57 + 1 },

    // bone
    {"hydroxyapatite", (10 + (4*6) + 2) * metals["molybdenum"]},

    // pineal gland chemical
    {"melatonin", 13 + 16 + 2 + 2},

    // SCN neurotransmittors
    {"acetylcholine", 7 + 16 + 1 + 2},
    {"glutamate", 5 + 8 + 1 + 4},
    {"neuropeptide Y", 190 + 287 + 55 + 57},
    {"serotonin", 10 + 12 + 2 + 1 },
    {"vasoactive intestinal peptide", 147 + 237 + 43 + 43},
    {"peptide histidine isoleucine", 27 },
    {"argine vasopressin", 46 + 65 + 15 + 12 + 2},

    {"tar", 4+6+6},

    // all metals in the body
    {"H", molecule + 1 + 1},
    {"He", molecule + 1 + 2 },
    {"C", molecule + 1 + 2 + 4},
    {"N", molecule + 1 + 2 + 5},
    {"O", molecule + 1 + 2 + 6},
    {"oxygen", 2*(molecule + 1 + 2 + 6)},
    {"hydrogen", 2*( molecule + 1 + 1) + (molecule + 1 + 2 + 6)},
    {"Na", molecule + 1 + 2 + 8 + 1},
    {"K", molecule + 1 + 2 + 8 + 8 + 1},
    {"Mg", molecule + 1 + 2 + 8 + 2},
    {"Ca", molecule + 1 + 2 + 8 + 8 + 2},
    {"calcium oxalate", (molecule + 1 + 2 + 8 + 8 + 2) + (2*( molecule + 1 + 2 + 4)) + (4* (molecule + 1 + 2 + 6)) } ,
    {"Cl", molecule + 1 + 2 + 8 + 7},
    {"P", molecule + 1 + 2 + 8 + 5 },
    {"S", molecule + 1 + 2 + 8 + 6 },
    {"Mn", molecule + 1 + 2 + 8 + 13 + 2 },
    {"Fe", molecule + 1 + 2 + 8 + 14 + 2 },
    {"Cu", molecule + 1 + 2 + 8 + 18 + 1 },
    {"Zn", molecule +1 + 2 + 7 + 18 },
    {"Se", molecule + 1 + 2 + 8 + 18 + 6},
    {"Co", molecule +1 + 2 + 8 + 15 + 2},
    {"Mo", molecule +1 + 2 + 8 + 18 + 13 + 1},
    {"F", molecule + 9},
    {"fluorine", molecule + 9 + 9 },
    {"sulfur dioxide", molecule + 1 + 2 + (1*( 1 + 2 + 8 + 6) + 2*(1 + 2 + 6)) },


    // fusion
    {"deuterium", molecule + 1 -1 +1 },
    {"tritium", molecule + 1 - 2 + 1 },

    // vitamins
    {"Vitamin A", 20 + 30 + 1},
    {"Provitamin", 40 + 56 },
    {"Vitamin B1", 12 + 17 + 5 + 4 },
    {"Vitamin B2", 17 + 20 + 4 + 6 },
    {"Vitamin B3", 6 + 5 + 1 + 2 },
    {"Vitamin B5", 9 + 17 + 5 },
    {"Vitamin B6", 8 + 12 + 2 + 2 },
    {"Vitamin B7", 10 + 16 + 2 + 3 },
    {"Vitamin B9", 19 + 19 + 7 + 6 },
    {"Vitamin B12", 63 + 88 + 1 + 14 + 14 + 1 },
    {"Vitamin C", 3 + 4 + 3 },
    {"Vitamin D3", 27 + 44 + 1 },
    {"Vitamin E", 29 + 50 + 2 },
    {"Vitamin K", 13 + 16 + 1 + 1 + 1 },
    {"Vitamin P", 28 + 34 + 15 },

    // white blood cells
    {"granulocytes", 1+8*8 },
    {"neutrophils", 1+8*8 },
    //{"proteolytic enzymes", },
    {"trypsin", 35 + 47 + 7 + 10 },
    {"chymotrypsin", 13 + 131 + 97 },
    {"elastase", 238 },
    {"cationic proteins", 400 + 620 + 100 + 120 + 1 + 1 },

    {"eosinophils", 1+8*8 },
    {"eosinophil peroxidase", 22 + 2 + 2 },
    {"ribonuclease", 124 },
    {"deoxyribonucleases", 260 },
    {"lipase", 11 + 9 + 3 + 1 + 2 },
    {"plasminogen", 5},

    {"basophils", 1+8*8 },
    // histamine
    {"heparine", 12 + 19 + 1 + 20 + 3 },
    {"lymphocytes", 1+8*8 },
    {"T cells", 1*8*8},
    {"perforin", 555 },
    {"granzyme B", (2 * 6)+3 },
    {"B cells", (2+2) + 1*8*8},
    {"B cell co-receptor complex", 19 + 21 + 81},
    {"monocytes", 14 + 16 },

    // digestive enzymes
    /*{"nuclease", },
     { "*amylase", },
     {"peptidase", },
     {"lipase", },
     *
    {"staphylococcal nuclease", 149 + (3 * (4+7)) + (5 * 12500 + (12*5)) },

    // red blood cells
    {"hemoglobin", 13 + 10 + 2 + 2},

    {"growth hormone", 72 + 132 },

    // laughing
    {"dopamine", (8 + 11 + 1 + 2) + 16 + (8*8) },
    {"oxytocin", (43 + 66 + 12 + 12 + 2) + 7 + (8*8)},
    {"endorphins", (77 + 120 + 18 + 26 + 1) + 7 + (8*8)},

    // ...
    {"adrenaline", 10 + 15 + 1 + 3 },
    {"cortisol", 21 + 30 + 5 },
    {"DMT", 10 + 10 + 4 },
    {"serotonine", 10 + 12 + 2 },
    {"y-aminobutyric acid", 4 + 9 + 1 + 2 },
    {"phospholipids", numerology((718 + (120*5)) + ((1 + 2 + 1 + 1 + 1 + 1 + 1 + 2 + 1) + (1+4) + (3*9) + (39+75+10+1)) + metals["molybdenum"] + metals["high steel"])},
    {"glucose", 6+12+6},
    {"potassium", 2 },

    // sperm
    {"phosphorylcholine", 5 + 14 + 1 + 4 },
    {"prostaglandins", 20 + 32 + 5 },
    {"citrate", 6 + 5 + 7 + 3 },
    {"fructose", 6 + 12 + 6 },
    {"flavin", 17 + 21 + 4 + 9},

    // eye retina light chemical
    {"retinal", 20 + 28 + 1},

    // fat
    {"fat", 55 + 104 + 6 },
    {"oleate", 18 + 34 + 2 },
    {"palmitate", 16 + 32 + 2 },
    {"linoleate", 18 + 32 + 2 },

    // tears
    {"mucin", 6 + 10 + 8 },
    {"lipids", 3 + 2 + 1 + 1 + 1 + 1 },
    {"lipocalin", 8 + 1},
    {"lacritin", 119 + 2 + 5 },

    // urine
    {"creatinine", 4 + 7 + 30 },
    {"uric acid", 5 + 4 + 4 + 3},

    {"cholesterol", 27 + 46 + 1},
    {"ethanol", (2+ 2 + 2 + 2 +1 )},

    // DNA & RNA
    {"deoxyribonucleic acid", forward_spiral_numerology((2*crystals["quartz"] + lightning()) + 1 + (15 + 31 + 3 + 13 + 2)+((23*8)+(23*8))+(16 + 6 + 2)+(8*8) + forward_spiral_numerology((1+1+2+8), (1+1+2+8), (1+1+2+8), 360/(1+1+2+8), (1+1+2+8)) + elements["plasma"], 1, 1, 45, 128 ) },
    {"ribose", 1 + (4 + lightning()) + 5 + 10 + 5 + (12*5) + (128 * metals["molybdenum"]) },
    // hearing gene
    //{"GJB2-GT", 2 + 5 + 5 + 6},
    // seeing gene
    //{"70BMP4", 2 + 5 + 5 + 6},
    {"genes", 2 + 5 + 5 + 6 + (8*8)},

    // rubber
    {"isoprene", molecule + 5 + 8},
    // silicone polymer
    {"silicon", molecule + (2+8+4) + (1+4+1)},
    {"boron", molecule + (2+3) },

    {"carbon", molecule + (2+4) },

    // enzymes (produce)
    {"enzymes", 4 + (5 + 2) + elements["electricity"] },
    // enzymes for glutamate (Seeing and more)
    {"aminotransferases", 11 + 16 + 2 + 6 },
    {"glutamate dehydrogenase", 1 + 3 + 1 + 1 + 1 + 1 + 1 + 1 },
    {"glutamine syntetase", 12 + 2 + (2*6) + 4 },
    {"phostphate-activated glutaminase", 5 + 10 + 2 + 3 + light },

    // phytohormones (plants)
    {"phytohormones", 5},
    {"auxin", 10 + 9 + 1 + 2 },
    {"gibberellin", 19 + 22 + 6 },
    {"cytokinin", 6 },
    {"ethylene", 2 + 4 },
    {"abscisic acid", 15 + 20 + 4 },


    {"shark liver oil", 5},
    {"tocopherol", 29 + 50 + 2 },
    {"squalene", 30 + 50 },

    {"nicotine", 10 + 14 + 2},
    {"caffeine", 8 + 10 + 4 + 2},

};
int acid = elements["acid"];
std::map<std::string, int> chemicals {
		// amino acids
		{"arginine", acid + (6+14+4+2) },
		{"histidine", acid + (6+9+3+2) },
		{"lysine", acid + (6+14+2+2) },
		{"aspartic acid", acid + (4+7+4) },
		{"NMDA", acid + (5 + 9 + 1 + 4) },
		{"glutamic acid", acid + (5+9+4) },
		{"serine", acid + (3+7+3) },
		{"threonine", acid + (4+9+3) },
		{"asparagine", acid + (4+8+2+3)},
		{"glutamine", acid + (5+10+2+3) },
		{"cysteine", acid + (4+7+2) },
		{"glycine", acid + (2+5+2) },
		{"proline", acid + (5+9+2)},
		{"alanine", acid + (3+7+2) },
		{"valine", acid + (5+11+2) },
		{"isoleucine", acid + (6+13+2) },
		{"leucine", acid + (6+13+2) },
		{"methionine", acid + (5+11+2) },
		{"phenylalanine", acid + (9+11+2) },
		{"tyrosine", acid + (9+11+3) },
		{"tryptohen", acid + (11+12+2+2) },

		// blood
		{"nitrogen", 2},
		{"carbon", 1},
		{"iron", 1},
		// milk chemicals
		{"Na", 1},
		{"K", 1},
		{"Ca", 1},
		{"Mg", 1},
		{"P", 1},
		{"C1", 1},
		// milk proteins
		{"casein", 81 + 125 + 22 + 39 + 1 },
		{"a-lactalbumin", 123 + 4 },
		{"lactoferrin", 35 + 53 + 9 + 12 },
		{"secretory immunoglobulin IgA", (1+1+2+3)*4 + (1+1)},
		{"lysozyme", 99 + 159 + 37 + 23 },
		{"serum albumin", 123 + 193 + 35 + 37},
		// lactose synthase (milk synthesis)
		{"N-acetyllactosamine", 14 + 25 + 1 + 11 },
		{"alpha-lactalbumin", 123 + 4 },

		// ...
		{"immunoglobulin", (1+1+2+3)*4 + (1+1)},
		{"epinephrine", 9+13+3 },
		{"norepinephrine", 8+11+3 },
		{"half-cystine", 6 + 12 + 2 + 4 + 2 },
		{"leucine", 6 + 13 + 1 + 2},
		{"keratin", 28 + 48 + 2 + 32 + 4},

		// vaginal fluid
		{"sialoglycoprotein", 12 + 19 + 11 },
		{"albumin", 6 + 8 + 2 + 4 },
		{"urea", 1 + 4 + 2 },


		{"GABA", 4+9+2 },
		{"Substance P", 63+98+18+13 },
		{"Neuropeptide Y", 189 + 285 + 55 + 57 + 1 },

		// bone
		{"hydroxyapatite", (10 + (4*6) + 2) * metals["molybdenum"]},

		// pineal gland chemical
		{"melatonin", 13 + 16 + 2 + 2},

		// SCN neurotransmittors
		{"acetylcholine", 7 + 16 + 1 + 2},
		{"glutamate", 5 + 8 + 1 + 4},
		{"neuropeptide Y", 190 + 287 + 55 + 57},
		{"serotonin", 10 + 12 + 2 + 1 },
		{"vasoactive intestinal peptide", 147 + 237 + 43 + 43},
		{"peptide histidine isoleucine", 27 },
		{"argine vasopressin", 46 + 65 + 15 + 12 + 2},

		{"tar", 4+6+6},

		// all metals in the body
		{"H", molecule + 1 + 1},
		{"He", molecule + 1 + 2 },
		{"C", molecule + 1 + 2 + 4},
		{"N", molecule + 1 + 2 + 5},
		{"O", molecule + 1 + 2 + 6},
		{"oxygen", 2*(molecule + 1 + 2 + 6)},
		{"hydrogen", 2*( molecule + 1 + 1) + (molecule + 1 + 2 + 6)},
		{"Na", molecule + 1 + 2 + 8 + 1},
		{"K", molecule + 1 + 2 + 8 + 8 + 1},
		{"Mg", molecule + 1 + 2 + 8 + 2},
		{"Ca", molecule + 1 + 2 + 8 + 8 + 2},
		{"calcium oxalate", (molecule + 1 + 2 + 8 + 8 + 2) + (2*( molecule + 1 + 2 + 4)) + (4* (molecule + 1 + 2 + 6)) } ,
		{"Cl", molecule + 1 + 2 + 8 + 7},
		{"P", molecule + 1 + 2 + 8 + 5 },
		{"S", molecule + 1 + 2 + 8 + 6 },
		{"Mn", molecule + 1 + 2 + 8 + 13 + 2 },
		{"Fe", molecule + 1 + 2 + 8 + 14 + 2 },
		{"Cu", molecule + 1 + 2 + 8 + 18 + 1 },
		{"Zn", molecule +1 + 2 + 7 + 18 },
		{"Se", molecule + 1 + 2 + 8 + 18 + 6},
		{"Co", molecule +1 + 2 + 8 + 15 + 2},
		{"Mo", molecule +1 + 2 + 8 + 18 + 13 + 1},
		{"F", molecule + 9},
		{"fluorine", molecule + 9 + 9 },
		{"sulfur dioxide", molecule + 1 + 2 + (1*( 1 + 2 + 8 + 6) + 2*(1 + 2 + 6)) },


		// fusion
		{"deuterium", molecule + 1 -1 +1 },
		{"tritium", molecule + 1 - 2 + 1 },

		// vitamins
		{"Vitamin A", 20 + 30 + 1},
		{"Provitamin", 40 + 56 },
		{"Vitamin B1", 12 + 17 + 5 + 4 },
		{"Vitamin B2", 17 + 20 + 4 + 6 },
		{"Vitamin B3", 6 + 5 + 1 + 2 },
		{"Vitamin B5", 9 + 17 + 5 },
		{"Vitamin B6", 8 + 12 + 2 + 2 },
		{"Vitamin B7", 10 + 16 + 2 + 3 },
		{"Vitamin B9", 19 + 19 + 7 + 6 },
		{"Vitamin B12", 63 + 88 + 1 + 14 + 14 + 1 },
		{"Vitamin C", 3 + 4 + 3 },
		{"Vitamin D3", 27 + 44 + 1 },
		{"Vitamin E", 29 + 50 + 2 },
		{"Vitamin K", 13 + 16 + 1 + 1 + 1 },
		{"Vitamin P", 28 + 34 + 15 },

		// white blood cells
		{"granulocytes", 1+8*8 },
			{"neutrophils", 1+8*8 },
				//{"proteolytic enzymes", },
					{"trypsin", 35 + 47 + 7 + 10 },
					{"chymotrypsin", 13 + 131 + 97 },
					{"elastase", 238 },
				{"cationic proteins", 400 + 620 + 100 + 120 + 1 + 1 },

			{"eosinophils", 1+8*8 },
				{"eosinophil peroxidase", 22 + 2 + 2 },
				{"ribonuclease", 124 },
				{"deoxyribonucleases", 260 },
				{"lipase", 11 + 9 + 3 + 1 + 2 },
				{"plasminogen", 5},

			{"basophils", 1+8*8 },
				// histamine
				{"heparine", 12 + 19 + 1 + 20 + 3 },
		{"lymphocytes", 1+8*8 },
			{"T cells", 1*8*8},
				{"perforin", 555 },
				{"granzyme B", (2 * 6)+3 },
			{"B cells", (2+2) + 1*8*8},
				{"B cell co-receptor complex", 19 + 21 + 81},
		{"monocytes", 14 + 16 },

		// digestive enzymes
		/*{"nuclease", },
		{"amylase", },
		{"peptidase", },
		{"lipase", },
		*
		{"staphylococcal nuclease", 149 + (3 * (4+7)) + (5 * 12500 + (12*5)) },

		// red blood cells
		{"hemoglobin", 13 + 10 + 2 + 2},

		{"growth hormone", 72 + 132 },

		// laughing
		{"dopamine", (8 + 11 + 1 + 2) + 16 + (8*8) },
		{"oxytocin", (43 + 66 + 12 + 12 + 2) + 7 + (8*8)},
		{"endorphins", (77 + 120 + 18 + 26 + 1) + 7 + (8*8)},

		// ...
		{"adrenaline", 10 + 15 + 1 + 3 },
		{"cortisol", 21 + 30 + 5 },
		{"DMT", 10 + 10 + 4 },
		{"serotonine", 10 + 12 + 2 },
		{"y-aminobutyric acid", 4 + 9 + 1 + 2 },
		{"phospholipids", numerology((718 + (120*5)) + ((1 + 2 + 1 + 1 + 1 + 1 + 1 + 2 + 1) + (1+4) + (3*9) + (39+75+10+1)) + metals["molybdenum"] + metals["high steel"])},
		{"glucose", 6+12+6},
		{"potassium", 2 },

		// sperm
		{"phosphorylcholine", 5 + 14 + 1 + 4 },
		{"prostaglandins", 20 + 32 + 5 },
		{"citrate", 6 + 5 + 7 + 3 },
		{"fructose", 6 + 12 + 6 },
		{"flavin", 17 + 21 + 4 + 9},

		// eye retina light chemical
		{"retinal", 20 + 28 + 1},

		// fat
		{"fat", 55 + 104 + 6 },
			{"oleate", 18 + 34 + 2 },
			{"palmitate", 16 + 32 + 2 },
			{"linoleate", 18 + 32 + 2 },

		// tears
		{"mucin", 6 + 10 + 8 },
		{"lipids", 3 + 2 + 1 + 1 + 1 + 1 },
		{"lipocalin", 8 + 1},
		{"lacritin", 119 + 2 + 5 },

		// urine
		{"creatinine", 4 + 7 + 30 },
		{"uric acid", 5 + 4 + 4 + 3},

		{"cholesterol", 27 + 46 + 1},
		{"ethanol", (2+ 2 + 2 + 2 +1 )},

		// DNA & RNA
		{"deoxyribonucleic acid", forward_spiral_numerology((2*crystals["quartz"] + lightning()) + 1 + (15 + 31 + 3 + 13 + 2)+((23*8)+(23*8))+(16 + 6 + 2)+(8*8) + forward_spiral_numerology((1+1+2+8), (1+1+2+8), (1+1+2+8), 360/(1+1+2+8), (1+1+2+8)) + elements["plasma"], 1, 1, 45, 128 ) },
		{"ribose", 1 + (4 + lightning()) + 5 + 10 + 5 + (12*5) + (128 * metals["molybdenum"]) },
		// hearing gene
		//{"GJB2-GT", 2 + 5 + 5 + 6},
		// seeing gene
		//{"70BMP4", 2 + 5 + 5 + 6},
		{"genes", 2 + 5 + 5 + 6 + (8*8)},

		// rubber
		{"isoprene", molecule + 5 + 8},
		// silicone polymer
		{"silicon", molecule + (2+8+4) + (1+4+1)},
		{"boron", molecule + (2+3) },

		{"carbon", molecule + (2+4) },

		// enzymes (produce)
		{"enzymes", 4 + (5 + 2) + elements["electricity"] },
			// enzymes for glutamate (Seeing and more)
			{"aminotransferases", 11 + 16 + 2 + 6 },
			{"glutamate dehydrogenase", 1 + 3 + 1 + 1 + 1 + 1 + 1 + 1 },
			{"glutamine syntetase", 12 + 2 + (2*6) + 4 },
			{"phostphate-activated glutaminase", 5 + 10 + 2 + 3 + light },

		// phytohormones (plants)
		{"phytohormones", 5},
			{"auxin", 10 + 9 + 1 + 2 },
			{"gibberellin", 19 + 22 + 6 },
			{"cytokinin", 6 },
			{"ethylene", 2 + 4 },
			{"abscisic acid", 15 + 20 + 4 },


		{"shark liver oil", 5},
			{"tocopherol", 29 + 50 + 2 },
			{"squalene", 30 + 50 },

		{"nicotine", 10 + 14 + 2},
		{"caffeine", 8 + 10 + 4 + 2},

	};
*/
