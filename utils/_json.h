#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>


std::vector<std::vector<std::string>> parse_json(std::string file="traits.json", std::vector<std::string> keys = {"action", "content"}) {

    using json = nlohmann::json;
    std::ifstream f(file);
    std::vector<int> installments = {};
    std::vector<std::vector<std::string>> values = {};
    try {
        json data = json::parse(f);
        for (int i=0; i<data.size(); i++) {
            std::vector<std::string> keyvalues = {};
            int installment = 0;
            for (int k=0; k<keys.size(); k++) {
                std::string key = keys[k];
                std::string content = data[i][key.c_str()];
                printf("%s: %s\n", key.c_str(), content.c_str());
                installment += casting_program(key.c_str()) + casting_program(content.c_str());
                keyvalues.push_back(content);
            }
            installments.push_back(installment);
            values.push_back(keyvalues);
        }
    }
    catch (const std::exception& e) {
        printf("parse_json error %s\n", file.c_str());
    }

    return values; //installments;

}


int parse_json_as_int(std::string file="claims.json", std::vector<std::string> keys = {"claim", "with"} ) {

    int integer = 0;
    std::vector<std::vector<std::string>> claims = parse_json(file, keys);
    for (int i=0; i<claims.size(); i++) { for (int q=0; q<claims[i].size(); q++) {

        integer += casting_program(claims[i][q]);
    }}


    int z = casting_program("the relationship between the keys") + casting_program("the domain of the relationship");
    return integer + z;

}


// Global string <-> integer mapping
std::unordered_map<std::string, int> stringToInt;
std::vector<std::string> intToString;


// Convert string to integer.
// Existing strings always return the same integer.
int encodeString(const std::string& value)
{
    auto it = stringToInt.find(value);

    if (it != stringToInt.end())
        return it->second;

    int id = static_cast<int>(intToString.size());

    stringToInt[value] = id;
    intToString.push_back(value);

    return id;
}


// Convert integer back to original string.
std::string decodeString(int value)
{
    if (value < 0 || value >= static_cast<int>(intToString.size()))
        return "";

    return intToString[value];
}


std::vector<std::vector<int>> parse_json_int(
    std::string file = "claims.json",
    std::vector<std::string> keys =
    { "claim", "with" }) {
    using json = nlohmann::json;
    std::ifstream f(file);
    std::vector<std::vector<int>> values;

    try
    {
        json data = json::parse(f);

        for (int i = 0; i < data.size(); i++)
        {
            std::vector<int> keyvalues;

            for (int k = 0; k < keys.size(); k++)
            {
                std::string key = keys[k];

                if (data[i][key].is_string())
                {
                    std::string content =
                    data[i][key].get<std::string>();

                    keyvalues.push_back(encodeString(content));
                }
                else
                {
                    int content =
                    data[i][key].get<int>();

                    keyvalues.push_back(content);
                }
            }

            values.push_back(keyvalues);
        }
    }
    catch (const std::exception& e)
    {
        printf(
            "parse_json_int error %s: %s\n",
            file.c_str(),
               e.what()
        );
    }

    return values;
}


int parse_droid_json(std::string file="dependencies/gmmm/mem.json") {

    std::vector<std::string> keys = { "id", "cmd", "structure", "mind", "evolution" };
    std::vector<std::vector<int>> json_data = parse_json_int(file);
    //int droid_json = recursive_construction(json_data[0]);



    int droid_instance = _programs->installer();
    for (int i=0; i<json_data.size(); i++) {
        for (int r=0; r<json_data[i].size(); r++) {
            printf("[ %d ]\n", json_data[i][r]);
            droid_instance += json_data[i][r] * plane(4);
        }
    }
    //droid_instance += droid_json;
    return activate_cube(asm_iron_stack(droid_instance));

}


/*
 s td*::vector<std::vector<int>>  parse_json_int(std::string file="traits.json", std::vector<std::string> keys =  { "id", "cmd", "structure", "mind", "evolution" }) {

 using json = nlohmann::json;
 std::ifstream f(file);
 std::vector<std::vector<int>> values = {};
 try {
 json data = json::parse(f);
 for (int i=0; i<data.size(); i++) {
     std::vector<int> keyvalues = {};
     int installment = 0;
     for (int k=0; k<keys.size(); k++) {
         std::string key = keys[k];
         int content = data[i][key.c_str()];
         keyvalues.push_back(content);
         }
         values.push_back(keyvalues);
         }
         }
         catch (const std::exception& e) {
         printf("parse_json_int error %s\n", file.c_str());
         }



         return values;

         }*/
