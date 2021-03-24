package example;

public class ShellSort {
	
	public static void main(String[] args) {
		  int[] arr = {5, 1, 7, 3, 1, 6, 9, 4};
	        shellSort(arr);

	        for (int i : arr) {
	            System.out.print(i + "\t");
	        }
	}
	  private static void shellSort(int[] arr) {
	        //step:����
	        for (int step = arr.length / 2; step > 0; step /= 2) {//�����ı仯���α�С
	            //��һ������������бȽ� [step,arr.length)
	            for (int i = step; i < arr.length; i++) {//�̶������µĸ���������ıȽϣ�i+������һλ����һ������ıȽ�
	                int value = arr[i];
	                int j;
	                //�Բ��������о����Ԫ�ؽ��бȽ�
	                for (j = i - step; j >= 0 && arr[j] > value; j -= step) {//�̶����������ݴ�����κ���
	                    //jΪ�������ȡֵ��j+stepΪ��������������Ķ�Ӧֵ��
	                    arr[j + step] = arr[j]; 
	                }
	                //��ʱstepΪһ��������[j + step]Ϊ�������ϵĳ�ʼ����ֵ
	                arr[j + step] = value;  
	            }
	        }
	    }
	  
	
}
