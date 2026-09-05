	push {r4, lr}
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0807B478
	bl Script_GetValue
	adds r4, r0, #0
	cmp r4, #2
	bgt _0807B478
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0807B450
	bl Script_GetValue
	adds r2, r0, #0
	b _0807B458
_0807B450:
	ldr r1, _0807B468 @ =0x085ABF4C
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r2, [r0]
_0807B458:
	ldr r0, _0807B46C @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0807B470
	adds r1, r4, #0
	bl FUN_08063574
	b _0807B478
	.align 2, 0
_0807B468: .4byte 0x085ABF4C
_0807B46C: .4byte 0x03002BE0
_0807B470:
	ldr r1, _0807B480 @ =0x03002BA0
	lsls r0, r4, #1
	adds r0, r0, r1
	strh r2, [r0]
_0807B478:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807B480: .4byte 0x03002BA0
