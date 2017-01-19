/*
 * Initial class for preparing the testing environment
 * Author  : Kui Song
 *
 */

import java.io.IOException;
import java.util.Properties;

import org.springframework.core.io.ClassPathResource;
import org.springframework.core.io.Resource;
import org.springframework.core.io.support.PropertiesLoaderUtils;
import org.springframework.core.io.FileSystemResource;

public class initialAuto {

	/**
	 * Spring �ṩ�� PropertiesLoaderUtils ������ֱ��ͨ��������·�����ļ���ַ����������Դ
	 * ���ĺô����ǣ�ʵʱ���������ļ����޸ĺ�������Ч����������
	 * @return 
	 */
	private static Properties springUtil(){
		Properties props = new Properties();
		while(true){
			try {
				props=PropertiesLoaderUtils.loadAllProperties("automationcfg.properties");
				for(Object key:props.keySet()){
					System.out.print(key+":");
					System.out.println(props.get(key));
					return props;
				}
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
			
			try {Thread.sleep(5000);} catch (InterruptedException e) {e.printStackTrace();}
		}
		
	}
	

	
}
