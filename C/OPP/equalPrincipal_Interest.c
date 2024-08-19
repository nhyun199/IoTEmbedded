#include <math.h>

// ������ �յ� ��ȯ
// principal = �������
// annual_interest_rate �� ������
// months = �� ��ȯ�Ⱓ
double calculate_monthly_payment(double principal, double annual_interest_rate, int months)
{
    double monthly_interest_rate = annual_interest_rate / 12 / 100; // �� ������
    double monthly_payment = principal * (monthly_interest_rate * pow(1 + monthly_interest_rate, months)) / 
                                         (pow(1 + monthly_interest_rate, months) - 1); // �� ��ȯ�ݾ�
    return monthly_payment;
}