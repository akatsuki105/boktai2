	ldr r1, _0823A878 @ =gSystemSaveData
	ldr r0, _0823A87C @ =0x030016C0
	str r0, [r1]
	bx lr
	.align 2, 0
_0823A878: .4byte gSystemSaveData
_0823A87C: .4byte 0x030016C0
