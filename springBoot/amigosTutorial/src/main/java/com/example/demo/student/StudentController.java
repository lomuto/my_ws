package com.example.demo.student;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import javax.transaction.Transactional;
import java.time.LocalDate;
import java.time.Month;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@RestController
@RequestMapping(path = "api/v1/student")
public class StudentController {

    private final StudentService studentService;

    @Autowired
    public StudentController(StudentService studentService) {
        this.studentService = studentService;
    }

    @GetMapping()
    public List<Student> getStudents() {
        return studentService.getStudents();
    }

    @GetMapping(path = "{studentId}")
    public Student getStudent(@PathVariable(value = "studentId") Long studentId) {
        return studentService.getStudentById(studentId);
    }

    @PostMapping()
    public Map<String, Object> registerNewStudent(@RequestBody Student student) {
        Map<String, Object> response = new HashMap<>();

        studentService.addNewStudent(student);

        response.put("message", "Student added successfully");
        response.put("student", student);
        return response;
    }

    @DeleteMapping(path = "{studentId}")
    public void deleteStudent(@PathVariable("studentId") Long studentId) {
        studentService.deleteStudent(studentId);
    }

    @PutMapping(path = "{studentId}")
    /*
    @RequestParam(required = flase) String name
    @RequestParam(required = flase) String email
    이렇게 멤버를 넘겨줘야 하는듯
     */
    public void updateStudent(
            @PathVariable(value = "studentId") Long studentId,
            @RequestBody Student student
    ) {
        studentService.updateStudent(studentId, student);
    }
}
