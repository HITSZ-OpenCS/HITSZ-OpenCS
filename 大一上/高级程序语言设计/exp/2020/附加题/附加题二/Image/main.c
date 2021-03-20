#include <stdio.h>
#include <stdlib.h>
#include "cv.h"

int main(int argc, char* argv[])
{
    BMPImage* img = LoadBMPImage("girl.bmp");
    BMPImage* convdImg;
    /**Write your code here**/
    float const kernel[3][3] = {{2, 0 , 0},
                                {0 , -1, 0},
                                {0 , 0, -1}};
    convdImg = Convolution2D(img, kernel);
    /**Done, save picture**/
    if(SaveBMPImage("result.bmp", convdImg))
    {
        printf("bmp image processed.\n");
    }

    return 0;
}




