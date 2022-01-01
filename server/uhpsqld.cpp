
#include <stdlib.h>

#include <string>

// include the sql parser
#include "../parser/sql_parser.h"

// contains printing utilities
#include "../parser/sqlhelper.h"

// contains hiredis
#include "../hiredis/hiredis.h"

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    fprintf(stderr, "Usage: ./example \"SELECT * FROM test;\"\n");
    return -1;
  }
  std::string query = argv[1];

  // parse a given query
  hsql::SQLParserResult result;
  hsql::SQLParser::parse(query, &result);

  //   // check whether the parsing was successful
  //   redisContext *c;
  //   redisReply *reply;

  //   struct timeval timeout = {1, 500000};  // 1.5 seconds

  //   c = redisConnectWithTimeout("172.17.0.2", 6379, timeout);
  //   if (c == NULL || c->err) {
  //     if (c) {
  //       printf("Connection error: %s\n", c->errstr);
  //       redisFree(c);
  //     } else {
  //       printf("Connection error: can't allocate redis context\n");
  //     }
  //     exit(1);
  //   }

  /* Set a key */
  //   reply = static_cast<redisReply *>(
  //       redisCommand(c, "SET %s %s", "x", "hello uhp sql"));
  //   printf("SET: %s\n", reply->str);
  //   freeReplyObject(reply);

  if (result.isValid()) {
    printf("Parsed successfully!\n");
    printf("Number of statements: %lu\n", result.size());

    for (auto i = 0u; i < result.size(); ++i) {
      // Print a statement summary.
      hsql::printStatementInfo(result.getStatement(i));
    }
    return 0;
  } else {
    fprintf(stderr, "Given string is not a valid SQL query.\n");
    fprintf(stderr, "%s (L%d:%d)\n", result.errorMsg(), result.errorLine(),
            result.errorColumn());
    return -1;
  }
}