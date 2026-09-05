	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080a7448
	adds r0, r4, #0
	bl FUN_080a7550
	movs r1, #0xd0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080A7ABC @ =0x00000341
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #5
	adds r0, r4, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _080A7AC0 @ =0x00000342
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A7A9A
	bl FUN_0823d340
	movs r2, #0xce
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
_080A7A9A:
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A7AC8
	bl Script_GetValue
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080A7AC4 @ =0x0000034A
	adds r1, r4, r2
	b _080A7ADA
	.align 2, 0
_080A7ABC: .4byte 0x00000341
_080A7AC0: .4byte 0x00000342
_080A7AC4: .4byte 0x0000034A
_080A7AC8:
	movs r0, #0xd2
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0xfa
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r2, _080A7B00 @ =0x0000034A
	adds r1, r4, r2
	movs r0, #0xfa
_080A7ADA:
	strh r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080A7B04
	bl Script_GetValue
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	b _080A7B0C
	.align 2, 0
_080A7B00: .4byte 0x0000034A
_080A7B04:
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
_080A7B0C:
	ldr r0, _080A7B18 @ =0x03000150
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A7B18: .4byte 0x03000150
