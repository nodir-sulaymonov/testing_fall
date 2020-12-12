//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"
#include <string>


cpr::Response get_temp_json(std::string temp, int status_code) {
    cpr::Response resp;
    resp.status_code = status_code;
    resp.text = "{\"list\":[{ \"main\": {\"temp\": " + temp + "}}]}";
    
    return resp;
} 


TEST(WeatherTestCase, test1) {
    WeatherMock mock;
    
    EXPECT_CALL(mock, Get)
            .WillOnce(testing::Return(get_temp_json("40", 200)))
            .WillOnce(testing::Return(get_temp_json("50", 200)))
            .WillOnce(testing::Return(get_temp_json("70", 200)))
            .WillOnce(testing::Return(get_temp_json("20", 200)));

    ASSERT_EQ(mock.FindDiffBetweenTwoCities("Moscow", "Tashkent"), -10);
    ASSERT_EQ(mock.FindDiffBetweenTwoCities("Madrid", "Berlin"), 50);
}