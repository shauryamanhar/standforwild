package standforwild;
import java.util.*;
import java.io.*;
public class FirePrediction {
	public String fire(String path){
		BufferedReader brf = null;
		String result="";
		try {
			brf = new BufferedReader(new FileReader(path));
			result=brf.readLine();
			result=result.charAt(2)+"";
			return result;
		} catch (Exception e) {
			e.printStackTrace();
		}
		return "n"; 
	}
}
