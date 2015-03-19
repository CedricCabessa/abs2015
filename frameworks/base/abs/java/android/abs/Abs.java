package android.abs;

public class Abs {
    static {
        System.loadLibrary("abs_jni");
    }

    public native static void clear();
    public native static String getData() throws AbsException;
    public native static void putData(String in) throws AbsException;
}
