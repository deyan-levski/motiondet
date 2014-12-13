#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <ctype.h>

IplImage *image = 0, *frameTime1=0, *frameTime2=0, *frameForeground=0, *img1=0, *img2=0;

int main( int argc, char** argv )
{
    printf("Terminate with ESC.\n");
    CvCapture* capture = 0;   		 //Video capturing structure
    capture = cvCreateCameraCapture( -1 );    //Initializes capturing a video from a camera   
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 160); // width of viewport of camera
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 120); // height of ...

    if( !capture )
    {
        fprintf(stderr,"Camera could not be initialized...\n");
        return -1;
    }
    cvNamedWindow( "Camera", 1 );  	 //create the window for the Camera Output (Directly)
    while(1)
    {
        IplImage* frame = 0;  		 //every time create/initialize an image (which name is frame) to process
        int  c;              		 //integer to exit program
        frame = cvQueryFrame( capture ); //grabs and returns a frame from a camera input
       
        if( !frame )    //if there is no frame exit the while(1)
            break;
        if( !image )    //if there is no image, do the following
        {
            /* allocate all the buffers */
            image = cvCreateImage( cvGetSize(frame), 8, 3 ); 
            frameTime1 = cvCreateImage( cvGetSize(frame), 8, 1 );
            frameTime2 = cvCreateImage( cvGetSize(frame), 8, 1 );  
            frameForeground = cvCreateImage( cvGetSize(frame), 8, 1 );
            img1 = cvCreateImage( cvGetSize(frame), 8, 1 );  
            img2 = cvCreateImage( cvGetSize(frame), 8, 1 );
        }
        cvCopy( frame, image, 0 );  
        cvCvtColor( image, img1, CV_BGR2GRAY ); 
        cvCopy( img1, frameTime1, 0 );    //currently frame in grayscale

        cvAbsDiff(
                  frameTime1,
                  frameTime2,
                  frameForeground
                  );

        cvShowImage( "AbsDiff", frameForeground);  //AbsDiff window
	
//	int row, col;
//	uchar b, g, r, sig1, sig2;

// Color segregation

//	for( row = 0; row < frameForeground->height; row++ )
//	{
//	  for ( col = 0; col < frameForeground->width; col+2 )
//	  {
//	
//	    sig1 = CV_IMAGE_ELEM( frameForeground, uchar, row, col * 2 );
//	    sig2 = CV_IMAGE_ELEM( frameForeground, uchar, row, col * 2 + 1 );
//	
//	    //printf("Y: %d X: %d Val: %d \n", row, col, sig1);
//	    //printf("Y: %d X: %d Val: %d \n", row, col, sig2);
//	
//	  }
//	}	

        cvThreshold(
                frameForeground,
                frameForeground,
                20,
                255,
                CV_THRESH_BINARY);
                 //CV_THRESH_BINARY_INV);
	         //CV_THRESH_TRUNC);
	         //CV_THRESH_TOZERO);
	         //CV_THRESH_TOZERO_INV);
        cvShowImage( "AbsDiffThreshold", frameForeground);  //AbsDiffThreshold window

	int row, col;
	uchar sig1, sig2;
	unsigned long int rowsum[120], totalsum;
	
	totalsum = 0;
	for( row = 0; row < frameForeground->height; row++ )
	{
	rowsum[row] = 0;
	  for ( col = 0; col < frameForeground->width; col++ )
	  {
	
	    sig1 = CV_IMAGE_ELEM( frameForeground, uchar, row, col * 2 );
	    sig2 = CV_IMAGE_ELEM( frameForeground, uchar, row, col * 2 + 1 );
	    rowsum[row] += (sig1 + sig2);

	    //printf("Y: %d X: %d Val: %d \n", row, col, sig1);
	    //printf("Y: %d X: %d Val: %d \n", row, col, sig2);
	
	  }

	totalsum += rowsum[row];
	
	}	

	printf("Totalsum: %20d \n", totalsum);

	if (totalsum >= 80000) {
             cvRectangle(image,cvPoint(10,10), cvPoint(150, 110),cvScalar(0, 255, 0, 0),1,8,0);
	}

//   cvErode(
//        frameForeground,
//        frameForeground,
//        0,
//        1);     
//      cvShowImage( "AbsDiffThresholdErode", frameForeground);  //AbsDiffThreshold window
//
//     cvDilate(
//             frameForeground,
//             frameForeground,
//             0,
//             1);      
//       cvShowImage( "AbsDiffThresholdErodeDilate", frameForeground );
        cvShowImage( "Camera", image );  //displays the image in the specified window 

        cvCopy( frameTime1, frameTime2, 0 );

        c = cvWaitKey(10);     //waits for a pressed key
        if( (char) c == 27 )  //if key==ESC (27 ESC button) then break
            break;
    }
    cvReleaseCapture( &capture );  //Releases the CvCapture structure
    cvDestroyWindow("Camera");
    cvDestroyWindow("AbsDiffThresholdDilate");
    cvDestroyWindow("AbsDiffThresholdErode");
    cvDestroyWindow("AbsDiffThreshold");
    cvDestroyWindow("AbsDiff");

    return 0;
}
