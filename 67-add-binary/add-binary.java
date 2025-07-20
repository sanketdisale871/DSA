class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int car = 0;
        int i=a.length()-1,j=b.length()-1;

        while(i>=0 || j>=0 || car==1){
            if(i>=0){
                car+=a.charAt(i--)-'0';
            }
            if(j>=0){
                car+=b.charAt(j--)-'0';
            }
            sb.append(car%2);
            car/=2;
        }    
        return sb.reverse().toString();
    }
}