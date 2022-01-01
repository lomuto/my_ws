package com.springdemo;

import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.util.Random;

public class BeanScopeDemoApp {
    public static void main(String[] args) throws InterruptedException {
        ClassPathXmlApplicationContext context =
                new ClassPathXmlApplicationContext("beanScope-applicationContext.xml");

        Coach coach = context.getBean("myCoach", Coach.class);

        Coach alphaCoach = context.getBean("myCoach", Coach.class);

        System.out.println(coach == alphaCoach);

        System.out.println(coach);

        System.out.println(alphaCoach);

        for(int i=0; i<100; i++) {
            if(i%10 == 0)
            System.out.println(i);
            Thread.sleep(100);
            new Random();
        }

        context.close();

        System.out.println("I Guess it is right after ClassPathXmlApplicationContext.close called");
    }
}
