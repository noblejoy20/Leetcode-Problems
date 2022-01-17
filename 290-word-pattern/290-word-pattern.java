class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap<String,List<Integer>> sentence=new HashMap<>();
        HashMap<Character,List<Integer>> pat=new HashMap<>();
        String[] result=s.split(" ");
        if(result.length!=pattern.length()){
            //System.out.println("dsgfds");
            return false;
        }
        
        for(int i=0;i<pattern.length();i++){
            if(!pat.containsKey(pattern.charAt(i))){
                pat.put(pattern.charAt(i),new ArrayList<>());
            }else{
                var temp=pat.get(pattern.charAt(i));
                temp.add(i);
            }            
        }
        
        for(int i=0;i<result.length;i++){
            //System.out.println(result[i]);
            if(!sentence.containsKey(result[i])){
                sentence.put(result[i],new ArrayList<>());
            }else{
                var temp=sentence.get(result[i]);
                temp.add(i);
            }            
        }
        
        for(int i=0;i<result.length;i++){
            List<Integer> temp1=sentence.get(result[i]);
            List<Integer> temp2=pat.get(pattern.charAt(i));
            if(temp1.size()==temp2.size()){
                for(int k=0;k<temp1.size();k++){
                    //System.out.println(temp1.get(k) + " "+ temp2.get(k));
                    if((int)temp1.get(k)!=(int)temp2.get(k)){
                        //System.out.println(k);
                        return false;
                    }
                }
            }else{
                //System.out.println("dsgfds");
                return false;
            }
        }
        return true;
        
    }
}