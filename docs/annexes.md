Annexes
=======

"TestArea" area example
-----------------------

This example (see https://github.com/ccsdsmo/malc/blob/master/xml/TestArea.xml) allows to test
various aspects of the MAL specification:

        - Interaction patterns: SEND, SUBMIT, INVOKE, REQUEST, PROGRESS and PUBSUB.
        - Composite structure.
        - Element list.
        - Message body with multiples elements.
        - Optional field ('canBeNull=true')
        - Polymorphism of the last element of the message body.

```xml
<?xml version="1.0" encoding="UTF-8"?>
<mal:specification xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
                   xmlns:mal="http://www.ccsds.org/schema/ServiceSchema">
  <mal:area name="TestArea" number="200" version="1">
    <mal:service name="TestService" number="1">
      <mal:capabilitySet number="100">
        <mal:sendIP name="testSend" number="100" supportInReplay="false"
         comment="">
          <mal:messages>
            <mal:send>
              <mal:type area="TestArea" service="TestService"
               name="TestComposite" />
              <mal:type list="true" area="MAL" name="String" />
              <mal:type area="TestArea" service="TestService"
               name="TestAbstractComposite" />
            </mal:send>
          </mal:messages>
        </mal:sendIP>
      </mal:capabilitySet>
      <mal:dataTypes>
        <mal:composite name="TestComposite" shortFormPart="1" comment="">
          <mal:extends>
            <mal:type area="MAL" name="Composite" />
          </mal:extends>
          <mal:field name="stringField" canBeNull="true" comment="">
            <mal:type area="MAL" name="String" />
          </mal:field>
          <mal:field name="intField" canBeNull="true" comment="">
            <mal:type area="MAL" name="Integer" />
          </mal:field>
        </mal:composite>
        <smc:composite name="TestAbstractComposite" comment="">
          <smc:extends>
            <smc:type area="MAL" name="Composite" />
          </smc:extends>
          <mal:field name="intField" canBeNull="false" comment="">
            <mal:type area="MAL" name="Integer" />
          </mal:field>
        </mal:composite>
        <smc:composite name="TestFinalCompositeA" shortFormPart="2"
         comment="">
          <smc:extends>
            <smc:type area="TestArea" service="TestService"
                      name="TestAbstractComposite" />
          </smc:extends>
          <mal:field name="intField2" canBeNull="false" comment="">
            <mal:type area="MAL" name="Integer" />
          </mal:field>
        </mal:composite>
        <smc:composite name="TestFinalCompositeB" shortFormPart="3"
         comment="">
          <smc:extends>
            <smc:type area="TestArea" service="TestService"
                      name="TestAbstractComposite" />
          </smc:extends>
          <mal:field name="stringField" canBeNull="false" comment="">
            <mal:type area="MAL" name="String" />
          </mal:field>
        </mal:composite>
      </mal:dataTypes>
    </mal:service>
  </mal:area>
</mal:specification>
```

Names collision
---------------

This annex lists the different name collisions that could occur during the code generation.
Solutions are proposed. They are currently not applied to the code generation.

### Composite fields

Add a `_f` suffix to the name of the field to avoid a possible collusion with the presence field
if it exists. For example, two MAL fields named `toto` and `toto_is_present`.

```c
bool <field>_is_present;
unsigned int <field>_attribute_tag;
<field type> <field>_f;
```

Encoding format of the MALZMQ header
------------------------------------

To simplify the encoding format of the MAL header, the `From URI` and `To URI` fields are encoded systematically and completely.

Version Number | SDU Type | Service Area | Service | Operation | Area Version | Is Error Message | QoSlevel | Session | Transaction Id
---------------|----------|--------------|---------|-----------|--------------|------------------|----------|---------|---------------
Binary value (3 bits) | Unsigned 5-bit Integer (5 bits) | Unsigned 16-bit Integer (16 bits) | Unsigned 16-bit Integer (16 bits) | Unsigned 16-bit Integer (16 bits) | Unsigned 8-bit Integer (8 bits) | Binary value (1 bit) | Unsigned 3-bit Integer (3 bits) | Unsigned 4-bit Integer (4 bits) | Unsigned 64-bit Integer (64 bits)

Spare                 | Priority Flag        | Time-stamp Flag      | Network Zone Flag    | Session Name Flag    | Domain Flag          | Authentication Id Flag
----------------------|----------------------|----------------------|----------------------|----------------------|----------------------|-----------------------
Binary value (2 bits) | Binary value (1 bit) | Binary value (1 bit) | Binary value (1 bit) | Binary value (1 bit) | Binary value (1 bit) | Binary value (1 bit)

Priority                        | URI From                            | URI To
--------------------------------|-------------------------------------|------------------------------------
UInteger (var. mult. of octet)  | Optional MDK (var., mult. of octet) | Optional MDK (var., mult. of octet)
If ‘Priority Flag’ is ‘1’       |

Timestamp                   | Network Zone                        | Session Name                        | Domain                                    | Authentication Id
----------------------------|-------------------------------------|-------------------------------------|-------------------------------------------|------------------------------
Time (var., mult. of octet) | Optional MDK (var., mult. of octet) | Optional MDK (var., mult. of octet) | List<Optional MDK> (var., mult. of octet) | Blob (var., mult. of octet)
If ‘Timestamp Flag’ is ‘1’  | If ‘Network Flag’ is ‘1’            | If ‘Session Flag’ is ‘1’            | If ‘Domain Flag’ is ‘1’                   | If ‘Authentication Id Flag’ is ‘1’

Classes description diagram
--------------------------

The diagram below shows the different implementation classes and their relationships. Classes are separated in two spaces: MAL/C and MAL/ZMQ transport. Most of these relationships are unitary, only `malzmq_poller_data_t` class contains a reference list to the `malzmq_endpoint_data_t` class.

![Class Diagram](img/class_diagram.png)

*Figure 1 - MAL classes diagram

