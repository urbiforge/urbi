/*
 * Copyright (C) 2010-2011, Gostai S.A.S.
 *
 * This software is provided "as is" without warranty of any kind,
 * either expressed or implied, including but not limited to the
 * implied warranties of fitness for a particular purpose.
 *
 * See the LICENSE file for more information.
 */

package examples.urbitalkie;

import java.io.IOException;

import urbi.*;
import urbi.*;

import java.io.*;

public class MicroNotify1 extends UCallbackInterface
{
    public MicroNotify1()
    {
        super ();
    }

    public UCallbackAction      onMessage(UMessage msg)
    {
        if (!(UMessageType.MESSAGE_DATA == msg.getType ()))
            return UCallbackAction.URBI_CONTINUE;
        UValue value = msg.getValue ();

        if (!(UDataType.DATA_BINARY == value.getType ()))
            return UCallbackAction.URBI_CONTINUE;
        UBinary bin = value.ubinaryValue ();

        if (!(UBinaryType.BINARY_SOUND == bin.getType ()))
            return UCallbackAction.URBI_CONTINUE;
        USound sound = bin.usoundValue ();
        byte[] data = sound.getData ();

        synchronized (URBITalkie.out1)
        {

            if (URBITalkie.out1.size() < 10000)
            {
                System.out.println("MicroNotify1 : write");
                URBITalkie.out1.write(data, 0, data.length);
            }
        }
        synchronized (URBITalkie.out2)
        {
            if (URBITalkie.out2.size() > 0)
            {
                System.out.println("MicroNotify1 : send size : " + URBITalkie.out2.size());
                byte audio[] = URBITalkie.out2.toByteArray();

                System.out.println("MicroNotify1 : begin send");
                URBITalkie.r1.sendBin(audio, audio.length,
                                      "speaker.val = BIN " + audio.length + " raw "
                                      + sound.getChannels() + " " + (int)sound.getRate() +
                                      " " + sound.getSampleSize() + " 1;");

                System.out.println("MicroNotify1 : end send");
                audio = null;
                URBITalkie.out2.reset();
                System.out.println("MicroNotify1 : end send");
            }
        }
        return UCallbackAction.URBI_CONTINUE;
    }
}
