#include "blockchain.h"

/**
 * block_mine - a function that mines
 * a Block in order to insert it in the Blockchain
 * it finds a hash for block that matches its difficulty
 * @block: points to the Block to be mined
 *
 * Void
 */
void block_mine(block_t *block)
{
	if (!block)
		return;
	block->info.nonce = 0;
	block_hash(block, block->hash);
	while (hash_matches_difficulty(block->hash, block->info.difficulty) != 1)
	{
		block->info.nonce++;
	}
}
