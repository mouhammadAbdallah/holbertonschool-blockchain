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
	uint64_t mynonce = 0;

	do {
		block->info.nonce = mynonce;
		block_hash(block, block->hash);
		mynonce++;
	} while (hash_matches_difficulty(block->hash, block->info.difficulty) != 1);
}
