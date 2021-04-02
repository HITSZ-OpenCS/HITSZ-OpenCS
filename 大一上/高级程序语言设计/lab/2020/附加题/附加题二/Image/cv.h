#ifndef CV_H
#define CV_H
# include<stdbool.h>
typedef struct
{
    unsigned long bfSize;  //文件大小
    unsigned short fReserved1;  //保留字
    unsigned short fReserved2;  //保留字
    unsigned long fOffBits;  //位图数据偏移字节数
} BitMapFileHeader;  /*文件头*/

typedef struct
{
    unsigned long biSize;   //结构体长度
    long biWidth;   //位图宽度
    long biHeight;   //位图高度
    unsigned short biPlanes;   //位图平面数
    unsigned short biBitCount;  //颜色位数
    unsigned long biCompression;   //压缩方式
    unsigned long biSizeImage;   //实际位图数据占用的字节数
    long biXPelsPerMeter;   //X方向分辨率
    long biYPelsPerMeter;   //Y方向分辨率
    unsigned long biClrUsed;   //使用的颜色数
    unsigned long biClrImportant;   //重要颜色数
} BitMapInfoHeader;  /*位图信息头*/

typedef struct
{
    unsigned char B;
    unsigned char G;
    unsigned char R;
} PixelBlock;

typedef struct
{
    int width;
    int height;
    int channels;
    PixelBlock* imageData;
}BMPImage;

BMPImage* LoadBMPImage(char* path);
bool SaveBMPImage(char* path, BMPImage* bmpImg);

#endif
