package com.springdemo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

/*
    Default Bean ID is same class name with lower case of first character
 */
@Component
public class TennisCoach implements Coach {

    private FortuneService fortuneService;

    public TennisCoach() {
        System.out.println(
                String.format("Field FortuneService is not available right now %s", fortuneService)
        );
    }

    @Autowired
    public TennisCoach(
            @Qualifier("randomFortuneService") FortuneService theFortuneService
    ) {
        this.fortuneService = theFortuneService;
        System.out.println(
                String.format("Field FortuneService is now available %s", fortuneService)
        );
    }

    @Override
    public String getDailyWorkout() {
        return "Practice your backhand volley";
    }

    public String getFortune() {
        return fortuneService.getFortune();
    }
}
