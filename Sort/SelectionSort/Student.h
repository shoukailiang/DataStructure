//
// Created by liang on 2019/8/11.
//

#ifndef DATASTRUCTURE_STUDENT_H
#define DATASTRUCTURE_STUDENT_H

#include <iostream>
#include <string>

using namespace std;


struct Student {

  string name;
  int score;

  bool operator<(const Student &otherStudent) {
    return score != otherStudent.score ?
           score > otherStudent.score : name < otherStudent.name;
  }

  friend ostream &operator<<(ostream &os, const Student &student) {

    os << "Student: " << student.name << " " << student.score << endl;
    return os;
  }
};

#endif //DATASTRUCTURE_STUDENT_H
