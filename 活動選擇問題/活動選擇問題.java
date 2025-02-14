import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        ArrayList<Activity> activities = new ArrayList<>();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int start = (int)st.nval;
            st.nextToken();
            int end = (int)st.nval;
            if(start == 0 && end == 0)
                break;
            activities.add(new Activity(start, end));
        }
        activities.sort(new Comparator<Activity>() {
            @Override
            public int compare(Activity a1, Activity a2) {
                return Integer.compare(a1.end, a2.end);
            }
        });
        int count = 0, last = 0;
        for(Activity a : activities) {
            if(a.start >= last) {
                last = a.end;
                ++count;
            }
        }
        System.out.println("Maximum number of non-overlapping activities: " + count);
	}
}

class Activity {
    int start, end;
    Activity(int start, int end) {
        this.start = start;
        this.end = end;
    }
}
