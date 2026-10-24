class Solution {
    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int[] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int aStartDay = toDay(arriveAlice,days);
        int aEndDay = toDay(leaveAlice,days);
        int bStartDay = toDay(arriveBob,days);
        int bEndDay = toDay(leaveBob,days);

        int startDay = Math.max(aStartDay,bStartDay);
        int endDay = Math.min(aEndDay,bEndDay);

        return startDay<=endDay?endDay-startDay+1:0;
    }

    private int toDay(String date,int[] days){
        int m = (date.charAt(0)-'0')*10 + (date.charAt(1)-'0');
        int d = (date.charAt(3)-'0')*10 + (date.charAt(4)-'0');
        int res = d;

        for(int i=0;i<m-1;i++){
            res+=(days[i]);
        }
        return res;
    }
}