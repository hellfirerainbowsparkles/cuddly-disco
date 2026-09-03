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
    std::vector<std::string> keys = { "claim", "with" })
{
    using json = nlohmann::json;

    std::vector<std::vector<int>> values;
    std::ifstream f(file);

    if (!f.is_open())
    {
        printf("parse_json_int: could not open %s\n", file.c_str());
        return values;
    }

    try
    {
        json data = json::parse(f);

        // --------------------------------------------------
        // Fallback for JSON containing just one primitive:
        //
        // 2
        //
        // Return it as:
        // {{2}}
        // --------------------------------------------------
        if (!data.is_array() && !data.is_object())
        {
            std::vector<int> row;

            if (data.is_number_integer())
            {
                row.push_back(data.get<int>());
            }
            else if (data.is_number())
            {
                row.push_back(static_cast<int>(data.get<double>()));
            }
            else if (data.is_string())
            {
                row.push_back(
                    encodeString(data.get<std::string>())
                );
            }
            else
            {
                // null / bool / unsupported
                row.push_back(0);
            }

            values.push_back(row);
            return values;
        }


        // --------------------------------------------------
        // If the file contains one object instead of array,
        // convert it into an array containing that object.
        //
        // { "c": 1, "w": 2 }
        //
        // becomes logically:
        //
        // [ { "c": 1, "w": 2 } ]
        // --------------------------------------------------
        if (data.is_object())
        {
            json temp = json::array();
            temp.push_back(data);
            data = temp;
        }


        // --------------------------------------------------
        // Normal array processing
        // --------------------------------------------------
        for (const auto& item : data)
        {
            std::vector<int> keyvalues;

            // Array entry isn't an object.
            // Prevent item[key] on numbers/null/etc.
            if (!item.is_object())
            {
                if (item.is_number_integer())
                {
                    keyvalues.push_back(item.get<int>());
                }
                else if (item.is_number())
                {
                    keyvalues.push_back(
                        static_cast<int>(item.get<double>())
                    );
                }
                else if (item.is_string())
                {
                    keyvalues.push_back(
                        encodeString(item.get<std::string>())
                    );
                }
                else
                {
                    keyvalues.push_back(0);
                }

                values.push_back(keyvalues);
                continue;
            }


            for (const std::string& key : keys)
            {
                // ------------------------------------------
                // KEY DOES NOT EXIST
                // fallback = 0
                // ------------------------------------------
                if (!item.contains(key))
                {
                    keyvalues.push_back(0);
                    continue;
                }

                const json& value = item.at(key);


                // ------------------------------------------
                // NULL
                // fallback = 0
                // ------------------------------------------
                if (value.is_null())
                {
                    keyvalues.push_back(0);
                }

                // ------------------------------------------
                // INTEGER
                // ------------------------------------------
                else if (value.is_number_integer())
                {
                    keyvalues.push_back(
                        value.get<int>()
                    );
                }

                // ------------------------------------------
                // FLOAT
                // convert to int
                // ------------------------------------------
                else if (value.is_number())
                {
                    keyvalues.push_back(
                        static_cast<int>(
                            value.get<double>()
                        )
                    );
                }

                // ------------------------------------------
                // STRING
                // encode using your existing function
                // ------------------------------------------
                else if (value.is_string())
                {
                    keyvalues.push_back(
                        encodeString(
                            value.get<std::string>()
                        )
                    );
                }

                // ------------------------------------------
                // BOOLEAN
                // true = 1, false = 0
                // ------------------------------------------
                else if (value.is_boolean())
                {
                    keyvalues.push_back(
                        value.get<bool>() ? 1 : 0
                    );
                }

                // ------------------------------------------
                // Anything else:
                // arrays / nested objects / etc.
                // fallback = 0
                // ------------------------------------------
                else
                {
                    keyvalues.push_back(0);
                }
            }

            values.push_back(keyvalues);
        }
    }
    catch (const json::parse_error& e)
    {
        printf(
            "parse_json_int parse error %s: %s\n",
            file.c_str(),
               e.what()
        );
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
