/*
 * Copyright (C) 2010-2011, Gostai S.A.S.
 *
 * This software is provided "as is" without warranty of any kind,
 * either expressed or implied, including but not limited to the
 * implied warranties of fitness for a particular purpose.
 *
 * See the LICENSE file for more information.
 */

package examples.urbiimage;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.awt.Image;
import java.awt.image.BufferedImage;

import urbi.*;
import urbi.*;

public class    ShowImage extends UCallbackInterface
{
    private static ImageSampler imageSampler;

    private static final String cmd = new String("cam<< camera.val &;");

    public ShowImage(ImageSampler sampler)
    {
        this.imageSampler = sampler;
    }

    public UCallbackAction      onMessage(UMessage msg)
    {
        if (!(UMessageType.MESSAGE_DATA == msg.getType ()))
            return UCallbackAction.URBI_CONTINUE;
        UValue value = msg.getValue ();

        if (!(UDataType.DATA_BINARY == value.getType ()))
            return UCallbackAction.URBI_CONTINUE;
        UBinary bin = value.ubinaryValue ();

        if (!(UBinaryType.BINARY_IMAGE == bin.getType ()))
            return UCallbackAction.URBI_CONTINUE;
        UImage img = bin.uimageValue ();
        byte[] data = img.getData ();

        BufferedImage buffer = null;
        try
        {
            ByteArrayInputStream bais = new ByteArrayInputStream(data);
            com.sun.image.codec.jpeg.JPEGImageDecoder decoder = com.sun.image.codec.jpeg.JPEGCodec.createJPEGDecoder(bais);
            buffer = decoder.decodeAsBufferedImage();
            imageSampler.addImage(buffer, (int) img.getWidth(), (int) img.getHeight());
            buffer.flush();
            buffer = null;
        } catch (Exception e)
        {
        }
        return UCallbackAction.URBI_CONTINUE;
    }
}
