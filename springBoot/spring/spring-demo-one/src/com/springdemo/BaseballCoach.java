package com.springdemo;

public class BaseballCoach implements Coach {
    private String name;
    private int age;
    private int height;

    private FortuneService theFortuneService = new HappyFortuneService();

    public BaseballCoach(String name, int age, int height, FortuneService theFortuneService) {
        this.name = name;
        this.age = age;
        this.height = height;
        this.theFortuneService = theFortuneService;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public int getHeight() {
        return height;
    }

    @Override
    public String getDailyWorkout() {
        return "Spend 30 min on batting practice";
    }

    @Override
    public String getDailyFortune() {
        return theFortuneService.getFortune();
    }

    private static void baseBallCoachInitMethod() {
        System.out.println("Initializing baseball coach");
    }

    private void baseballCoachDestroyMethod() {
        System.out.println("When this bean destroyed?");
    }
}