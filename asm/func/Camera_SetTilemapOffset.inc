	push {r4, lr}
	movs r0, #0x76
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _0823B718
	ldr r0, _0823B704 @ =0x000056C2
	bl FUN_08230e70
	adds r4, r0, #0
	ldr r1, _0823B708 @ =FUN_0822db5c
	ldr r2, _0823B70C @ =FUN_0822aaac
	ldr r3, _0823B710 @ =FUN_0822f204
	movs r0, #0
	bl FUN_0822a448
	cmp r4, #0
	beq _0823B722
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _0823B722
	ldr r1, _0823B714 @ =0x03003540
	ldrh r0, [r0, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r1, #8]
	ldr r0, [r4, #4]
	ldrh r0, [r0, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	b _0823B728
	.align 2, 0
_0823B704: .4byte 0x000056C2
_0823B708: .4byte FUN_0822db5c
_0823B70C: .4byte FUN_0822aaac
_0823B710: .4byte FUN_0822f204
_0823B714: .4byte 0x03003540
_0823B718:
	ldr r1, _0823B730 @ =FUN_0822de64
	ldr r2, _0823B734 @ =FUN_0822ac90
	ldr r3, _0823B738 @ =FUN_0822f224
	bl FUN_0822a448
_0823B722:
	ldr r1, _0823B73C @ =0x03003540
	movs r0, #0
	strh r0, [r1, #8]
_0823B728:
	strh r0, [r1, #0xa]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823B730: .4byte FUN_0822de64
_0823B734: .4byte FUN_0822ac90
_0823B738: .4byte FUN_0822f224
_0823B73C: .4byte 0x03003540
