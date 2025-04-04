#include <algorithm>	// sort().algorithm
#include <iomanip>		// precision, setprecision
#include <ios>
#include <iostream>		// cin, cout, endl
#include <string>		// string
#include <vector>		// vector (배열)
#include <stdexcept>	// domain_error()
#include "grade.h"
#include "Student_info.h"


using std::cin;			using std::cout;
using std::endl;		using std::string;
using std::streamsize;	using std::setprecision; // 정도
using std::vector;		using std::sort; // 정렬
using std::domain_error;	using std::max;




int main() {
	vector<Student_info> students;
	Student_info record; // 한 학생의 행(record)
	string::size_type maxlen = 0; // 학생 이름 최대 길이
	
	// 학생의 모든 데이터를 읽고 저장
	// 불변성: students는 지금까지 읽은 모든 학생 정보가 있음
	// maxlen은 students에서 가장 긴 이름의 길이
	while (read(cin, record)) {
		// 길이가 가장 긴 이름을 찾음
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// 학생정보를 알파벳 순으로 정렬
	sort(students.begin(), students.end(), compare);

	typedef vector<Student_info>::size_type si_size;

	// 이름과 점수를 출력
	for (si_size i = 0; i != students.size(); ++i) {
		// 이름과 오른쪽 공백을 포함하여 maxlen + 1개 문자를 출력
		cout << students[i].name <<
			string(maxlen + 1 - students[i].name.size(), ' ');

		// 최종 점수를 계산하여 출력!
		try {
			double final_grade = grade(students[i]);
			// 결과를 출력
			streamsize prec = cout.precision();
			cout << setprecision(3)
				<< final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}

	return 0;
}