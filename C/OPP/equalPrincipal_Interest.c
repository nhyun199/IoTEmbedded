#include <math.h>

// 원리금 균등 상환
// principal = 대출원금
// annual_interest_rate 연 이자율
// months = 총 상환기간
double calculate_monthly_payment(double principal, double annual_interest_rate, int months)
{
    double monthly_interest_rate = annual_interest_rate / 12 / 100; // 월 이자율
    double monthly_payment = principal * (monthly_interest_rate * pow(1 + monthly_interest_rate, months)) / 
                                         (pow(1 + monthly_interest_rate, months) - 1); // 월 상환금액
    return monthly_payment;
}