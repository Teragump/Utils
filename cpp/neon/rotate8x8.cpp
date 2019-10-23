#include <arm_neon.h>
#include <iostream>

void rotate_minus90(short *src, short *dst)
{
    int16x8_t v0, v1, v2, v3, v4, v5, v6, v7;

    v0 = vld1q_s16(src + 0*8);
    v1 = vld1q_s16(src + 1*8);
    v2 = vld1q_s16(src + 2*8);
    v3 = vld1q_s16(src + 3*8);
    v4 = vld1q_s16(src + 4*8);
    v5 = vld1q_s16(src + 5*8);
    v6 = vld1q_s16(src + 6*8);
    v7 = vld1q_s16(src + 7*8);

    int16x8x2_t temp0 = vtrnq_s16(v1, v0);
    int16x8x2_t temp1 = vtrnq_s16(v3, v2);
    int16x8x2_t temp2 = vtrnq_s16(v5, v4);
    int16x8x2_t temp3 = vtrnq_s16(v7, v6);

    int32x4x2_t temp4, temp5, temp6, temp7;
    temp4.val[0] = vreinterpretq_s32_s16(temp0.val[0]);
    temp4.val[1] = vreinterpretq_s32_s16(temp0.val[1]);
    temp5.val[0] = vreinterpretq_s32_s16(temp1.val[0]);
    temp5.val[1] = vreinterpretq_s32_s16(temp1.val[1]);
    temp6.val[0] = vreinterpretq_s32_s16(temp2.val[0]);
    temp6.val[1] = vreinterpretq_s32_s16(temp2.val[1]);
    temp7.val[0] = vreinterpretq_s32_s16(temp3.val[0]);
    temp7.val[1] = vreinterpretq_s32_s16(temp3.val[1]);

    int32x4x2_t temp8 = vtrnq_s32(temp5.val[0], temp4.val[0]);
    int32x4x2_t temp9 = vtrnq_s32(temp5.val[1], temp4.val[1]);
    int32x4x2_t temp10 = vtrnq_s32(temp7.val[0], temp6.val[0]);
    int32x4x2_t temp11 = vtrnq_s32(temp7.val[1], temp6.val[1]);

    int32x4_t temp12 = vcombine_s32(vget_low_s32(temp10.val[0]), vget_low_s32(temp8.val[0]));
    int32x4_t temp13 = vcombine_s32(vget_low_s32(temp11.val[0]), vget_low_s32(temp9.val[0]));
    int32x4_t temp14 = vcombine_s32(vget_low_s32(temp10.val[1]), vget_low_s32(temp8.val[1]));
    int32x4_t temp15 = vcombine_s32(vget_low_s32(temp11.val[1]), vget_low_s32(temp9.val[1]));
    int32x4_t temp16 = vcombine_s32(vget_high_s32(temp10.val[0]), vget_high_s32(temp8.val[0]));
    int32x4_t temp17 = vcombine_s32(vget_high_s32(temp11.val[0]), vget_high_s32(temp9.val[0]));
    int32x4_t temp18 = vcombine_s32(vget_high_s32(temp10.val[1]), vget_high_s32(temp8.val[1]));
    int32x4_t temp19 = vcombine_s32(vget_high_s32(temp11.val[1]), vget_high_s32(temp9.val[1]));

    v0 = vreinterpretq_s16_s32(temp12);
    v1 = vreinterpretq_s16_s32(temp13);
    v2 = vreinterpretq_s16_s32(temp14);
    v3 = vreinterpretq_s16_s32(temp15);
    v4 = vreinterpretq_s16_s32(temp16);
    v5 = vreinterpretq_s16_s32(temp17);
    v6 = vreinterpretq_s16_s32(temp18);
    v7 = vreinterpretq_s16_s32(temp19);

    vst1q_s16(dst + 0*8, v0);
    vst1q_s16(dst + 1*8, v1);
    vst1q_s16(dst + 2*8, v2);
    vst1q_s16(dst + 3*8, v3);
    vst1q_s16(dst + 4*8, v4);
    vst1q_s16(dst + 5*8, v5);
    vst1q_s16(dst + 6*8, v6);
    vst1q_s16(dst + 7*8, v7);
}

void rotate_90(short *src, short *dst)
{
    int16x8_t v0, v1, v2, v3, v4, v5, v6, v7;

    v0 = vld1q_s16(src + 0*8);
    v1 = vld1q_s16(src + 1*8);
    v2 = vld1q_s16(src + 2*8);
    v3 = vld1q_s16(src + 3*8);
    v4 = vld1q_s16(src + 4*8);
    v5 = vld1q_s16(src + 5*8);
    v6 = vld1q_s16(src + 6*8);
    v7 = vld1q_s16(src + 7*8);

    int16x8x2_t temp0 = vtrnq_s16(v0, v1);
    int16x8x2_t temp1 = vtrnq_s16(v2, v3);
    int16x8x2_t temp2 = vtrnq_s16(v4, v5);
    int16x8x2_t temp3 = vtrnq_s16(v6, v7);

    int32x4x2_t temp4, temp5, temp6, temp7;
    temp4.val[0] = vreinterpretq_s32_s16(temp0.val[0]);
    temp4.val[1] = vreinterpretq_s32_s16(temp0.val[1]);
    temp5.val[0] = vreinterpretq_s32_s16(temp1.val[0]);
    temp5.val[1] = vreinterpretq_s32_s16(temp1.val[1]);
    temp6.val[0] = vreinterpretq_s32_s16(temp2.val[0]);
    temp6.val[1] = vreinterpretq_s32_s16(temp2.val[1]);
    temp7.val[0] = vreinterpretq_s32_s16(temp3.val[0]);
    temp7.val[1] = vreinterpretq_s32_s16(temp3.val[1]);

    int32x4x2_t temp8 = vtrnq_s32(temp4.val[0], temp5.val[0]);
    int32x4x2_t temp9 = vtrnq_s32(temp4.val[1], temp5.val[1]);
    int32x4x2_t temp10 = vtrnq_s32(temp6.val[0], temp7.val[0]);
    int32x4x2_t temp11 = vtrnq_s32(temp6.val[1], temp7.val[1]);

    int32x4_t temp12 = vcombine_s32(vget_low_s32(temp8.val[0]), vget_low_s32(temp10.val[0]));
    int32x4_t temp13 = vcombine_s32(vget_low_s32(temp9.val[0]), vget_low_s32(temp11.val[0]));
    int32x4_t temp14 = vcombine_s32(vget_low_s32(temp8.val[1]), vget_low_s32(temp10.val[1]));
    int32x4_t temp15 = vcombine_s32(vget_low_s32(temp9.val[1]), vget_low_s32(temp11.val[1]));
    int32x4_t temp16 = vcombine_s32(vget_high_s32(temp8.val[0]), vget_high_s32(temp10.val[0]));
    int32x4_t temp17 = vcombine_s32(vget_high_s32(temp9.val[0]), vget_high_s32(temp11.val[0]));
    int32x4_t temp18 = vcombine_s32(vget_high_s32(temp8.val[1]), vget_high_s32(temp10.val[1]));
    int32x4_t temp19 = vcombine_s32(vget_high_s32(temp9.val[1]), vget_high_s32(temp11.val[1]));

    v0 = vreinterpretq_s16_s32(temp12);
    v1 = vreinterpretq_s16_s32(temp13);
    v2 = vreinterpretq_s16_s32(temp14);
    v3 = vreinterpretq_s16_s32(temp15);
    v4 = vreinterpretq_s16_s32(temp16);
    v5 = vreinterpretq_s16_s32(temp17);
    v6 = vreinterpretq_s16_s32(temp18);
    v7 = vreinterpretq_s16_s32(temp19);

    vst1q_s16(dst + 0*8, v7);
    vst1q_s16(dst + 1*8, v6);
    vst1q_s16(dst + 2*8, v5);
    vst1q_s16(dst + 3*8, v4);
    vst1q_s16(dst + 4*8, v3);
    vst1q_s16(dst + 5*8, v2);
    vst1q_s16(dst + 6*8, v1);
    vst1q_s16(dst + 7*8, v0);
}

int main(void)
{
    short arr[64];
    short result[64];

    std::cout << "init array:" << std::endl;
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            arr[j * 8 + i] = j * 10 + i;
            std::cout << arr[j * 8 + i] << " ";
        }
        std::cout << std::endl;
    }

    rotate_minus90(arr, result);
    std::cout << "-90:" << std::endl;
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            std::cout << result[j * 8 + i] << " ";
        }
        std::cout << std::endl;
    }

    rotate_90(arr, result);
    std::cout << "+90:" << std::endl;
    for (int j = 0; j < 8; j++) {
        for (int i = 0; i < 8; i++) {
            std::cout << result[j * 8 + i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
