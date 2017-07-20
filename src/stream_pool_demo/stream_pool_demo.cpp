#include <string>                      // std::string
#include <iostream>                    // std::[cin|getline]
#include <stream_pool/stream_pool.hpp> // StreamPool



int
main()
{
    StreamPool stream_pool;

    std::string input;
    std::string payload;
    std::string::size_type i_split;

    while (std::getline(std::cin, input)) {
        i_split = input.find(':');

        if (i_split == std::string::npos) {
            payload = "DEFAULT MESSAGE";

        } else {
            payload = input.substr(i_split);
            input.resize(i_split - (i_split > 0));
        }

        stream_pool.route(input, // session_id
                          payload);
    }
    
    return 0;
}
