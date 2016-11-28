/*
 * Converter.cpp
 *
 *  Created on: 17 nov. 2016
 *      Author: gustavo
 */

#include "Converter.h"

const char *nameZip = "videoFile.zip";
const char *nameBin = "videoFile.bin";
const char *folder = "videos/";
Encripter crypto;

Converter::Converter() {
}

Converter::~Converter() {
}

void Converter::loadVideo(const char *path){
	this->pathVideo = path;
	videoCompress();
	ifstream fileZip(nameZip, ifstream::binary|ifstream::in);
	char dataZip;
	string dataToBinary;
	while(fileZip.get(dataZip)){
		dataToBinary += dataZip;
	}
	fileZip.close();
	//remove(nameZip);

	dataToBinary = crypto.encode(dataToBinary);

	ofstream zipVideoToBit;
	zipVideoToBit.open(nameBin, ofstream::binary|ofstream::out);
	for(int i = 0; i < (int)dataToBinary.length(); i++){
		for (int j = 7; j >= 0; j--){
			zipVideoToBit << ((dataToBinary[i] >> j) & 1);
		}
	}
	zipVideoToBit.close();
}


void Converter::videoCompress(){
	int err = 0;
	zip *zipFile(NULL);
	zip_source_t *source;
	zip_int64_t sizeFile;
	zipFile = zip_open(nameZip, ZIP_CREATE, &err);

	/*
	 * load file to compress
	 */
	ifstream fileToCompress(pathVideo, ios::in|ios::binary|ios::ate);
	streampos size;
	char *data;
	size = fileToCompress.tellg();
	data = new char[size];
	fileToCompress.seekg(0, ios::beg);
	fileToCompress.read(data, size);
	fileToCompress.close();

	sizeFile = size;
	source = zip_source_buffer(zipFile, data, sizeFile, 0);
	zip_file_add(zipFile, pathVideo, source, ZIP_FL_ENC_UTF_8);
	zip_close(zipFile);
	delete[] data;

}


string Converter::sendVideo(){
	ifstream fileBin(nameBin, ios::in|ios::binary|ios::ate);
	char data;
	string dataBin;
	while(fileBin.get(data)){
		dataBin += data;
	}
	fileBin.close();
	//remove(nameBin);
	return dataBin;
}


void Converter::receiveVideo(string dataBin){
	ofstream binToZip;
	binToZip.open(nameZip, ofstream::binary|ofstream::out);
	binToZip << crypto.decode((binaryToAscii(dataBin)));
	binToZip.close();
}


void Converter::videoDecompress(){
	int err = 0;
	zip *zipFile;
	zip_stat_t stat;
	zip_file_t *file;
	zipFile = zip_open(nameZip, 0, &err);
	int len;
	char buf[100];
	long long sum;
	int fd;
	for (int i = 0; i < zip_get_num_entries(zipFile, 0); i++){
		if (zip_stat_index(zipFile, i, 0, &stat) == 0 ){
			len = strlen(stat.name);

			file = zip_fopen_index(zipFile, i, 0);

			fd = open(stat.name, O_RDWR | O_TRUNC | O_CREAT, 0644);
			 if (fd < 0) {
				cout << "error fd";
			}
			sum = 0;
			while(sum != stat.size){
				len = zip_fread(file, buf, 100);
				if (len < 0){
					cout << "error \n Write" << endl;
				}
				write(fd, buf, len);
				sum += len;
			}
			close(fd);
			zip_fclose(file);
		}
	}
	zip_close(zipFile);
	remove(nameZip);



}


string Converter::binaryToAscii(string input){

	int length = input.size();
	//int length = strlen(input);
	int binary[8];    //array used to store 1 byte of binary number (1 character)
	int asciiNum = 0;      //the ascii number after conversion from binary
	string ascii;      //the ascii character itself

	int z = 0;   //counter used

	for(int x = 0; x < length / 8; x++)     //reading in bytes. total characters = length / 8
	{
		for(int a = 0; a < 8; a++)      //store info into binary[0] through binary[7]
		{
			binary[a] = (int)input[z] - 48;      //z never resets
			z++;
		}

		int power[8];    //will set powers of 2 in an array
		int counter = 7;        //power starts at 2^0, ends at 2^7
		for(int x = 0; x < 8; x++)
		{
			power[x] = counter;      //power[] = {7, 6, 5, ..... 1, 0}
			counter--;    //decrement counter each time
		}

		for(int y = 0; y < 8; y++)    //will compute asciiNum
		{
			double a = binary[y];    //store the element from binary[] as "a"
			double b = power[y];    //store the lement from power[] as "b"

			asciiNum += a* pow(2, b);   //asciiNum = sum of a * 2^power where 0 <= power <= 7, power is int
		}

		ascii.append((const char*)&asciiNum);   //assign the asciiNum value to ascii, to change it into an actual character
		asciiNum = 0;    //reset asciiNum for next loop
	}
	return ascii;
}


int Converter::byteVideo(const char* path){
    ifstream fileToCompress(path, ios::in|ios::binary|ios::ate);
    streampos size;
    char *data;
    size = fileToCompress.tellg();
    data = new char[size];
    fileToCompress.seekg(0, ios::beg);
    fileToCompress.read(data, size);
    fileToCompress.close();
    delete[] data;
    return (int)size;

}
