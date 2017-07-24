#include <string>                      // std::string
#include <iostream>                    // std::[cin|getline]
#include <stream_pool/stream_pool.hpp> // StreamPool



int
main()
{
    StreamPool stream_pool;

    stream_pool.listen();
    
    return 0;
}
