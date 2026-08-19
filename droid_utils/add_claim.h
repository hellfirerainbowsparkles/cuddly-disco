#include <fstream>
#include <stdexcept>

using json = nlohmann::json;

void addClaim(const std::string& filename,
              const std::string& claim,
              const std::string& with)
{
    json data;

    // Read existing file
    {
        std::ifstream in(filename);
        if (in.good()) {
            in >> data;
        } else {
            // If the file doesn't exist, start with an empty array.
            data = json::array();
        }
    }

    if (!data.is_array()) {
        throw std::runtime_error("JSON root is not an array.");
    }

    // Append the new object
    data.push_back({
        {"claim", claim},
        {"with", with}
    });

    // Write it back
    {
        std::ofstream out(filename);
        out << data.dump(4); // Pretty-print with 4-space indentation
    }
}
