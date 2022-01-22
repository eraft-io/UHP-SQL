#ifndef SQLPARSER_COLUMN_TYPE_H
#define SQLPARSER_COLUMN_TYPE_H

#include <ostream>

namespace hsql {

enum class DataType {
  UNKNOWN,
  INT,
  LONG,
  FLOAT,
  DOUBLE,
  DECIMAL,
  REAL,
  CHAR,
  VARCHAR,
  TEXT,
  DATETIME,
  DATE,
  TIME,
  SMALLINT,
};

static int DataType2Int(DataType dt) {
  switch (dt) {
    case DataType::UNKNOWN:
      return 0;
    case DataType::INT:
      return 1;
    case DataType::LONG:
      return 2;
    case DataType::FLOAT:
      return 3;
    case DataType::DOUBLE:
      return 4;
    case DataType::DECIMAL:
      return 5;
    case DataType::REAL:
      return 6;
    case DataType::CHAR:
      return 7;
    case DataType::VARCHAR:
      return 8;
    case DataType::TEXT:
      return 9;
    case DataType::DATETIME:
      return 10;
    case DataType::DATE:
      return 11;
    case DataType::TIME:
      return 12;
    case DataType::SMALLINT:
      return 13;
    default:
      return 15;
  }
}

struct ColumnSpecification {
  ColumnSpecification() = default;
  ColumnSpecification(int64_t precision, int64_t scale);
  ColumnSpecification(int64_t precision);
  int64_t precision;
  int64_t scale;
};

// Represents the type of a column, e.g., FLOAT or VARCHAR(10)
struct ColumnType {
  ColumnType() = default;
  ColumnType(DataType data_type, int64_t length = 0,
             ColumnSpecification column_specification = ColumnSpecification{});
  DataType data_type;
  int64_t length;  // Used for, e.g., VARCHAR(10)
  ColumnSpecification
      columnSpecification;  // used for, e.g. DECIMAL (6, 4) or TIME (5)
};

bool operator==(const ColumnType& lhs, const ColumnType& rhs);
bool operator!=(const ColumnType& lhs, const ColumnType& rhs);
std::ostream& operator<<(std::ostream&, const ColumnType&);

}  // namespace hsql

#endif
