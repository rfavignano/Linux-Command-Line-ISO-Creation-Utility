#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main( int argc, char** argv ){
	int device, isofile;
	int i, bytes_read;
	unsigned char buffer[1000] = {0};

	if( argc != 3 ){
		printf( "Error: Two arguments not supplied.\n" );
		printf( "Syntax: %s file_to_copy new_file\n", argv[0] );
		return -4;
	}

	// Access CD-ROM or DVD-ROM drive
	if( ( device = open( argv[1], O_RDONLY ) ) == -1 ){
		printf( "Cannot open cdrom.\n" );
		return -1;
	}

	printf( " %s\n ", argv[2] );
	
	// Create the ISO file.
	if( ( isofile = open( argv[2], O_WRONLY ) ) == -1 ) {
		printf( "Cannot create iso file.\n" );
		return -2;
	}

	// The primary read and write algorithm.
	while( bytes_read != 0){
		if( ( bytes_read = read( device, buffer, sizeof( buffer ) ) ) == -1 ){
			printf( "Failed to read into buffer.\n" );
			return -3;
		}

		if( ( write( isofile, buffer, bytes_read ) ) == -1 ){
			printf( "Failed to write to file.\n" );
			return -4;
		}
	}

	printf( "Finished!\n" );

	return 0;

	// The above code opens the cdrom for reading.
	// Open a pointer to a file (fopen), and 
	// read the cdrom data into the file directly.

}
