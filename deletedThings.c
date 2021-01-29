void testingArray() {
	unsigned char *tmp =(char *)malloc(5);
	unsigned char comb[16][4] =
						{
						{ '0','0','0','0' },
						{ '0','0','0','1' } ,
						{ '0','0','1','0' } ,  // 3
						{ '0','1','0','0' } ,
						{ '0','1','1','1' } ,
						{ '0','1','1','0' } ,
						{ '0','0','1','1' } ,
						{ '0','1','0','1' } ,	// 8
						{ '1','0','0','0' } ,
						{ '1','0','0','1' } ,
						{ '1','0','1','0' } ,
						{ '1','1','0','0' } ,
						{ '1','0','1','1' } ,		//13
						{ '1','1','0','1' } ,
						{ '1','1','1','1' }		 // 15
						};
		for (int i=0 ; i < 16  ; i++) {
                memcpy(tmp,comb[i],4);
                tmp[4] = '\0';
            for (int idx= 0; idx < 4;idx++) {
                if (comb[i][idx] == '1') 
                    printf("   Array[%i][%i] ",i,idx);
            }
        }

	}
	
	void testingArray256() {
    unsigned char *tmp =(char *)malloc(5);
    char numOfRows = pow(8,4); 
	unsigned char *positions[numOfRows][4]; // Need to alloc 256 per position
	
	
	// Memory allocated...
    for (int i=0 ; i< numOfRows ; i++) {
        for (int idx =0 ; idx < 4;idx++) {
            
            
            
            positions[i][idx] = (char *) malloc(256);
            for (int memAlloc = 0 ; memAlloc < 256; memAlloc){
                    positions[i][idx] = memAlloc;
                    // Obter todas posicose
                    //obterTodasAsPosicoes(1); // Todas as rows e idxs com uma determinada posicao
                    for (int i2= 0 ; i2 < numOfRows ; i2++) {
                        for (int letter; letter < 4; letter++) {
                            if
 (positions[i2][letter] == positions[i][idx])
                                positions[i2][letter]= positions[i][idx];
                                
                        }
                    }
                    
            }
                    
                        
            // Get other positions to equal  (like, {1,0,0,0} {0,1,0,0} just need to assign
            // Other positions
            }
            
            
            
        }
    }

    
    
    
    // Set each position with all elements (rows)
    
	
}

void assignArray(unsigned char positionToColumn[numPositions][numOfRows]) {

        for (int pos=0 ; pos < 7 ; pos++) {
            positionToColumn[pos][0] = 0;
            for (int i=1 ; i <= numOfRows; i++) {

                positionToColumn[pos][i] += 8;
                positionToColumn[pos][i] += pos;

               // printf("\nPOsitio co colm %i",positionToColumn[pos][i]);
           // printf("\n\t\t\t %i ",i);
               // printf("\nPOS TO COLUM %i %i",pos,i);
               // printf("\nPosToColum[%i][%i] = %i ",pos,i,positionToColumn[pos][i]);
            }


      }


}


	
	void TestIteration() {
    
    // Populate array (populate 1 byte)
    u_char arr[] =  {1,2,3,4,5,6,7,8};
    u_char secBytes[8][8];
    secBytes[0] = 1 and 
    secBytes[1] = 1;

    

    
    
    
}
