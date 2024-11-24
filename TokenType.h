#pragma once
enum TokenType {
	IDENTIFIER,
	KEYWORD,
	NUMBER,
	OPERATOR,
	SEPARATOR,
	STRING,
	COMMENT,
	EOF__
};
static inline std::ostream& operator<<(std::ostream& os, const TokenType& t) {
	switch (t) {
		case IDENTIFIER: os << "IDENTIFIER"; break;
		case KEYWORD: os << "KEYWORD"; break;
		case NUMBER: os << "NUMBER"; break;
		case OPERATOR: os << "OPERATOR"; break;
		case SEPARATOR: os << "SEPARATOR"; break;
		case STRING: os << "STRING"; break;
		case COMMENT: os << "COMMENT"; break;
		case EOF__: os << "EOF"; break;
	}
	return os;
}