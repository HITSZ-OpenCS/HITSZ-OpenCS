#include "cv.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

BMPImage* LoadBMPImage(char* path)
{
    FILE* pFile;

    /**0. Init Values**/
    //BMP Image parts
    BMPImage* bmpImg;  //Img Content
    BitMapFileHeader bmpFileHeader;
    BitMapInfoHeader bmpInfoHeader;
    //BMP Image file info
    unsigned short fileType;  //Picture type Sign
    int channels = 3;
    int width = 0;
    int height = 0;
    //Data Content Parameters
    int offset = 0;
    PixelBlock pixVal;  //One Pixel Value
    unsigned char offset_char;
    int i, j;

    bmpImg = (BMPImage*)malloc(sizeof(BMPImage));  //Will return this Variable

    /**1. File Open**/
    pFile = fopen(path, "rb");
    if (!pFile){
        free(bmpImg);
        return NULL;
    }

    /**2. Read Image File Content**/
    fread(&fileType, sizeof(unsigned short), 1, pFile);
    if (fileType == 0x4D42)
    {
        //2.1 Read Header
        fread(&bmpFileHeader, sizeof(BitMapFileHeader), 1, pFile);

        //2.2 Get Picture Info
        fread(&bmpInfoHeader, sizeof(BitMapInfoHeader), 1, pFile);
        assert(bmpInfoHeader.biBitCount == 24);
        width = bmpInfoHeader.biWidth;
        height = bmpInfoHeader.biHeight;
        bmpImg->width = width;
        bmpImg->height = height;
        bmpImg->channels = channels;
        bmpImg->imageData = (PixelBlock*)malloc(sizeof(PixelBlock)*width*height);
        offset = (channels*width)%4;    //offset in bmpFile

        if (offset != 0)
        {
            offset = 4 - offset;
        }

        /**Most Important**/
        //2.3 Reading ImageData
        for (i=0; i<height; i++)
        {
            for (j=0; j<width; j++)
            {
                //2.3.1 Read One single Pixel to &pixVal
                fread(&pixVal.B, sizeof(unsigned char), 1, pFile);
                fread(&pixVal.G, sizeof(unsigned char), 1, pFile);
                fread(&pixVal.R, sizeof(unsigned char), 1, pFile);
                //2.3.2 Read One single Pixel to &pixVal
                bmpImg->imageData[(height-1-i)*width+j] = pixVal;
            }
            if (offset != 0)
            {
                for (j=0; j<offset; j++)
                {
                    fread(&offset_char, sizeof(unsigned char), 1, pFile);
                }
            }
        }
    }
    fclose(pFile);
    return bmpImg;
}

bool SaveBMPImage(char* path, BMPImage* bmpImg)
{
    FILE *pFile;
    unsigned short fileType;
    BitMapFileHeader bmpFileHeader;
    BitMapInfoHeader bmpInfoHeader;
    int rowLen;
    int offset;
    PixelBlock pixVal;
    unsigned char offset_char;
    int i, j;

    pFile = fopen(path, "wb");
    if (!pFile)
    {
        return false;
    }

    fileType = 0x4D42;
    fwrite(&fileType, sizeof(unsigned short), 1, pFile);

    assert(bmpImg->channels == 3);
    rowLen = bmpImg->channels*bmpImg->width;
    offset = (rowLen)%4;
    if (offset != 4)
    {
        rowLen += 4-offset;
    }

    //Write Header
    bmpFileHeader.bfSize = bmpImg->height*rowLen + 54;
    bmpFileHeader.fReserved1 = 0;
    bmpFileHeader.fReserved2 = 0;
    bmpFileHeader.fOffBits = 54;
    fwrite(&bmpFileHeader, sizeof(BitMapFileHeader), 1, pFile);

    //Write Info
    bmpInfoHeader.biSize = 40;
    bmpInfoHeader.biWidth = bmpImg->width;
    bmpInfoHeader.biHeight = bmpImg->height;
    bmpInfoHeader.biPlanes = 1;
    bmpInfoHeader.biBitCount = 24;
    bmpInfoHeader.biCompression = 0;
    bmpInfoHeader.biSizeImage = bmpImg->height*rowLen;
    bmpInfoHeader.biXPelsPerMeter = 0;
    bmpInfoHeader.biYPelsPerMeter = 0;
    bmpInfoHeader.biClrUsed = 0;
    bmpInfoHeader.biClrImportant = 0;
    fwrite(&bmpInfoHeader, sizeof(BitMapInfoHeader), 1, pFile);

    //Write Image Data
    for (i=bmpImg->height-1; i>-1; i--)
    {
        for (j=0; j<bmpImg->width; j++)
        {
            pixVal = bmpImg->imageData[i*bmpImg->width+j];
            fwrite(&pixVal.B, sizeof(unsigned char), 1, pFile);
            fwrite(&pixVal.G, sizeof(unsigned char), 1, pFile);
            fwrite(&pixVal.R, sizeof(unsigned char), 1, pFile);
        }
        if (offset!=0)
        {
            for (j=0; j<offset; j++)
            {
                offset_char = 0;
                fwrite(&offset_char, sizeof(unsigned char), 1, pFile);
            }
        }
    }
    fclose(pFile);

    return true;
}
