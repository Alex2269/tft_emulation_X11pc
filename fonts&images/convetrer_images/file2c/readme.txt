This utility converts a file (of any type) into a c array
so that it can be compiled into your project.

For example:
	file2c       test.bmp   test-image.h
	file2c -cs   test.bmp   test-image.h
	file2c -dcs  infile     outfile
	file2c -dbcs infile     outfile


	convert -define bmp:format=bmp3 tiger.png tiger.bmp
	file2c       tiger.bmp  tiger.h

For usage instructions:
	file2c -?




