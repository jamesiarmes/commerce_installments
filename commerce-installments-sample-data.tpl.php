<?php

/**
 * @file
 * Example tpl file for theming a single commerce installments specific theme
 *
 * Available variables:
 * - $status: The variable to theme (while only show if you tick status)
 * 
 * Helper variables:
 * - $installment: The commerce installments object this status is derived from
 */
?>

<div class="commerce-installments-status">
  <?php print '<strong>Commerce Installment Sample Data:</strong> ' . $installment_sample_data = ($installment_sample_data) ? 'Switch On' : 'Switch Off' ?>
</div>