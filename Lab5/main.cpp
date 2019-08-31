#include <iostream>
#include <stdio.h>

struct Student {
    int studentId;
    int assignmentGrades[4];
};


int main() {
    Student students;

    FILE * studentFile = fopen("records", "wb+");

    //Writing
    if(studentFile != NULL){
        for(int i = 0; i < 5; i++){ //Number of students = i
            students.studentId = i + 1;

            for(int j = 0; j < 4; j++){ //Number of grades = j
                int grade;

                std::cout << "Please enter grade " << j + 1 << " for student "<< i + 1 << ": ";
                std::cin >> grade;

                students.assignmentGrades[j] = grade; //Grade for class X
            }
            std::cout << std::endl;

            //Error checking
            int check = fwrite(&students, sizeof(Student) ,1,studentFile);

            if(check != 1){
                std::cout << "Error in write" << std::endl;
                break;
            }
        }
    }
    else{
        std::cout << "File is null";
    }


    //Reading
    Student readStudent[5];

    for(int i = 1; i < 6; i++) {

        //Seek
        if(fseek(studentFile, i * sizeof(Student) * -1, SEEK_END) != 0){
            std::cout << "Failed to seek" << std::endl;
        }

        if(fread(&readStudent[i - 1], sizeof(Student), 1, studentFile) != 1){
            std::cout << "Read error" << std::endl;
        }

        //Print Student Values
        std::cout << "Student ID: " << readStudent[i - 1].studentId << std::endl;
        std::cout << "Grade 1: " << readStudent[i - 1].assignmentGrades[0] << std::endl;
        std::cout << "Grade 2: " << readStudent[i - 1].assignmentGrades[1] << std::endl;
        std::cout << "Grade 3: " << readStudent[i - 1].assignmentGrades[2] << std::endl;
        std::cout << "Grade 4: " << readStudent[i - 1].assignmentGrades[3] << std::endl;

        //Re-write new grades to file
        for(int j = 0; j < 4; j++){
            int grade;

            if(fseek(studentFile, i * sizeof(Student) * -1, SEEK_END) != 0) {
                std::cout << "Failed to seek" << std::endl;
            }

            std::cout << "Please enter grade " << j + 1 << ":" << std::endl;
            std::cin >> grade;

            readStudent[i - 1].assignmentGrades[j] = grade; //Grade for class X
        }
        fwrite(&readStudent[i-1], sizeof(Student) ,1, studentFile);

    }


    //Read again
    for(int i = 1; i < 6; i++) {

        //Seek
        if (fseek(studentFile, i * sizeof(Student) * -1, SEEK_END) != 0) {
            std::cout << "Failed to seek" << std::endl;
        }

        if (fread(&readStudent[i - 1], sizeof(Student), 1, studentFile) != 1) {
            std::cout << "Read error" << std::endl;
        }

        //Print Student Values
        std::cout << "Student ID: " << readStudent[i - 1].studentId << std::endl;
        std::cout << "Grade 1: " << readStudent[i - 1].assignmentGrades[0] << std::endl;
        std::cout << "Grade 2: " << readStudent[i - 1].assignmentGrades[1] << std::endl;
        std::cout << "Grade 3: " << readStudent[i - 1].assignmentGrades[2] << std::endl;
        std::cout << "Grade 4: " << readStudent[i - 1].assignmentGrades[3] << std::endl;
    }

    fclose(studentFile);
    return 0;
}