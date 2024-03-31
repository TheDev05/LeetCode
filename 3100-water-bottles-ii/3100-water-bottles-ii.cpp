class Solution {
public:
    int maxBottlesDrunk(int full, int exchange) {
        
    int empty = 0;
    int sum = 0;
        
        while(full)
        {            
            sum += full;
            empty += full;
            
            full = 0;
            
            if(empty >= exchange)
                empty -= exchange, exchange++, full++;
            
        }
        
        return sum;
        
    }
};