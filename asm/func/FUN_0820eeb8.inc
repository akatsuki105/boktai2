	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r3, #1
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #4
_0820EEC6:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820EEC6
	movs r1, #0x25
	adds r1, r1, r5
	mov ip, r1
	movs r3, #1
	movs r2, #0xdd
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #2
_0820EEE4:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0820EEE4
	movs r4, #0
	movs r3, #0
	mov r6, ip
	ldrb r0, [r6]
	cmp r0, #8
	bhi _0820EF76
	lsls r0, r0, #2
	ldr r1, _0820EF08 @ =_0820EF0C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820EF08: .4byte _0820EF0C
_0820EF0C: @ jump table
	.4byte _0820EF30 @ case 0
	.4byte _0820EF36 @ case 1
	.4byte _0820EF3C @ case 2
	.4byte _0820EF46 @ case 3
	.4byte _0820EF4E @ case 4
	.4byte _0820EF54 @ case 5
	.4byte _0820EF5E @ case 6
	.4byte _0820EF64 @ case 7
	.4byte _0820EF6E @ case 8
_0820EF30:
	movs r1, #0
	movs r2, #0
	b _0820EF40
_0820EF36:
	movs r1, #0
	movs r2, #1
	b _0820EF40
_0820EF3C:
	movs r1, #0
	movs r2, #2
_0820EF40:
	movs r4, #0x70
	movs r3, #0x13
	b _0820EF7A
_0820EF46:
	movs r1, #1
	movs r2, #1
	rsbs r2, r2, #0
	b _0820EF7A
_0820EF4E:
	movs r1, #2
	movs r2, #0
	b _0820EF58
_0820EF54:
	movs r1, #2
	movs r2, #1
_0820EF58:
	movs r4, #0x60
	movs r3, #0x13
	b _0820EF7A
_0820EF5E:
	movs r1, #3
	movs r2, #0
	b _0820EF68
_0820EF64:
	movs r1, #3
	movs r2, #1
_0820EF68:
	movs r4, #0x80
	movs r3, #0x13
	b _0820EF7A
_0820EF6E:
	movs r1, #4
	movs r2, #1
	rsbs r2, r2, #0
	b _0820EF7A
_0820EF76:
	movs r1, #0
	movs r2, #1
_0820EF7A:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	movs r6, #0xca
	lsls r6, r6, #1
	adds r1, r5, r6
	adds r1, r1, r0
	ldr r0, [r1]
	movs r6, #2
	rsbs r6, r6, #0
	ands r0, r6
	str r0, [r1]
	cmp r2, #0
	blt _0820EFBA
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #5
	movs r0, #0xdd
	lsls r0, r0, #2
	adds r2, r5, r0
	adds r2, r2, r1
	ldr r0, [r2]
	ands r0, r6
	str r0, [r2]
	adds r1, r5, r1
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r1, r2
	strh r4, [r0]
	ldr r6, _0820EFC0 @ =0x0000038E
	adds r1, r1, r6
	strh r3, [r1]
_0820EFBA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0820EFC0: .4byte 0x0000038E
