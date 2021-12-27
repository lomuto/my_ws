package com.springdemo;

public class BaseballCoach implements Coach {

    private FortuneService theFortuneService = new HappyFortuneService();

    public BaseballCoach(FortuneService theFortuneService) {
        this.theFortuneService = theFortuneService;
    }

    @Override
    public String getDailyWorkout() {
        return "Spend 30 min on batting practice";
    }

}