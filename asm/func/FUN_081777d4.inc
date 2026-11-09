	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r6, [r0]
	movs r7, #0xff
	movs r2, #0
	ldr r3, _08177810 @ =0x00001012
	adds r0, r6, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r2, r0
	bge _0817782E
	movs r3, #4
	mov ip, r3
	adds r4, r0, #0
	movs r3, #0
_081777FA:
	adds r0, r3, r6
	ldr r5, _08177814 @ =0x00000755
	adds r0, r0, r5
	ldrb r0, [r0]
	mov r5, ip
	ands r0, r5
	cmp r0, #0
	beq _08177818
	movs r0, #1
	b _0817781A
	.align 2, 0
_08177810: .4byte 0x00001012
_08177814: .4byte 0x00000755
_08177818:
	movs r0, #0
_0817781A:
	cmp r0, #0
	beq _08177822
	adds r7, r2, #0
	b _0817782E
_08177822:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r3, r3, r0
	adds r2, #1
	cmp r2, r4
	blt _081777FA
_0817782E:
	cmp r7, #0xff
	beq _0817787A
	ldr r2, _08177884 @ =0x00000FC4
	adds r5, r6, r2
	ldrh r1, [r1]
	adds r1, #1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r4, r7, #3
	adds r4, r4, r7
	lsls r4, r4, #3
	adds r4, r4, r7
	lsls r4, r4, #2
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r4, r4, r3
	adds r4, r6, r4
	adds r2, r4, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl Mover_Init
	ldr r1, _08177888 @ =0x00000FEC
	adds r0, r6, r1
	str r4, [r0]
	adds r0, r5, #0
	bl FUN_08002a48
	movs r0, #1
	ldr r3, _0817788C @ =0x00001008
	adds r2, r6, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0817787A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08177884: .4byte 0x00000FC4
_08177888: .4byte 0x00000FEC
_0817788C: .4byte 0x00001008
