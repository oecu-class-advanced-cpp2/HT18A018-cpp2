#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>


namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi

	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	private:
		int value_;
		int unit(char c) {    //単位に対応する値を取得します。
			int i = 0;
			if (c == 'm') {i = 1000;}
			else if(c=='c'){i = 100;}
			else if (c == 'x') {i = 10;}
			else if (c == 'i') {i = 1;}
			return i;
		}

	public:
		mcxi(const std::string& s) : value_(0) {
			int digit = 0;
			int w = 0;
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				if (*pos >= '2' && *pos <= '9') {
					if (w == 0) {
						digit = *pos - '0';
						w = 1;
					}else{
						std::cout << "数字連続エラー" << std::endl;
					}
				}
				else {
					auto u = unit(*pos);
					value_ += std::max(digit, 1) * u;
					digit = 0;
					w = 0;
				}
			}
			if (w == 1) {
				value_ += digit;
			}
		}

		mcxi operator+(const mcxi& rhs) {//2 つのオブジェクトの加算結果を取得します。
			auto res = this->value_ + rhs.value_;
			cpp2::mcxi x("");
			x.value_ = res;

			return x;
		}

	std::string to_string() const {//現在の値を mcxi 記法に変換します。
		std::stringstream ss;

		int q = value_ / 1000;
		int p = value_ % 1000;
		if (q == 1) {
			ss << 'm';
		}
		if (q > 1) {
			ss << q;
			ss << 'm';
		}
		q = p / 100;
		p = p % 100;
		if (q == 1) {
			ss << 'c';
		}
		if (q > 1) {
			ss << q;
			ss << 'c';
		}
		q = p / 10;
		p = p % 10;
		if (q == 1) {
			ss << 'x';
		}
		if (q > 1) {
			ss << q;
			ss << 'x';
		}
		q = p / 1;
		p = p % 1;
		if (q == 1) {
			ss << 'i';
		}
		if (q > 1) {
			ss << q;
		}

		return ss.str();
	}
	};
}

int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	auto result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;

	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;

	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	auto result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	auto result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;

	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;

	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	auto result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;

	std::cin.get();
}
