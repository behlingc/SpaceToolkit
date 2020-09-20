#include "SpaceToolkit/SpaceToolkitException.h"
#include <iostream>

using SpaceToolkit::SpaceToolkitException;
using std::cout;
using std::endl;

SpaceToolkitException::SpaceToolkitException(const string& errorId,
                                             const string file, int line)
    : m_errorId(errorId), m_file(file), m_line(line) {}

SpaceToolkitException::~SpaceToolkitException() throw() {}

void SpaceToolkitException::handle() {
  cout << "----------------------------------------" << endl;
  cout << "Error message: " << m_errors[m_errorId] << endl;
  cout << "File:          " << m_file << endl;
  cout << "Line:          " << m_line << endl;
  cout << "----------------------------------------" << endl;
}
