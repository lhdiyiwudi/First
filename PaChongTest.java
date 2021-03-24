
package example;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
 
import java.io.FileWriter;
 
public class PaChongTest {
    public void test() {
        FileWriter fw =null;
        int a =1;
        try {
            String allUrl ="http://www.paoshuzw.com/";
            Document docAll = Jsoup.connect(allUrl).get();
            Elements urlAll = docAll.select(".time");
            Elements hrefAll = urlAll.select("a[href]");
            for (Element hr : hrefAll) {
                String url = hr.attr("abs:href");
                Document doc = Jsoup.connect(url).get();
                //������±���
                Elements main = doc.getElementsByClass("title");
                Elements link = main.select("a[href]");
                for (Element hr1 : link) {
                    String href = hr1.attr("abs:href");
                    Document inDoc = Jsoup.connect(href).get();
                    Elements inMain = inDoc.getElementsByClass("blkContainer");
                    Elements h1 = inMain.select("h1");
                    Elements artInfo = inMain.select(".artInfo");
                    Elements blkContainerSblkCon = inDoc.getElementsByClass("blkContainerSblkCon");
                    Elements p = blkContainerSblkCon.select("p");
                    String title = h1.text();
                    String author = artInfo.select("#pub_date").text();
                    String source = artInfo.select("#media_name").text();
                    String content = "";
                    for (Element contxt : p) {
                        content += contxt.text();
                    }
                    fw = new FileWriter("F:\\����\\"+hr.text()+".doc", true);
                    fw.write("���⣺"+title + "\r\n" + author + "\r\n" + source + "\r\n" + content);//�������ļ���������123
                    fw.flush();
//                    System.out.println("����:" + title);
//                    System.out.println(author);
//                    System.out.println(source);
//                    System.out.println("����:" + content);
                    System.out.println("������"+a+++"��");
                }
                System.out.println("test");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
 
    public static void main(String[] args) {
        PaChongTest pt = new PaChongTest();
        pt.test();
 
 
    }
}	