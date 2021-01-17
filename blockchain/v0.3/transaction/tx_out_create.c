#include "transaction.h"

/**
 * tx_out_create - allocate and initializes a transaction output structure
 * @amount: the amount of the transaction
 * @pub: the public key of the transaction receiver
 *
 * Return: pointer to the created tx_out, or NULL upon failure
 */
tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN])
{
	tx_out_t *tx_out;

	if (amount == 0 || pub == NULL)
		return (NULL);
	tx_out = calloc(1, sizeof(*tx_out));
	if (tx_out == NULL)
		return (NULL);
	tx_out->amount = amount;
	memcpy(tx_out->pub, pub, EC_PUB_LEN);
	sha256((int8_t const *)&(tx_out->amount), 4 + EC_PUB_LEN, tx_out->hash);
	return (tx_out);
}
