package learn;

import java.util.Arrays;
import java.util.Random;
/**
 * ĳ��ϷҪ�ٰ�һ�γ鿨�����10�ֲ�ͬ�Ŀ���ÿ�γ鿨���Գ鵽��10�ֿ���һ�ţ��ѳ鵽�Ŀ������ظ��鵽����
 * ÿ�ֿ����鵽�ĸ��ʶ���ʮ��֮һ������Ҽ���ʮ�ֿ���һ��ʱ������Զһ��󽱣�����ǲ��ܰѿ�Ƭ�����˵ģ�
 * ����ÿ��������ֻ�ܶһ�һ�δ󽱣�Ҳ����˵�鵽�ظ��Ŀ�ֻ���˷��ˣ���
 * ���ʣ������Ҫ����һ�ף�����鿨��������ѧ������
 * @author 29284
 *
 */
public class CardTest {

	 private static Random rand = new Random();
	    private static int count = 0;
	    public static void main(String[] args) {
	        long time = System.currentTimeMillis();
	        cal();
	        System.out.println("ƽ��������" + count / 10000000.0);
	        System.out.println("��ʱ��" + (System.currentTimeMillis() - time) / 1000.0);
	    }
	    private static void cal() {
	        boolean[] buf = new boolean[10];
	        for (int i = 0; i < 10000000; i++) {//��һǧ�����ҽ���ģ��鿨
	            Arrays.fill(buf, false);
	            for (int c = 0; c < 10;) {//ʮ�ſ�����������ѭ������һ����
	                int index = rand.nextInt(10);
	                count++;//ÿrandomһ�Σ��൱�ڳ���һ�ſ�
	                if (!buf[index]) {
	                    c++;//����鵽���ظ��Ŀ������һ
	                    buf[index] = true;
	                }
	            }
	        }
	    }
	
}
