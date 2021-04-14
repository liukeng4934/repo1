import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Field;
import java.net.URL;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

public class JDBCUtils {
    private static String user;
    private static String password;
    private static String driver;
    private static String url;

    static {
        try {
            //读取资源文件，获取值
            Properties pro=new Properties();
            //获取src路径下的文件的方式--》ClassLoader类加载器
            ClassLoader classLoader=JDBCUtils.class.getClassLoader();
            URL resource = classLoader.getResource("jdbc.properties");
            String path=resource.getPath();
            //加载文件
            pro.load(new FileReader(path));

            //获取数据，赋值
            url=pro.getProperty("url");
            user=pro.getProperty("username");
            password=pro.getProperty("password");
            driver=pro.getProperty("driver");

            //注册驱动
            Class.forName(driver);
            //Class.forName("com.mysql.cj.jdbc.Driver");

        }  catch (ClassNotFoundException | FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url,user,password);
    }



    public static void close(PreparedStatement pstm,Connection conn){
        if (pstm!=null){
            try {
                pstm.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
        if (conn!=null){
            try {
                conn.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }

    }


    public static void close(PreparedStatement pstm, Connection conn, ResultSet rs){
        if (rs!=null){
            try {
                rs.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
        if (pstm!=null){
            try {
                pstm.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
        if (conn!=null){
            try {
                conn.close();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }


    }
    //增删改
    public static int executeUpdate(String  sql,Object ...obj){
        int num=0;//返回影响的行数
        Connection conn=null;
        PreparedStatement pstm=null;
        try {
            conn=getConnection();
            pstm= conn.prepareStatement(sql);
            //给？赋值
            for (int i=0;i< obj.length;i++){
                pstm.setObject(i+1,obj[i]);
            }
            num=pstm.executeUpdate();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }finally {
            close(pstm,conn);
        }
        return num;
    }

    //查询
    public static<T> List<T> insert(String sql,Class<T> cls,Object ... obj){
        Connection conn=null;
        PreparedStatement pstm=null;
        ResultSet rs=null;
        T object=null;
        List<T> list=new ArrayList<>();
        try {
            pstm=conn.prepareStatement(sql);
            //给？赋值
            for (int i=0;i< obj.length;i++){
                pstm.setObject(i+1,obj[i]);
            }
            rs= pstm.executeQuery();
            ResultSetMetaData rsmd=rs.getMetaData();//表结构
            int columnCount=rsmd.getColumnCount();//字段数
            while(rs.next()) {
                object = cls.newInstance();
                for (int i = 0; i < columnCount; i++) {
                    String columnName = rsmd.getColumnName(i + 1);
                    Object columnValue = rs.getObject(columnName);
                    Field field = cls.getDeclaredField(columnName);
                    field.setAccessible(true);
                    field.set(object, columnValue);
                }
                list.add(object);
            }
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        } finally {
            close(pstm,conn,rs);
        }
        return list;
    }




}
