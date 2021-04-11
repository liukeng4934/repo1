public class AQueue<T> {
    public int MAXQUEUE=10;
    public data[] data;
    public int front;
    public int rear;
    public int length;

    public AQueue(){
        data=new data[MAXQUEUE];
    }

    public  int getMAXQUEUE() {
        return MAXQUEUE;
    }

    public data[] getData() {
        return data;
    }

    public void setData(data[] data) {
        this.data = data;
    }
}


