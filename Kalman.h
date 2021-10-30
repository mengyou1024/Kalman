#ifndef __KALMAN__H_
#define __KALMAN__H_
/*
 *卡尔曼滤波
 */

typedef struct
{
    float x_last;	// 上次的数据
	float P_last;	// 
	float Q;		// 计算偏差，该值越大越相信输入值z_real
	float R;		// 测量偏差,该值越大越相信上一次的数据
}KalmanFilterTypeDef;//卡尔曼滤波器


float KalmanFilterSingalCalc(KalmanFilterTypeDef* Filter, float z_real);//卡尔曼滤波单次计算
void KalmanFilterInit(float Q, float R, KalmanFilterTypeDef* Filter);//卡尔曼滤波器参数初始化 Q，R参照结构体
#endif
