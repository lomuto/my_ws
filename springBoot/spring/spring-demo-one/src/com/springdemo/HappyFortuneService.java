package com.springdemo;

import org.springframework.stereotype.Component;

@Component("happyFortuneServiceComponent")
public class HappyFortuneService implements FortuneService {
    @Override
    public String getFortune() {
        return "Today is your lucky day!";
    }
}
