#include <stdio.h>
#include <iostream>
#include "BitmapTexture.h"



void createTestImage(BitmapTexture *texture)
{
    for (int i = 0; i < texture->getSize().height; i++) {
        texture->setColor(Color(255, 0, 0, 255), texture->getSize().width / 3, i);
    }
}


int main(int argc, char **argv)
{
    int width = 500;
    int height = 300;

    printf("Creating Image\n");
    BitmapTexture texture(GSize2D(width, height));
    createTestImage(&texture);

    printf("Saving PNG\n");
    std::string name = "result.png";
    std::string title = "test image";
    texture.Save(name, title);
    return 0;
}


