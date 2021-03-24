package example2;

import java.util.Scanner;

public class StockProfit {
    public static int maxProfit(int[] prices) {
        if(prices.length<=0){
            return 0;
        }
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 0; i < prices.length; i++) {
            // ��ǰ�۸��Ƿ�����С�۸�
            if(prices[i] < minPrice){
                minPrice = prices[i];
                continue;
            }
            // ��ǰ������
            int localProfit = prices[i] - minPrice;
            if(localProfit > maxProfit){
                maxProfit = localProfit;
            }
        }
        return maxProfit;
    }


	public static void main(String[] args) {
		int[] test=new int[12];
		Scanner scanner=new Scanner(System.in);
		System.out.println("input:");
		for(int i=0;i<12;i++){
			test[i]=scanner.nextInt();
		}
		System.out.println(maxProfit(test));

		scanner.close();
	}


}
