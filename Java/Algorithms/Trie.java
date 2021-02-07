//Accepts only lowercase alphabets
class Trie { 
    static final int ALPHABET_SIZE = 26; 
      
    static class TrieNode 
    { 
        TrieNode[] children = new TrieNode[ALPHABET_SIZE]; 
        boolean isEndOfWord; 
          
        TrieNode(){ 
            isEndOfWord = false; 
            for (int i = 0; i < ALPHABET_SIZE; i++) 
                children[i] = null; 
        } 
    }; 
       
    static TrieNode root;  
      
    static void insert(String key) 
    { 
        int level; 
        int length = key.length(); 
        int index;       
        TrieNode pCrawl = root;       
        for (level = 0; level < length; level++) 
        { 
            index = key.charAt(level) - 'a'; 
            if (pCrawl.children[index] == null) 
                pCrawl.children[index] = new TrieNode();        
            pCrawl = pCrawl.children[index]; 
        } 
        pCrawl.isEndOfWord = true; 
    } 
    
    static boolean search(String key) 
    { 
        int level; 
        int length = key.length(); 
        int index; 
        TrieNode pCrawl = root; 
        for (level = 0; level < length; level++) 
        { 
            index = key.charAt(level) - 'a'; 
            if (pCrawl.children[index] == null) 
                return false; 
            pCrawl = pCrawl.children[index]; 
        } 
        return (pCrawl != null && pCrawl.isEndOfWord); 
    } 
    
    public static void main(String args[]) 
    { 
        String keys[] = {"the", "a", "there", "answer", "any", 
                         "by", "bye", "their"}; 
        root = new TrieNode(); 
        int i; 
        for (i = 0; i < keys.length ; i++) 
            insert(keys[i]); 
        if(search("the") == true) 
            System.out.println("the --- Present in trie"); 
        else System.out.println("the --- Not present in trie"); 
          
        if(search("these") == true) 
            System.out.println("these --- Present in trie"); 
        else System.out.println("these --- Not present in trie"); 
          
        if(search("their") == true) 
            System.out.println("their --- Present in trie"); 
        else System.out.println("their --- Not present in trie"); 
          
        if(search("thaw") == true) 
            System.out.println("thaw --- Present in trie"); 
        else System.out.println("thaw --- Not present in trie"); 
         
    } 
} 
