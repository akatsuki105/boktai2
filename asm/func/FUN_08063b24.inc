	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08063B64 @ =0x000004C4
	adds r0, r4, r1
	bl FUN_08247504
	ldr r1, _08063B68 @ =0x0000060C
	adds r0, r4, r1
	bl FUN_080138fc
	movs r1, #0xca
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822dabc
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822dabc
	adds r0, r4, #0
	bl FUN_08061db4
	adds r0, r4, #0
	bl FUN_08062258
	adds r0, r4, #0
	bl FUN_08061b98
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08063B64: .4byte 0x000004C4
_08063B68: .4byte 0x0000060C
