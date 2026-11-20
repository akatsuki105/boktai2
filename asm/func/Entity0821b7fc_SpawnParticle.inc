	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r2, r1, #0
	movs r0, #0
	movs r1, #0x7c
	adds r1, r1, r6
	mov r8, r1
	adds r4, r6, #0
	adds r4, #0x94
_0821B376:
	movs r1, #0x10
	ldrsh r3, [r4, r1]
	mov sb, r3
	cmp r3, #0
	bne _0821B454
	movs r1, #0
	movs r0, #1
	strh r0, [r4, #0x10]
	strh r2, [r4, #0x12]
	strb r1, [r4, #0x16]
	ldr r5, _0821B41C @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r7, _0821B420 @ =0x000003FF
	ands r0, r7
	str r0, [r5]
	lsls r0, r0, #1
	ldr r3, _0821B424 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xa
	str r2, [sp]
	bl Mod
	adds r0, #0xa
	strb r0, [r4, #0x17]
	ldr r2, [sp]
	cmp r2, #0
	bge _0821B428
	ldr r0, [r5]
	adds r0, #1
	ands r0, r7
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _0821B424 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xa0
	bl Mod
	adds r1, r6, #0
	adds r1, #0x60
	ldrh r1, [r1]
	subs r1, #0x50
	adds r1, r1, r0
	strh r1, [r4]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r7
	str r0, [r5]
	lsls r0, r0, #1
	ldr r3, _0821B424 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x50
	bl Mod
	adds r1, r6, #0
	adds r1, #0x62
	ldrh r1, [r1]
	subs r1, #0x28
	adds r1, r1, r0
	strh r1, [r4, #2]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r7
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _0821B424 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xa0
	bl Mod
	adds r1, r6, #0
	adds r1, #0x64
	ldrh r1, [r1]
	subs r1, #0x50
	adds r1, r1, r0
	strh r1, [r4, #4]
	mov r3, sb
	strh r3, [r4, #0x14]
	b _0821B444
	.align 2, 0
_0821B41C: .4byte 0x030046B8
_0821B420: .4byte 0x000003FF
_0821B424: .4byte 0x0203B400
_0821B428:
	adds r0, r6, #0
	adds r0, #0x60
	ldrh r0, [r0]
	strh r0, [r4]
	adds r0, r6, #0
	adds r0, #0x62
	ldrh r0, [r0]
	strh r0, [r4, #2]
	adds r0, r6, #0
	adds r0, #0x64
	ldrh r0, [r0]
	strh r0, [r4, #4]
	movs r0, #0xf
	strh r0, [r4, #0x14]
_0821B444:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r3, r8
	str r0, [r3]
	b _0821B460
_0821B454:
	movs r1, #0x30
	add r8, r1
	adds r4, #0x30
	adds r0, #1
	cmp r0, #7
	ble _0821B376
_0821B460:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
