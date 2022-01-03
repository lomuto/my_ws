package com.springdemo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

/*
    Default Bean ID is same class name with lower case of first character
 */
@Component
public class TennisCoach implements Coach {

    @Autowired
    private FortuneService happyFortuneService;

    public TennisCoach() {
    }

    public TennisCoach(FortuneService happyFortuneService) {
        this.happyFortuneService = happyFortuneService;
    }

    @Override
    public String getDailyWorkout() {
        return "Practice your backhand volley";
    }

    public String getFortune() {
        return happyFortuneService.getFortune();
    }
}
