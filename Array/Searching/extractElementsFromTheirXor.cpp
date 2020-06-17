 /* Get the rightmost set bit in set_bit_no */
    set_bit_no = Xor & ~(Xor-1);  
      
    /* Now divide elements in two sets by comparing rightmost set  
    bit of Xor with bit at same position in each element. */
    for(i = 0; i < size; i++)  
    {  
        if(arr[i] & set_bit_no)  
        x = x ^ arr[i]; /*Xor of first set in arr[] */
        else
        y = y ^ arr[i]; /*Xor of second set in arr[] */
    }  
    for(i = 1; i <= n; i++)  
    {  
        if(i & set_bit_no)  
        x = x ^ i; /*Xor of first set in arr[] and {1, 2, ...n }*/
        else
        y = y ^ i; /*Xor of second set in arr[] and {1, 2, ...n } */
    }  
