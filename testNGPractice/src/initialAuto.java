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
	 * Spring 提供的 PropertiesLoaderUtils 允许您直接通过基于类路径的文件地址加载属性资源
	 * 最大的好处就是：实时加载配置文件，修改后立即生效，不必重启
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
