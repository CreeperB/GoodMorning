#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct Score {
    string subject;
    int score;
};
struct Student {
    string studentID;
    vector<Score> scores;
    int average;
};

void swap(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

// Function to calculate the score for each student
int calculateScore(const vector<int>& answerKey, const vector<int>& studentAnswers, int totalQuestions, string subject) {
    int score = 0;
    for (int i = 0; i < totalQuestions; ++i) {
        // C001卷：答對一題10分，答錯一題倒扣2分
        if (subject == "C001") {
            if (answerKey[i] == studentAnswers[i]) {
                score += 10;
            } else {
                score -= 2;
            }
        }
        // C002卷：答對一題5分，（前15 題答錯一題倒扣1分、後5題答鑽一題倒扣2分）
        else if (subject == "C002") {
            if(answerKey[i] == studentAnswers[i]) {
                score += 5;
            } else {
                if (i < 15) {
                    score -= 1;
                } else {
                    score -= 2;
                }
            }
        }
        // C003卷：前10題（答對一題6分，答錯一題倒扣1分），後5題（答對一題8分，答錯一題倒扣2分）
        else if (subject == "C003") {
            if (i < 10) {
                if (answerKey[i] == studentAnswers[i]) {
                    score += 6;
                } else {
                    score -= 1;
                }
            } else {
                if (answerKey[i] == studentAnswers[i]) {
                    score += 8;
                } else {
                    score -= 2;
                }
            }
        }
    }
    return score;
}

int main() {
    ifstream inputFile("Final1.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    // Reading the standard answers for each subject
    map<string, vector<int> > answerKeys;
    string subject;
    // Read the only three subjects
    for (int i = 0; i < 3; ++i) {
        inputFile >> subject;
        // Read the answer key for the subject so get the line and use stringstream to read the answers
        string line;
        getline(inputFile, line);
        stringstream ss(line);
        int answer;
        vector<int> answers;
        while (ss >> answer) {
            answers.push_back(answer);
        }
        answerKeys[subject] = answers;
    }

    // Reading and processing student data
    string studentID, studentSubject;
    // Create student data structure to store the student ID and subject and score
    vector<Student> students;
    while (inputFile >> studentID >> studentSubject) {
        int totalQuestions = answerKeys[studentSubject].size();
        vector<int> studentAnswers(totalQuestions);

        for (int i = 0; i < totalQuestions; ++i) {
            inputFile >> studentAnswers[i];
        }

        // Calculate the score for the student
        int score = calculateScore(answerKeys[studentSubject], studentAnswers, totalQuestions, studentSubject);
        // Print the student ID and score
        cout << studentID << " " << studentSubject << " Score: " << score << endl;

        // Search for the student ID in the students vector
        bool found = false;
        for (int i = 0; i < students.size(); ++i) {
            if (students[i].studentID == studentID) {
                // Add the score to the student
                Score studentScore = {studentSubject, score};
                students[i].scores.push_back(studentScore);
                found = true;
                break;
            }
        }
        // If the student ID is not found, add the student to the vector
        if (!found) {
            Student student;
            student.studentID = studentID;
            Score studentScore = {studentSubject, score};
            student.scores.push_back(studentScore);
            students.push_back(student);
        }
    }

    // Calculate the average score for each student
    cout << "Average score for each student" << endl;
    for (int i = 0; i < students.size(); ++i) {
        int totalScore = 0;
        for (int j = 0; j < students[i].scores.size(); ++j) {
            totalScore += students[i].scores[j].score;
        }
        students[i].average = totalScore / students[i].scores.size();
        cout << students[i].studentID << " Average: " << students[i].average << endl;
    }

    // Sort the students by average score
    for (int i = 0; i < students.size(); ++i) {
        for (int j = i + 1; j < students.size(); ++j) {
            if (students[i].average < students[j].average) {
                swap(students[i], students[j]);
            }
        }
    }
    // Print the sorted students
    cout << "Sorted students" << endl;
    for (int i = 0; i < students.size(); ++i) {
        cout << students[i].studentID << " Average: " << students[i].average << endl;
    }
    return 0;
}
