// Source file for logger class

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "logger.hxx"



logger::logger(list<int> & icolw, list<string> & iheader,
	       list<any> & ivalue )
{
  if (! (colw.size() == header.size() && header.size() == value.size()) )
    throw runtime_error("logger: incompatible initialising lists.\n");

  colw  .splice( colw  .begin(), icolw  );
  header.splice( header.begin(), iheader);
  value .splice( value .begin(), ivalue );
}


void logger::log()
{
  list<int>::iterator colwItr;
  list<string>::iterator headerItr;
  list<any>::iterator valueItr;

  // temporary
  for (colwItr = colw.begin(); colwItr != colw.end(); ++colwItr)
    {
      std::cout << *colwItr << ", ";
    }
  std::cout << std::endl;

  for (headerItr = header.begin(); headerItr != header.end(); ++headerItr)
    {
      std::cout << *headerItr << ", ";
    }
  std::cout << std::endl;

  for (valueItr = value.begin(); valueItr != value.end(); ++valueItr)
    {
      if ( is_int(*valueItr) )
	std::cout << any_cast<int>(*valueItr) << ", ";
      if ( is_double(*valueItr) )
	std::cout << any_cast<double>(*valueItr) << ", ";
      if ( is_char_ptr(*valueItr) )
	std::cout << any_cast<const char *>(*valueItr) << ", ";
    }
  std::cout << std::endl;
}


void logger::set_column_width( list<int> & icolw )
{
  colw.splice( colw.begin(), icolw );
}


void logger::set_header( list<string> & iheader )
{
  header.splice( header.begin(), iheader);
}


void logger::set_value( list<any> & ivalue )
{
  value.splice( value.begin(), ivalue );
}



// boost::any utilities copied from boost examples.

bool is_empty(const any & operand)
{
  return operand.empty();
}


bool is_int(const any & operand)
{
  return operand.type() == typeid(int);
}


bool is_float(const any & operand)
{
  return operand.type() == typeid(float);
}


bool is_double(const any & operand)
{
  return operand.type() == typeid(double);
}


bool is_char_ptr(const any & operand)
{
  try
    {
      any_cast<const char *>(operand);
      return true;
    }
  catch(const bad_any_cast &)
    {
      return false;
    }
}


bool is_string(const any & operand)
{
  return any_cast<string>(&operand);
}
