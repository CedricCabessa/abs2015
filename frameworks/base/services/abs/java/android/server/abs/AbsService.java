package android.server.abs;

import android.content.Context;
import android.util.Slog;
import android.abs.Abs;
import android.abs.AbsException;
import android.abs.IAbsManager;

/**
 * @hide
 */
public class AbsService extends IAbsManager.Stub {
    private static final String TAG = "AbsService";
    private Context mContext;


    public AbsService(Context context) {
        mContext = context;
    }

    private void enforceAccessPermission() {
        mContext.enforceCallingOrSelfPermission(android.Manifest.permission.ABS_ACCESS,
                                                "AbsService");
    }

    public void clear() {
        enforceAccessPermission();
        Abs.clear();
    }

    public String getData() {
        enforceAccessPermission();
        try {
            return Abs.getData();
        } catch(AbsException e) {
            Slog.d(TAG, "cannot getdata");
        }
        return null;
    }

    public void putData(String in) {
        enforceAccessPermission();
        try {
            Abs.putData(in);
        } catch(AbsException e) {
            Slog.d(TAG, "cannot putdata "+e.toString());
        }
    }
}
