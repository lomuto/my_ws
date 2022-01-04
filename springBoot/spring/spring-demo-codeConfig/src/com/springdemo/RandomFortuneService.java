package com.springdemo;

import org.springframework.stereotype.Component;

import java.util.Random;

public class RandomFortuneService implements FortuneService{
    private static String[] fortuneServices = {
            "Fortune 1",
            "Fortune 2",
            "Fortune 3",
            "Fortune 4"
    };

    @Override
    public String getFortune() {
        return fortuneServices[new Random().nextInt(4)];
    }
}
