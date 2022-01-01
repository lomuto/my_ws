package com.springdemo;

import org.springframework.stereotype.Component;

/*
    Default Bean ID is same class name with lower case of first character
 */
@Component
public class TennisCoach implements Coach{


    @Override
    public String getDailyWorkout() {
        return "Practice your backhand volley";
    }

}
