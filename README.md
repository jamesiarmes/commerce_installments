Commerce Installments

This module was developed as a custom module for AllPlayers.com. The basic idea
is that one product, when purchased (as the first installment) creates
additional installment products.

There are two module components here:
* The code portion (commerce_installments.module)
* The feature portion, which includes views and rules (commerce_installments_feature.module)

The feature provides two custom product types:
  * master_installment has an installment field and is used for a first-payment of an installment plan. 
  * installment_payment is the product used for an installment.

The module has dependencies on commerce_installments, features, commerce_features, date_api, date, commerce_installments_feature, entityreference.

To demonstrate the module's features, enable both modules and then:

1. Create a product of type installment_payment, adding a payment plan to it. 
2. Create a product display node that points to it.
3. Purchase the product and pay for it. (That is the first installment). New products of type installment_payment are created per the recipe in the master_installment's installment field.
4. Visit the "my installments" page and the Administrative installments page. Both show the current status. Both are views so can be changed by sitebuilders to whatever is needed. (Note that the "My installments" page line items can be changed from VBO to Add-to-cart forms in views if the patch in http://drupal.org/node/1284236 is applied or has been committed.)
5. Pay an installment by adding to the cart from the "My installments" page and checking out.
6. Visit the My Installments page to see that it is now marked paid. (The view can be changed to not show paid installments, or it's easy clone this display alter it to show paid installments.)