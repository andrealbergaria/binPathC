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
    
    for (int n = 0 ; n < numOfRows ; n++) {
        
        
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
    for (int i = 0 ; i < 31; i++) {
                secBytes[0][i] = 
                arr[0] += 8;
                arr[1] += 8;
                arr[2] += 8;
                arr[3] += 8;
                arr[4] += 8;
                arr[5] += 8;
                arr[6] += 8;
                arr[7] += 8;
    }
    
	void TestIteration() {
    
    u_int pos1[32];
    u_int pos2[32];
    u_int pos3[32];
    u_int pos4[32];
    u_int pos5[32];
    u_int pos6[32];
    u_int pos7[32];
    u_int pos8[32];


    // Populate array (populate 1 byte)
    pos1[0] = 1;
    pos2[0] = 2;
    pos3[0] = 3;
    pos4[0] = 4;
    pos5[0] = 5;
    pos6[0] = 6;
    pos7[0] = 7;
    pos8[0] = 8;
    for (int i = 0 ; i < 31; i++) {
                pos1[i] += 8;
                pos2[i] += 8;
                pos3[i] += 8;
                pos4[i] += 8;
                pos5[i] += 8;
                pos6[i] += 8;
                pos7[i] += 8;
                pos8[i] += 8;
    }
    
    // going for 2 bytes
    // 
    pos1 pos1
    pos1 pos2
    pos1 pos3
    pos1 .
    
    printf("\n");
    
    u_char position[8][8]; 
    
    [0][1]
    pos1    pos1
    pos1    pos2
    pos1    pos3
    pos1
    // populate first elemen of array
    for (int i = 1 ; i < 9; i++) {
        position[0][0]= 
        
          
    }
    
    
    
    for (int i = 0; i < 8;i++) {
        
    }
    
    
    
    
}
