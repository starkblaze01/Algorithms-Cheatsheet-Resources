
import java.net.*; 
import java.io.*; 
  
public class Client2
{ 
    private Socket socket            = null; 
    private DataInputStream  input   = null; 
    private DataOutputStream out     = null; 
  
    public Client2(String address, int port) 
    { 
        try
        { 
            socket = new Socket(address, port); 
            System.out.println("Connected"); 
  
            input  = new DataInputStream(System.in); 
  
            out    = new DataOutputStream(socket.getOutputStream()); 
        } 
        catch(UnknownHostException u) 
        { 
            System.out.println(u); 
        } 
        catch(IOException i) 
        { 
            System.out.println(i); 
        } 
  
        String line = ""; 
  
        while (!line.equals("Over")) 
        { 
            try
            { 
                line = input.readLine(); 
                out.writeUTF(line); 
            } 
            catch(IOException i) 
            { 
                System.out.println(i); 
            } 
        } 
  
        try
        { 
            input.close(); 
            out.close(); 
            socket.close(); 
        } 
        catch(IOException i) 
        { 
            System.out.println(i); 
        } 
    } 
  
    public static void main(String args[]) 
    { 
        Client2 client = new Client2("127.0.0.1", 5001); 
    } 
} 
