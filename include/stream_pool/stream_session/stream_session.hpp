#ifndef STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
#define STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP

// EXTERNAL DEPENDENCIES
// =============================================================================
#include <unordered_map> // std::unordered_map
#include <string>        // std::string



// FORWARD DECLARATIONS
// =============================================================================
class StreamPool;



class StreamSession
{
private:
    friend StreamPool;

    typedef std::unordered_map<std::string, StreamSession> Register;
    typedef Register::iterator Record;



    StreamSession();
    ~StreamSession();


    start();
    stop();


    Record enrollment;
}; // class StreamSession

#endif // STREAM_POOL_STREAM_SESSION_STREAM_SESSION_HPP
