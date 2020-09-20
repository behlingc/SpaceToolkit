#ifndef SPACETOOLKITEXCEPTION_H_
#define SPACETOOLKITEXCEPTION_H_

#include <map>
#include <string>

using std::map;
using std::string;

namespace SpaceToolkit {

class SpaceToolkitException {
 public:
  explicit SpaceToolkitException(const string& errorId, const string file,
                                 int line);
  virtual ~SpaceToolkitException();

  void handle();

 private:
  map<string, string> m_errors = {
      {"errUnknown", "Unknown error."},
      {"errInputParameterOutOfRange",
       "One or more input parameter are out of range."},
  };

  string m_errorId;
  string m_errorMessage;
  string m_file;
  int m_line;
};
}  // namespace SpaceToolkit
#endif  // SPACETOOLKITEXCEPTION_H_
