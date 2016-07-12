# TestArea area example and tests

This example allows to test various aspects of the MAL specification:

  - Interaction patterns: SEND, SUBMIT, INVOKE, REQUEST, PROGRESS and PUBSUB.
  - Composite structure.
  - Element list.
  - Message body with multiples elements.
  - Optional field ('canBeNull=true')
  - Polymorphism of the last element of the message body.

The description of the TestArea area can be found in [TestArea.xml](https://github.com/ccsdsmo/malc/blob/master/xml/TestArea.xml).
The code in testarea sub-directory is automatically generated from this XML description with the
[CNES MO C Stub Generator](https://github.com/ccsdsmo/stubgenerator_c/tree/master/generator#cnes-mo-c-stub-generator) v1.0
(tag [C_STUB_GENERATOR_1_0](https://github.com/ccsdsmo/stubgenerator_c/releases/tag/C_STUB_GENERATOR_1_0)).
