package example;
public class InsertSort{
    public static int[] insertSort(int[] arr)
    {
        for (int i = 1; i < arr.length; i++)//ÿ��ѡ��һ������
        {
            int k = arr[i];//k��������arr��i�����д�С�ж�
            int j = i;//j��ѭ�������жϵ�ǰλ��ǰһλ�Ĵ�С
            while (j > 0 && arr[j - 1] > k)//���Ҫ�����Ԫ�ص�ǰһλ��������ǰһλ����
            {
                arr[j] = arr[j - 1];//Ԫ�غ���
                j--;//����ǰ��
            }
            arr[j] = k;//k���뵽��
       }
        return arr;
    }
		public static void main(String[] args) {
			int[] arr={1,23,3,44,5,4,56,57,6,7,568,67,89,67,986,7,6,79,23,86,78,6,8};
			arr=insertSort(arr);
			for (int i : arr) {
				System.out.println(i);
			}
		}
}