#ifndef __DEMO_TIMESTAMP_GET_FCN_HEADER__
#define __DEMO_TIMESTAMP_GET_FCN_HEADER__

#include "mwadaptorimaq.h"
#include "source_adaptor.h"

/**
 * Class TemperatureGetFcn
 *
 * @brief:  Provides a custom get function for the timestamp properties.
 *
 */
class TemperatureGetFcn : public imaqkit::IPropCustomGetFcn {

  public:
    //**************************************
    //* CONSTRUCTOR/DESTRUCTOR
    //**************************************
    /**
     * Constructor for TemperatureGetFcn class.
     *
     * @param parent: Handle to the instance of the IAdaptor class
     *                that is the parent of this object.
     */
    TemperatureGetFcn(SourceAdaptor *parent) : m_parent(parent){};

    // Destructor
    virtual ~TemperatureGetFcn(void){};

    // *******************************************************************
    // METHODS FOR CONFIGURING AND UPDATING DEMO SOURCE INPUTS.
    // *******************************************************************
    /**
     * This is the method the engine calls when the value of a property
     * that has an imaqkit::IPropCustomGetFcn associated with it.  This method
     * handles both the string and integer versions of the timestamp property.
     * It uses the imaqkit::IPropInfo to determine the storage type of the
     * property and then casts the value parameter appropriately.
     *
     * This method returns a timestamp as an example because it is easy to
     * generate and changes in a predictable manner.  A typical adaptor
     * would query the device's SDK to determine the current value of
     * a hardware parameter.
     *
     * @param propertyInfo: Property information object.
     * @param value: The current value of the property..
     *
     * @return void:
     */
    virtual void getValue(imaqkit::IPropInfo *propertyInfo, void *value);

  private:
    /// The instance of the parent class that created this listener.
    SourceAdaptor *m_parent;
};

#endif
