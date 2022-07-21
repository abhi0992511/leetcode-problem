int currSum = 0;
    int count = 0; 
    unordered_map<int, int>map;
    
    for(int i = 0; i < input1; i++)
    {
        currSum += input2[i]; 
        
        if(currSum == input3) 
        {
            count++;
        }
        if(map.find(currSum - input3) != map.end()) 
        {
            count += map[currSum-input3];
        } 
		map[currSum]++; 
    }