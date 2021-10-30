#include    "Kalman.h"


float KalmanFilterSingalCalc(KalmanFilterTypeDef* Filter, float z_real)
{
    float P_temp = Filter->P_last + Filter->Q;
    float K = P_temp/(P_temp + Filter->R);
    Filter->x_last = Filter->x_last +K*(z_real - Filter->x_last);
    Filter->P_last = (1 - K) * P_temp;
    return Filter->x_last;
}

/* Q计算偏差 越大越相信真实值
 * R测量偏差 越大越相信预测值
 */
void KalmanFilterInit(float Q, float R, KalmanFilterTypeDef* Filter)
{
    Filter->Q = Q;
    Filter->R = R;
    Filter->P_last = 0;
    Filter->x_last = 0;
    return;
}
