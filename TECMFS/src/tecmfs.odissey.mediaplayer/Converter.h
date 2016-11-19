/*
 * Converter.h
 *
 *  Created on: 17 nov. 2016
 *      Author: gustavo
 */

#ifndef CONVERTER_H_
#define CONVERTER_H_

#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <strings.h>
#include <fstream>
#include <cstring>
#include <cstddef>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cv.h>
#include <highgui.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/opencv.hpp>

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <zip.h>

#include "Encripter.h"


using namespace std;
using namespace cv;

class Converter {
public:
	Converter();
	virtual ~Converter();
	void loadVideo(const char *path);
	void videoCompress();
	string sendVideo();
	void receiveVideo(string dataBin);
	void videoDecompress();

	string binaryToAscii(string input);

private:
	const char *pathVideo;
};

#endif /* CONVERTER_H_ */
