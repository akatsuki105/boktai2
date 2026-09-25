	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	bne _0820F126
	adds r4, r6, #0
	adds r4, #0x28
	adds r0, r4, #0
	bl FUN_08055d20
	adds r7, r4, #0
	cmp r0, #0
	beq _0820F0E8
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0xc
	bhi _0820F0E8
	lsls r0, r0, #2
	ldr r1, _0820F054 @ =_0820F058
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820F054: .4byte _0820F058
_0820F058: @ jump table
	.4byte _0820F08C @ case 0
	.4byte _0820F098 @ case 1
	.4byte _0820F0A4 @ case 2
	.4byte _0820F0B0 @ case 3
	.4byte _0820F0BC @ case 4
	.4byte _0820F0C8 @ case 5
	.4byte _0820F0D4 @ case 6
	.4byte _0820F0E8 @ case 7
	.4byte _0820F0E8 @ case 8
	.4byte _0820F0E8 @ case 9
	.4byte _0820F0E8 @ case 10
	.4byte _0820F0E8 @ case 11
	.4byte _0820F0E0 @ case 12
_0820F08C:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	b _0820F0E8
_0820F098:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	b _0820F0E8
_0820F0A4:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #3
	strh r0, [r1]
	b _0820F0E8
_0820F0B0:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #4
	strh r0, [r1]
	b _0820F0E8
_0820F0BC:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #5
	strh r0, [r1]
	b _0820F0E8
_0820F0C8:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #6
	strh r0, [r1]
	b _0820F0E8
_0820F0D4:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #0xc
	strh r0, [r1]
	b _0820F0E8
_0820F0E0:
	adds r1, r6, #0
	adds r1, #0x24
	movs r0, #1
	strb r0, [r1]
_0820F0E8:
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	subs r1, #0xa
	adds r4, r6, r1
	adds r1, #1
	adds r5, r6, r1
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0820efc4
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldrb r2, [r4]
	ldrb r3, [r5]
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r7, #0
	bl FUN_08055b5c
	adds r0, r7, #0
	bl FUN_08055c04
_0820F126:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
