package example;


public class PermutationOfRecursion {
	public static void permutation(String input ){
		if(input==null) throw new IllegalArgumentException();
		char[] data=input.toCharArray();
		permutation(data,0);
	}
	public static void permutation(char[] data,int begin){//��begin��ʼ
		int length=data.length;
		if(begin==length)  System.out.println(data);//����Ϊ0
		for(int i=begin;i<length;i++){
			if(isUnique(data, begin, i)){
				swap(data,begin,i);
				permutation(data,begin+1);
				swap(data, begin, i);
			}
		}
	}
	private static boolean  isUnique(char[] data,int begin,int end) {//���ظ�������
		for(int i=begin;i<end;i++){
			if(data[i]==data[end])
				return false;
		}
		return true;
	}
	private static void swap(char[] data,int left,int right) {//����
		char temp=data[left];
		data[left]=data[right];
		data[right]=temp;
	}
	public static void main(String[] args) {
		PermutationOfRecursion.permutation("abbewrwer");
		
	}
}
