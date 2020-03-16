#include <stdio.h>
#include <dirent.h>			
#include <locale.h>
#include <stdlib.h>
#include<math.h>



		struct node { 
		char docName[100] ;
		char textName[100] ;
		char termName[100] ;
		int frequency ;
		struct node *term_next ;
		};
		typedef struct node termNode ;
		typedef termNode *nodePtr ;
	
			struct node *head=NULL;
			struct node *end=NULL;	
		
		struct firstOrder {
		char term1[100] ;
		char term2[100] ;
		struct firstOrder *nextOrder ;
			
		};
		
		struct Text {
		char text[100] ;
		char term[100] ;
		int frequency ;	
		struct Text *nextPtr ;
		};	
		static char str12[100]  ;
		char *returnStr(char doc[100] , char econ[100] ) {
		strcpy(str12, "") ;
		strcat(str12,doc) ;
		strcat(str12,econ) ;
		return str12 ;	
		}

						void swap2(struct firstOrder *a, struct firstOrder *b) 
					{ 
					char term2[100] = "" ;
					strcpy(term2, a->term2) ;
					strcpy(a->term2 , b->term2) ;
					strcpy(b->term2 , term2) ;		    
					} 			
				
			
			
			
				void swap(struct firstOrder *a, struct firstOrder *b) 
			{ 
			char term1[100] = "" ;
			char term2[100] = "" ;
			strcpy(term1 , a->term1) ;
			strcpy(term2, a->term2) ;
			strcpy(a->term1 , b->term1) ;
			strcpy(a->term2 , b->term2) ;
			strcpy(b->term1  , term1) ;
			strcpy(b->term2 , term2) ;
			
			    
			    
			} 		
					void bubbleSort(struct firstOrder *start) 
			{ 
			    int swapped, i; 
			    struct firstOrder *ptr1; 
			    struct firstOrder *lptr = NULL; 
			  
			    /* Checking for empty list */
			    if (start == NULL) 
			        return; 
			  
			    do
			    { 
			        swapped = 0; 
			        ptr1 = start; 
			  
			        while (ptr1->nextOrder != NULL) 
			        { 
			            if (strcmp(ptr1->term1 , ptr1->nextOrder->term1) > 0) //condition for sorting alphabetically
			            {  
			                swap(ptr1, ptr1->nextOrder); 
			                swapped = 1; 
			            } 
			            if (strcmp(ptr1->term1 , ptr1->nextOrder->term1) == 0 ) { 
			            	if(strcmp(ptr1->term2 , ptr1->nextOrder->term2) > 0) {
			            		swap2(ptr1, ptr1->nextOrder); 
			                		swapped = 1; 
							}	
					
						}		
						ptr1 = ptr1->nextOrder ; 
			        } 
			        lptr = ptr1; 
			    } 
			    while (swapped); 
			} 
			  
			
			void swap4freq(struct node *a, struct node *b) 
			{ 
			char docName1[100] = "" ;
			char docName2[100] = "" ;
			char termName1[100] = "" ;
			char termName2[100] = "" ;
			char textName1[100] = "" ;
			char textName2[100] = "" ;
			int temp ;
			strcpy(docName1 , a->docName) ;
			strcpy(docName2, b->docName) ;
			strcpy(a->docName , docName2) ;
			strcpy(b->docName , docName1) ;
			strcpy(termName1 , a->termName) ;
			strcpy(termName2, b->termName) ;
			strcpy(a->termName , termName2) ;
			strcpy(b->termName , termName1) ;
			strcpy(textName1 , a->docName) ;
			strcpy(textName2, b->docName) ;
			strcpy(a->textName , textName2) ;
			strcpy(b->textName , textName1) ;
			temp = a->frequency ;
			a->frequency = b->frequency ;
			b->frequency = temp ;
			
			    
			    
			} 		
			
			void sort4freq(struct node *start) 
			{ 
			    int swapped, i; 
			    struct node *ptr1; 
			    struct node *lptr = NULL; 
			    if (start == NULL) 
			        return; 
			  
			    do
			    { 
			        swapped = 0; 
			        ptr1 = start; 
			  
			        while (ptr1->term_next != NULL) 
			        { 
			            if (ptr1->frequency < ptr1->term_next->frequency && strcmp(ptr1->docName, ptr1->term_next->docName) == 0) 
			            {  
			                swap4freq(ptr1, ptr1->term_next); 
			                swapped = 1; 
			            } 	
						ptr1 = ptr1->term_next ; 
			        } 
			        lptr = ptr1; 
			    } 
			    while (swapped); 
			} 
			
						
			void firstOrd(struct firstOrder **head , char term1[100] ,char term2[100]){
		struct firstOrder *newNode = (struct firstOrder*)malloc(sizeof(struct firstOrder)) ;
		strcpy(newNode->term1 , term1) ;
		strcpy(newNode->term2 , term2) ;
		char tempPtr[100] ;
		struct firstOrder *tempForDup = (struct firstOrder*)malloc(sizeof(struct firstOrder)) ;
		strcpy(tempForDup->term1, term2) ;
		strcpy(tempForDup->term2 ,term1) ;
		newNode->nextOrder = NULL ;
		struct firstOrder *temp = *head ;	
			if(*head == NULL) {
				*head = newNode ;	
			}	
			else {
				while(temp->nextOrder != NULL) {
				if(strcmp(tempForDup->term1 , temp->term1) == 0 && strcmp(tempForDup->term2 , temp->term2) == 0 ) { // if there is some duplication with switching terms , eliminate it from firstOrder
				return ;	
				}	
				temp = temp->nextOrder ;
				}	
				temp->nextOrder = newNode ;
			}
		}
			
		
		
		void secondOrd(struct firstOrder **head , char term1[100] ,char term2[100]){
		struct firstOrder *newNode = (struct firstOrder*)malloc(sizeof(struct firstOrder)) ;
		strcpy(newNode->term1 , term1) ;
		strcpy(newNode->term2 , term2) ;
		newNode->nextOrder = NULL ;
		struct firstOrder *temp = *head ;	
			if(*head == NULL) {
				*head = newNode ;	
			}	
			else {
				while(temp->nextOrder != NULL) {
				temp = temp->nextOrder ;
				}	
				temp->nextOrder = newNode ;
			}
		}
		void thirdOrd(struct firstOrder **head , char term1[100] ,char term2[100]){
		struct firstOrder *newNode = (struct firstOrder*)malloc(sizeof(struct firstOrder)) ;
		strcpy(newNode->term1 , term1) ;
		strcpy(newNode->term2 , term2) ;
		struct firstOrder *tempForDup = (struct firstOrder*)malloc(sizeof(struct firstOrder)) ;
		strcpy(tempForDup->term1, term2) ;
		strcpy(tempForDup->term2 ,term1) ;
		newNode->nextOrder = NULL ;
		struct firstOrder *temp = *head ;	
			if(*head == NULL) {
				*head = newNode ;	
			}	
			else {
				while(temp->nextOrder != NULL) {
				if(strcmp(tempForDup->term1 , temp->term1) == 0 && strcmp(tempForDup->term2 , temp->term2) == 0 ) { // if there is some duplication with switching terms , eliminate it from firstOrder
				return ;	
				}	
				temp = temp->nextOrder ;
				}	
				temp->nextOrder = newNode ;
			}
		}
		
				void wordLists(struct node **head , char docName[100] ,char termName[100] , int freq , char textName[100]){
			struct node *newNode = (struct node*)malloc(sizeof(struct node)) ;
			strcpy(newNode->docName , docName) ;
			strcpy(newNode->termName , termName) ;
			strcpy(newNode->textName , textName) ;
			newNode->frequency = freq ;
			newNode->term_next = NULL ;
			struct node *temp = *head ;	
				if(*head == NULL) {
					*head = newNode ;	
				}	
				else {
					while(temp->term_next != NULL) {
					temp = temp->term_next ;
					}	
					temp->term_next = newNode ;
				}
			}
			
		
		
		
		
		
		
		void textSets (struct Text **head , char data[100] , char term[100] ) { // this function gets all the worlds inside of all folders and assign them to the  head pointer  we can call it MLL basically
		struct Text *newNode = (struct Text*)malloc(sizeof(struct Text)) ;
		strcpy(newNode->text , data) ;
		strcpy(newNode->term , term) ;
		newNode->nextPtr = NULL ;
		struct Text *temp = *head ;	
			if(*head == NULL) {
				*head = newNode ;	
			}	
			else {
				while(temp->nextPtr != NULL) {
				temp = temp->nextPtr ;
				if(strcmp(temp->term,newNode->term)== 0 && strcmp(temp->text , newNode->term) == 0){ // condition for removing duplications
				return ;
				}
				
				
				}	
				temp->nextPtr = newNode ;
			}
		
		} 
		
	
	
	
	
	
		void addNode(struct node **head , char docNam[100] , char textNam[100] , char termNam[100] , int a) { // this function  is for counting frequency's of each word it will assign it to the recording pointer with duplications
		struct node *newNode = (struct node*)malloc(sizeof(struct node)) ;
		strcpy(newNode->docName , docNam) ;
		strcpy(newNode->textName , textNam) ;
		strcpy(newNode->termName , termNam) ;
		newNode->frequency = a ;
		newNode->term_next = NULL ;
		struct node *temp = *head ;
			if(*head == NULL) {
				*head = newNode ;	
			}	
			
			else {
				while(temp->term_next != NULL) {
				temp = temp->term_next ;
				}	
				temp->term_next = newNode ;
			}
		
		}
		
		

		
		int main()
		{
			setlocale(LC_ALL, "Turkish");
		    DIR *folder;
		    DIR *subfolder ;
		    struct node *ptr = NULL;
		    struct Text *ptr4texts = NULL ;
		    struct node *headPtr ;
			struct dirent *entry;
			struct firstOrder *ptr1stOrd = NULL ;
		    struct firstOrder *ptr2ndOrd = NULL ;
		    struct firstOrder *ptr3rdOrd = NULL ;
			struct dirent *subreader ;
			termNode *nodePtr = NULL ;
			int files = 0 , i = 0;
			struct term *root = NULL;
		    folder = opendir("dataset");
			if(folder == NULL)
		    {
		        perror("Unable to read directory");
		        return(1);
		    }
		    while( (entry=readdir(folder))!= NULL ) // function for reading the directory folder
		    {
				files++;
		        if(strlen(entry->d_name) > 2) {				
				char str[100]  = "dataset";
				char str2[100]  ;
				char line[1000] ;
				char line4order1st[1000] ;
				char backslash[] = "\\";
				strcat(str , backslash); //dataset\
				//strcat(str2 , backslash);
				strcat(str , entry->d_name); //dataset\econ
				//strcat(str2 , entry->d_name);
			    strcpy(str2 , str) ; //dataset\econ
				subfolder = opendir(str);	
				while ((subreader = readdir(subfolder))!= NULL) {
				if(strlen(subreader->d_name) > 2){	
				strcat(str , backslash); //dateset\econ\bla
				strcat(str , subreader->d_name); //dataset\econ\1.txt
				FILE *fp = fopen(str , "r");
				
				char *p ;
				while( fgets(line ,sizeof line , fp ) != NULL ) {
						for(p = strtok(line," "); p != NULL; p = strtok(NULL, " ")) { // tokenize the current line
						int a = 1 ;
						textSets(&ptr4texts , returnStr(entry->d_name , subreader->d_name) , p ) ;
						addNode(&ptr , entry->d_name , subreader->d_name , p  , a ); 	
					}
				}
						
				strcpy(str , str2) ;
				}
		 
				}	
				closedir(subfolder) ;		
				}
			}		
			closedir(folder);
			
				struct node *a = ptr ;
				int result = 1 ;
				struct Text *c = NULL;
				struct node *b = NULL ; 
				struct Text *kung = ptr4texts ;
				struct Text *f = NULL ; 
				struct Text *fu = NULL ;
				struct Text *du = ptr4texts ;
				struct Text *g = ptr4texts ;
				struct Text *gYanCar = ptr4texts ;
				
				struct Text *h = NULL ;
				struct Text *hYanCar = NULL ;
				struct Text *gTemp = ptr4texts ; 
				struct Text *t = NULL ;
				char ned[] = "\n" ;
				struct firstOrder *e = NULL ;
				struct Text *w = NULL ;
				struct Text *u = NULL ;
				int ds ;
				struct Text *ptr1 = ptr4texts ;
				struct Text *ptr2 = ptr4texts ;
				struct Text *ptr3 = ptr4texts ;
				struct Text *nEqualizer = ptr4texts ;
				struct Text *ptr4 = ptr4texts ;
				struct Text *ptr5 = ptr4texts ;
				struct Text *ptr6 = NULL ;			
				printf("\n1st order term co-occurance: \n") ;
				while(kung != NULL) { //regarding pointer holds MLL
				for( fu = kung->nextPtr  ; fu!= NULL ; fu = fu->nextPtr) {
				
				if(strcmp(kung->text , fu->text) == 0 &&
				strcmp(kung->term , fu->term) != 0 && 
				strcmp(kung->term , ned) != 0 &&
				strcmp(fu->term , ned) != 0 				
				) {
				firstOrd(&ptr1stOrd , kung->term , fu->term) ;	
				}	
				
				}
				kung = kung->nextPtr ;
				}
				
			bubbleSort(ptr1stOrd) ; //sorts the firstOrder alphabetically
				
				for(ptr1stOrd ; ptr1stOrd != NULL ; ptr1stOrd = ptr1stOrd->nextOrder) {		
					printf("(%s,%s) " , ptr1stOrd->term1 ,ptr1stOrd->term2) ;				
				}
				
				
				printf("\n2nd order term co-occurance: \n") ;
				while(du != NULL) {
					for(f = du->nextPtr ; f!= NULL ; f = f->nextPtr) {
						if(strcmp(du->text , f->text) != 0 && 
						strcmp(du->term , f->term) == 0  ) {
							while(g != NULL) {
							u = f ;	
							  if(strcmp(g->text , du->text) == 0 && strcmp(g->term , du->term) != 0 ) {
							  	for(h = g->nextPtr ; h != NULL ; h = h->nextPtr ) {
							  		if(strcmp(h->text , f->text) == 0 && strcmp(h->term , f->term) != 0 && strcmp(h->term , g->term) != 0)  {
							  		secondOrd(&ptr2ndOrd , g->term , h->term ) ;	
									}
							    }	
								}
							g = g->nextPtr ;
							}							
						}
					}	
				for( u ; u != NULL ; u = u->nextPtr) {
					for(w = u->nextPtr ; w != NULL ; w = w->nextPtr) {
						if(strcmp(w->term , u->term) == 0) {
						while( gYanCar!= NULL) {
								
							  if(strcmp(gYanCar->text , du->text) == 0 && strcmp(gYanCar->term , u->term) != 0 ) {
							  	for(hYanCar = gYanCar->nextPtr ; hYanCar != NULL ; hYanCar = hYanCar->nextPtr ) {
							  		if(strcmp(hYanCar->text , w->text) == 0 && strcmp(hYanCar->term , w->term) != 0 && strcmp(hYanCar->term , gYanCar->term) != 0)  {
								   secondOrd(&ptr2ndOrd , gYanCar->term , hYanCar->term ) ;	
									}
							    }	
								}
							gYanCar = gYanCar->nextPtr ;
							}			
					
						}

					}	
	
				}		
				if(result) {
				du = du->nextPtr ;
				g = gTemp ;				
				}				
				}
				bubbleSort(ptr2ndOrd) ;
				for(ptr2ndOrd ; ptr2ndOrd->nextOrder != NULL ; ptr2ndOrd = ptr2ndOrd->nextOrder) {
					if(strcmp(ptr2ndOrd->term2 , ptr2ndOrd->nextOrder->term2) != 0) {
					printf("(%s,%s) " , ptr2ndOrd->term1 ,ptr2ndOrd->term2) ;
					}	
								
				}
				printf("\n3rd order term co-occurance: \n") ;
				while(ptr1!= NULL) {
					for(ptr6 = ptr1->nextPtr ; ptr6 != NULL ; ptr6 = ptr6->nextPtr) {
						if(strcmp(ptr1->text , ptr6->text) != 0 && strcmp(ptr1->term, ptr6->term) == 0 ) {
							for(ptr2 ; ptr2!= NULL ; ptr2= ptr2->nextPtr) {
								if(strcmp(ptr2->text , ptr6->text) == 0) {
									for(ptr3 ; ptr3 != NULL ; ptr3 = ptr3->nextPtr) {
										if(strcmp(ptr3->text, ptr1->text) != 0 && strcmp(ptr3->term , ptr2->term) == 0 && strcmp(ptr3->text , ptr2->text) != 0) {
											for(ptr4 ; ptr4 != NULL ; ptr4 = ptr4->nextPtr) {
												if(strcmp(ptr4->text , ptr3->text) == 0 && strcmp(ptr4->term , ptr3->term) != 0) {
													for(ptr5 ; ptr5 != NULL ; ptr5 = ptr5->nextPtr) {
														if(strcmp(ptr5->text , ptr1->text) == 0 && strcmp(ptr5->term , ptr1->term) != 0) {
															thirdOrd(&ptr3rdOrd , ptr5->term , ptr4->term) ;
														}
													}
													ptr5 = nEqualizer;
												}
										
											}
										ptr4 = nEqualizer ;
										}
									}
								ptr3 = nEqualizer ;
								}	
							}	
						ptr2 = nEqualizer ;
						}
					}				
				ptr6 = nEqualizer ;
				ptr1 = ptr1->nextPtr ;
				
				}			
				bubbleSort(ptr3rdOrd) ;
				for(ptr3rdOrd ; ptr3rdOrd->nextOrder != NULL ; ptr3rdOrd = ptr3rdOrd->nextOrder) {
					if(strcmp(ptr3rdOrd->term2 , ptr3rdOrd->nextOrder->term2) != 0 ) {
					printf("(%s,%s) " , ptr3rdOrd->term1 ,ptr3rdOrd->term2) ;
					}	
								
				}
				struct node *bpPtr = ptr ;
				struct node *bpNext = NULL ;
				struct node *ptr4frequency = NULL ;
				for(bpPtr ; bpPtr != NULL ; bpPtr = bpPtr->term_next) {
					for(bpNext = bpPtr->term_next ; bpNext != NULL ; bpNext = bpNext->term_next)	 {
						if(strcmp(bpPtr->docName , bpNext->docName) == 0 && strcmp(bpPtr->termName , bpNext->termName) == 0) {
						bpPtr->frequency += 1 ;	
						}	
					}
				wordLists(&ptr4frequency , bpPtr->docName , bpPtr->termName , bpPtr->frequency , bpPtr->textName) ;
				}
				sort4freq(ptr4frequency) ;
				int j = 0 ;
				struct node *ptrNext = NULL ;
				double rst  ;
				float value ;
				int num = 1 ;
				printf("\n%s\t\t %s\t %3s\t %s\t\n","Terms","Number of Times","TF*IDF" , "  Documents");
			  int count = 1 ; 
			  int count1  = 1 ;
			  int count2 = 1 ;
			  
			  struct node *copyFreq = NULL ;
			  
			  
			  	
				for(ptr4frequency ; ptr4frequency->term_next != NULL ; ptr4frequency = ptr4frequency->term_next) {
					for(ptrNext = ptr4frequency->term_next ; ptrNext->term_next != NULL ; ptrNext = ptrNext->term_next) {
						if(strcmp(ptrNext->docName , ptrNext->term_next->docName) != 0) {
						char str[100] ;
						strcpy(str , ptrNext->textName)  ;	
						num = atoi(str) ;
						break ;
						}	
						else 
						num = 1 ;
					}
				value = log((float)num / ptr4frequency->frequency ); 			
				value *= ptr4frequency->frequency ;
				if(count <= 5 && strcmp(ptr4frequency->docName , "econ") == 0) {
				
				printf ("%s\t\t %8d %19.2lf\t   %s\n", ptr4frequency->termName, ptr4frequency->frequency , value , ptr4frequency->docName);			
				count++ ;				
				}
				else if (count1 <= 5 && strcmp(ptr4frequency->docName , "health") == 0) {
				printf ("%s\t\t %8d %19.2lf\t   %s\n", ptr4frequency->termName, ptr4frequency->frequency , value , ptr4frequency->docName);			
				count1++ ;		
				}
				else if (count2 <= 5 && strcmp(ptr4frequency->docName , "magazin") == 0) {
				printf ("%s\t\t %8d %19.2lf\t   %s\n", ptr4frequency->termName, ptr4frequency->frequency , value , ptr4frequency->docName);			
				count2++ ;		
				}
		
			
			}			
			return(0);
		}
