#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::vector;

// 세번째 과락 학생과 통과하는 학생 나누기 
// 인덱스 대신 반복자 사용하기 (아직도 느림)
vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();

	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			// 원번 벡터 i 인덱스에 있는 학생 삭제하기
			iter = students.erase(iter);
		}
		else {
			++iter;
		}
	}
	return fail;
}