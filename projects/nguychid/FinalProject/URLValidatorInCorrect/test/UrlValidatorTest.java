

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
	   UrlValidator urlValidator = new UrlValidator(null,null, UrlValidator.ALLOW_ALL_SCHEMES);        
       String[] urls = {
               "http://www.ebay.com/",
               "http://www.google.com/",
               "http://www.google2.com/",
               "http://www.google.com/",
               "http://www.google.com/",
               "http:google.com/",
               "http/www.google.com/",
               "http/www.---.com/",
               "http://what-everything-go-off-the-rails",
               "not-a-url"};

       for (String u : urls) {
           if (urlValidator.isValid(u)) {
               System.out.println(u + " is valid");
           } else {
               System.out.println(u + " is invalid");
           }
       }
	   
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
	 assertFalse(urlVal.isValid("http://"+testUrlAuthority[3].item));
	 //assertFalse(urlVal.isValid("http://"+testUrlAuthority[4].item));
	 //  assertFalse(urlVal.isValid("http://"+testUrlAuthority[5]));
	  // assertFalse(urlVal.isValid("http://"+testUrlAuthority[6]));
	   
	   /*   for(ResultPair duo: testUrlScheme ) {
		   
		   if(duo.valid) {
			   assertTrue(urlVal.isValid(duo.item + "www.google.com"));
		   }
		   else
			   assertFalse(urlVal.isValid(duo.item + "www.google.com"));
		   
	   }*/
	   
   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	 //You can use this function for programming based testing
       UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

	   System.out.println("testIsValid() Tests");
	   
       // Iterate through every test URL combination
       for(int a = 0; a < testUrlScheme.length; a++) {
    	 for(int b = 0; b < testUrlAuthority.length; b++) {
	       for(int c = 0; c < testUrlPort.length; c++) {
	    	  for(int d = 0; d < testPath.length; d++) {
		       for(int e = 0; e < testUrlQuery.length; e++) {
		    	   boolean expectedResult = testUrlScheme[a].valid && testUrlAuthority[b].valid && testUrlPort[c].valid && testPath[d].valid && testUrlQuery[e].valid;
		    	   System.out.println("" + testUrlScheme[a].valid + " " + testUrlAuthority[b].valid + " " + testUrlPort[c].valid + " " + testPath[d].valid + " " + testUrlQuery[e].valid);

			   System.out.println("Expected Result Bool: " + expectedResult);
			   
			   String url = testUrlScheme[a].item + testUrlAuthority[b].item + testUrlPort[c].item + testPath[d].item + testUrlQuery[e].item;

			   if (expectedResult == true) {
			       assertTrue(urlVal.isValid(url));
				   System.out.println("Expected Result: true  Actual Result: " + Boolean.toString(urlVal.isValid(url)));
				   System.out.println("URL: " + url);
			   }
			   else {
				   // isValid appears to return inconsistent results with bad URLs
			       assertFalse(urlVal.isValid(url));
				   System.out.println("Expected Result: false  Actual Result: " + Boolean.toString(urlVal.isValid(url)));
				   System.out.println("URL: " + url);
			   }
		       }
	       }
    	 }
       }
       }
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
   // Adding from here
   ResultPair[] testUrlPort = {new ResultPair(":80", true),
                              new ResultPair(":65535", true),
                              new ResultPair(":0", true),
                              new ResultPair("", true),
                              new ResultPair(":-1", false),
                             new ResultPair(":65636",false),
                              new ResultPair(":65a", false)
    };
    ResultPair[] testPath = {new ResultPair("/test1", true),
                           new ResultPair("/t123", true),
                           new ResultPair("/$23", true),
                           new ResultPair("/..", false),
                           new ResultPair("/../", false),
                           new ResultPair("/test1/", true),
                           new ResultPair("", true),
                           new ResultPair("/test1/file", true),
                           new ResultPair("/..//file", false),
                           new ResultPair("/test1//file", false)
    };
    //Test allow2slash, noFragment
    ResultPair[] testUrlPathOptions = {new ResultPair("/test1", true),
                                     new ResultPair("/t123", true),
                                     new ResultPair("/$23", true),
                                     new ResultPair("/..", false),
                                     new ResultPair("/../", false),
                                     new ResultPair("/test1/", true),
                                     new ResultPair("/#", false),
                                     new ResultPair("", true),
                                     new ResultPair("/test1/file", true),
                                     new ResultPair("/t123/file", true),
                                     new ResultPair("/$23/file", true),
                                     new ResultPair("/../file", false),
                                     new ResultPair("/..//file", false),
                                     new ResultPair("/test1//file", true),
                                     new ResultPair("/#/file", false)
    };

    ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
                               new ResultPair("?action=edit&mode=up", true),
                               new ResultPair("", true)
    };

    Object[] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};
    //Object[] testUrlPartsOptions = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPathOptions, testUrlQuery};
          
}
