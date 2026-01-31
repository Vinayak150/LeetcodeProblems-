import "math"
func minimumK(nums []int) int {
    n := len(nums)
    startK := int(math.Ceil(math.Sqrt(float64(n))))
    maxVal := 0
    for _, x := range nums{
        if x > maxVal{
           maxVal = x}
    }    
    if startK > maxVal{
        return startK
    }

    for k := startK; k <= maxVal; k++ {
        
         var operations int64 = 0
         limit := int64(k) * int64(k)

        for _, x:= range nums{
           operations += int64(( x + k-1)/k)
            
           if operations > limit{
              break}   
        }
       if operations <= limit {
          return k
      }   
   }

    return maxVal
    
}