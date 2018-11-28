

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testScheme()
   {
	 //Scheme Testing	
	   UrlValidator urlVal = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES);
	    
	   assertTrue(urlVal.isValid(testUrlScheme[0].item+"www.google.com"));
	   assertTrue(urlVal.isValid(testUrlScheme[1].item+"www.google.com"));
	   assertTrue(urlVal.isValid(testUrlScheme[4].item+"www.google.com"));
	   /*assertFalse(urlVal.isValid(testUrlScheme[2].item+"www.google.com"));
	   assertFalse(urlVal.isValid(testUrlScheme[3].item+"www.google.com"));
	   assertFalse(urlVal.isValid(testUrlScheme[5].item+"www.google.com"));
	   assertFalse(urlVal.isValid(testUrlScheme[6].item+"www.google.com"));
	   assertFalse(urlVal.isValid(testUrlScheme[7].item+"www.google.com"));*/
	   
	   
   }
   
   public void testAuth(){
		 //You can use this function to implement your Second Partition testing	   
	   UrlValidator urlVal = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES);
	    
	   assertTrue(urlVal.isValid("http://"+testUrlAuthority[0].item));
	   assertTrue(urlVal.isValid("http://"+testUrlAuthority[1].item));
	   assertTrue(urlVal.isValid("http://"+testUrlAuthority[2].item));
	   //This is wrong//
	   assertTrue(urlVal.isValid("http://"+testUrlAuthority[3].item));
	   assertTrue(urlVal.isValid("http://"+testUrlAuthority[4].item));
	   assertTrue(urlVal.isValid("http://"+testUrlAuthority[5].item));
	   assertTrue(urlVal.isValid("http://"+testUrlAuthority[6].item));
	   //this is right//
	  //assertFalse(urlVal.isValid("http://"+testUrlAuthority[3].item));
	 assertFalse(urlVal.isValid("http://"+testUrlAuthority[4]));
	 //  assertFalse(urlVal.isValid("http://"+testUrlAuthority[5]));
	  // assertFalse(urlVal.isValid("http://"+testUrlAuthority[6]));
	   
   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   
   // Taken from part A //
   ResultPair[] testUrlScheme = {
		   new ResultPair("http://", true),
		   new ResultPair("https://", true),
		   new ResultPair("h77p://", false),
		   new ResultPair("h77ps://", false),
		   new ResultPair("ftp://", true),
		   new ResultPair("http:/", false),
		   new ResultPair("http/", false),
		   new ResultPair("http:", false),
		   
   };
   ResultPair[] testUrlAuthority = {
           new ResultPair("254.254.254.250", true),
           new ResultPair("www.multi-word-check.com", true),
           new ResultPair("www.gmail.com", true),
           new ResultPair("www.------------.com", false),
           new ResultPair("www-wrong-multi-format", false),
           new ResultPair("256.256.256.256", false),
           new ResultPair("0.0.0.0.0", false)};
          
}
