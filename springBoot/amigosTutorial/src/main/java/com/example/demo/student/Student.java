package com.example.demo.student;


import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.SequenceGenerator;
import javax.persistence.Table;
import javax.persistence.Transient;
import java.time.LocalDate;
import java.time.Period;

@Entity
@Table
public class Student {

    @Id
    // 제너레이터 설정을 해주고
    @SequenceGenerator(
            name = "student_sequence_generator",
            sequenceName = "student_sequence",
            /*initialValue = default 1*/
            allocationSize = 1
    )
    // 여기서 어떤 제너레이터를 써줄지 고르는거
    @GeneratedValue(
            strategy = GenerationType.SEQUENCE,
            generator = "student_sequence_generator" // 위의 name 필드값
    )
    private Long id;
    private String name;
    private String email;
    private LocalDate dob; // Date Of Birth

    @Transient  // age can be calculated through date of birth
                // Similar meaning with temporary
    private Integer age;

    public Student() {
    }

    public Student(Long id, String name, String email, LocalDate dob) {
        this.id = id;
        this.name = name;
        this.email = email;
        this.dob = dob;
    }

    public Student(String name, String email, LocalDate dob) {
        this.name = name;
        this.email = email;
        this.dob = dob;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public LocalDate getDob() {
        return dob;
    }

    public void setDob(LocalDate dob) {
        this.dob = dob;
    }

    public Integer getAge() {
        return Period.between(this.dob, LocalDate.now()).getYears();
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", dob=" + dob +
                ", age=" + age +
                '}';
    }
}
