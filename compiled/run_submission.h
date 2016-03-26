#ifndef RUN_SUBMISSION_H
#define RUN_SUBMISSION_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Options.h"

struct Libpair
{
  Libpair(std::string libIn, std::string sha1In)
    : lib(libIn), sha1(sha1In) {}

  std::string lib;
  std::string sha1;
};

typedef std::unordered_map<std::string,std::string> Table;
typedef unsigned int uint;

void buildEnvT(char* env[], Table& envT);
void buildUserT(Options& options, Table& userT);
void capture(std::string& cmd, std::vector<std::string>& result);
void extractXALTRecord(std::string& exec, Table& recordT);
void parseLDD(std::string& exec, std::vector<Libpair>& lddA);
void direct2db(std::string& confFn, std::string& usr_cmdline, std::string& hash_id, Table& envT, Table& userT,
               Table& recordT, std::vector<Libpair>& lddA);
void translate(Table& envT, Table& userT);
void buildRmapT(Table& rmapT, std::vector<std::string> xlibmap);

#endif //RUN_SUBMISSION_H