package com.springdemo;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan("com.springdemo")
public class Config {
    @Bean
    public FortuneService randomFortuneService() {
        return new RandomFortuneService();
    }

}
