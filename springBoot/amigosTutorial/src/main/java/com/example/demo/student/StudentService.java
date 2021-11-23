package com.example.demo.student;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;

import javax.transaction.Transactional;
import java.time.LocalDate;
import java.time.Month;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Optional;

@Service
public class StudentService {

    private final StudentRepository studentRepository;

    @Autowired
    public StudentService(StudentRepository studentRepository) {
        this.studentRepository = studentRepository;
    }

    public List<Student> getStudents() {
        return studentRepository.findAll();
    }


    public Student getStudentById(Long id) {
        Optional<Student> stduent = studentRepository.findById(id);

        if (!stduent.isPresent()) {
            return null;
        }

        return stduent.get();
    }

    public void addNewStudent(Student student) {
        Optional<Student> studentOptional = studentRepository.findStudentByEmail(student.getEmail());

        if (studentOptional.isPresent()) {
            throw new IllegalStateException("Email taken");
        }

        studentRepository.save(student);
    }

    public void deleteStudent(Long studentId) {
        boolean exists = studentRepository.existsById(studentId);
        if (!exists) {
            throw new IllegalStateException(
                    String.format("Student with id [%d] does not exist", studentId)
            );
        }

        studentRepository.deleteById(studentId);
    }

    @Transactional
    // Student 개체 전부를 인자로 받아야하나?
    public void updateStudent(Long studentId, Student newStudent) {
        /*
        // 원래 studentRepository는 Optional을 리턴하는데
        // orElse가 예외상황을 처리해주면서 예외가 아닌 상황에서는 항상 valid한 값이니 Optional이 필요 x
        // Student 개체를 리턴해줌
        Student student = studentRepository.findById(studentId)
                .orElseThrow(() -> new IllegalStateException(
                    String.format("Student with id %ld dose not exist", studentId)
                ));

            // name validation, email validation
            // email validation 같은 경우 수정하고자 하는 email이 이미 db에 있는지도 검사.
             Optional<Student> studentOptionByEmail = studentRepository.findByEmail(email);
             if(studentOptional.isPresent()){
                throw new IllegalStateException("email exists");
             }
         */
        Optional<Student> studentOptional = studentRepository.findById(studentId);

        if (!studentOptional.isPresent()) {
            studentRepository.save(newStudent);
            return;
        }

        Student student = studentOptional.get();

        student.setName(newStudent.getName());
        student.setDob(newStudent.getDob());
        student.setEmail(newStudent.getEmail());

        // 레포에 다시 저장을 하지 않고 set만 해줘도 이게 db에 저장이 되네? 신기하다

//        studentRepository.save(student);
    }
}
