//  |---------------------------------------------------------------|
//  | Analog frame difference model for motion detection based on   |
//  | an N-spot motion detection.                                   |
//  |---------------------------------------------------------------|
//  | Version P1A, Deyan Levski deyan.levski@gmail.com, 26 Oct 2014 |
//  |---------------------------------------------------------------|

#define IMGTH 1

#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <ctype.h>

// Returns a new image that is a cropped version (rectangular cut-out)
// of the original image.
IplImage* cropImage(const IplImage *img, const CvRect region)
{
	IplImage *imageCropped;
	CvSize size;

	if (img->width <= 0 || img->height <= 0
		|| region.width <= 0 || region.height <= 0) {
		//cerr << "ERROR in cropImage(): invalid dimensions." << endl;
		exit(1);
	}

	if (img->depth != IPL_DEPTH_8U) {
		//cerr << "ERROR in cropImage(): image depth is not 8." << endl;
		exit(1);
	}

	// Set the desired region of interest.
	cvSetImageROI((IplImage*)img, region);
	// Copy region of interest into a new iplImage and return it.
	size.width = region.width;
	size.height = region.height;
	imageCropped = cvCreateImage(size, IPL_DEPTH_8U, img->nChannels);
	cvCopy(img, imageCropped);	// Copy just the region.
	cvResetImageROI((IplImage*)img);

	return imageCropped;
}

IplImage *image = 0, *frameTime1=0, *frameTime2=0, *frameForeground=0, *img1=0, *img2=0, *imageROI = 0;

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

	#if IMGTH == 1

       cvAbsDiff(
                  frameTime1,
                  frameTime2,
                  frameForeground
                  );

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


//	cvAdaptiveThreshold(
//		frameForeground,
//		frameForeground,
//		255,
//		CV_ADAPTIVE_THRESH_MEAN_C,
//		CV_THRESH_BINARY_INV,
//		3,
//		1);

	cvShowImage( "AbsDiffThreshold", frameForeground);  //AbsDiffThreshold window
         
	#endif
	 
	uchar sig1[15][15];
	unsigned int colSpotCnt = 0;
	unsigned int rowSpotCnt = 0;
	unsigned int spot = 0;
	unsigned int row = 0;
	unsigned int col = 0;

        for( row = 0; row < ((frameForeground->height)); row+=31 )
        {
	colSpotCnt = 0;
          for ( col = 0; col < ((frameForeground->width)); col+=31 )
          {

            sig1[rowSpotCnt][colSpotCnt] = CV_IMAGE_ELEM( frameForeground, uchar, row, col );

		if ( sig1[rowSpotCnt][colSpotCnt] > 0 ) {
		cvCircle(image,cvPoint(col,row),2,CV_RGB(255,0,0),-1);	
		}

	colSpotCnt++;

           }
	rowSpotCnt++;
	}

	imageROI = cropImage(image,cvRect(0, 0, 100, 100)); // X,Y,W,H

        cvShowImage( "CameraROI", imageROI);  //Display the original image w/wo added green rectangle

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
