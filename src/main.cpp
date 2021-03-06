#include <stdio.h>
#include <iostream>
#include "BitmapTexture.h"
#include "NoiseGenerator.h"
#include "Map.h"
#include <time.h>



void createTestImage(BitmapTexture *texture, float moreWater)
{
    PerlinNoise p(rand());
    for (int x = 0; x < texture->getSize().width; x++) {
        for (int y = 0; y < texture->getSize().height; y++) {
            float n = p.noise((float)x / 30, (float)y / 30, 1);
            n -= moreWater;
            Color color;
            if (n > 0.5) {
                color = Color(255, 255, 255, 255);
            }
            else {
                color = Color(128, 128, 255, 255);
            }
            texture->setColor(color, x, y);
        }
    }
}

void GenerateMaps(int offset, int count, float water)
{
    int width = 112;
    int height = 112;
    for (int i = offset; i < offset + count; i++) {
        printf("Creating Image\n");
        BitmapTexture texture(GSize2D(width, height));
        createTestImage(&texture, water);
        
        texture.DrawLine(GPoint2D(10, 10), GPoint2D(100, 50), __Color(10, 10, 100, 255));

        printf("Saving PNG\n");
        std::string name = "result";
        name += std::to_string(i);
        name += ".png";
        std::string title = "test image";
        texture.Save(name, title);
    }
}


int main(int argc, char **argv)
{
    time_t t;
    srand((unsigned) time(&t));
    
    GenerateMaps(0, 10, 0);
    GenerateMaps(10, 10, 0.1);
    GenerateMaps(20, 10, -0.1);
    return 0;
}


