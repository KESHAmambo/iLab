package com.javarush.test.NetCraker.Utils.Archiver;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by Аркадий on 05.11.2015.
 */
public class MainArchiver
{
    /**
     *
     * @param args contains an identifier of the command at args[0] :
     *             "-c" for compression, "-d" for decompression, "-a" for addition;
     *             contains an archive's abstract pathname at args[1].
     *
     * @throws IOException
     */
    public static void main(String[] args) throws IOException
    {
        //args = new String[] {"-c", "c:/javaidea/newArchive.zip", "c:/javaidea/dir1", "c:/javaidea/res.txt", "c:/javaidea/newDir"};
        //args = new String[] {"-d", "c:/javaidea/newArchive.zip", "c:/javaidea/resultFolder"};
        args = new String[] {"-a", "c:/javaidea/newArchive.zip", "c:/javaidea/result.txt", "c:/javaidea/try.txt", "c:/javaidea/lalka"};

        try {
            switch (args[0])
            {
                case "-c":
                    List<String> list1 = new ArrayList<>();
                    list1.addAll(Arrays.asList(args).subList(2, args.length));
                    Archiver.zipCompress(args[1], list1);
                    break;
                case "-d":
                    Archiver.zipDecompress(args[1], args[2]);
                    break;
                case "-a":
                    List<String> list2 = new ArrayList<>();
                    list2.addAll(Arrays.asList(args).subList(2, args.length));
                    Archiver.zipAdd(args[1], list2);
                    break;
                default:
                    System.out.println("Incorrect command!\n" +
                            "You should enter one of the allowed commands as the first argument:\n" +
                            "\"-c\" - compression, \"-d\" - decompression, \"-a\" - addition.");
            }
        } catch(IndexOutOfBoundsException ie) {
            System.out.println("Incorrect arguments!");
        }
        catch(Exception e) {
            System.out.println("Look for incorrect arguments or some programs, that can use your arguments' files!");
        }
    }
}
