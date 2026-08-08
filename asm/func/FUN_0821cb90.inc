	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _0821CC32
	ldr r1, _0821CBC0 @ =0x085AFFA8
	ldr r3, _0821CBC4 @ =0x00000809
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #9
	beq _0821CBD2
	cmp r0, #9
	bgt _0821CBC8
	cmp r0, #6
	beq _0821CC00
	b _0821CD84
	.align 2, 0
_0821CBC0: .4byte 0x085AFFA8
_0821CBC4: .4byte 0x00000809
_0821CBC8:
	cmp r0, #0xa
	beq _0821CC20
	cmp r0, #0xb
	beq _0821CBE2
	b _0821CD84
_0821CBD2:
	str r2, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #9
	bl FUN_0821d870
	b _0821CD84
_0821CBE2:
	movs r4, #0x3d
	str r2, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xb
	bl FUN_0821d870
	ldr r1, _0821CBFC @ =0x00000806
	adds r0, r5, r1
	strh r4, [r0]
	b _0821CD84
	.align 2, 0
_0821CBFC: .4byte 0x00000806
_0821CC00:
	movs r0, #0x3c
	movs r4, #0x3d
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #6
	bl FUN_0821d870
	ldr r2, _0821CC1C @ =0x00000806
	adds r0, r5, r2
	strh r4, [r0]
	b _0821CD84
	.align 2, 0
_0821CC1C: .4byte 0x00000806
_0821CC20:
	movs r0, #0x3c
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xa
	bl FUN_0821d870
	b _0821CD84
_0821CC32:
	ldr r1, _0821CC54 @ =0x085AFFA8
	ldr r3, _0821CC58 @ =0x00000809
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #6
	cmp r0, #5
	bls _0821CC4A
	b _0821CD38
_0821CC4A:
	lsls r0, r0, #2
	ldr r1, _0821CC5C @ =_0821CC60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0821CC54: .4byte 0x085AFFA8
_0821CC58: .4byte 0x00000809
_0821CC5C: .4byte _0821CC60
_0821CC60: @ jump table
	.4byte _0821CCA8 @ case 0
	.4byte _0821CD38 @ case 1
	.4byte _0821CCC8 @ case 2
	.4byte _0821CC78 @ case 3
	.4byte _0821CD28 @ case 4
	.4byte _0821CC8A @ case 5
_0821CC78:
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #9
	bl FUN_0821d870
	b _0821CD38
_0821CC8A:
	movs r0, #0
	movs r4, #0x5a
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xb
	bl FUN_0821d870
	ldr r1, _0821CCA4 @ =0x00000806
	adds r0, r5, r1
	strh r4, [r0]
	b _0821CD38
	.align 2, 0
_0821CCA4: .4byte 0x00000806
_0821CCA8:
	movs r0, #0x3c
	movs r4, #0x2d
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #6
	bl FUN_0821d870
	ldr r2, _0821CCC4 @ =0x00000806
	adds r0, r5, r2
	strh r4, [r0]
	b _0821CD38
	.align 2, 0
_0821CCC4: .4byte 0x00000806
_0821CCC8:
	movs r0, #0x3c
	movs r4, #0x2d
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #8
	bl FUN_0821d870
	ldr r3, _0821CD04 @ =0x00000806
	adds r0, r5, r3
	movs r1, #0
	strh r4, [r0]
	ldr r2, _0821CD08 @ =0x0000080C
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0x20
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r2, r5, r3
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0821CD10
	ldr r0, _0821CD0C @ =0x00000809
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0821CD18
	.align 2, 0
_0821CD04: .4byte 0x00000806
_0821CD08: .4byte 0x0000080C
_0821CD0C: .4byte 0x00000809
_0821CD10:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
_0821CD18:
	ldr r2, _0821CD24 @ =0x000003DB
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	b _0821CD38
	.align 2, 0
_0821CD24: .4byte 0x000003DB
_0821CD28:
	movs r0, #0x3c
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xa
	bl FUN_0821d870
_0821CD38:
	ldr r3, _0821CD8C @ =0x0000080C
	adds r6, r5, r3
	ldr r1, [r6]
	ldr r0, _0821CD90 @ =0x000005DB
	cmp r1, r0
	ble _0821CD60
	movs r0, #0x3c
	movs r4, #0x39
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #8
	bl FUN_0821d870
	ldr r1, _0821CD94 @ =0x00000806
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	str r1, [r6]
_0821CD60:
	movs r2, #0x81
	lsls r2, r2, #4
	adds r4, r5, r2
	ldr r1, [r4]
	ldr r0, _0821CD98 @ =0x00000BB7
	cmp r1, r0
	ble _0821CD84
	movs r0, #0x3c
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #7
	bl FUN_0821d870
	movs r0, #0
	str r0, [r6]
	str r0, [r4]
_0821CD84:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0821CD8C: .4byte 0x0000080C
_0821CD90: .4byte 0x000005DB
_0821CD94: .4byte 0x00000806
_0821CD98: .4byte 0x00000BB7
