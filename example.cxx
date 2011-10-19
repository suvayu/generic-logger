#include <list>
#include <stdexcept>
#include <boost/any.hpp>

#include "logger.hxx"


int main()
{
  std::list<int> colwidth;
  std::list<std::string> colheader;
  std::list<boost::any> colvalue;

  for (int i(0); i < 3; ++i)
    {
      colwidth.push_back(5);
    }

  colheader.push_back("one");
  colheader.push_back("two");
  colheader.push_back("three");

  colvalue.push_back(1);
  colvalue.push_back(2.0);
  const char * bla;
  bla = "three";
  colvalue.push_back(bla);

  logger testlog( colwidth, colheader, colvalue);

  testlog.log();

  return 1;
}
