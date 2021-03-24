package example;

public class SelectSort {
	
	public static int[] selectSort(int[] arr,int n) {
		for (int i = 0; i < n - 1; i++) {//��ѭ����������ÿһ�˾�λ�ü�һ
            int index = i;
            int j;
            // �ҳ���Сֵ��Ԫ���±�
            for (j = i + 1; j < n; j++) {//��ѭ����ÿһ��һ��Ԫ��������Ԫ�ص�ÿһ�αȽ�
                if (arr[j] < arr[index]) {
                    index = j;//ÿ�ν�С�ĸ���index��ѭ��������index������С��
                }
            }
            int tmp = arr[index];
            arr[index] = arr[i];
            arr[i] = tmp;//���ҵ�����������ѭ�����Ǹ�ѭ��λ��
		}
		return arr;
	}
	public static void main(String[] args) {
		int[] arr={12,3,23,2,3,2314,23,45,3425,34,53,45,4,65,7,56,786,78,34};
		arr=selectSort(arr,arr.length);
		for (int i : arr) {
		System.out.println(i);	
		}
	}
}
