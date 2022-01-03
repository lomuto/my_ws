package com.springdemo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

/*
    Default Bean ID is same class name with lower case of first character
 */
@Component
public class TennisCoach implements Coach {

    @Autowired
    @Qualifier("randomFortuneService")
    private FortuneService fortuneService;

    @Override
    public String getDailyWorkout() {
        return "Practice your backhand volley";
    }

    public String getFortune() {
        return fortuneService.getFortune();
    }
}
