//  |---------------------------------------------------------------|
//  | Analog frame difference model for motion detection based on
//  | a two-row frame buffer comparison                             |
//  |---------------------------------------------------------------|
//  | Version P1A, Deyan Levski deyan.levski@gmail.com, 26 Oct 2014 |
//  |---------------------------------------------------------------|

#define ABSDIFF 0
#define IMGTH 0


#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <ctype.h>

IplImage *image = 0, *frameTime1=0, *frameTime2=0, *frameForeground=0, *img1=0, *img2=0;

int main( int argc, char** argv )
{
    printf("Terminate with ESC.\n");
    CvCapture* capture = 0;   		      //Video capturing structure
    capture = cvCreateCameraCapture( -1 );    //Initializes capturing a video from a camera   
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 640);  // width of viewport of camera
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 480); // height of ...

    if( !capture )
    {
        fprintf(stderr,"Camera could not be initialized...\n");
        return -1;
    }
    cvNamedWindow( "Camera", 1 );  	      //create the window for the Camera Output (Directly)
    while(1)
    {
        IplImage* frame = 0;  		      //every time create/initialize an image (which name is frame) to process
        int  c;              		      //integer to exit program
        frame = cvQueryFrame( capture );      //grabs and returns a frame from a camera input
       
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
	
	#if ABSDIFF == 1	

        cvAbsDiff(
                  frameTime1,
                  frameTime2,
                  frameForeground
                  );

        cvShowImage( "AbsDiff", frameForeground);  //AbsDiff window

	#endif

	#if IMGTH == 1

        cvThreshold(
                frameForeground,
                frameForeground,
                20,  //Threshold
                255, //Saturate up to 255
                CV_THRESH_BINARY);
                 //CV_THRESH_BINARY_INV);
	         //CV_THRESH_TRUNC);
	         //CV_THRESH_TOZERO);
	         //CV_THRESH_TOZERO_INV);
	        
	cvShowImage( "AbsDiffThreshold", frameForeground);  //AbsDiffThreshold window
         
	#endif
	         
	int row, col;
	uchar sig1, sig2;
	unsigned long int colsum[frameForeground->width], totalsum;
	
	totalsum = 0;
	for( col = 0; col < frameForeground->width; col++ )
	{
	colsum[col] = 0;
	  for ( row = 0; row < frameForeground->height; row++ )
	  {
	
	    sig1 = CV_IMAGE_ELEM( frameTime1, uchar, row, col );
	    sig2 = CV_IMAGE_ELEM( frameTime2, uchar, row + 1, col );

	    //colsum[col] += (sig1 + sig2);
	    
	    //Comparator	    
	    if (abs(sig1-sig2) >= 40)
		{
		colsum[col] += 1;
		}

	    //printf("Y: %d X: %d Val: %d \n", row, col, sig1);
	    //printf("Y: %d X: %d Val: %d \n", row, col, sig2);
	
	  }

	totalsum += colsum[col];
	
	}	

	printf("Totalsum: %20d \n", totalsum);

	if (totalsum >= 5000) // Motion detection threshold
	{ 
             cvRectangle(image,cvPoint(40,40), cvPoint(600, 440),cvScalar(0, 255, 0, 0),1,8,0); // Draw a green rectangle
	}

        cvShowImage( "Camera", image );  //Display the original image w/wo added green rectangle

        cvCopy( frameTime1, frameTime2, 0 );

        c = cvWaitKey(10);    		 //waits for a pressed key
        if( (char) c == 27 ) 		 //if key==ESC (27 ESC button) then break
            break;
    }
    cvReleaseCapture( &capture );  	 //Releases the CvCapture structure
    cvDestroyWindow("Camera");
    cvDestroyWindow("AbsDiffThresholdDilate");
    cvDestroyWindow("AbsDiffThresholdErode");
    cvDestroyWindow("AbsDiffThreshold");
    cvDestroyWindow("AbsDiff");

    return 0;
}
