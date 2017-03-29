
import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
public class Main { // Main Class
    public static void main (String[] args) throws IOException {
        
        
        GridWalker gridWalker = new GridWalker();

        double points = gridWalker.GetNumberOfAccessiblePoints();
        System.out.println(Math.round(points));
    }
}
 class Pair{
// For Hash Map 
     int x;
     int y;

     public boolean equals(Object o) {
         Pair c = (Pair) o;
         return c.x == x && c.y == y;
     }

     public Pair(int x, int y) {
         super();
         this.x = x;
         this.y = y;
     }

     public int hashCode() {
         return new Integer(x + "0" + y);
     }

    }
class GridWalker
{
   
    private Map< Boolean, Pair> accessiblePoints; // Creaitng a hash map
    private List<Pair> orderedPoints;
    private int pointSumLimit = 19; //limit

    public GridWalker()
    {
         accessiblePoints = new HashMap<Boolean, Pair>();  
         accessiblePoints.put(true, new Pair(0, 0));
          orderedPoints = new ArrayList<Pair>();
          orderedPoints.add(new Pair(0,0));
    }

    public GridWalker(int argPointSumLimit) 
    {
        pointSumLimit = argPointSumLimit;
    }
    
    public double GetNumberOfAccessiblePoints()
    {
        int index = 0;
        do
        {
            Pair pointToNavigateFrom = orderedPoints.get(index);
            
            AddPointIfValid(pointToNavigateFrom.x, pointToNavigateFrom.y); // Moving right
            AddPointIfValid(pointToNavigateFrom.x, pointToNavigateFrom.y+ 1); //moving up
            AddPointIfValid(pointToNavigateFrom.x - 1, pointToNavigateFrom.y);
            AddPointIfValid(pointToNavigateFrom.x, pointToNavigateFrom.y - 1);

            //If we reached the end of the visited points and none were added in the previous checks then we're done.
            if (orderedPoints.size() - 1 == index) break;
            index++;
        } while (true);

        return orderedPoints.size();
    }

    private void AddPointIfValid(int x, int y)
    {
        if (LimitCheck(x, y, pointSumLimit))
        {
            Pair newPoint = new Pair(x, y);
            if (!accessiblePoints.containsKey(newPoint))
            {   
                accessiblePoints.put(true, newPoint);
                orderedPoints.add(newPoint);
            }
        }
    }

    private Boolean LimitCheck(int x, int y, int limit)
    {
        int tempx = x, tempy =y;
          int sum = 0 ;
    while( tempx != 0){
        sum += tempx % 10;
        tempx = tempx/10;
    }
    
        while(tempy != 0){
        sum += tempy % 10;
        tempy = tempy/10;
    }
    if(sum>limit)
    return false;

        return (sum <= limit);
    }
}
