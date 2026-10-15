	push {lr}
	adds r2, r0, #0
	adds r0, #0x64
	ldrh r0, [r0]
	ldrh r1, [r2, #0x38]
	adds r0, r0, r1
	strh r0, [r2, #0x38]
	adds r0, r2, #0
	adds r0, #0x68
	ldrh r0, [r0]
	ldrh r1, [r2, #0x3c]
	adds r0, r0, r1
	strh r0, [r2, #0x3c]
	adds r1, r2, #0
	adds r1, #0x70
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	adds r1, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080C1914
	ldr r1, _080C1918 @ =FUN_080c191c
	adds r0, r2, #0
	bl Entity080c1abc_SetUpdateCallback
_080C1914:
	pop {r0}
	bx r0
	.align 2, 0
_080C1918: .4byte FUN_080c191c
