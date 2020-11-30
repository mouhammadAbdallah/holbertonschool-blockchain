#include "hblk_crypto.h"

/**
 * ec_save - a function that saves an existing EC key pair on the disk
 * @key: points to the EC key pair to be saved on disk
 * @folder: the path to the folder in which to save the keys
 *
 * Return: 1 or 0 upon success or failure
 */
int ec_save(EC_KEY *key, char const *folder)
{
	char buffer[BUFSIZ];
	FILE *fp;

	if (!key || !folder)
		return (0);
	mkdir(folder, 0700);
	sprintf(buffer, "%s/%s", folder, PRV_FILE);
	fp = fopen(buffer, "w");
	if (!fp)
		return (0);

	/* Write Private key to PEM */
	if (!PEM_write_ECPrivateKey(fp, key, NULL, NULL, 0, NULL, NULL))
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);

	sprintf(buffer, "%s/%s", folder, PUB_FILE);
	fp = fopen(buffer, "w");
	if (!fp)
		return (0);

	/* Write Public key to PEM */
	if (!PEM_write_EC_PUBKEY(fp, key))
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);
	return (1);
}
