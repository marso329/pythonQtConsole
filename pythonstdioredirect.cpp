#include "pythonstdioredirect.h"


    void PythonStdIoRedirect::Write( std::string const& str ) {
        if (m_outputs.capacity()<100)
            m_outputs.resize(100);
        m_outputs.push_back(str);
    }
    PythonStdIoRedirect::ContainerType PythonStdIoRedirect::m_outputs;
