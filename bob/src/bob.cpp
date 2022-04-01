#include "bob.hpp"

#include <ctype.h>
#include <algorithm>

bool is_all_capitals(std::string_view msg) {
    bool contains_alpha = false;

    for (auto& ch : msg)
        if (isalpha(ch)) {
            contains_alpha = true;

            if (islower(ch))
                return false;
        }
            

    return contains_alpha;
}

namespace bob {
    std::string_view hey(std::string_view msg) {
        const auto& last_nonwhitespace_ch = msg.find_last_not_of(" \t\f\v\n\r");

        if (last_nonwhitespace_ch==std::string::npos)
            return "Fine. Be that way!";

        auto is_question = [&msg, &last_nonwhitespace_ch]() {
            return msg[last_nonwhitespace_ch] == '?';
        };

        if (is_all_capitals(msg)) {
            if (is_question())
                return "Calm down, I know what I'm doing!";

            return "Whoa, chill out!";
        }
        
        if (is_question())
            return "Sure.";

        return "Whatever.";      
    }
}  // namespace bob
