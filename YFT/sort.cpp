#include "sort.h"
#include "structures.h"
#include "ioFile.h"
/**********************************************************************************
* Function Name:	Sort.h														  *	
* Description:		This function is used to QuickSort			                  * 
* Date:				2013-07-30													  *
* Parameter:		void														  *												
* Model	:			≈≈–Úƒ£øÈ													  *
* Author:			≥Ÿ◊”ËØ ∂≠≤©													  *
**********************************************************************************/
void QSort (RoadArray_t* stRK, int itag)
{
	int ilow, ihigh, low, high, top = -1;
	RoadMsg_t tempstRK;
	struct node
	{      
		int low, high;
	}st[INFO_SIZE];

	top++;
		
	st[top].low = 0;		
	st[top].high = stRK->length - 1;
	
	switch (itag)
	{
	case TYPE_ID:	      
		while (top > -1)
		{      
			low = st[top].low;
			high = st[top].high;
			top--;
			ilow = low;
			ihigh = high;
			if (low < high)
			{      
				tempstRK = stRK->roadMsgs[low];
				while (ilow != ihigh)
				{      
					while (ilow < ihigh && stRK->roadMsgs[ihigh].linkID > tempstRK.linkID)
					{
						ihigh--;
					}
				
					if (ilow < ihigh)
					{
						stRK->roadMsgs[ilow] = stRK->roadMsgs[ihigh];
						ilow++;
					}
					while (ilow < ihigh && stRK->roadMsgs[ilow].linkID < tempstRK.linkID)
					{
						ilow++;
					}
					if (ilow < ihigh)
					{
						stRK->roadMsgs[ihigh] = stRK->roadMsgs[ilow];
						ihigh--;
					}
				}
				stRK->roadMsgs[ilow] = tempstRK;
				top++;
				st[top].low = low;
				st[top].high = ilow - 1;
				top++;
				st[top].low = ilow + 1;
				st[top].high = high;
			}
		}

		break;
	case TYPE_BRUNCH:
		while (top > -1)
		{      
			low = st[top].low;
			high = st[top].high;
			top--;
			ilow = low;
			ihigh = high;
			if (low < high)
			{      
				tempstRK = stRK->roadMsgs[low];
				while (ilow!=ihigh)
				{      
					while (ilow < ihigh && stRK->roadMsgs[ihigh].brunch > tempstRK.brunch)
					{
						ihigh--;
					}
					
					if (ilow < ihigh)
					{
						stRK->roadMsgs[ilow] = stRK->roadMsgs[ihigh];
						ilow++;
					}
					while (ilow < ihigh && stRK->roadMsgs[ilow].brunch <  tempstRK.brunch)
					{
						ilow++;
					}
					if (ilow < ihigh)
					{
						stRK->roadMsgs[ihigh] = stRK->roadMsgs[ilow];
						ihigh--;
					}
				}
				stRK->roadMsgs[ilow] = tempstRK;
				top++;
				st[top].low = low;
				st[top].high = ilow - 1;
				top++;
				st[top].low = ilow + 1;
				st[top].high = high;
			}
		}
		
		break;
	case TYPE_CLASSNO:
		while (top > -1)
		{      
			low = st[top].low;
			high = st[top].high;
			top--;
			ilow = low;
			ihigh = high;
			if (low < high)
			{      
				tempstRK = stRK->roadMsgs[low];
				while (ilow != ihigh)
				{      
					while (ilow < ihigh && stRK->roadMsgs[ihigh].dispclass > tempstRK.dispclass)
					{
						ihigh--;
					}
					
					if (ilow < ihigh)
					{
						stRK->roadMsgs[ilow] = stRK->roadMsgs[ihigh];
						ilow++;
					}
					while (ilow < ihigh && stRK->roadMsgs[ilow].dispclass <  tempstRK.dispclass)
					{
						ilow++;
					}
					if (ilow < ihigh)
					{
						stRK->roadMsgs[ihigh] = stRK->roadMsgs[ilow];
						ihigh--;
					}
				}
				stRK->roadMsgs[ilow] = tempstRK;
				top++;
				st[top].low = low;
				st[top].high = ilow - 1;
				top++;
				st[top].low = ilow + 1;
				st[top].high = high;
			}
		}
		
		break;
	case TYPE_NAME:
		while (top > -1)
		{      
			low = st[top].low;
			high = st[top].high;
			top--;
			ilow = low;
			ihigh = high;
			if (low < high)
			{      
				tempstRK = stRK->roadMsgs[low];
				while (ilow != ihigh)
				{      
					while (ilow < ihigh && strcmp(stRK->roadMsgs[ihigh].roadname + 4, tempstRK.roadname + 4) > 0)
					{
						ihigh--;
					}
					
					if (ilow < ihigh)
					{
						stRK->roadMsgs[ilow] = stRK->roadMsgs[ihigh];
						ilow++;
					}
					while (ilow < ihigh && strcmp(stRK->roadMsgs[ilow].roadname + 4, tempstRK.roadname + 4) < 0)
					{
						ilow++;
					}
					if (ilow < ihigh)
					{
						stRK->roadMsgs[ihigh] = stRK->roadMsgs[ilow];
						ihigh--;
					}
				}
				stRK->roadMsgs[ilow] = tempstRK;
				top++;
				st[top].low = low;
				st[top].high = ilow - 1;
				top++;
				st[top].low = ilow + 1;
				st[top].high = high;
			}
		}
				
		break;
	default:
		printf("The tag you enter is wrong!");
		break;
	}

} 

/**********************************************************************************
* Function Name:	QuickSort													  *	
* Description:		øÏÀŸ≈≈–Ú∑®                                                    * 
* Date:				2013-07-30													  *
* Parameter:		RoadArray_t*												  *												
* Model	:			≈≈–Úƒ£øÈ													  *
* Author:			≥Ÿ◊”ËØ    ∂≠≤©	      										  *
**********************************************************************************/
RoadArray_t* QuickSort (RoadArray_t* stRK, int itag)
{
	switch (itag)
	{
		case TYPE_ID:
			QSort(stRK, itag);
			break;
		case TYPE_BRUNCH:
			QSort(stRK, itag);
			break;
		case TYPE_CLASSNO:
			QSort(stRK, itag);
			  break;
		case TYPE_NAME:
			QSort(stRK, itag);
			break;
		default:
			printf("The tag you enter is wrong!");
			break;
	
	}
#if _DEBUG
	stRK->roadMsgs[0];
#endif
	return stRK;

}
/**********************************************************************************
* Function Name:	BubbleSort													  *	
* Description:      √∞≈›≈≈–Ú∑®                                                    * 
* Date:				2013-07-30													  *
* Parameter:		RoadArray_t*												  *												
* Model	:			≈≈–Úƒ£øÈ													  *
* Author:			∂≠≤© ≥Ÿ◊”ËØ	                                                  *
**********************************************************************************/
RoadArray_t* BubbleSort (RoadArray_t* stRK, int itag)
{
	int i = 1, j, n = stRK->length;//≥ı ºªØ—≠ª∑±‰¡ø
	int b = 1;
	RoadMsg_t stTemp;
	switch (itag)
	{
	case TYPE_ID:
		while (b)
		{ 
			b=0;
			for (j = n-i;  j >= i;  j--)
			{
				if (stRK->roadMsgs[j].linkID < stRK->roadMsgs[j-1].linkID)
				{
					b = 1;
					stTemp = stRK->roadMsgs[j];
					stRK->roadMsgs[j] = stRK->roadMsgs[j-1];
					stRK->roadMsgs[j-1] = stTemp;       
				}
			}
			for (j = i - 1; j < n - i; j++ )
			{
				if (stRK->roadMsgs[j].linkID > stRK->roadMsgs[j+1].linkID)
				{
					b = 1;
					stTemp = stRK->roadMsgs[j];
					stRK->roadMsgs[j] = stRK->roadMsgs[j+1];
					stRK->roadMsgs[j+1] = stTemp;      
				}
			}  
			i++; 
		}
		break;
	case TYPE_BRUNCH:
		while (b)
		{ 
			b=0;
			for (j = n-i;  j >= i;  j--)
			{
				if (stRK->roadMsgs[j].brunch < stRK->roadMsgs[j-1].brunch)
				{
					b = 1;
					stTemp = stRK->roadMsgs[j];
					stRK->roadMsgs[j] = stRK->roadMsgs[j-1];
					stRK->roadMsgs[j-1] = stTemp;       
				}
			}
			for (j = i - 1; j < n - i; j++ )
			{
				if (stRK->roadMsgs[j].brunch > stRK->roadMsgs[j+1].brunch)
				{
					b = 1;
					stTemp = stRK->roadMsgs[j];
					stRK->roadMsgs[j] = stRK->roadMsgs[j+1];
					stRK->roadMsgs[j+1] = stTemp;      
				}
			}  
			i++; 
		}
		break;
	case TYPE_CLASSNO:
		while (b)
		{ 
			b=0;
			for (j = n-i;  j >= i;  j--)
			{
				if (stRK->roadMsgs[j].dispclass < stRK->roadMsgs[j-1].dispclass)
				{
					b = 1;
					stTemp = stRK->roadMsgs[j];
					stRK->roadMsgs[j] = stRK->roadMsgs[j-1];
					stRK->roadMsgs[j-1] = stTemp;       
				}
			}
			for (j = i - 1; j < n - i; j++ )
			{
				if (stRK->roadMsgs[j].dispclass > stRK->roadMsgs[j+1].dispclass)
				{
					b = 1;
					stTemp = stRK->roadMsgs[j];
					stRK->roadMsgs[j] = stRK->roadMsgs[j+1];
					stRK->roadMsgs[j+1] = stTemp;      
				}
			}  
			i++; 
		}
		break;
	case TYPE_NAME:
		while (b)
		{ 
			b = 0;
			for (j = n-i;  j >= i;  j--)
			{
				if (strcmp(stRK->roadMsgs[j].roadname, stRK->roadMsgs[j-1].roadname) < 0 )
				{
					b = 1;
					stTemp = stRK->roadMsgs[j];
					stRK->roadMsgs[j] = stRK->roadMsgs[j-1];
					stRK->roadMsgs[j-1] = stTemp;       
				}
			}
			for (j = i - 1; j < n - i; j++ )
			{
				if (strcmp(stRK->roadMsgs[j].roadname, stRK->roadMsgs[j+1].roadname) > 0 )
				{
					b = 1;
					stTemp = stRK->roadMsgs[j];
					stRK->roadMsgs[j] = stRK->roadMsgs[j+1];
					stRK->roadMsgs[j+1] = stTemp;      
				}
			}  
			i++; 
		}
		break;
	default:
		printf("The tag you enter is wrong!");
		break;
		
	}
#if _DEBUG
	stRK->roadMsgs[0];
#endif
	return stRK;
}//BubbleSort End

/**********************************************************************************
* Function Name:	InsertionSort												  *	
* Description:		≤Â»Î≈≈–Ú∑®                                                    * 
* Date:				2013-07-30													  *
* Parameter:		RoadArray_t*												  *												
* Model	:			≈≈–Úƒ£øÈ													  *
* Author:		    ≥Ÿ◊”ËØ	∂≠≤©												  *
**********************************************************************************/

RoadArray_t* InsertionSort(RoadArray_t* stRK,int itag) 
{
	int i,j;
	RoadMsg_t stTemp;
	switch (itag)
	{
	case TYPE_ID:
		for (i = 1; i < stRK->length; ++i ) 
		{
			if (stRK->roadMsgs[i].linkID < stRK->roadMsgs[i-1].linkID) 
			{
				stTemp = stRK->roadMsgs[i];              
				for ( j = i - 1; (stTemp.linkID < stRK->roadMsgs[j].linkID) && (j >= 0); --j )
				{
					stRK->roadMsgs[j + 1] = stRK->roadMsgs[j];        
				}
				stRK->roadMsgs[j + 1] = stTemp;   				
			}
		}
		break;
	case TYPE_BRUNCH:
		for (i = 1; i < stRK->length; ++i )
		{
			if (stRK->roadMsgs[i].brunch < stRK->roadMsgs[i-1].brunch) 
			{
				stTemp = stRK->roadMsgs[i];              
				for ( j = i - 1; (stTemp.brunch < stRK->roadMsgs[j].brunch) && (j >= 0); --j )
				{
					stRK->roadMsgs[j + 1] = stRK->roadMsgs[j];        
				}
				stRK->roadMsgs[j + 1] = stTemp;   				
			}
		}
		break;
	case TYPE_CLASSNO:
		for (i = 1; i < stRK->length; ++i ) 
		{
			if (stRK->roadMsgs[i].dispclass < stRK->roadMsgs[i-1].dispclass) 
			{
				stTemp = stRK->roadMsgs[i];              
				for (j = i - 1; (stTemp.dispclass < stRK->roadMsgs[j].dispclass) && (j >= 0); -- j )
				{
					stRK->roadMsgs[j + 1] = stRK->roadMsgs[j];        
				}
				stRK->roadMsgs[j + 1] = stTemp;   				
			}
		}
		break;
	case TYPE_NAME:
		for (i = 1; i < stRK->length; ++i )
		{
			if (strcmp(stRK->roadMsgs[i].roadname, stRK->roadMsgs[i-1].roadname) < 0) 
			{
				stTemp = stRK->roadMsgs[i];              
				for ( j=i - 1; (strcmp(stTemp.roadname, stRK->roadMsgs[j].roadname) < 0) && (j >= 0); --j )
				{
					stRK->roadMsgs[j + 1] = stRK->roadMsgs[j];        
				}
				stRK->roadMsgs[j + 1] = stTemp;   				
			}
		}
		break;
	default:
		printf("The tag you enter is wrong!");
		break;
		
	}
#if _DEBUG
	stRK->roadMsgs[0];
#endif
	return stRK;
} // InsertSort End

/**********************************************************************************
* Function Name:	HeapSort											    	  *	
* Description:		∂—≈≈–Ú                                                        * 
* Date:				2013-07-30													  *
* Parameter:		RoadArray_t*												  *												
* Model	:			≈≈–Úƒ£øÈ													  *
* Author:			∂≠≤©  ≥Ÿ◊”ËØ											      *
**********************************************************************************/
RoadArray_t* HeapSort(RoadArray_t* stRK,int itag)
{
	int i,j,m,s;
	RoadMsg_t stTemp;
	switch (itag)
	{
	case TYPE_ID:
		for (i = (stRK->length - 1)/2; i >= 0; --i) 
		{  
			s = i;
			m = stRK->length ;
			stTemp = stRK->roadMsgs[s];                         
			for (j = 2 * s ; j < m ; j *= 2 ) 
			{ 			
				if (j < m -1 && stRK->roadMsgs[j].linkID < stRK->roadMsgs[j + 1].linkID)  
				{
					++j;     
				}
				if (stTemp.linkID >= stRK->roadMsgs[j].linkID ) 
				{
					break; 
				}
				stRK->roadMsgs[s] = stRK->roadMsgs[j]; 
				s = j;
			}	
			stRK->roadMsgs[s] = stTemp;       
		} 
		for (i = stRK->length - 1; i > 0; --i)
		{
			stTemp = stRK->roadMsgs[0];
			stRK->roadMsgs[0] = stRK->roadMsgs[i];  
			stRK->roadMsgs[i] = stTemp;

			s = 0;
			m = i - 1;
			
			stTemp = stRK->roadMsgs[s];                         
			for (j = 2 * s; j <= m ; j *= 2 ) 
			{ 			
				if (j < m - 1 && stRK->roadMsgs[j].linkID < stRK->roadMsgs[j+1].linkID)  
				{
					++j;     
				}
				if (stTemp.linkID >= stRK->roadMsgs[j].linkID ) 
				{
					break; 
				}
				stRK->roadMsgs[s] = stRK->roadMsgs[j]; 
				s = j;
			}	
			stRK->roadMsgs[s] = stTemp;       
		}
			stTemp = stRK->roadMsgs[0];
			stRK->roadMsgs[0] = stRK->roadMsgs[1];  
			stRK->roadMsgs[1] = stTemp;
		
			break;
	case TYPE_BRUNCH:
		for (i = (stRK->length - 1)/2; i >= 0; --i)  
		{  
			s = i;
			m = stRK->length ;
			stTemp = stRK->roadMsgs[s];                         
			for ( j = 2 * s ; j < m ; j *= 2 ) 
			{ 			
				if (j < m -1 && stRK->roadMsgs[j].brunch < stRK->roadMsgs[j + 1].brunch)  
				{
					++j;     
				}
				if (stTemp.brunch >= stRK->roadMsgs[j].brunch ) 
				{
					break; 
				}
				stRK->roadMsgs[s] = stRK->roadMsgs[j]; 
				s = j;
			}	
			stRK->roadMsgs[s] = stTemp;       
		} 
		for (i = stRK->length - 1; i > 0; --i)
		{
			stTemp = stRK->roadMsgs[0];
			stRK->roadMsgs[0] = stRK->roadMsgs[i];  
			stRK->roadMsgs[i] = stTemp;

			s = 0;
			m = i - 1;
			
			stTemp = stRK->roadMsgs[s];                         
			for (j = 2 * s; j <= m ; j *= 2 ) 
			{ 			
				if (j < m - 1 && stRK->roadMsgs[j].brunch < stRK->roadMsgs[j + 1].brunch)  
				{
					++j;     
				}
				if ( stTemp.brunch >= stRK->roadMsgs[j].brunch ) 
				{
					break; 
				}
				stRK->roadMsgs[s] = stRK->roadMsgs[j]; 
				s = j;
			}	
			stRK->roadMsgs[s] = stTemp;       
		}
			stTemp = stRK->roadMsgs[0];
			stRK->roadMsgs[0] = stRK->roadMsgs[1];  
			stRK->roadMsgs[1] = stTemp;
			break;
	case TYPE_CLASSNO:
		for (i = (stRK->length - 1)/2; i >= 0; --i)  
		{  
			s = i;
			m = stRK->length ;
			stTemp = stRK->roadMsgs[s];                         
			for (j = 2 * s ; j < m ; j *= 2 ) 
			{ 			
				if (j < m -1 && stRK->roadMsgs[j].dispclass < stRK->roadMsgs[j + 1].dispclass)  
				{
					++j;     
				}
				if (stTemp.dispclass >= stRK->roadMsgs[j].dispclass ) 
				{
					break; 
				}
				stRK->roadMsgs[s] = stRK->roadMsgs[j]; 
				s = j;
			}	
			stRK->roadMsgs[s] = stTemp;       
		} 
		for (i = stRK->length - 1; i > 0; --i)
		{
			stTemp = stRK->roadMsgs[0];
			stRK->roadMsgs[0] = stRK->roadMsgs[i];  
			stRK->roadMsgs[i] = stTemp;

			s = 0;
			m = i - 1;
			
			stTemp = stRK->roadMsgs[s];                         
			for (j = 2 * s; j<= m ; j*=2 ) 
			{ 		
				if (j < m - 1 && stRK->roadMsgs[j].dispclass < stRK->roadMsgs[j + 1].dispclass)  
				{
					++j;     
				}
				if (stTemp.dispclass >= stRK->roadMsgs[j].dispclass ) 
				{
					break; 
				}
				stRK->roadMsgs[s] = stRK->roadMsgs[j]; 
				s = j;
			}	
			stRK->roadMsgs[s] = stTemp;       
		}
			stTemp = stRK->roadMsgs[0];
			stRK->roadMsgs[0] = stRK->roadMsgs[1];  
			stRK->roadMsgs[1] = stTemp;
				break;
	case TYPE_NAME:
		for (i = (stRK->length - 1)/2; i >= 0; --i)  
		{  
			s = i;
			m = stRK->length ;
			stTemp = stRK->roadMsgs[s];                         
			for ( j = 2 * s ; j < m ; j *=2 ) 
			{ 			
				if ( j < m -1 && strcmp(stRK->roadMsgs[j].roadname, stRK->roadMsgs[j + 1].roadname) < 0)  
				{
					++j;     
				}
				if ( strcmp(stTemp.roadname, stRK->roadMsgs[j].roadname) >= 0 ) 
				{
					break; 
				}
				stRK->roadMsgs[s] = stRK->roadMsgs[j]; 
				s = j;
			}	
			stRK->roadMsgs[s] = stTemp;       
		} 
		for (i = stRK->length - 1; i > 0; --i) 
		{
			stTemp = stRK->roadMsgs[0];
			stRK->roadMsgs[0] = stRK->roadMsgs[i];  
			stRK->roadMsgs[i] = stTemp;

			s = 0;
			m = i - 1;
			
			stTemp = stRK->roadMsgs[s];                         
			for (j = 2 * s; j <= m ; j *=2 ) 
			{ 			
				if (j < m - 1 && strcmp(stRK->roadMsgs[j].roadname, stRK->roadMsgs[j + 1].roadname) < 0)  
				{
					++j;     
				}
				if (strcmp(stTemp.roadname, stRK->roadMsgs[j].roadname) >= 0  ) 
				{
					break; 
				}
				stRK->roadMsgs[s] = stRK->roadMsgs[j]; 
				s = j;
			}	
			stRK->roadMsgs[s] = stTemp;       
		}
			stTemp = stRK->roadMsgs[0];
			stRK->roadMsgs[0] = stRK->roadMsgs[1];  
			stRK->roadMsgs[1] = stTemp;
				break;
	default:
		printf("The tag you enter is wrong!");
		break;
		
	}
#if _DEBUG
	stRK->roadMsgs[0];
#endif
	return stRK;
}
 

void TimeOfQuickSort(RoadArray_t* stRK, int itag)
{
	double dStart, dEnd, dTime;
	dStart = clock();
	QuickSort(stRK, itag);
	dEnd = clock();
	dTime = (dEnd - dStart) / CLOCKS_PER_SEC;
	
	printf("---------------------------------------------------\n");
	printf("Time:%lf\n",dTime);
	printf("---------------------------------------------------\n");
}

/**********************************************************************************
* Function Name:	TimeOfBubbleSort										      *	
* Description:		º∆À„√∞≈›≈≈–Ú∑®µƒ ±º‰                                          * 
* Date:				2013-07-31													  *
* Parameter:		void               											  *												
* Model	:			≈≈–Úƒ£øÈ													  *
* Author:			∂≠≤©  ≥Ÿ◊”ËØ												  *
**********************************************************************************/
void TimeOfBubbleSort(RoadArray_t* stRK, int itag)
{
	double dStart, dEnd, dTime;//Initialization the variables for count time
	dStart = clock();
	BubbleSort(stRK, itag);
	dEnd = clock();
	dTime = (dEnd - dStart) / CLOCKS_PER_SEC;
	
	printf("---------------------------------------------------\n");
	printf("Time:%lf\n",dTime);
	printf("---------------------------------------------------\n");
}//TimeOfBubbleSort End

/**********************************************************************************
* Function Name:	TimeOfInsertionSort										      *	
* Description:		º∆À„≤Â»Î≈≈–Ú∑®µƒ ±º‰                                          * 
* Date:				2013-07-31													  *
* Parameter:		void               											  *												*
* Model	:			≈≈–Úƒ£øÈ													  *
* Author:			∂≠≤©  ≥Ÿ◊”ËØ												  *
**********************************************************************************/
void TimeOfInsertionSort(RoadArray_t* stRK, int itag)
{
	double dStart, dEnd, dTime;
	dStart = clock();
	InsertionSort(stRK, itag);
	dEnd = clock();
	dTime = (dEnd - dStart) / CLOCKS_PER_SEC;
	
	printf("---------------------------------------------------\n");
	printf("Time:%lf\n",dTime);
	printf("---------------------------------------------------\n");
}


void TimeOfHeapSort(RoadArray_t* stRK, int itag)
{
	double dStart,dEnd,dTime;
	dStart = clock();
	HeapSort(stRK, itag);
	dEnd = clock();
	dTime = (dEnd - dStart) / CLOCKS_PER_SEC;

	printf("---------------------------------------------------\n");
	printf("Time:%lf\n",dTime);
	printf("---------------------------------------------------\n");
}


void TimeOfTreeSort(TreeNode_Point* root, RoadArray_t* date)
{
	double dStart, dEnd, dTime; 
	dStart = clock();
	readToTree(root, date);
	dEnd = clock();
	dTime = (dEnd - dStart) / CLOCKS_PER_SEC;
	
	printf("---------------------------------------------------\n");
	printf("Time:%lf\n",dTime);
	printf("---------------------------------------------------\n");
}

/**********************************************************************************
* Function Name:	TimeComp            									      *	
* Description:		±»Ωœ ±º‰µƒ≤Ó“Ï                                                * 
* Date:				2013-07-31													  *
* Parameter:		void               											  *												*
* Model	:			≈≈–Úƒ£øÈ													  *
* Author:			∂≠≤©  ≥Ÿ◊”ËØ														  *
**********************************************************************************/
void TimeComp(RoadArray_t* stRK, char *path, int itag)
{
	printf("QuickSort:\n");
	TimeOfQuickSort(stRK, itag);

	free(stRK->roadMsgs);
	readToArray(path, stRK);
	printf("BubbleSort:\n");
	TimeOfBubbleSort(stRK, itag);

	free(stRK->roadMsgs);
	readToArray(path, stRK);
	printf("InsertionSort:\n");
	TimeOfInsertionSort(stRK, itag);

	free(stRK->roadMsgs);
	readToArray(path, stRK);
	printf("HeapSort:\n");
	TimeOfHeapSort(stRK, itag);
}

