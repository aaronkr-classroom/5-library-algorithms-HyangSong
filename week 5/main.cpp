#include <algorithm>	// sort().algorithm
#include <iomanip>		// precision, setprecision
#include <ios>
#include <iostream>		// cin, cout, endl
#include <string>		// string
#include <vector>		// vector (�迭)
#include <stdexcept>	// domain_error()
#include "grade.h"
#include "Student_info.h"


using std::cin;			using std::cout;
using std::endl;		using std::string;
using std::streamsize;	using std::setprecision; // ����
using std::vector;		using std::sort; // ����
using std::domain_error;	using std::max;




int main() {
	vector<Student_info> students;
	Student_info record; // �� �л��� ��(record)
	string::size_type maxlen = 0; // �л� �̸� �ִ� ����
	
	// �л��� ��� �����͸� �а� ����
	// �Һ���: students�� ���ݱ��� ���� ��� �л� ������ ����
	// maxlen�� students���� ���� �� �̸��� ����
	while (read(cin, record)) {
		// ���̰� ���� �� �̸��� ã��
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// �л������� ���ĺ� ������ ����
	sort(students.begin(), students.end(), compare);

	typedef vector<Student_info>::size_type si_size;

	// �̸��� ������ ���
	for (si_size i = 0; i != students.size(); ++i) {
		// �̸��� ������ ������ �����Ͽ� maxlen + 1�� ���ڸ� ���
		cout << students[i].name <<
			string(maxlen + 1 - students[i].name.size(), ' ');

		// ���� ������ ����Ͽ� ���!
		try {
			double final_grade = grade(students[i]);
			// ����� ���
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