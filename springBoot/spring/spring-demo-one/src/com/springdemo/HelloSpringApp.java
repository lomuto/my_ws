package com.springdemo;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class HelloSpringApp {
    public static void main(String[] args) {
        // load ths spring configuration file
        ClassPathXmlApplicationContext context =
                new ClassPathXmlApplicationContext("applicationContext.xml");

        // retrieve bean from spring container
        BaseballCoach coach = context.getBean("myCoach", BaseballCoach.class);

        // call method from bean
        System.out.println(coach.getDailyWorkout());

        // call new method fortune service from bean
        System.out.println(coach.getDailyFortune());

        System.out.println(coach.getName());

        System.out.println("My age is: " + coach.getAge());

        // close the context
        context.close();
    }
}
