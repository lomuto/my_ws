package com.springdemo;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class AnnotationApp {
    public static void main(String[] args) {
        ClassPathXmlApplicationContext context
                = new ClassPathXmlApplicationContext("annotation-applicationContext.xml");

        Coach coach = context.getBean("annotatedCoach", Coach.class);

        System.out.println(coach.getDailyFortune());
    }
}
