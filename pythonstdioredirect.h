#ifndef PYTHONSTDIOREDIRECT_H
#define PYTHONSTDIOREDIRECT_H
#include <boost/circular_buffer.hpp>
#include <iostream>
#include <sstream>

class PythonStdIoRedirect {
public:
    typedef boost::circular_buffer<std::string> ContainerType;
    void Write( std::string const& str ) ;
    inline static std::string GetOutput()
    {
        std::string ret;
        std::stringstream ss;
        for(boost::circular_buffer<std::string>::const_iterator it=m_outputs.begin();
            it!=m_outputs.end();
            it++)
        {
            ss << *it;
        }
        m_outputs.clear();
        ret =  ss.str();
        return ret;
    };
private:
    static ContainerType m_outputs; // must be static, otherwise output is missing
};

#endif
