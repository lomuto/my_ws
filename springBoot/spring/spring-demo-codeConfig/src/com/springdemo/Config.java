package com.springdemo;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;

@Configuration
@ComponentScan("com.springdemo")
@PropertySource("classpath:application.properties")
public class Config {
    @Bean
    public FortuneService randomFortuneService() {
        return new RandomFortuneService();
    }

}
