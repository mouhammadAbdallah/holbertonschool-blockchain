#include "hblk_crypto.h"

/**
 * ec_load - a function that loads an EC key pair from the disk
 * @folder: the path to the folder from which to load the keys
 *
 * Return: a pointer to the created EC key pair, or NULL upon failure
 */
EC_KEY *ec_load(char const *folder)
{
	EC_KEY *ec_key;
	char buffer[BUFSIZ];
	FILE *fp;

	if (folder == NULL)
		return (NULL);
	sprintf(buffer, "%s/%s", folder, PUB_FILE);
	fp = fopen(buffer, "r");
	if (!fp)
		return (NULL);
	if (!PEM_read_EC_PUBKEY(fp, &ec_key, NULL, NULL))
	{
		fclose(fp);
		return (NULL);
	}
	sprintf(buffer, "%s/%s", folder, PRV_FILE);
	fp = fopen(buffer, "r");
	if (!fp)
		return (NULL);
	if (!PEM_read_ECPrivateKey(fp, &ec_key, NULL, NULL))
	{
		fclose(fp);
		return (NULL);
	}
	fclose(fp);
	return (ec_key);
}
