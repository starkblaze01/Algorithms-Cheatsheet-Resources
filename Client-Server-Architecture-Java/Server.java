import java.net.*; 
import java.io.*; 
  
public class Server 
{ 
    private Socket          socket   = null; 
    private ServerSocket    server   = null; 
    private DataInputStream in       =  null; 
    private Socket          socketone   = null; 
    private ServerSocket    serverone   = null; 
    private DataInputStream inone       =  null; 
  
    public Server(int port, int port1) 
    { 
        try
        { 
            server = new ServerSocket(port); 
            serverone = new ServerSocket(port1);
            System.out.println("Server started"); 
  
            System.out.println("Waiting for a client ..."); 
  
            socket = server.accept();
            socketone = serverone.accept();
            System.out.println("Client accepted"); 
  
            in = new DataInputStream( 
                new BufferedInputStream(socket.getInputStream())); 
            inone = new DataInputStream( 
                new BufferedInputStream(socketone.getInputStream())); 
            String line = ""; 
            String lineone = "";
            while (!line.equals("Close")) 
            { 
                try
                {   lineone = inone.readUTF();
                    line = in.readUTF(); 
                    System.out.println(line);
                    System.out.println(lineone); 
  
                } 
                catch(IOException i) 
                { 
                    System.out.println(i); 
                } 
            } 
            System.out.println("Closing connection"); 
  
            // close connection 
            socket.close(); 
            in.close(); 
        } 
        catch(IOException i) 
        { 
            System.out.println(i); 
        } 
    } 
  
    public static void main(String args[]) 
    { 
        Server server = new Server(5000, 5001); 
    } 
} 
