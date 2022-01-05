package com.springdemo;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class App {
    public static void main(String[] args) {
        AnnotationConfigApplicationContext context =
                new AnnotationConfigApplicationContext(Config.class);

        Coach coach = context.getBean("tennisCoach", TennisCoach.class);

        System.out.println(coach.getDailyWorkout());

        System.out.println(coach.getFortune());

        System.out.println(String.format("name: %s", ((TennisCoach)coach).getName()));

        context.close();
    }
}
