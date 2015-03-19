package android.abs;

import android.os.RemoteException;

final public class AbsManager {
    IAbsManager mService;

    /**
     * @hide
     */
    public AbsManager(IAbsManager service) {
        mService = service;
    }

    /**
     * Remove every data in the "abs" device.
     */
    public void clear() {
        try {
            mService.clear();
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    /**
     * Fetch data from the abs device.
     * @return data as a String.
     */
    public String getData() {
        try {
            return mService.getData();
        } catch (RemoteException e) {
            e.printStackTrace();
        }
        return null;
    }

    /**
     * Feed abs device with data.
     * @param data the data as String
     */
    public void putData(String data) {
        try {
            mService.putData(data);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }
}
