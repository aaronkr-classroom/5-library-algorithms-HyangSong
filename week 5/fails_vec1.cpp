#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;

// 첫번째 과락 학생과 패스하는 학생 나누기 (메모리 사용량 큼)
vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> pass, fail;

	for (vector<Student_info>::size_type i = 0;
		i != students.size(); ++i) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
		}
		else {
			pass.push_back(students[i]);
		}
	}

	students = pass; // 원래 있는 students 벡터에서 pass 학생만 유지
	return fail;
}