package test.scripts;

import org.testng.annotations.Test;
import org.testng.annotations.BeforeTest;

import org.openqa.selenium.WebDriver;
import org.openqa.*;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.testng.annotations.BeforeMethod;

public class testscript01 {
  @Test
  public void f() {
		//Create a new instance of Firefox Browser
	  WebDriver ffdriver=new FirefoxDriver();
      //Open the URL in firefox browser
      ffdriver.get("https://sina.com.cn/");

      //Maximize the Browser window
      ffdriver.manage().window().maximize();

      //Get the current page URL and store the value in variable 'str'
      String str = ffdriver.getCurrentUrl();
    
      assert str.equals("http://sina.com.cn");
      //Print the value of variable in the console
      System.out.println("The current URL is " + str);
  }
  @BeforeMethod
  public void beforeMethod() {
	  System.setProperty("webdriver.firefox.bin", "D:\\installed\\Mozilla Firefox\\firefox.exe");
	  System.setProperty("webdriver.firefox.marionette","E:\\software\\TDSoft\\QA\\Selenium\\geckodriver.exe");
	  
  }

}
