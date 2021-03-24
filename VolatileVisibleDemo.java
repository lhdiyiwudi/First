package example;

public class VolatileVisibleDemo {
    private int num = 0;

    public void addNum() {
        num = num + 60;
    }

    public static void main(String[] args) {
        VolatileVisibleDemo volatileVisibleDemo = new VolatileVisibleDemo();

        // t1�̶߳�num���и��Ĳ���
        new Thread(() -> {
            System.out.println(Thread.currentThread().getName() + "\t come in");
            try {
                // ģ��num���Ĳ�����ʱ3m������֤�����̶߳�ȡ��num����
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            volatileVisibleDemo.addNum();
            System.out.println(Thread.currentThread().getName() + "\t" + "numֵ�Ѿ�������Ϊ��" + volatileVisibleDemo.num);
        }, "t1").start();
        while (volatileVisibleDemo.num == 0) {
            // main�߳�һֱ�ȴ���ֱ��num������0
        }
        System.out.println(Thread.currentThread().getName() + "\t mission is over");
    }
}
