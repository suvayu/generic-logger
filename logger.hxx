// Header file for logger class

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <list>
#include <boost/any.hpp>

using namespace std;
using namespace boost;


class logger {

public:

  logger() {};
  logger(list<int> & icolw, list<string> & iheader, list<any> & ivalue );
  virtual ~logger() {};

  void log();

  void set_column_width( list<int> & icolw);
  void set_header( list<string> & iheader);
  void set_value( list<any> & ivalue);
  // bool set_logfile( const string & filename ) : logfile( filename ) {};
  // inline bool is_logfile() { return (! logfile.empty() ); };

protected:

  // static unsigned long counter();

  list<int>	colw;
  list<string> 	header;
  list<any> 	value;
  string 	logfile;

};


// boost::any utilities copied from boost examples.

bool is_empty( const any & operand );
bool is_int( const any & operand );
bool is_float( const any & operand );
bool is_double( const any & operand );
bool is_char_ptr( const any & operand );
bool is_string( const any & operand );

#endif // LOGGER_H
