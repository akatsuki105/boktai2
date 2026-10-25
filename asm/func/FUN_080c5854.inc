	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldr r1, _080C5888 @ =0x000008F9
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _080C5906
	ldr r0, _080C588C @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r5, #0x2c
	ldrsh r2, [r0, r5]
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r2, r0
	blt _080C5894
	ldr r1, _080C5890 @ =0x000008FA
	adds r0, r4, r1
	strb r3, [r0]
	b _080C589C
	.align 2, 0
_080C5888: .4byte 0x000008F9
_080C588C: .4byte 0x03002BE0
_080C5890: .4byte 0x000008FA
_080C5894:
	ldr r2, _080C5914 @ =0x000008FA
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
_080C589C:
	ldr r5, _080C5918 @ =0x000008F9
	adds r0, r4, r5
	movs r2, #1
	strb r2, [r0]
	ldr r7, _080C5914 @ =0x000008FA
	adds r3, r4, r7
	ldrb r0, [r3]
	lsls r0, r0, #7
	adds r5, #2
	adds r1, r4, r5
	strb r0, [r1]
	ldrb r0, [r3]
	subs r2, r2, r0
	lsls r2, r2, #1
	mov ip, r2
	ldr r7, _080C591C @ =FUN_080c52f0
	mov sb, r7
	movs r0, #0x90
	lsls r0, r0, #4
	adds r2, r4, r0
	adds r3, r4, #0
	movs r6, #0
	mov sl, r2
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	movs r5, #0xd
_080C58D2:
	mov r7, sl
	adds r1, r7, r6
	ldr r0, [r1]
	mov r7, r8
	ands r0, r7
	str r0, [r1]
	ldr r0, _080C5920 @ =0x0000094E
	adds r1, r3, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080C5924 @ =0x0000094B
	adds r0, r3, r1
	ldrb r0, [r0]
	add r0, ip
	strh r0, [r2, #0x10]
	adds r2, #0x50
	adds r3, #0x50
	adds r6, #0x50
	subs r5, #1
	cmp r5, #0
	bge _080C58D2
	ldr r2, _080C5928 @ =0x000008F8
	adds r0, r4, r2
	mov r1, sb
	bl FUN_080c52e0
_080C5906:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C5914: .4byte 0x000008FA
_080C5918: .4byte 0x000008F9
_080C591C: .4byte FUN_080c52f0
_080C5920: .4byte 0x0000094E
_080C5924: .4byte 0x0000094B
_080C5928: .4byte 0x000008F8
