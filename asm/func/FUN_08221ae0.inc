	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r0, r0, r5
	mov r8, r0
	movs r7, #0
	ldr r0, _08221B04 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r5, r2
	b _08221C8A
	.align 2, 0
_08221B04: .4byte 0x03002B4C
_08221B08:
	ldr r0, _08221B38 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, r8
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #0x25
	bls _08221B2E
	b _08221C7E
_08221B2E:
	lsls r0, r0, #2
	ldr r1, _08221B3C @ =_08221B40
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08221B38: .4byte 0x03002B4C
_08221B3C: .4byte _08221B40
_08221B40: @ jump table
	.4byte _08221BD8 @ case 0
	.4byte _08221BEA @ case 1
	.4byte _08221C04 @ case 2
	.4byte _08221C7E @ case 3
	.4byte _08221C7E @ case 4
	.4byte _08221C7E @ case 5
	.4byte _08221C7E @ case 6
	.4byte _08221C7E @ case 7
	.4byte _08221C7E @ case 8
	.4byte _08221C7E @ case 9
	.4byte _08221C7E @ case 10
	.4byte _08221C7E @ case 11
	.4byte _08221C7E @ case 12
	.4byte _08221C7E @ case 13
	.4byte _08221C7E @ case 14
	.4byte _08221C7E @ case 15
	.4byte _08221C7E @ case 16
	.4byte _08221C7E @ case 17
	.4byte _08221C7E @ case 18
	.4byte _08221C7E @ case 19
	.4byte _08221C7E @ case 20
	.4byte _08221C7E @ case 21
	.4byte _08221C7E @ case 22
	.4byte _08221C7E @ case 23
	.4byte _08221C7E @ case 24
	.4byte _08221C7E @ case 25
	.4byte _08221C7E @ case 26
	.4byte _08221C7E @ case 27
	.4byte _08221C7E @ case 28
	.4byte _08221C7E @ case 29
	.4byte _08221C7E @ case 30
	.4byte _08221C7E @ case 31
	.4byte _08221C7E @ case 32
	.4byte _08221C24 @ case 33
	.4byte _08221C36 @ case 34
	.4byte _08221C48 @ case 35
	.4byte _08221C5A @ case 36
	.4byte _08221C6E @ case 37
_08221BD8:
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	movs r3, #0
	bl FUN_0821d870
	b _08221C7E
_08221BEA:
	ldrh r1, [r4, #8]
	adds r0, r6, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrh r0, [r4, #0xa]
	adds r1, r6, #0
	adds r1, #0x52
	strh r0, [r1]
	ldrh r1, [r4, #0xc]
	adds r0, r6, #0
	adds r0, #0x54
	strh r1, [r0]
	b _08221C60
_08221C04:
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	movs r3, #1
	bl FUN_0821d870
	ldrh r1, [r4, #8]
	ldr r2, _08221C20 @ =0x00000804
	adds r0, r5, r2
	strh r1, [r0]
	b _08221C7E
	.align 2, 0
_08221C20: .4byte 0x00000804
_08221C24:
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	movs r3, #4
	bl FUN_0821d870
	b _08221C7E
_08221C36:
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	movs r3, #5
	bl FUN_0821d870
	b _08221C7E
_08221C48:
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	movs r3, #2
	bl FUN_0821d870
	b _08221C7E
_08221C5A:
	adds r0, r5, #0
	bl FUN_0821bd14
_08221C60:
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #1
	bl FUN_08022488
	b _08221C7E
_08221C6E:
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	movs r3, #3
	bl FUN_0821d870
_08221C7E:
	adds r7, #1
	ldr r0, _08221CA4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, r8
	adds r0, #6
_08221C8A:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _08221C96
	b _08221B08
_08221C96:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08221CA4: .4byte 0x03002B4C
