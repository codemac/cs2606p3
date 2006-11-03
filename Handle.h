#ifndef HANDLE_H_
#define HANDLE_H_

/**
 * Class Handle
 * 
 * This class is used to create and store information for handles to be used
 * in the Memory Manager.  The Handle object contains the ID, the location
 * and length of the string it references too in the file.
 * 
 * @author codemac @ braundui
 * @version 11/02/06
 */

class Handle
{
    public:
    /**
     * Constructor.  Takes in a length, a location and an ID.
     * @param length the length of the string to which this handle references in
     * the file
     * @param location the location of the string to which this handle
     * references in the file
     * @param ID the ID which corresponds to this handle.
     */
    Handle(int length, int location, int ID);
    
    /**
     * Destructor.
     */
    ~Handle();
    
    /**
     * Simple accessor that returns the location value.
     * @return unsigned int the location of the string in the file
     */
    unsigned int getLocation();
    
    /**
     * Simple accessor that returns the length value.
     * @return unsigned int the length of the string in the file.
     */
    unsigned int getLength();
    
    /**
     * Simple accessor that returns the ID value
     * @return unsigned int the ID that corresponds to this handle.
     */
    unsigned int getID();
    
    private:
    unsigned int strLength;
    unsigned int strLocation;
    unsigned int strID;
};
#endif //HANDLE_H_
