#pragma once
# include <string>

class EncryptStrategy {
public:
	virtual std::string encode(std::string mes) = 0;
};

class InsertStrategy : public EncryptStrategy {
	std::string encode(std::string mes) {
		std::string result;
		for (auto i = mes.begin(); i != mes.end(); i++) {
			result += *i;
			result += '#';
		}
		return result;
	}
};

class InvertStrategy : public EncryptStrategy {
	std::string encode(std::string mes) {
		std::string result;
		for (int i = mes.size() - 1; i >= 0; i--) {
			result += mes[i];
		}
		return result;
	}
};