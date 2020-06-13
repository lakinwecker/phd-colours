#include "vivid.h"

#include <range/v3/range_for.hpp>
#include <fort.hpp>
#include <fmt/core.h>


#include <iostream>
#include <string>
#include <vector>

using namespace vivid;

struct MyColor {
    std::string name;
    Color color;
};

int main() {
    std::vector<MyColor> colors = {
        {"dark_blue_normal", Color("#074c61")},
        {"dark_blue_dark", Color("#294550")},
        {"light_blue_normal", Color("#0d90b9")},
        {"light_blue_dark", Color("#4f6d7a")},
        {"dark_green", Color("#386641")},
        {"light_green", Color("#6a994e")},
        {"dark_red", Color("#b42e30")},
        {"light_red", Color("#db504a")},
        {"yellow", Color("#e3b506")},
        {"yellow_brown_spectrum_1", Color("#ecce5c")},
        {"yellow_brown_spectrum_2", Color("#e3b506")},
        {"yellow_brown_spectrum_3", Color("#da9b04")},
        {"yellow_brown_spectrum_4", Color("#483a06")},
        {"blue_spectrum_1", Color("#2da0c4")},
        {"blue_spectrum_2", Color("#0d90b9")},
        {"blue_spectrum_3", Color("#07678b")},
        {"blue_spectrum_4", Color("#073d51")},
    };

    fort::char_table table;
    table
        << fort::header
        << "My Name"
        << "Actual Name"
        << "Hex"
        << "Char"
        << "Float"
        << "Quick Info"
        << fort::endr;


    for(auto const &c : colors) {
    }
    for(auto const &c : colors) {
        auto const r8 = c.color.rgb8();
        table
            << c.name
            << c.color.name()
            << c.color.hex()
            << fmt::format("rgb({}, {}, {})", r8.r, r8.g, r8.b)
            << fmt::format("rgb({}, {}, {})", r8.r/255.f, r8.g/255.f, r8.b/255.f)
            << c.color.quickInfo()
            << fort::endr;
    }
    std::cout << table.to_string() << std::endl;

}
